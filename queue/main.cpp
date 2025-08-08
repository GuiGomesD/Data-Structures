#include <iostream>
#include "include/fila.hpp"

int main() {
    Fila fila(5);

    try {
        std::cout << "Fila vazia? " << (fila.estaVazia() ? "Sim" : "Nao") << "\n";

        fila.inserir(10);
        fila.inserir(20);
        fila.inserir(30);

        std::cout << "Inicio da fila: " << fila.consultarInicio() << "\n";

        std::cout << "Removido: " << fila.remover() << "\n";
        std::cout << "Novo inicio da fila: " << fila.consultarInicio() << "\n";

        fila.inserir(40);
        fila.inserir(50);
        fila.inserir(60);

        std::cout << "Fila cheia? " << (fila.estaCheia() ? "Sim" : "Nao") << "\n";

        fila.inserir(70);

    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }

    return 0;
}
