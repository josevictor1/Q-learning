#include <stdlib.h>
#include <iostream>

typedef struct problema{
    double matriz_recompensas[16][16];
    double matriz_q[16][16];
    double fator_desconto;
    int estado_inicial;
    int estado_meta;
    int numero_interacoes;

} Problema;

void aprendizagem(Problema *problema, int n);
int escolheproximo(Problema problema, int n, int estadoatual,int iterador);
double calculaQ(Problema problema, int estadoprox,int n);
void imprimematriz(double matriz[16][16]);
int retorna_aleatrio(int n,int iterador);
