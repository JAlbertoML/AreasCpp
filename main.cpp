#include <iostream>
#include "calculos.h"
#include "historial.h"

using namespace std;

int main()
{
    int opcionSeleccionada;
    float radio, resultado;
    char respuesta;
    /*
     * El código dentro del ciclo do-while se ejecutará siempre que el usuario 
     * responda que sí desea volver al menú principal.
     */
    do
    {
        // Reemplazar la palabra 'clear' por la abreviatura 'cls' en windows.
        system("clear");
        /*
         * Los caracteres '\n' y '\t' sirven para dar un salto de linea y
         * una tabulación a la derecha, respectivamente.
         */
        cout << " Opciones disponibles:" << endl;
        cout << "\t1.- Calcular área del circulo\n\t2.- Calcular volumen de la esfera\n\t3.- Ver historial de calculos" << endl;
        cout << " Elige una figura: ";
        cin >> opcionSeleccionada;
        switch (opcionSeleccionada)
        {
        case CIRCULO:
            pedirRadio(&radio, CIRCULO);
            resultado = areaCirculo(&radio);
            cout << "\n El area del circulo es de " << resultado << " cm^2." << endl;
            agregarAHistorial(CIRCULO, radio, resultado);
            break;

        case ESFERA:
            pedirRadio(&radio, ESFERA);
            resultado = volumenEsfera(&radio);
            cout << "\n El volumen de la esfera es de " << resultado << " cm^3." << endl;
            agregarAHistorial(ESFERA, radio, resultado);
            break;

        case HISTORIAL:
            imprimirHistorial();
            break;

        default:
            cout << "\n Opcion no valida" << endl;
            break;
        }
        cout << "\n Deseas volver al menú principal? (S/N): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
    cout << "\n ¡¡¡BYE!!!" << endl;
}