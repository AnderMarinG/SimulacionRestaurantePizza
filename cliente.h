#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

class Cliente{
    private:
        //atributos clase cliente
        std::string nombre;
        std::string primerApellido;
        std::string segundoApellido;
        unsigned long id;
    public:
        //constructor
        Cliente(const std::string &nombre, const std::string &primerApellido,
        const std::string &segundoApellido, unsigned long id);
    
        //métodos getter
        std::string getNombre() const;
        std::string getPrimerApellido() const;
        std::string getSegundoApellido() const;
        unsigned long getId() const;

        //sobrecarga operador <<
        friend std::ostream& operator<<(std::ostream &out, const Cliente &cliente);
};
#endif