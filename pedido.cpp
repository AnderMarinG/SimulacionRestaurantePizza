#include "pedido.h"
Pedido::Pedido(){
    this->idPedido = 0;
    this->idPersona = 0;
    this->dia = 0;
    this->tipoPizza = 0;
    this->tipoBebida = 0;
    this->precioPizza = 0;
    this->precioBebida = 0;
    this->descripcionPizza = "";
    this->descripcionBebida = "";
    this->precio = 0;
}
Pedido::Pedido(int idPedido, unsigned long idPersona, int dia, int pizza, int bebida){
    this->idPedido = idPedido;
    this->idPersona = idPersona;
    this->dia = dia;
    int precioAumentoPizza = (dia/30)*500;
    int precioAumentoBebida = (dia/30)*70;
    switch(pizza){
        case 1:
            this->tipoPizza = 1;
            this->precioPizza =10000+precioAumentoPizza;
            this->descripcionPizza = "Napolitana";
            break;
        case 2:
            this->tipoPizza = 2;
            this->precioPizza =12000+precioAumentoPizza;
            this->descripcionPizza = "Hawaiana"; 
            break;
        case 3:
            this->tipoPizza = 3;
            this->precioPizza =15000+precioAumentoPizza;
            this->descripcionPizza = "Con hongos";
            break;
    }
    switch(bebida){
        case 0:
            this->tipoBebida = 0;
            this->precioBebida =0;
            this->descripcionBebida = "No bebida";
            break;
        case 1:
            this->tipoBebida = 1;
            this->precioBebida =500+precioAumentoBebida;
            this->descripcionBebida = "Gaseosa";
            break;
        case 2:
            this->tipoBebida = 2;
            this->precioBebida =700+precioAumentoBebida;
            this->descripcionBebida = "Limonada";
            break;
        case 3:
            this->tipoBebida = 3;
            this->precioBebida =800+precioAumentoBebida;
            this->descripcionBebida = "Limonada de coco";
            break;
        case 4:
            this->tipoBebida = 4;
            this->precioBebida =400+precioAumentoBebida;
            this->descripcionBebida = "te";
            break;
    }
    this->precio = this->precioBebida + this->precioPizza;
}
int Pedido::getIdPersona() const{
    return this->idPersona;
}
int Pedido::getPrecio() const{
    return this->precio;
}
int Pedido::getTipoPizza() const{
    return this->tipoPizza;
}
int Pedido::getTipoBebida() const{
    return this->tipoBebida;
}
int Pedido::getPrecioPizza() const{
    return this->precioPizza;
}
int Pedido::getPrecioBebida() const{
    return this->precioBebida;
}
std::ostream& operator<<(std::ostream &out, const Pedido &pedido){
    std::string descripcion = pedido.descripcionPizza + " y " + pedido.descripcionBebida;
    out << pedido.idPersona << " " << pedido.dia+1 << " " << pedido.idPedido << " "
    << pedido.tipoPizza << " " << pedido.tipoBebida << " " << descripcion << " "
    << pedido.precio;   
    return out;
}