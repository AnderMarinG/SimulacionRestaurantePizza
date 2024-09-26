#include "arrayClientes.h"
ArrayClientes::ArrayClientes(){
    size = 0;
    MAX_SIZE = 50000;
    elements = new NodeCliente[MAX_SIZE];
}
ArrayClientes::~ArrayClientes(){
    delete[] elements;
}
void ArrayClientes::insertar(const Cliente &data){
    elements[size] = NodeCliente(data);
    size++;
}
NodeCliente ArrayClientes::get(int index) const{
    return elements[index];
}
int ArrayClientes::getSize() const{
    return size;
}
void ArrayClientes::listar() const{
    for (int i = 0; i <MAX_SIZE; i++){
        std::cout << "[" << i << "] : " << elements[i].getData() << std::endl;
    }
    std::cout << "fin." << std::endl;
}