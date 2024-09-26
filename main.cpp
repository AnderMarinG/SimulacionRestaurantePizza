#include "cliente.h"
#include "arrayClientes.h"
#include "nodeCliente.h"

#include "arrayString.h"

#include "pedido.h"
#include "nodePedido.h"
#include "pilaPedido.h"
#include "colaPedido.h"
#include "matrizPrecios.h"

#include <cstdlib>
#include <ctime>
#include <fstream>

int main(){
    //creación del azar
    std::srand(static_cast<unsigned int> (std::time(0)));

    //creación de los array de los archivos.
    ArrayString nombres(200);
    ArrayString apellidos(350);
    nombres.leerArchivo("nombres.txt");
    apellidos.leerArchivo("apellidos.txt");
    
    //creación del primer escritor de texto, las salidas de los clientes generados
    std::ofstream archivoClientes("clientesOutput.txt");
    archivoClientes << "Nombre Apellido1 Apellido2 ID" << "\n";

    //Creación de las 50mil personas.   
    ArrayClientes arrayCliente;
    for(int i = 0; i < 50000; i++){
        std::string nombreAlAzar = nombres.getAleatorio();
        std::string apellidoAlAzar1 = apellidos.getAleatorio();
        std::string apellidoAlAzar2 = apellidos.getAleatorio();
        unsigned long id = 1000000000 + i;
        Cliente clienteAleatorio(nombreAlAzar, apellidoAlAzar1, apellidoAlAzar2, id);
        arrayCliente.insertar(clienteAleatorio);
        archivoClientes << clienteAleatorio << clienteAleatorio.getId() << "\n";
    }
    
    //destruir Arrays sin más uso.
    nombres.~ArrayString();
    apellidos.~ArrayString();

    //Creación Cola y Pila de pedidos
    ColaPedido colaPedidos;
    PilaPedido pilaPedidos;
    //Creación Matriz
    MatrizPrecios matriz;

    //información para la matriz.
    int verificadorMes = 0;
    int contadorVentasPizza1 = 0;
    int contadorVentasPizza2 = 0;
    int contadorVentasPizza3 = 0;
    int contadorVentasBebida1 = 0;
    int contadorVentasBebida2 = 0;
    int contadorVentasBebida3 = 0;
    int contadorVentasBebida4 = 0;
    int fila = 0;
    
    //paso de los días, lógica del programa:
    unsigned int contadorOrdenes = 0;
    for(int dia = 0; dia<361; dia++){

        //lógica de la matriz
        int mes = dia/30;
        if(verificadorMes != mes){
            matriz.insert(contadorVentasPizza1,fila,0);
            matriz.insert(contadorVentasPizza2,fila,1);
            matriz.insert(contadorVentasPizza3,fila,2);
            matriz.insert(contadorVentasBebida1,fila,3);
            matriz.insert(contadorVentasBebida2,fila,4);
            matriz.insert(contadorVentasBebida3,fila,5);
            matriz.insert(contadorVentasBebida4,fila,6);

            contadorVentasPizza1 = 0;
            contadorVentasPizza2 = 0;
            contadorVentasPizza3 = 0;
            contadorVentasBebida1 = 0;
            contadorVentasBebida2 = 0;
            contadorVentasBebida3 = 0;
            contadorVentasBebida4 = 0;
            verificadorMes++;
            fila++;
            if(dia == 360){
                break;
            }
        }

        int ordenes = (std::rand()%60)+40; //ordenes de 40 a 100;
        for(int j = 0; j<ordenes; j++){

            //crear ordenes
            contadorOrdenes++;
            int idPedido = contadorOrdenes;
            unsigned long idPersona = (std::rand() % 50000)+1000000000;
            int tipoPizza = (std::rand()%3)+1;
            int tipoBebida= std::rand()%5;
            Pedido ordenAzar(idPedido, idPersona, dia, tipoPizza, tipoBebida);

            //guardar la información para la matriz
            switch(tipoPizza){
                case 1:
                    contadorVentasPizza1 = contadorVentasPizza1 + ordenAzar.getPrecioPizza();
                    break;
                case 2:
                    contadorVentasPizza2 = contadorVentasPizza2 + ordenAzar.getPrecioPizza();
                    break;
                case 3:
                    contadorVentasPizza3 = contadorVentasPizza3 + ordenAzar.getPrecioPizza();
                    break;
            }
            switch (tipoBebida){
                case 0:
                    break;
                case 1:
                    contadorVentasBebida1 = contadorVentasBebida1 + ordenAzar.getPrecioBebida();
                    break;
                case 2:
                    contadorVentasBebida2 = contadorVentasBebida2 + ordenAzar.getPrecioBebida();
                    break;
                case 3:
                    contadorVentasBebida3 = contadorVentasBebida3 + ordenAzar.getPrecioBebida();
                    break;
                case 4:
                    contadorVentasBebida4 = contadorVentasBebida4 + ordenAzar.getPrecioBebida();
                    break;
            }

            //guardar los pedidos en las colas y pilas respectivas
            colaPedidos.enqueue(ordenAzar);
            pilaPedidos.push(ordenAzar);
        }
    }

    //creación de archivo de texto, guardar la cola
    std::ofstream archivoCola("colaOutput.txt");
    archivoCola << "[idCliente dia idPedido tipoPizza tipoBebida descripcionOrden precio]\n";
    archivoCola << colaPedidos;

    //creación de archivo de texto, guardar la pila
    std::ofstream archivoPila("pilaOutput.txt");
    archivoPila << "[idCliente dia idPedido tipoPizza tipoBebida descripcionOrden precio]\n";
    archivoPila << pilaPedidos;

    //imprimir los 10 primeros de la cola
    std::cout<<"\nCola:\n";
    std::cout << "Nombre Apellido1 Apellido2 idCliente dia idPedido tipoPizza tipoBebida descripcionOrden precio\n";
    for(int z= 1; z<=10; z++){
        Pedido temp = colaPedidos.dequeue()->getData();
        unsigned long indexPersonaTemp = temp.getIdPersona()-1000000000;
        Cliente clienteTemp = arrayCliente.get(indexPersonaTemp).getData();
        std::cout << clienteTemp << temp << "\n";
    }

    //llegar a los 5 ultimos
    for (int x = colaPedidos.getSize(); x>5 ; x--){
        colaPedidos.dequeue();
    }

    //imprimir los 5 ultimos
    std::cout << "(...)\n";
    for(int i = 0; i <5; i++){
        Pedido temp = colaPedidos.dequeue()->getData();
        unsigned long indexPersonaTemp = temp.getIdPersona()-1000000000;
        Cliente clienteTemp = arrayCliente.get(indexPersonaTemp).getData();
        std::cout << clienteTemp << temp << "\n";
    }

    //lo mismo, con pila esta vez
    std::cout<<"\nPila:\n";
    std::cout << "idCliente dia idPedido tipoPizza tipoBebida descripcionOrden precio\n";

    //imprimir los 10 últimos
    for(int z= 1; z<=10; z++){
        std::cout << pilaPedidos.pop()->getData() << "\n";
    }

    //llegar a los 5 primeros
    for (int x = pilaPedidos.getSize(); x>5 ; x--){
        pilaPedidos.pop();
    }
    
    //imprimir los 5 primeros
    std::cout << "(...)\n";
    for(int i = 0; i <5; i++){
        std::cout << pilaPedidos.pop()->getData() << "\n";
    }

    //imprimir la matriz
    matriz.mostrar();

    return 0;
}