#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_REGISTROS = 1000;

struct Registro {
    string dni;
    string datos[40];
};

bool compararDNI(const Registro& r1, const Registro& r2) {
    return r1.dni < r2.dni;
}

int main() {
    string archivo = "NUEVOS DATOS.csv";
    ifstream archivoCSV(archivo);

    if (!archivoCSV.is_open()) {
        cerr << "Error: No se pudo abrir el archivo '" << archivo << "'" << endl;
        return 1;
    }

    Registro registros[MAX_REGISTROS];
    string linea;
    string dni;
    string dniBuscado;
    int numRegistros = 0;

    getline(archivoCSV, linea);

    cout << "Columnas disponibles: " << endl;
    cout << "DOC_IDENTIDAD, NOMBRE, DIRECCION, DISTRITO, PROVINCIA, DEPARTAMENTO, REGIONES, ... (y más)" << endl;

    while (getline(archivoCSV, linea) && numRegistros < MAX_REGISTROS) {
        stringstream ss(linea);
        Registro registro;
        getline(ss, registro.dni, ';');

        int i = 0;
        string dato;
        while (getline(ss, dato, ';') && i < 40) {
            registro.datos[i++] = dato;
        }

        registros[numRegistros++] = registro;
    }

    sort(registros, registros + numRegistros, compararDNI);

    cout << "Ingrese el DNI que desea buscar: ";
    cin >> dniBuscado;

    clock_t start = clock();

    int izquierda = 0, derecha = numRegistros - 1;
    bool encontrado = false;
    int pasos = 0;

    while (izquierda <= derecha) {
        pasos++;
        int medio = izquierda + (derecha - izquierda) / 2;

        if (registros[medio].dni == dniBuscado) {
            encontrado = true;

            cout << "Datos encontrados para el DNI " << dniBuscado << ":\n";
            cout << "DNI: " << registros[medio].dni << endl;
            cout << "Nombre: " << registros[medio].datos[0] << endl;
            cout << "Dirección: " << registros[medio].datos[1] << endl;
            cout << "Distrito: " << registros[medio].datos[2] << endl;
            cout << "Provincia: " << registros[medio].datos[3] << endl;
            cout << "Departamento: " << registros[medio].datos[4] << endl;
            cout << "Regiones: " << registros[medio].datos[5] << endl;
            cout << "T1: " << registros[medio].datos[6] << endl;
            cout << "T2: " << registros[medio].datos[7] << endl;
            cout << "T3: " << registros[medio].datos[8] << endl;
            cout << "T4: " << registros[medio].datos[9] << endl;
            cout << "NOMB_CAMPAÑA_LD: " << registros[medio].datos[10] << endl;
            cout << "NOMB_CAMPAÑA_TC: " << registros[medio].datos[11] << endl;
            cout << "NOMB_CAMPAÑA_XL: " << registros[medio].datos[12] << endl;
            cout << "PerfilCliente: " << registros[medio].datos[13] << endl;
            cout << "Prod_Priorizado: " << registros[medio].datos[14] << endl;
            cout << "GAMAPRODUCTO: " << registros[medio].datos[15] << endl;
            cout << "OFERTA_LD: " << registros[medio].datos[16] << endl;
            cout << "OFERTA_TC: " << registros[medio].datos[17] << endl;
            cout << "OFERTA_XL: " << registros[medio].datos[18] << endl;
            cout << "TASA_FINAL: " << registros[medio].datos[19] << endl;
            cout << "PLAZOMINIMO: " << registros[medio].datos[20] << endl;
            cout << "FLG_COMBO: " << registros[medio].datos[21] << endl;
            cout << "PCT: " << registros[medio].datos[22] << endl;
            cout << "TASAXL: " << registros[medio].datos[23] << endl;
            cout << "PROPENSION: " << registros[medio].datos[24] << endl;
            cout << "TipoOferta: " << registros[medio].datos[25] << endl;
            cout << "UBIGEO: " << registros[medio].datos[26] << endl;
            cout << "DireccionNegocio: " << registros[medio].datos[27] << endl;
            cout << "DistNegocio: " << registros[medio].datos[28] << endl;
            cout << "ProvNegocio: " << registros[medio].datos[29] << endl;
            cout << "DptoNegocio: " << registros[medio].datos[30] << endl;
            cout << "EDAD: " << registros[medio].datos[31] << endl;
            cout << "ZONA: " << registros[medio].datos[32] << endl;
            cout << "CDR: " << registros[medio].datos[33] << endl;
            cout << "AGENCIA: " << registros[medio].datos[34] << endl;
            cout << "UsodeDatosPers: " << registros[medio].datos[35] << endl;
            cout << "RetriccionPlazoLD: " << registros[medio].datos[36] << endl;
            cout << "TIPO_ZONA: " << registros[medio].datos[37] << endl;
            cout << "GrupoContacto: " << registros[medio].datos[38] << endl;
            cout << "MarcaPEP: " << registros[medio].datos[39] << endl;

            break;
        } else if (registros[medio].dni < dniBuscado) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    clock_t end = clock();

    if (!encontrado) {
        cout << "No se encontraron datos para el DNI " << dniBuscado << "." << endl;
    }

    double tiempoTranscurrido = double(end - start) / CLOCKS_PER_SEC;

    cout << "Tiempo de búsqueda: " << tiempoTranscurrido << " segundos." << endl;
    cout << "Número de pasos realizados: " << pasos << endl;

    archivoCSV.close();

    return 0;
}
