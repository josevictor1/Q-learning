#include "aprendizagem.h"


int main(){

    Problema p; /*= (Problema)malloc(sizeof(Problema));*/
    int i,j;
    

    for(i = 0; i < 16; i++){
        //printf(" %d ",rand()%16);
        for(j = 0;j < 16; j++){

            p.matriz_recompensas[i][j] = -1;
            p.matriz_q[i][j] = 0;

        }

    }

    p.fator_desconto = 0.8;
    p.estado_inicial = 0;
    p.estado_meta = 15;
    p.numero_interacoes = 200;

    p.matriz_recompensas[0][1] = 0;
    p.matriz_recompensas[0][4] = 0;
    p.matriz_recompensas[1][0] = 0;
    p.matriz_recompensas[2][3] = 0;
    p.matriz_recompensas[2][6] = 0;
    p.matriz_recompensas[3][2] = 0;
    p.matriz_recompensas[3][7] = 0;
    p.matriz_recompensas[4][0] = 0;
    p.matriz_recompensas[4][8] = 0;
    p.matriz_recompensas[5][6] = 0;
    p.matriz_recompensas[5][9] = 0;
    p.matriz_recompensas[6][2] = 0;
    p.matriz_recompensas[6][5] = 0;
    p.matriz_recompensas[7][3] = 0;
    p.matriz_recompensas[7][11] = 0;
    p.matriz_recompensas[8][4] = 0;
    p.matriz_recompensas[8][12] = 0;
    p.matriz_recompensas[8][9] = 0;
    p.matriz_recompensas[9][5] = 0;
    p.matriz_recompensas[9][8] = 0;
    p.matriz_recompensas[9][10] = 0;
    p.matriz_recompensas[9][13] = 0;
    p.matriz_recompensas[10][9] = 0;
    p.matriz_recompensas[10][14] = 0;
    p.matriz_recompensas[11][7] = 0;
    p.matriz_recompensas[11][15] = 100;
    p.matriz_recompensas[12][8] = 0;
    p.matriz_recompensas[13][9] = 0;
    p.matriz_recompensas[13][14] = 0;
    p.matriz_recompensas[14][10] = 0;
    p.matriz_recompensas[14][13] = 0;
    p.matriz_recompensas[15][11] = 0;
    p.matriz_recompensas[15][15] = 100;
    /*
    for(i = 0; i < 16; i++){
        std::cout << retorna_aleatrio(16,i) << std::endl;
    }
    aprendizagem(&p,16);

    std::cout << "matriz_q" << std::endl;
    imprimematriz(p.matriz_q);


    std::cout << "matriz_recompensas" << std::endl;
    imprimematriz(p.matriz_recompensas);
    */

    

    







}
