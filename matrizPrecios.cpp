#include "matrizPrecios.h"
MatrizPrecios::MatrizPrecios() : rows(12), cols(7) {
    elements = new int[rows * cols];
}
MatrizPrecios::~MatrizPrecios(){
    delete[] elements;
}
void MatrizPrecios::insert(const int data, int i, int j) {
        elements[i * cols + j] = data;
}
void MatrizPrecios::mostrar() const {
    std::cout << "\n[MATRIZ (" << rows << "x" << cols << ")]\n";
    std::cout<< "Ventas  [Napolitana Hawaiana Hongos Gaseosa Limonada LimonadaCoco te]\n";
    for(int i = rows-1; i >= 0 ; i--){
        std::cout << " Mes: " << i+1 << " : [";
        for(int j = 0; j < cols; ++j){
            std::cout << elements[i * cols + j];
            if(j != 6){
                std::cout<< " ";
            }
        }
        std::cout << "]" << "\n";
    }
    std::cout << "FIN" << std::endl;
}