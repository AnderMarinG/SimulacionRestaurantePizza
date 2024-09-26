#include "nodeCliente.h"
NodeCliente::NodeCliente(const Cliente &data) : data(data){}
NodeCliente::NodeCliente(): data(Cliente("", "", "", 0)){}
Cliente NodeCliente::getData() const{
   return this->data;
}
void NodeCliente::setData(const Cliente &data){
    this->data = data;
}