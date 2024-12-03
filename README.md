Autor: Jhon Anderson Marín González

Version: 1.2

C++ version: g++-exe 13.1.0

El proyecto crea datta dummie de 50mil personas, usadas para identificar por id
como una especia de base de datos (Estos dummies son guardados en clientesGenerados.txt).

Luego, crea de 40 a 100 pedidos diarios en un año (360 días), y los pone dentro
de un par de estructura de datos: Cola y Pila.

También guarda los datos de las ventas para al final imprimirlos en una matriz
según el producto y el mes.

Ambas, cola y pila, son guardados en sus respectivos outputs (Archivos .txt), y luego se procede a mostrar las 10 primeras ocurrencias según sus estructuras (Los primeros según cola, los últimos según pila<>), y luego las ultimas 5 ocurrencias.

Ejecución:

Para compilar los programas headers, usar el siguiente comando:

g++ -c arrayString.cpp arrayClientes.cpp cliente.cpp colaPedido.cpp matrizPrecios.cpp nodeCliente.cpp nodePedido.cpp pedido.cpp pilaPedido.cpp

Para crear el ejecutable, usar el siguiente comando:

g++ -o main main.cpp arrayString.o Arrayclientes.o cliente.o colaPedido.o matrizPrecios.o nodeCliente.o nodePedido.o pedido.o pilaPedido.o

Para ejecutarlo:

.\main.exe

Todas las estructuras de datos fueron creadas por mí.
