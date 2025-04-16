#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_REGISTROS = 1000;

struct Registro {
    string dni;
    string datos[40];
};

int main() {
    string archivo = "NUEVOS DATOS.csv";
    ifstream archivoCSV(archivo);

    if (!archivoCSV.is_open()) {
        cerr << "Error: No se pudo abrir el archivo '" << archivo << "'" << endl;
        return 1;
    }

    Registro registros[MAX_REGISTROS];
    string linea;
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

    cout << "Ingrese el DNI que desea buscar: ";
    cin >> dniBuscado;

    clock_t start = clock();

    bool encontrado = false;
    int pasos = 0;

    // Búsqueda lineal
    for (int i = 0; i < numRegistros; ++i) {
        pasos++;
        if (registros[i].dni == dniBuscado) {
            encontrado = true;

            cout << "Datos encontrados para el DNI " << dniBuscado << ":\n";
            cout << "DNI: " << registros[i].dni << endl;
            cout << "Nombre: " << registros[i].datos[0] << endl;
            cout << "Dirección: " << registros[i].datos[1] << endl;
            cout << "Distrito: " << registros[i].datos[2] << endl;
            cout << "Provincia: " << registros[i].datos[3] << endl;
            cout << "Departamento: " << registros[i].datos[4] << endl;
            cout << "Regiones: " << registros[i].datos[5] << endl;
            cout << "T1: " << registros[i].datos[6] << endl;
            cout << "T2: " << registros[i].datos[7] << endl;
            cout << "T3: " << registros[i].datos[8] << endl;
            cout << "T4: " << registros[i].datos[9] << endl;
            cout << "NOMB_CAMPAÑA_LD: " << registros[i].datos[10] << endl;
            cout << "NOMB_CAMPAÑA_TC: " << registros[i].datos[11] << endl;
            cout << "NOMB_CAMPAÑA_XL: " << registros[i].datos[12] << endl;
            cout << "PerfilCliente: " << registros[i].datos[13] << endl;
            cout << "Prod_Priorizado: " << registros[i].datos[14] << endl;
            cout << "GAMAPRODUCTO: " << registros[i].datos[15] << endl;
            cout << "OFERTA_LD: " << registros[i].datos[16] << endl;
            cout << "OFERTA_TC: " << registros[i].datos[17] << endl;
            cout << "OFERTA_XL: " << registros[i].datos[18] << endl;
            cout << "TASA_FINAL: " << registros[i].datos[19] << endl;
            cout << "PLAZOMINIMO: " << registros[i].datos[20] << endl;
            cout << "FLG_COMBO: " << registros[i].datos[21] << endl;
            cout << "PCT: " << registros[i].datos[22] << endl;
            cout << "TASAXL: " << registros[i].datos[23] << endl;
            cout << "PROPENSION: " << registros[i].datos[24] << endl;
            cout << "TipoOferta: " << registros[i].datos[25] << endl;
            cout << "UBIGEO: " << registros[i].datos[26] << endl;
            cout << "DireccionNegocio: " << registros[i].datos[27] << endl;
            cout << "DistNegocio: " << registros[i].datos[28] << endl;
            cout << "ProvNegocio: " << registros[i].datos[29] << endl;
            cout << "DptoNegocio: " << registros[i].datos[30] << endl;
            cout << "EDAD: " << registros[i].datos[31] << endl;
            cout << "ZONA: " << registros[i].datos[32] << endl;
            cout << "CDR: " << registros[i].datos[33] << endl;
            cout << "AGENCIA: " << registros[i].datos[34] << endl;
            cout << "UsodeDatosPers: " << registros[i].datos[35] << endl;
            cout << "RetriccionPlazoLD: " << registros[i].datos[36] << endl;
            cout << "TIPO_ZONA: " << registros[i].datos[37] << endl;
            cout << "GrupoContacto: " << registros[i].datos[38] << endl;
            cout << "MarcaPEP: " << registros[i].datos[39] << endl;

            break;
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
