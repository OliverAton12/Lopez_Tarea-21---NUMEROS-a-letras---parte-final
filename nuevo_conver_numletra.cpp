//fecha: 22/07/24
//Autor: Lopez Quiroz Wagner
//tema: Utilice el programa de conversión de NUMEROS a LETRAS realizado en clases y complete hasta el número 999.999.999 
//Además:  en el mismo programa, diseñe una función que genere 100 números aleatorios comprendidos entre 1 y 999.999.999. LA función debe imprimir el valor numérico y su equivalente en letras.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const string unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis",
                           "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince",
                           "dieciseis", "diecisiete", "dieciocho", "diecinueve"};

const string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta",
                          "sesenta", "setenta", "ochenta", "noventa"};

const string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos",
                           "seiscientos", "setecientos", "ochocientos", "novecientos"};

const string miles[] = {"", "mil"};
const string millones[] = {"", "un millón", "millones"};

string GetUnidades(int num) {
    return unidades[num];
}

string GetDecenas(int num) {
    int x = num / 10;
    int resto = num % 10;
    string aux = "";

    if (num < 20)
        aux = GetUnidades(num);
    else {
        aux = decenas[x];
        aux = resto > 0 ? aux + " y " + GetUnidades(resto) : aux;
    }
    return aux;
}

string GetCentenas(int num) {
    int x = num / 100;
    int resto = num % 100;
    string aux = "";

    if (num < 100) {
        aux = GetDecenas(num);
    } else {
        aux = centenas[x];
        aux = resto > 0 ? aux + " " + GetDecenas(resto) : aux;
    }
    return aux;
}

string GetMiles(int num) {
    if (num == 0) return "";
    if (num == 1) return "mil";
    
    int x = num / 1000;
    int resto = num % 1000;
    string aux = "";

    if (num < 1000) {
        aux = GetCentenas(num);
    } else {
        aux = GetCentenas(x) + " mil";
        aux = resto > 0 ? aux + " " + GetCentenas(resto) : aux;
    }
    return aux;
}

string GetMillones(int num) {
    int x = num / 1000000;
    int resto = num % 1000000;
    string aux = "";

    if (num < 1000000) {
        aux = GetMiles(num);
    } else {
        aux = x == 1 ? "un millón" : GetCentenas(x) + " millones";
        aux = resto > 0 ? aux + " " + GetMiles(resto) : aux;
    }
    return aux;
}

void GenerarNumerosAleatorios() {
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        int num = rand() % 999999999 + 1;
        string texto = GetMillones(num);
        cout << num << " : " << texto << endl;
    }
}

int main() {
    // Prueba con un número específico
    int num = 999999999;
    string resultado = GetMillones(num);
    cout << num << " en letras es " << resultado << endl;

    // Generar 100 números aleatorios y sus equivalentes en letras
    GenerarNumerosAleatorios();

    return 0;
}





