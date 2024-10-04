/*
Programa: RestaUm.c
Autores: Christian Oliveira
         Igor Antunes
         Marcus William
Data de criacao: 12/03/2022
Descricao: Este programa emula o jogo de tabuleiro Resta Um na linguagem C.
O usuario controla um cursor sobre o tabuleiro com as teclas direcionais e seleciona a peca a ser movimentada
com a tecla espaco. A tecla R reinicia o jogo. O jogador vence no momento em que
houver apenas uma peca no tabuleiro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int k=3;
int l=3;
int selecao=0;
int movimentos(int *matriz[][7]);

int main(void){
/* Na funcao main, determinamos as pecas do jogo */
    int i, j, tabuleiro[7][7], *tabuleiroPont[7][7];
    char gatilho;
/* Tela de inicio, aguardando o input do usuario */
    system("@cls||clear");
    printf("\n");                                                       
    printf("\t\033[1;31mRRRRRRRRRRRRRRRRR                                                 tttt                                   \033[1;34m1111111\n");  
    printf("\t\033[1;31mR::::::::::::::::R                                             ttt:::t                                  \033[1;34m1::::::1\n");   
    printf("\t\033[1;31mR::::::RRRRRR:::::R                                            t:::::t                                 \033[1;34m1:::::::1\n");   
    printf("\t\033[1;31mRR:::::R     R:::::R                                           t:::::t                                 \033[1;34m111:::::1\n");   
    printf("\t\033[1;31m  R::::R     R:::::R    eeeeeeeeeeee        ssssssssss   ttttttt:::::ttttttt      aaaaaaaaaaaaa           \033[1;34m1::::1\n");   
    printf("\t\033[1;31m  R::::R     R:::::R  ee::::::::::::ee    ss::::::::::s  t:::::::::::::::::t      a::::::::::::a          \033[1;34m1::::1\n");   
    printf("\t\033[1;31m  R::::RRRRRR:::::R  e::::::eeeee:::::eess:::::::::::::s t:::::::::::::::::t      aaaaaaaaa:::::a         \033[1;34m1::::1\n");  
    printf("\t\033[1;31m  R:::::::::::::RR  e::::::e     e:::::es::::::ssss:::::stttttt:::::::tttttt               a::::a         \033[1;34m1::::l\n");   
    printf("\t\033[1;31m  R::::RRRRRR:::::R e:::::::eeeee::::::e s:::::s  ssssss       t:::::t              aaaaaaa:::::a         \033[1;34m1::::l\n");   
    printf("\t\033[1;31m  R::::R     R:::::Re:::::::::::::::::e    s::::::s            t:::::t            aa::::::::::::a         \033[1;34m1::::l\n");   
    printf("\t\033[1;31m  R::::R     R:::::Re::::::eeeeeeeeeee        s::::::s         t:::::t           a::::aaaa::::::a         \033[1;34m1::::l\n");   
    printf("\t\033[1;31m  R::::R     R:::::Re:::::::e           ssssss   s:::::s       t:::::t    tttttta::::a    a:::::a         \033[1;34m1::::l\n");   
    printf("\t\033[1;31mRR:::::R     R:::::Re::::::::e          s:::::ssss::::::s      t::::::tttt:::::ta::::a    a:::::a      \033[1;34m111::::::111\n");
    printf("\t\033[1;31mR::::::R     R:::::R e::::::::eeeeeeee  s::::::::::::::s       tt::::::::::::::ta:::::aaaa::::::a      \033[1;34m1::::::::::1\n");
    printf("\t\033[1;31mR::::::R     R:::::R  ee:::::::::::::e   s:::::::::::ss          tt:::::::::::tt a::::::::::aa:::a     \033[1;34m1::::::::::1\n");
    printf("\t\033[1;31mRRRRRRRR     RRRRRRR    eeeeeeeeeeeeee    sssssssssss              ttttttttttt    aaaaaaaaaa  aaaa     \033[1;34m111111111111\n\n");
    printf("                                        \033[1;37m\tAperte Enter para continuar\n\n\n");
    gatilho = getchar();
    while (gatilho != '\n') {
        gatilho = getchar();
    }
    system("@cls||clear");
    for (i = 0; i<7; i ++) {
        for (j = 0; j<7; j ++) {
            if (i == 3 && j == 3) {
                tabuleiro[i][j] = 10;
            }
            else {
                tabuleiro[i][j] = 1;
            }
        }
    }
    
    tabuleiro[0][0] = 8;
    tabuleiro[0][1] = 8;
    tabuleiro[0][5] = 8;
    tabuleiro[0][6] = 8;
    tabuleiro[1][0] = 8;
    tabuleiro[1][1] = 8;
    tabuleiro[1][5] = 8;
    tabuleiro[1][6] = 8;
    tabuleiro[5][0] = 8;
    tabuleiro[5][1] = 8;
    tabuleiro[5][5] = 8;
    tabuleiro[5][6] = 8;
    tabuleiro[6][0] = 8;
    tabuleiro[6][1] = 8;
    tabuleiro[6][5] = 8;
    tabuleiro[6][6] = 8;
