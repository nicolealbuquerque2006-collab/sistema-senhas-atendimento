# Sistema de Senhas de Atendimento
Projeto da disciplina **Algoritmos e Pensamento Computacional**, feito em linguagem C.
**Autora:** Nicole Moreira de Albuquerque

## Objetivo
Organizar o atendimento de pacientes por senhas. O sistema cadastra o paciente, define a categoria (Urgente, Preferencial ou Normal), emite uma senha sequencial e chama os pacientes respeitando a prioridade.

## Funcionalidades
- **Cadastro:** o atendente informa gênero, idade, se é gestante ou lactante (só para mulheres), se tem necessidade especial e se tem obesidade. O sistema define a categoria e emite a senha.
- **Classificação:**
  - **Urgente (U001):** idade superior a 80 anos
  - **Preferencial (P001):** gestantes, lactantes, pessoas com necessidades especiais, pessoas obesas, mulheres com 60 anos ou mais e homens com 65 anos ou mais
  - **Normal (N001):** sem condições de prioridade
- **Atendimento:** consultar a próxima senha, chamar o paciente, ver quem está em atendimento e finalizar o atendimento.
- **Painel:** mostra a senha atual, a categoria, as próximas senhas e quantos pacientes estão esperando em cada categoria.
- **Prioridade:** Urgente, depois Preferencial, depois Normal. Dentro de cada categoria, vale a ordem de emissão (FIFO). Senhas já atendidas não voltam para a fila.
- **Validação:** entradas inválidas mostram mensagem de erro e a pergunta é repetida. Também não é possível chamar com a fila vazia, finalizar sem atendimento ou chamar outro paciente sem finalizar o atual.

## Como compilar e executar
Pelo terminal:
```bash
gcc main.c -o sistema
./sistema
```

pelo OnlineGDB: escolher a linguagem C, colar o código de `main.c` e clicar em **Run**.

## Funções

| Função | O que faz |
|---|---|
| `main` | Mostra o menu e chama a função escolhida |
| `limpar` | Limpa a entrada do teclado |
| `lerNumero` | Lê um número e valida se está no intervalo |
| `lerLetra` | Lê uma letra e valida se é uma das opções (S/N ou F/M) |
| `categoria` | Define a categoria do paciente |
| `proximaFila` | Retorna a categoria que deve ser chamada primeiro |
| `totalEsperando` | Retorna o total de pacientes aguardando |
| `cadastrar` | Cadastra o paciente, gera a senha e coloca na fila |
| `consultar` | Mostra a próxima senha |
| `chamar` | Chama o próximo paciente |
| `verAtual` | Mostra a senha em atendimento |
| `finalizar` | Finaliza o atendimento atual |
| `painel` | Exibe o painel de chamada |

## Exemplos de uso

Cadastro:
```
Opcao: 1
Genero (F/M): F
Idade: 62
Gestante? (S/N): N
Lactante? (S/N): N
Necessidade especial? (S/N): N
Obesidade? (S/N): N
Senha: P001 (Preferencial)
```

Entrada inválida:
```
Opcao: abc
Valor invalido!
```

Painel depois de cadastrar um homem de 30 anos, uma mulher de 62 e um homem de 85, nessa ordem:
```
--- PAINEL ---
Ninguem em atendimento.
Proximas: U001 P001 N001
Urgente: 1 esperando
Preferencial: 1 esperando
Normal: 1 esperando
```

O paciente de 85 anos chegou por último, mas é chamado primeiro:
```
Opcao: 3
Chamando senha U001 (Urgente)
```
