#include "arrayString.h"
ArrayString::ArrayString(): size(0) , MAX_SIZE(350){
    std::srand(static_cast<unsigned int>(std::time(0)));
    elementos = new std::string[MAX_SIZE];
}
ArrayString::ArrayString(int n): size(0), MAX_SIZE(350){
    std::srand(static_cast<unsigned int>(std::time(0)));
    elementos = new std::string[n];
}
ArrayString::~ArrayString(){
    delete[] elementos;
}
void ArrayString::insert(std::string string1){
    elementos[size] = string1;
    size++;
}
std::string ArrayString::get(int index) const{
    return elementos[index];
}
int ArrayString::getSize() const{
    return size;
}
void ArrayString::leerArchivo(const std::string &nombreArchivo){
     std::ifstream archivo(nombreArchivo);
    if(archivo.is_open()){
        std::string texto;
        while(std::getline(archivo,texto)){
            insert(texto);
        }
    }
}
std::string ArrayString::getAleatorio() const{
    int indiceAleatorio = std::rand() % size;
    return get(indiceAleatorio);
}