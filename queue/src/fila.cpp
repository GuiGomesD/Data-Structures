#include "../include/fila.hpp"
#include <iostream>
#include <stdexcept>

Fila::Fila(int capacidade) : capacidade(capacidade), inicio(0), fim(0), tamanho(0) {
    dados = new int[capacidade];
}

Fila::~Fila() {
    delete[] dados;
}

bool Fila::estaVazia() const {
    return tamanho == 0;
}

bool Fila::estaCheia() const {
    return tamanho == capacidade;
}

void Fila::inserir(int elemento) {
    if (estaCheia())
        throw std::overflow_error("Fila cheia");

    dados[fim] = elemento;
    fim = (fim + 1) % capacidade;
    tamanho++;
}

int Fila::remover() {
    if (estaVazia())
        throw std::underflow_error("Fila vazia");

    int removido = dados[inicio];
    inicio = (inicio + 1) % capacidade;
    tamanho--;
    return removido;
}

int Fila::consultarInicio() const {
    if (estaVazia())
        throw std::underflow_error("Fila vazia");

    return dados[inicio];
}
