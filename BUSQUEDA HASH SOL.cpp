#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
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

    unordered_map<string, Registro> registros;  // Usar unordered_map para la búsqueda por DNI
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

        // Insertar el registro en el unordered_map, usando el DNI como clave
        registros[registro.dni] = registro;
        numRegistros++;
    }

    cout << "Ingrese el DNI que desea buscar: ";
    cin >> dniBuscado;

    clock_t start = clock();

    bool encontrado = false;
    int pasos = 0;

    // Buscar usando unordered_map
    auto it = registros.find(dniBuscado);
    if (it != registros.end()) {
        pasos++;
        encontrado = true;

        cout << "Datos encontrados para el DNI " << dniBuscado << ":\n";
        cout << "DNI: " << it->second.dni << endl;
        cout << "Nombre: " << it->second.datos[0] << endl;
        cout << "Dirección: " << it->second.datos[1] << endl;
        cout << "Distrito: " << it->second.datos[2] << endl;
        cout << "Provincia: " << it->second.datos[3] << endl;
        cout << "Departamento: " << it->second.datos[4] << endl;
        cout << "Regiones: " << it->second.datos[5] << endl;
        cout << "T1: " << it->second.datos[6] << endl;
        cout << "T2: " << it->second.datos[7] << endl;
        cout << "T3: " << it->second.datos[8] << endl;
        cout << "T4: " << it->second.datos[9] << endl;
        cout << "NOMB_CAMPAÑA_LD: " << it->second.datos[10] << endl;
        cout << "NOMB_CAMPAÑA_TC: " << it->second.datos[11] << endl;
        cout << "NOMB_CAMPAÑA_XL: " << it->second.datos[12] << endl;
        cout << "PerfilCliente: " << it->second.datos[13] << endl;
        cout << "Prod_Priorizado: " << it->second.datos[14] << endl;
        cout << "GAMAPRODUCTO: " << it->second.datos[15] << endl;
        cout << "OFERTA_LD: " << it->second.datos[16] << endl;
        cout << "OFERTA_TC: " << it->second.datos[17] << endl;
        cout << "OFERTA_XL: " << it->second.datos[18] << endl;
        cout << "TASA_FINAL: " << it->second.datos[19] << endl;
        cout << "PLAZOMINIMO: " << it->second.datos[20] << endl;
        cout << "FLG_COMBO: " << it->second.datos[21] << endl;
        cout << "PCT: " << it->second.datos[22] << endl;
        cout << "TASAXL: " << it->second.datos[23] << endl;
        cout << "PROPENSION: " << it->second.datos[24] << endl;
        cout << "TipoOferta: " << it->second.datos[25] << endl;
        cout << "UBIGEO: " << it->second.datos[26] << endl;
        cout << "DireccionNegocio: " << it->second.datos[27] << endl;
        cout << "DistNegocio: " << it->second.datos[28] << endl;
        cout << "ProvNegocio: " << it->second.datos[29] << endl;
        cout << "DptoNegocio: " << it->second.datos[30] << endl;
        cout << "EDAD: " << it->second.datos[31] << endl;
        cout << "ZONA: " << it->second.datos[32] << endl;
        cout << "CDR: " << it->second.datos[33] << endl;
        cout << "AGENCIA: " << it->second.datos[34] << endl;
        cout << "UsodeDatosPers: " << it->second.datos[35] << endl;
        cout << "RetriccionPlazoLD: " << it->second.datos[36] << endl;
        cout << "TIPO_ZONA: " << it->second.datos[37] << endl;
        cout << "GrupoContacto: " << it->second.datos[38] << endl;
        cout << "MarcaPEP: " << it->second.datos[39] << endl;
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