/* Realiza a atribuicao ao ponteiro *tabuleiroPont */
    for (i = 0; i<7; i ++) {
        printf("\n");
        printf("\t\t");
        for (j = 0; j<7; j ++) {
            tabuleiroPont[i][j] = &tabuleiro[i][j];
            if (tabuleiro[i][j] == 8) {
                printf("   ");
            }
            else if (tabuleiro[i][j] == 0) {
                printf("\033[1;31m . \033[0;37m");
            }
            else if (tabuleiro[i][j] == 10) {
                printf("\033[1;33m(.)\033[0;37m");
            }
            else if (tabuleiro[i][j] == 11) {
                printf("\033[1;33m(O)\033[0;37m");
            }
            else if (tabuleiro[i][j] == 12) {
                printf("\033[1;32m<.>\033[0;37m");
            }
            else if (tabuleiro[i][j] == 13) {
                printf("\033[1;32m<O>\033[0;37m");
            }
            else {
                printf("\033[1;34m O \033[0;37m");
            }
        }
    }
    printf("\n");
    movimentos(tabuleiroPont);
    return 0;
}

int movimentos(int *matriz[][7]){
/* Na funcao movimentos, determinamos as regras de movimentacao, comportamento das pecas e condicoes especiais */
    int venceu, m, n;
    char direcao;
    printf("\n\n\t\tControles:\n");
    printf("\t\tSetas Direcionais: Movimentar Cursor\n");
    printf("\t\tEspaco: Selecionar\n");
    printf("\t\tTecla R: Reiniciar\n");
    direcao=getch();
    system("@cls||clear");
/* Determina o que sera realizado a partir do input do usuario, indicando movimentos invalidos e possiveis erros de entrada */
    switch (direcao) {
        case 72:
            if (selecao==0 && (k-1)>=0 && *matriz[k-1][l]!=8){
                *matriz[k][l]-=10;
                *matriz[k-1][l]+=10;
                k--;
            }
            else if ((k-2)>=0 && *matriz[k][l] + *matriz[k-1][l] + *matriz[k-2][l] == 14 && *matriz[k][l] + *matriz[k-1][l] == 14) {
                *matriz[k][l] = 0;
                *matriz[k-1][l] = 0;
                *matriz[k-2][l] = 11;
                k-=2;
                selecao--;
            }
            else {
                printf("\t\t\033[1;31m  Movimento Invalido\033[0m");
                
            }
            break;
        case 75:
            if (selecao==0 && (l-1)>=0 && *matriz[k][l-1]!=8){
                *matriz[k][l]-=10;
                *matriz[k][l-1]+=10;
                l--;
            }
            else if ((l-2)>=0 && *matriz[k][l] + *matriz[k][l-1] + *matriz[k][l-2] == 14 && *matriz[k][l] + *matriz[k][l-1] == 14) {
                *matriz[k][l] = 0;
                *matriz[k][l-1] = 0;
                *matriz[k][l-2] = 11;
                l-=2;
                selecao--;
            }
            else {
                printf("\t\t\033[1;31m  Movimento Invalido\033[0m");
                
            }
            break;
        case 80:
            if (selecao==0 && (k+1)<=6 && *matriz[k+1][l]!=8){
                *matriz[k][l]-=10;
                *matriz[k+1][l]+=10;
                k++;
            }
            else if ((k+2)<=6 && *matriz[k][l] + *matriz[k+1][l] + *matriz[k+2][l] == 14 && *matriz[k][l] + *matriz[k+1][l] == 14) {
                *matriz[k][l] = 0;
                *matriz[k+1][l] = 0;
                *matriz[k+2][l] = 11;
                k+=2;
                selecao--;
            }
            else {
                printf("\t\t\033[1;31m  Movimento Invalido\033[0m");
                
            }
            break;
        case 77:
            if (selecao==0 && (l+1)<=6 && *matriz[k][l+1]!=8){
                *matriz[k][l]-=10;
                *matriz[k][l+1]+=10;
                l++;
            }
            else if ((l+2)<=6 && *matriz[k][l] + *matriz[k][l+1] + *matriz[k][l+2] == 14 && *matriz[k][l] + *matriz[k][l+1] == 14){
                *matriz[k][l] = 0;
                *matriz[k][l+1] = 0;
                *matriz[k][l+2] = 11;
                l+=2;
                selecao--;
            }
            else {
                printf("\t\t\033[1;31m  Movimento Invalido\033[0m");
                
            }
            break;
        case ' ':
            if (selecao==0){
                selecao++;
                *matriz[k][l] += 2;
            }
            else if( selecao==1) {
                selecao--;
                *matriz[k][l] -= 2;
            }
            break;
        case 'r':
            k=3;
            l=3;
            selecao=0;
            return main();
            break;
        case 'R':
            k=3;
            l=3;
            selecao=0;
            return main();
            break;
        default:
            break;
    }
/* Realiza a impressao de um novo tabuleiro a cada movimento */
    for (m = 0; m<7; m++) {
        printf("\n");
        printf("\t\t");
        for (n = 0; n<7; n++) {
            if (*matriz[m][n] == 8) {
                printf("   ");
            }
            else if (*matriz[m][n] == 0) {
                printf("\033[1;31m . \033[0;37m");
            }
            else if (*matriz[m][n] == 10) {
                printf("\033[1;33m(.)\033[0;37m");
            }
            else if (*matriz[m][n] == 11) {
                printf("\033[1;33m(O)\033[0;37m");
            }
            else if (*matriz[m][n] == 12) {
                printf("\033[1;32m<.>\033[0;37m");
            }
            else if (*matriz[m][n] == 13) {
                printf("\033[1;32m<O>\033[0;37m");
            }
            else {
                printf("\033[1;34m O \033[0;37m");
            }
        }
    }
/* Condicao especial de vitoria */
    printf("\n");
    for (m = 0; m<7; m++) {
        for (n = 0; n<7; n++) {
            venceu += *matriz[m][n];
        }
    }
    if (venceu <=139) {
    printf("\t\033[1;32m________                             ___                                                                 \033[0;37m\n");
    printf("\t\033[1;32m`MMMMMMMb.                            MM                                                                 \033[0;37m\n");
    printf("\t\033[1;32m MM    `Mb                            MM                                                                 \033[0;37m\n");
    printf("\t\033[1;32m MM     MM    ___   ___  __    ___    MM____     ____  ___  __     ____                                  \033[0;37m\n");
    printf("\t\033[1;32m MM     MM  6MMMMb  `MM 6MM  6MMMMb   MMMMMMb   6MMMMb `MM 6MMb   6MMMMb                                 \033[0;37m\n");
    printf("\t\033[1;32m MM    .M9 8M'  `Mb  MM69   8M'  `Mb  MM'  `Mb 6M'  `Mb MMM9 `Mb MM'    `                                \033[0;37m\n");
    printf("\t\033[1;32m MMMMMMM9'     ,oMM  MM'        ,oMM  MM    MM MM    MM MM'   MM YM.                                     \033[0;37m\n");
    printf("\t\033[1;32m MM        ,6MM9'MM  MM     ,6MM9'MM  MM    MM MMMMMMMM MM    MM  YMMMMb                                 \033[0;37m\n");
    printf("\t\033[1;32m MM        MM'   MM  MM     MM'   MM  MM    MM MM       MM    MM      `Mb                                \033[0;37m\n");
    printf("\t\033[1;32m MM        MM.  ,MM  MM     MM.  ,MM  MM.  ,M9 YM    d9 MM    MM L    ,MM 68b                            \033[0;37m\n");
    printf("\t\033[1;32m_MM_       `YMMM9'Yb_MM_    `YMMM9'Yb_MYMMMM9   YMMMM9 _MM_  _MM_MYMMMM9  Y89                            \033[0;37m\n");
    printf("\t\033[1;32m                                                                           9                             \033[0;37m\n");
    printf("\t\033[1;32m                                                                          /                              \033[0;37m\n");                                                                                                                                                                            
    printf("\t\033[1;32m____     ___                                 ____     ___                                             8  \033[0;37m\n");
    printf("\t\033[1;32m`Mb(     )d'                                 `Mb(     )d'                                            (M) \033[0;37m\n");
    printf("\t\033[1;32m YM.     ,P                                   YM.     ,P                                             (M) \033[0;37m\n");
    printf("\t\033[1;32m `Mb     d'  _____     ____     ____          `Mb     d'  ____  ___  __     ____     ____  ___   ___ (M) \033[0;37m\n");
    printf("\t\033[1;32m  YM.   ,P  6MMMMMb   6MMMMb.  6MMMMb          YM.   ,P  6MMMMb `MM 6MMb   6MMMMb.  6MMMMb `MM    MM  M  \033[0;37m\n");
    printf("\t\033[1;32m  `Mb   d' 6M'   `Mb 6M'   Mb 6M'  `Mb         `Mb   d' 6M'  `Mb MMM9 `Mb 6M'   Mb 6M'  `Mb MM    MM  M  \033[0;37m\n");
    printf("\t\033[1;32m   YM. ,P  MM     MM MM    `' MM    MM          YM. ,P  MM    MM MM'   MM MM    `' MM    MM MM    MM  M  \033[0;37m\n");
    printf("\t\033[1;32m   `Mb d'  MM     MM MM       MMMMMMMM          `Mb d'  MMMMMMMM MM    MM MM       MMMMMMMM MM    MM  8  \033[0;37m\n");
    printf("\t\033[1;32m    YM,P   MM     MM MM       MM                 YM,P   MM       MM    MM MM       MM       MM    MM     \033[0;37m\n");
    printf("\t\033[1;32m    `MM'   YM.   ,M9 YM.   d9 YM    d9           `MM'   YM    d9 MM    MM YM.   d9 YM    d9 YM.   MM 68b \033[0;37m\n");
    printf("\t\033[1;32m     YP     YMMMMM9   YMMMM9   YMMMM9             YP     YMMMM9 _MM_  _MM_ YMMMM9   YMMMM9   YMMM9MM_Y89 \033[0;37m\n\n");
    }
    return movimentos(matriz);
}
