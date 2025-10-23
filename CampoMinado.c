/*
    Implementação do TF da disciplina de Programação de Software Básico
    
Por Natan de Aragão Müller - 23104739;
Data final de entrega: 06/10/2025.

Propósito: Implementação do jogo campo minado utilizando a linguagem C, seguindo as regras clássicas do jogo presentes 
na wikipédia, mais detalhes no PDF do enunciado.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preparaTabuleiro(char tab[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tab[i][j] = ' ';
        }
    }
    int bombasPostas = 0;
    while(bombasPostas < 3) {
        int linha = rand() % 5;
        int coluna = rand() % 5;
        if(tab[linha][coluna] != '*') {
            tab[linha][coluna] = '*';
            bombasPostas++;
        }
    }
}

void imprimeTabuleiro(char tab[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("|%c|", tab[i][j]);
        }
        printf("\n");
    }
}

void preencheComNumeros(char tab[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(tab[i][j] != '*') {
                int contadorBombas = 0;
                for(int x = -1; x <= 1; x++) {
                    for(int y = -1; y <= 1; y++) {
                        int novoI = i + x;
                        int novoJ = j + y;
                        if(novoI >= 0 && novoI < 5 && novoJ >= 0 && novoJ < 5) {
                            if(tab[novoI][novoJ] == '*') {
                                contadorBombas++;
                            }
                        }
                    }
                }
                if(contadorBombas > 0) {
                    tab[i][j] = '0' + contadorBombas;
                }
                else {
                    tab[i][j] = '0';
                }
            }
        }
    }
}

void ocultaTabuleiro(char tab[5][5]) {
    char tab_oculto[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tab_oculto[i][j] = 'X';
        }
    }
}

void revelaPosicao(char tab[5][5], int linha, int coluna) {

}

int main() {
    
    char nomeJogador[20];

    printf("Digite seu nome (maximo 20 caracteres):\n");
    fgets(nomeJogador, sizeof(nomeJogador), stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = 0;

    printf("Olá, %s!\nSelecione uma opcao dentre as listadas:\n", nomeJogador);
    printf("0 - Iniciar novo jogo\n1 - Consultar os 10 ultimos escores\n\nPara sair selecione qualquer outra tecla.\n");
    
    int selecao;
    scanf("%d", &selecao);

    if(selecao == 0) {
        printf("Vamos comecar o jogo, boa sorte, %s!\n", nomeJogador);
        char tab[5][5];
        preparaTabuleiro(tab);
        preencheComNumeros(tab);
//PROXIMO PASSO AJUSTAR A LOGICA DE OCULTAR O TABULEIRO!!!!!!
        ocultaTabuleiro(tab);
        imprimeTabuleiro(tab);
        return 0;
    }
    else if(selecao == 1) {
        return 0;
    }
    else {
        printf("Ate a proxima, %s!\n", nomeJogador);
        return 0;
    }
}