#include <iostream>
#include <fstream>
#include <string>

// Definición de constantes para hacer un código más legible.
#define HISTORIAL 3
#define NOMBRE_ARCHIVO "historial.txt"

using namespace std;

// Definición de una clase para gestionar los registros de calculos en el historial
class Registro
{
private:
    string figura;
    float radio;
    float resultado;

public:
    Registro(string figura, float radio, float resultado)
    {
        this->figura = figura;
        this->radio = radio;
        this->resultado = resultado;
    }

    /*
     * Declaración del destructor del objeto (Nos sirve para eliminar de la memoria)
     * los objetos sin utilizar.
     */
    ~Registro();

    /*
     * El método toString nos servirá para construir la cadena de texto que se
     * guardará en el archivo del historial
     */ 
    string toString()
    {
        return figura + " con radio de " + to_string(radio) + " cm tuvo un " +
                (figura == "Circulo" ? ("area de " + to_string(resultado) +" cm^2")
                : ("volumen de " + to_string(resultado) + " cm^3"));
    }
};

// Definición del destructor
Registro::~Registro() {}

// Le siguiente función lee linea por linea el archivo e imprime lo que encuentra
void leerHistorial()
{
    string s;
    ifstream f(NOMBRE_ARCHIVO);
    if (f.is_open())
    {
        getline(f, s);
        while (!f.eof())
        {
            cout << " " << s << endl;
            getline(f, s);
        }
    }
    else
        cerr << "\n Error de apertura del archivo." << endl;
}

// Verifica si el archivo del historial existe
bool historialExiste()
{
    bool r = false;
    if (ifstream(NOMBRE_ARCHIVO))
    {
        r = true;
    }
    return r;
}

// Crea el archivo del historial
void crearArchivo()
{
    ofstream file(NOMBRE_ARCHIVO);
    if (!file)
    {
        cout << "\n No se pudo crear el archivo" << endl;
    }
}

// Imprime el historial con el formato deseado
void imprimirHistorial()
{
    if (!historialExiste())
    {
        cout << "\n Aun no has realizado ningún calculo." << endl;
    }
    else
    {
        system("clear");
        cout << " HISTORIAL DE CALCULOS\n" << endl;
        leerHistorial();
    }
}

// Agrega los registros al archivo del historial
void agregarAHistorial(int f, float radio, float resultado)
{
    bool existe = true;
    do
    {
        /*
         * En caso de que el archivo del historial exista, escribe en él. De lo
         * contrario, lo crea. Para ello es necesario utilizar un bucle; pues en
         * caso de que el archivo no exista, se debe volver a ejecutar la condición
         * para poder crearlo y luego se ejecuta nuevamente para escribir en él.
         */
        if (historialExiste)
        {
            existe = true;
            Registro registro((f == 1 ? "Circulo" : "Esfera"), radio, resultado);
            ofstream f(NOMBRE_ARCHIVO, ios::app);
            f << registro.toString() << endl;
            registro.~Registro();
            f.close();
        }
        else
        {
            crearArchivo();
            existe = false;
        }
    } while (existe == false);
}