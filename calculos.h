#include <iostream>
#include <cmath> // La biblioteca cmath nos permite utilizar funciones matemáticas como la potencia

// Definición de constantes para hacer un código más legible.
#define CIRCULO 1
#define ESFERA 2

using namespace std;

/*
 * NOTA: La constante M_PI está declarada en la biblioteca math.h.
 *       No hay necesidad de incluir dicha biblioteca (por lo menos en
 *       linux con el compilador GCC).
 * 
 * Las siguientes funciones trabajan con punteros.
 */

float areaCirculo(float *radio)
{
    return M_PI * pow(*radio, 2);
}

float volumenEsfera(float *radio)
{
    return 4 * M_PI * pow(*radio, 2);
}

/*
 * La siguiente función hace uso del operador ternario para pedir el radio de la
 * esfera o del circulo dependiendo del valor de la variable figura que se le pasa 
 * por parámetro.
 */
void pedirRadio(float *radio, int figura)
{
    cout << " Ingresa el radio de tu " << (figura == CIRCULO ? "circulo" : "esfera") << " (cm): ";
    cin >> *radio;
}
