#ifndef FILA_HPP
#define FILA_HPP

class Fila {
private:
    int* dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;

public:
    Fila(int capacidade);
    ~Fila();

    bool estaVazia() const;
    bool estaCheia() const;
    void inserir(int elemento);
    int remover();
    int consultarInicio() const;
};

#endif
