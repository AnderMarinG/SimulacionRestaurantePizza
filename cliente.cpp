#include "cliente.h"
Cliente::Cliente(const std::string &nombre, const std::string &primerApellido,
const std::string &segundoApellido, unsigned long id){
    this->nombre = nombre;
    this->primerApellido = primerApellido;
    this->segundoApellido = segundoApellido;
    this->id = id;
}
std::string Cliente::getNombre() const{
    return this->nombre;
}
std::string Cliente::getPrimerApellido() const{
    return this->primerApellido;
}
std::string Cliente::getSegundoApellido() const{
    return this->segundoApellido;
}
unsigned long Cliente::getId() const{
    return this->id;
}
std::ostream& operator<<(std::ostream &out, const Cliente &cliente){
    out << cliente.nombre << " " << cliente.primerApellido << " " <<
    cliente.segundoApellido << " ";
    return out;
}