#include "aprendizagem.h"
#include <time.h>
#include <list>

int escolheproximo(Problema problema, int n, int estadoatual,int iterador){

    int i,posicao,j = 0,selecionado = 0;
    int lista[16];

    for (i = 0; i< 16; i++){
        lista[i] = -1;
    }
    //std::list<int> mylist;
    //std::list<int>::iterator it;
    srand(time(NULL));

    for(i = 0; i < n; i++){

        std::cout << problema.matriz_recompensas[estadoatual][i];

        if(problema.matriz_recompensas[estadoatual][i] != -1){

            lista[j] = i;
            //mylist.push_back(i);
            j++;
        }

    }
    printf("\n");

    printf("tamanho da lista \n");
    //std::cout << mylist.size() << std::endl;

    posicao = retorna_aleatrio(n,iterador)%j;

    //printf("\n passou aqui");
    return lista[posicao];

}

double calculaQ(Problema problema, int estadoprox,int n){

    int i,maior = 0;


    for(i = 0; i < n; i++){

        if(problema.matriz_recompensas[estadoprox][i] != -1 && problema.matriz_recompensas[estadoprox][maior] < problema.matriz_recompensas[estadoprox][maior]){
            maior = i;
        }

    }

    return problema.fator_desconto * problema.matriz_recompensas[estadoprox][maior];

}

void imprimematriz(double matriz[16][16]){

    int i,j;

    std::cout << "MATRIZ" << std::endl;
    for(i = 0; i < 16;i++){

        for(j = 0; j < 16; j++){

            printf(" %0.1lf ",matriz[i][j]);

        }

        printf("\n");
    }

}

int retorna_aleatrio(int n,int iterador){

    srand((time(NULL)*iterador)*iterador*(100+8));
    //std::cout << "retornou" << std::endl;
    return rand()%n;
}

void aprendizagem(Problema *problema, int n){

    int i,j = 1,estadoatual,estadoprox,anterior1,anteriror2,resultado;


    for(i = 0; i < problema -> numero_interacoes ; i++){
        std::cout<<"EPISODIO" << i << std::endl;
        //printf(" %d ",rand()%16);
        estadoatual = (retorna_aleatrio(n,j)*i)%16;
        std::cout << "ESTE É O PRIMEIRO ATUAL"<< estadoatual << std::endl;
        //while (estadoatual == anterior1) {
        //    estadoatual = (retorna_aleatrio(n,j)*i)%16;
        //}

        std::cout << estadoatual << std::endl;
        printf("passou aqui");
        while(estadoatual != problema -> estado_meta){
            printf("\n entrou");
            estadoprox = escolheproximo(*problema,n,estadoatual,j);

            std::cout << "PRIMEIRO PROXIMO ESTADO"<< estadoprox << std::endl;
            
            std::cout << "PROXIMO" <<problema->matriz_q[estadoatual][estadoprox]  << std::endl;
            resultado = problema-> matriz_recompensas[estadoatual][estadoprox] + calculaQ(*problema,estadoprox,n);
            problema->matriz_q[estadoatual][estadoprox] = resultado;
            estadoatual = estadoprox;
            //std::cout<<"ESTADO PROX: " << estadoprox << std::endl;
            j++;

            
        }
        //anterior1 = estadoatual;
    }

}
