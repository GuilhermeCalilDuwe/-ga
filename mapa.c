//SEU PROGRAMA DEVE INCLUIR ESSAS TRES BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <windows.h>
// INCLUA EM SEU CODIGO AS FUNCOES randomInteger, geraMapa E atualizaMapa
// ATENCAO: NAO ALTERE NENHUMA DESSAS TRES FUNCOES

int randomInteger (int low, int high) {
    int k;
    double d;

    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);

    return low + k;
}

void geraMapa(int mapa[10][10]) {
    int i, j, qtdO, qtdA, lin, col;

    srand((unsigned int)time(NULL));

    for (i=0; i<10; i++)
        for (j=0; j<10; j++)
            mapa[i][j] = 0;

    mapa[randomInteger(0,9)][0]= 1;
    mapa[randomInteger(0,9)][9]= 2;
    qtdO = randomInteger(5,25);
    qtdA = randomInteger(3,10);

    while (qtdO>0) {
        lin = randomInteger(0,9);
        col = randomInteger(1,8);
        if (mapa[lin][col] == 0) {
            mapa[lin][col] = 3;
            qtdO--;
        }
    }

    while (qtdA>0) {
        lin = randomInteger(0,9);
        col = randomInteger(1,8);
        if (mapa[lin][col] == 0) {
            mapa[lin][col] = 4;
            qtdA--;
        }
    }
}

void atualizaMapa(int mapa[10][10]) {
    int i, j, upd, atualizado[10][10];
    for (i=0; i<10; i++) for (j=0; j<10; j++) atualizado[i][j]=0;

    for (i=0; i<10; i++)
        for (j=0; j<10; j++) {
            if ((mapa[i][j] == 2 || mapa[i][j] == 3 || mapa[i][j] == 4) && atualizado[i][j] == 0) {
                upd = randomInteger(1,4);
                switch (upd) {
                    case 1:
                        if ((mapa[i-1][j] == 0 || (mapa[i-1][j] == 1 && mapa[i][j] == 3)) && i>0) {
                            mapa[i-1][j] = mapa[i][j];
                            mapa[i][j] = 0;
                            atualizado[i-1][j]=1;
                        }
                        break;
                    case 2:
                        if ((mapa[i+1][j] == 0 || (mapa[i+1][j] == 1 && mapa[i][j] == 3)) && i<9) {
                            mapa[i+1][j] = mapa[i][j];
                            mapa[i][j] = 0;
                            atualizado[i+1][j]=1;
                        }
                        break;
                    case 3:
                        if ((mapa[i][j+1] == 0 || (mapa[i][j+1] == 1 && mapa[i][j] == 3)) && j<9) {
                            mapa[i][j+1] = mapa[i][j];
                            mapa[i][j] = 0;
                            atualizado[i][j+1]=1;
                        }
                        break;
                    case 4:
                        if ((mapa[i][j-1] == 0 || (mapa[i][j-1] == 1 && mapa[i][j] == 3)) && j>0) {
                            mapa[i][j-1] = mapa[i][j];
                            mapa[i][j] = 0;
                            atualizado[i][j-1]=1;
                        }
                }
            }
       }
}


// DECLARE A MATRIZ mapa, COM ESCOPO GLOBAL, VEJA O EXEMPLO A SEGUIR
//int mapa[10][10];

// TODA VEZ QUE VOCE DESEJAR GERAR UM NOVO MAPA, BASTA CHAMAR A FUNCAO geraMapa, conforme o exemplo a seguir
//geraMapa(mapa);

// TODA VEZ QUE VOCE DESEJAR ATUALIZAR UM MAPA, BASTA CHAMAR A FUNCAO atualizaMapa, conforme o exemplo a seguir
//atualizaMapa(mapa);¨
