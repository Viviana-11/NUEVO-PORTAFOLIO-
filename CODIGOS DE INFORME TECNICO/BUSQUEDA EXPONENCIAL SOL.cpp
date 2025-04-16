#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

    getline(archivoCSV, linea);  // Ignorar la primera línea (encabezados)

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

    // Ordenar los registros por el DNI para que la búsqueda exponencial funcione
    sort(registros, registros + numRegistros, [](const Registro& a, const Registro& b) {
        return a.dni < b.dni;
    });

    cout << "Ingrese el DNI que desea buscar: ";
    cin >> dniBuscado;

    clock_t start = clock();

    bool encontrado = false;
    int pasos = 0;

    // Búsqueda exponencial
    if (numRegistros > 0 && registros[0].dni == dniBuscado) {
        encontrado = true;
        cout << "Datos encontrados para el DNI " << dniBuscado << ":\n";
        cout << "DNI: " << registros[0].dni << endl;
        cout << "Nombre: " << registros[0].datos[0] << endl;
        cout << "Dirección: " << registros[0].datos[1] << endl;
        cout << "Distrito: " << registros[0].datos[2] << endl;
        cout << "Provincia: " << registros[0].datos[3] << endl;
        cout << "Departamento: " << registros[0].datos[4] << endl;
        cout << "Regiones: " << registros[0].datos[5] << endl;
        cout << "T1: " << registros[0].datos[6] << endl;
        cout << "T2: " << registros[0].datos[7] << endl;
        cout << "T3: " << registros[0].datos[8] << endl;
        cout << "T4: " << registros[0].datos[9] << endl;
        cout << "NOMB_CAMPAÑA_LD: " << registros[0].datos[10] << endl;
        cout << "NOMB_CAMPAÑA_TC: " << registros[0].datos[11] << endl;
        cout << "NOMB_CAMPAÑA_XL: " << registros[0].datos[12] << endl;
        cout << "PerfilCliente: " << registros[0].datos[13] << endl;
        cout << "Prod_Priorizado: " << registros[0].datos[14] << endl;
        cout << "GAMAPRODUCTO: " << registros[0].datos[15] << endl;
        cout << "OFERTA_LD: " << registros[0].datos[16] << endl;
        cout << "OFERTA_TC: " << registros[0].datos[17] << endl;
        cout << "OFERTA_XL: " << registros[0].datos[18] << endl;
        cout << "TASA_FINAL: " << registros[0].datos[19] << endl;
        cout << "PLAZOMINIMO: " << registros[0].datos[20] << endl;
        cout << "FLG_COMBO: " << registros[0].datos[21] << endl;
        cout << "PCT: " << registros[0].datos[22] << endl;
        cout << "TASAXL: " << registros[0].datos[23] << endl;
        cout << "PROPENSION: " << registros[0].datos[24] << endl;
        cout << "TipoOferta: " << registros[0].datos[25] << endl;
        cout << "UBIGEO: " << registros[0].datos[26] << endl;
        cout << "DireccionNegocio: " << registros[0].datos[27] << endl;
        cout << "DistNegocio: " << registros[0].datos[28] << endl;
        cout << "ProvNegocio: " << registros[0].datos[29] << endl;
        cout << "DptoNegocio: " << registros[0].datos[30] << endl;
        cout << "EDAD: " << registros[0].datos[31] << endl;
        cout << "ZONA: " << registros[0].datos[32] << endl;
        cout << "CDR: " << registros[0].datos[33] << endl;
        cout << "AGENCIA: " << registros[0].datos[34] << endl;
        cout << "UsodeDatosPers: " << registros[0].datos[35] << endl;
        cout << "RetriccionPlazoLD: " << registros[0].datos[36] << endl;
        cout << "TIPO_ZONA: " << registros[0].datos[37] << endl;
        cout << "GrupoContacto: " << registros[0].datos[38] << endl;
        cout << "MarcaPEP: " << registros[0].datos[39] << endl;
    } else {
        // Buscar exponencialmente
        int i = 1;
        while (i < numRegistros && registros[i].dni < dniBuscado) {
            i *= 2;  // Aumentar el rango de búsqueda exponencialmente
            pasos++;
        }

        // Búsqueda lineal dentro del rango encontrado
        int limiteSuperior = min(i, numRegistros);  // No superar el número total de registros
        for (int j = i / 2; j < limiteSuperior; ++j) {
            pasos++;
            if (registros[j].dni == dniBuscado) {
                encontrado = true;
                cout << "Datos encontrados para el DNI " << dniBuscado << ":\n";
                cout << "DNI: " << registros[j].dni << endl;
                cout << "Nombre: " << registros[j].datos[0] << endl;
                cout << "Dirección: " << registros[j].datos[1] << endl;
                cout << "Distrito: " << registros[j].datos[2] << endl;
                cout << "Provincia: " << registros[j].datos[3] << endl;
                cout << "Departamento: " << registros[j].datos[4] << endl;
                cout << "Regiones: " << registros[j].datos[5] << endl;
                cout << "T1: " << registros[j].datos[6] << endl;
                cout << "T2: " << registros[j].datos[7] << endl;
                cout << "T3: " << registros[j].datos[8] << endl;
                cout << "T4: " << registros[j].datos[9] << endl;
                cout << "NOMB_CAMPAÑA_LD: " << registros[j].datos[10] << endl;
                cout << "NOMB_CAMPAÑA_TC: " << registros[j].datos[11] << endl;
                cout << "NOMB_CAMPAÑA_XL: " << registros[j].datos[12] << endl;
                cout << "PerfilCliente: " << registros[j].datos[13] << endl;
                cout << "Prod_Priorizado: " << registros[j].datos[14] << endl;
                cout << "GAMAPRODUCTO: " << registros[j].datos[15] << endl;
                cout << "OFERTA_LD: " << registros[j].datos[16] << endl;
                cout << "OFERTA_TC: " << registros[j].datos[17] << endl;
                cout << "OFERTA_XL: " << registros[j].datos[18] << endl;
                cout << "TASA_FINAL: " << registros[j].datos[19] << endl;
                cout << "PLAZOMINIMO: " << registros[j].datos[20] << endl;
                cout << "FLG_COMBO: " << registros[j].datos[21] << endl;
                cout << "PCT: " << registros[j].datos[22] << endl;
                cout << "TASAXL: " << registros[j].datos[23] << endl;
                cout << "PROPENSION: " << registros[j].datos[24] << endl;
                cout << "TipoOferta: " << registros[j].datos[25] << endl;
                cout << "UBIGEO: " << registros[j].datos[26] << endl;
                cout << "DireccionNegocio: " << registros[j].datos[27] << endl;
                cout << "DistNegocio: " << registros[j].datos[28] << endl;
                cout << "ProvNegocio: " << registros[j].datos[29] << endl;
                cout << "DptoNegocio: " << registros[j].datos[30] << endl;
                cout << "EDAD: " << registros[j].datos[31] << endl;
                cout << "ZONA: " << registros[j].datos[32] << endl;
                cout << "CDR: " << registros[j].datos[33] << endl;
                cout << "AGENCIA: " << registros[j].datos[34] << endl;
                cout << "UsodeDatosPers: " << registros[j].datos[35] << endl;
                cout << "RetriccionPlazoLD: " << registros[j].datos[36] << endl;
                cout << "TIPO_ZONA: " << registros[j].datos[37] << endl;
                cout << "GrupoContacto: " << registros[j].datos[38] << endl;
                cout << "MarcaPEP: " << registros[j].datos[39] << endl;
                break;
            }
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
