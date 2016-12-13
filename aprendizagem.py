import random

class Problema(object):

    def __init__(self,matriz_recompenas,matriz_q,fator_desconto,estado_inicial,estado_meta,numero_iteracoes):

        self.matriz_recompensas = matriz_recompenas
        self.matriz_q = matriz_q
        self.fator_desconto = fator_desconto
        self.estado_inicial = estado_inicial
        self.estado_meta = estado_meta
        self.numero_iteracoes = numero_iteracoes 
'''
def imprime(matriz):
    
    print()
    print("Matriz Q:")

    for linha in matriz:
        for valor in linha:
            print("{:>6.2f}".format(valor), end = ' ')
        print()

def imprime_norm(matriz):

    print()
    print("Matriz Q Normalizada:")

    max_l = []
    for i in range(len(matriz)):    
        max_l.append(max(matriz[i]))

    max_m = max(max_l)

    for i in range(len(matriz)):
        for j in range(len(matriz)):
            print("{:>5.1f}".format((matriz[i][j] / max_m) * 100), end = ' ')
        print()
'''
def inicializamatriz(mat):
    return [[0 for i in range(len(mat))] for j in range(len(mat))]

def selecionaaleatorio(mat):
    return random.randrange(len(mat))

def selecionaproximo(mat,estado_corrente):

    for i in range(len(mat)):
        if mat[estado_corrente][i] != -1:
            return i



def agente_aprendizagem(problema):

    for i in range(problema.numero_iteracoes):

        estado_corrente = selecionaaleatorio(problema.matriz_recompensas)

        while estado_corrente != problema.estado_meta:

            prox = selecionaproximo(problemas, estado_corrente)









