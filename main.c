#include <stdio.h>
#include <ctype.h>
#define MAX 999
int inicio[3], fim[3];
char letras[3] = {'U', 'P', 'N'};
char *nomes[3] = {"Urgente", "Preferencial", "Normal"};
int catAtual = -1, numAtual = 0;
void limpar() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);}
int lerNumero(char *msg, int min, int max) {
    int n, r;
    while (1) {
        printf("%s", msg);
        r = scanf("%d", &n);
        if (r == EOF) return 0;
        limpar();
        if (r == 1 && n >= min && n <= max) return n;
        printf("Valor invalido!\n");}}
char lerLetra(char *msg, char a, char b) {
    char c;
    while (1) {
        printf("%s", msg);
        if (scanf(" %c", &c) != 1) return b;
        limpar();
        c = toupper(c);
        if (c == a || c == b) return c;
        printf("Opcao invalida!\n");}}
int categoria(char genero, int idade, int prioridade) {
    if (idade > 80) return 0;
    if (prioridade || (genero == 'F' && idade >= 60) || (genero == 'M' && idade >= 65)) return 1;
    return 2;}
int proximaFila() {
    for (int i = 0; i < 3; i++)
        if (inicio[i] < fim[i]) return i;
    return -1;}
int totalEsperando() {
    return (fim[0] - inicio[0]) + (fim[1] - inicio[1]) + (fim[2] - inicio[2]);}
void cadastrar() {
    int prioridade = 0;
    char genero = lerLetra("Genero (F/M): ", 'F', 'M');
    int idade = lerNumero("Idade: ", 0, 130);
    if (genero == 'F') {
        if (lerLetra("Gestante? (S/N): ", 'S', 'N') == 'S') prioridade = 1;
        if (lerLetra("Lactante? (S/N): ", 'S', 'N') == 'S') prioridade = 1;}
    if (lerLetra("Necessidade especial? (S/N): ", 'S', 'N') == 'S') prioridade = 1;
    if (lerLetra("Obesidade? (S/N): ", 'S', 'N') == 'S') prioridade = 1;
    int c = categoria(genero, idade, prioridade);
    if (fim[c] == MAX) {
        printf("Fila cheia!\n");
        return;}
    fim[c]++;
    printf("Senha: %c%03d (%s)\n", letras[c], fim[c], nomes[c]);}
void consultar() {
    int i = proximaFila();
    if (i == -1) printf("Fila vazia!\n");
    else printf("Proxima senha: %c%03d (%s)\n", letras[i], inicio[i] + 1, nomes[i]);}
void chamar() {
    if (catAtual != -1) {
        printf("Finalize o atendimento atual primeiro!\n");
        return;}
    int i = proximaFila();
    if (i == -1) {
        printf("Fila vazia!\n");
        return;}
    inicio[i]++;
    catAtual = i;
    numAtual = inicio[i];
    printf("Chamando senha %c%03d (%s)\n", letras[i], numAtual, nomes[i]);}
void verAtual() {
    if (catAtual == -1) printf("Ninguem em atendimento.\n");
    else printf("Em atendimento: %c%03d (%s)\n", letras[catAtual], numAtual, nomes[catAtual]);}
void finalizar() {
    if (catAtual == -1) {
        printf("Nenhum atendimento em andamento!\n");
        return;}
    printf("Atendimento da senha %c%03d finalizado.\n", letras[catAtual], numAtual);
    catAtual = -1;
    printf("Pacientes aguardando: %d\n", totalEsperando());}
void painel() {
    printf("\n--- PAINEL ---\n");
    verAtual();
    printf("Proximas: ");
    for (int i = 0; i < 3; i++)
        for (int j = inicio[i] + 1; j <= fim[i]; j++)
            printf("%c%03d ", letras[i], j);
    printf("\n");
    for (int i = 0; i < 3; i++)
        printf("%s: %d esperando\n", nomes[i], fim[i] - inicio[i]);}
int main() {
    int op;
    do {
        printf("\n1-Cadastrar 2-Proxima senha 3-Chamar 4-Atendimento atual 5-Finalizar 6-Painel 0-Sair\n");
        op = lerNumero("Opcao: ", 0, 6);
        switch (op) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: chamar(); break;
            case 4: verAtual(); break;
            case 5: finalizar(); break;
            case 6: painel(); break;}
    } while (op != 0);
    return 0;}
