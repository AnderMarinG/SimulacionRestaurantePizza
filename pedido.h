#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <iostream>

class Pedido{
    //Atributos
    private:
        unsigned long idPersona;
        int idPedido;
        int dia;
        int tipoPizza;
        int tipoBebida;
        int precioPizza;
        int precioBebida;
        std::string descripcionPizza;
        std::string descripcionBebida;
        int precio;
    public:
        //constructores
        Pedido();
        Pedido(int idPedido,unsigned long idPersona, int dia, int pizza, int bebida);

        //manipulación
        int getIdPersona() const;
        int getPrecio() const;
        int getTipoPizza() const;
        int getTipoBebida() const;
        int getPrecioBebida() const;
        int getPrecioPizza() const;

        //sobrecarga operador <<
        friend std::ostream& operator<<(std::ostream &out, const Pedido &pedido);
};
#endif