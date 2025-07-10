# -*- coding: utf-8 -*-
from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)
            

    def getJogada(self) -> (int, int):
        #Primeiro verifica se pode ganhar - R1
        jogada = self.verificar_sequencia(2, self.tipo)
        if jogada is not None:
            return jogada
            
        #Verifica se precisa bloquear o oponente - R1
        oponente = Tabuleiro.JOGADOR_X if self.tipo == Tabuleiro.JOGADOR_0 else Tabuleiro.JOGADOR_0
        jogada = self.verificar_sequencia(2, oponente)
        if jogada is not None:
            return jogada
            
        #Verifica jogadas que criam duas sequencias de duas marcacoes - R2
        jogada = self.encontrar_jogada_com_duas_sequencias()
        if jogada is not None:
            return jogada
            
        #Se o centro estiver livre, marca - R3
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            return (1, 1)
            
        #Se oponente marcou um canto, marca o canto oposto - R4
        jogada = self.marcar_canto_oposto(oponente)
        if jogada is not None:
            return jogada
            
        #Marca um canto vazio - R5
        jogada = self.marcar_canto_vazio()
        if jogada is not None:
            return jogada
            
        #Marca qualquer quadrado vazio - R6
        return self.marcar_quadrado_aleatorio()
    
    def verificar_sequencia(self, quantidade, jogador):
        #Verifica linhas
        for l in range(3):
            contador = 0
            vazio = None
            for c in range(3):
                if self.matriz[l][c] == jogador:
                    contador += 1
                elif self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    vazio = (l, c)
            if contador == quantidade and vazio is not None:
                return vazio
                
        #Verifica colunas
        for c in range(3):
            contador = 0
            vazio = None
            for l in range(3):
                if self.matriz[l][c] == jogador:
                    contador += 1
                elif self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    vazio = (l, c)
            if contador == quantidade and vazio is not None:
                return vazio
                
        #Verifica diagonal principal
        contador = 0
        vazio = None
        for i in range(3):
            if self.matriz[i][i] == jogador:
                contador += 1
            elif self.matriz[i][i] == Tabuleiro.DESCONHECIDO:
                vazio = (i, i)
        if contador == quantidade and vazio is not None:
            return vazio
            
        #Verifica diagonal secundaria
        contador = 0
        vazio = None
        for i in range(3):
            if self.matriz[i][2-i] == jogador:
                contador += 1
            elif self.matriz[i][2-i] == Tabuleiro.DESCONHECIDO:
                vazio = (i, 2-i)
        if contador == quantidade and vazio is not None:
            return vazio
            
        return None
    
    def encontrar_jogada_com_duas_sequencias(self):
        #Verifica todas as posicoes vazias para ver se criam duas sequencias
        for l in range(3):
            for c in range(3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    #Simula a jogada
                    self.matriz[l][c] = self.tipo
                    #Verifica quantas sequencias de 2 sao criadas
                    sequencias = 0
                    
                    #Verifica linha
                    contador = 0
                    for col in range(3):
                        if self.matriz[l][col] == self.tipo:
                            contador += 1
                    if contador == 2:
                        sequencias += 1
                        
                    #Verifica coluna
                    contador = 0
                    for lin in range(3):
                        if self.matriz[lin][c] == self.tipo:
                            contador += 1
                    if contador == 2:
                        sequencias += 1
                        
                    #Verifica diagonais se aplicável
                    if l == c:  #Diagonal principal
                        contador = 0
                        for i in range(3):
                            if self.matriz[i][i] == self.tipo:
                                contador += 1
                        if contador == 2:
                            sequencias += 1
                            
                    if l + c == 2:  #Diagonal secundária
                        contador = 0
                        for i in range(3):
                            if self.matriz[i][2-i] == self.tipo:
                                contador += 1
                        if contador == 2:
                            sequencias += 1
                    
                    #Desfaz a simulação
                    self.matriz[l][c] = Tabuleiro.DESCONHECIDO
                    
                    if sequencias >= 2:
                        return (l, c)
        return None
    
    def marcar_canto_oposto(self, oponente):
        cantos = [(0, 0), (0, 2), (2, 0), (2, 2)]
        opostos = {(0, 0): (2, 2), (0, 2): (2, 0), (2, 0): (0, 2), (2, 2): (0, 0)}
        
        for canto in cantos:
            l, c = canto
            if self.matriz[l][c] == oponente:
                l_oposto, c_oposto = opostos[canto]
                if self.matriz[l_oposto][c_oposto] == Tabuleiro.DESCONHECIDO:
                    return (l_oposto, c_oposto)
        return None
    
    def marcar_canto_vazio(self):
        cantos = [(0, 0), (0, 2), (2, 0), (2, 2)]
        for canto in cantos:
            l, c = canto
            if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                return (l, c)
        return None
    
    def marcar_quadrado_aleatorio(self):
        lista = []
        for l in range(0,3):
            for c in range(0,3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))
                    
        if(len(lista) > 0):
            p = randint(0, len(lista)-1)
            return lista[p]
        else:
           return None