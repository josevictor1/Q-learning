#!/usr/bin/env python3
# -*- coding=utf-8 -*-

import numpy as np

FATOR_DESCONTO = 0.8

import random

def imprime(matriz):
    for linha in matriz:
        for valor in linha:
            print("{:>6.2f}".format(valor), end=' ')
        print()

def imprime_norm(matriz):
    max_l = []
    for i in range(len(matriz)):
        max_l.append(max(matriz[i]))
    max_m = max(max_l)

    for i in range(len(matriz)):
        for j in range(len(matriz)):
            print("{:>5.1f}".format((matriz[i][j] / max_m) * 100), end=' ')
        print()


"""def imprime_caminhos(m, atual, fim, cont):
    print(atual, end=' ')
    cont += 1

    if atual != fim:
        maior_v = max([m[atual][i] for i in range(len(m))])
        maior_is = [i for i in range(len(m)) if m[atual][i] == maior_v]

        for adj in maior_is:
            if len(maior_is) > 1:
                for i in range(cont):
                    print("  ", end='')
                print("-> ", end='')
            imprime_caminhos(m, adj, fim, cont)
    print()"""

def q_learning(r, inicio, meta, k):
    q = [[0 for i in range(len(r))] for j in range(len(r))]

    for j in range(k):
        atual = random.randrange(len(r))
        while atual != meta:
            prox = random.choice([i for i in range(len(r)) if r[atual][i] != -1])
            q[atual][prox] = r[atual][prox] + (FATOR_DESCONTO * max(
                [q[prox][i] for i in range(len(r)) if r[prox][i] != -1]))
            atual = prox
        prox = random.choice([i for i in range(len(r)) if r[atual][i] != -1])
        q[atual][prox] = r[atual][prox] + (FATOR_DESCONTO * max(
            [q[prox][i] for i in range(len(r)) if r[prox][i] != -1]))

    print()
    print("Matriz Q:")
    imprime(q)

    print()
    print("Matriz Q Normalizada:")
    imprime_norm(q)

    melhor_caminho = [inicio]
    atual = inicio
    while atual != meta:
        maior_v = max(q[atual])
        maior_i = q[atual].index(maior_v)
        melhor_caminho.append(maior_i)
        atual = maior_i

    print()
    print("Melhor caminho: " + str(melhor_caminho))
'''
r = [[ -1,  -1,  -1,  -1,   0,  -1],
     [ -1,  -1,  -1,   0,  -1, 100],
     [ -1,  -1,  -1,   0,  -1,  -1],
     [ -1,   0,   0,  -1,   0,  -1],
     [  0,  -1,  -1,   0,  -1, 100],
     [ -1,   0,  -1,  -1,   0, 100]]

q_learning(r, 2, 5, 200)
'''

r = [[-1 for j in range(16)] for i in range(16)]

r[0][1] = 0
r[0][4] = 0
r[1][0] = 0
r[2][3] = 0
r[2][6] = 0
r[3][2] = 0
r[3][7] = 0
r[4][0] = 0
r[4][8] = 0
r[5][6] = 0
r[5][9] = 0
r[6][2] = 0
r[6][5] = 0
r[7][3] = 0
r[7][11] = 0
r[8][4] = 0
r[8][12] = 0
r[8][9] = 0
r[9][5] = 0
r[9][8] = 0
r[9][10] = 0
r[9][13] = 0
r[10][9] = 0
r[10][14] = 0
r[11][7] = 0
r[11][15] = 100
r[12][8] = 0
r[13][9] = 0
r[13][14] = 0
r[14][10] = 0
r[14][13] = 0
r[15][11] = 0
r[15][15] = 100

q_learning(r, 0, 15, 200)