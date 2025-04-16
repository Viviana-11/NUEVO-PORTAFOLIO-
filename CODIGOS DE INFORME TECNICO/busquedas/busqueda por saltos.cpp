#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>      
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

// Función de ordenación (Bubble Sort)
void ordenarPorDNI(Registro registros[], int numRegistros) {
    for (int i = 0; i < numRegistros - 1; ++i) {
        for (int j = 0; j < numRegistros - 1 - i; ++j) {
            if (compararDNI(registros[j + 1], registros[j])) {
                Registro temp = registros[j];
                registros[j] = registros[j + 1];
                registros[j + 1] = temp;
            }
        }
    }
}

// búsqueda de saltos
int jumpSearch(Registro registros[], int numRegistros, const string& dniBuscado, int& saltos) {
    int salto = sqrt(numRegistros); 
    int prev = 0;
    
    while (registros[min(salto, numRegistros) - 1].dni < dniBuscado) {
        prev = salto;
        salto += sqrt(numRegistros);
        saltos++; 
        if (prev >= numRegistros) {
            return -1; 
        }
    }
  
    for (int i = prev; i < min(salto, numRegistros); i++) {
        if (registros[i].dni == dniBuscado) {
            return i;  
        }
    }
    return -1; 
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

    ordenarPorDNI(registros, numRegistros);

    cout << "Ingrese el DNI que desea buscar: ";
    cin >> dniBuscado;

    clock_t start = clock();

    int saltos = 0;  

    int indiceEncontrado = jumpSearch(registros, numRegistros, dniBuscado, saltos);

    if (indiceEncontrado != -1) {
        cout << "Datos encontrados para el DNI " << dniBuscado << ":\n";
        cout << "DNI: " << registros[indiceEncontrado].dni << endl;
        cout << "Nombre: " << registros[indiceEncontrado].datos[0] << endl;
        cout << "Dirección: " << registros[indiceEncontrado].datos[1] << endl;
        cout << "Distrito: " << registros[indiceEncontrado].datos[2] << endl;
        cout << "Provincia: " << registros[indiceEncontrado].datos[3] << endl;
        cout << "Departamento: " << registros[indiceEncontrado].datos[4] << endl;
        cout << "Regiones: " << registros[indiceEncontrado].datos[5] << endl;
        cout << "T1: " << registros[indiceEncontrado].datos[6] << endl;
        cout << "T2: " << registros[indiceEncontrado].datos[7] << endl;
        cout << "T3: " << registros[indiceEncontrado].datos[8] << endl;
        cout << "T4: " << registros[indiceEncontrado].datos[9] << endl;
        cout << "NOMB_CAMPAÑA_LD: " << registros[indiceEncontrado].datos[10] << endl;
        cout << "NOMB_CAMPAÑA_TC: " << registros[indiceEncontrado].datos[11] << endl;
        cout << "NOMB_CAMPAÑA_XL: " << registros[indiceEncontrado].datos[12] << endl;
        cout << "PerfilCliente: " << registros[indiceEncontrado].datos[13] << endl;
        cout << "Prod_Priorizado: " << registros[indiceEncontrado].datos[14] << endl;
        cout << "GAMAPRODUCTO: " << registros[indiceEncontrado].datos[15] << endl;
        cout << "OFERTA_LD: " << registros[indiceEncontrado].datos[16] << endl;
        cout << "OFERTA_TC: " << registros[indiceEncontrado].datos[17] << endl;
        cout << "OFERTA_XL: " << registros[indiceEncontrado].datos[18] << endl;
        cout << "TASA_FINAL: " << registros[indiceEncontrado].datos[19] << endl;
        cout << "PLAZOMINIMO: " << registros[indiceEncontrado].datos[20] << endl;
        cout << "FLG_COMBO: " << registros[indiceEncontrado].datos[21] << endl;
        cout << "PCT: " << registros[indiceEncontrado].datos[22] << endl;
        cout << "TASAXL: " << registros[indiceEncontrado].datos[23] << endl;
        cout << "PROPENSION: " << registros[indiceEncontrado].datos[24] << endl;
        cout << "TipoOferta: " << registros[indiceEncontrado].datos[25] << endl;
        cout << "UBIGEO: " << registros[indiceEncontrado].datos[26] << endl;
        cout << "DireccionNegocio: " << registros[indiceEncontrado].datos[27] << endl;
        cout << "DistNegocio: " << registros[indiceEncontrado].datos[28] << endl;
        cout << "ProvNegocio: " << registros[indiceEncontrado].datos[29] << endl;
        cout << "DptoNegocio: " << registros[indiceEncontrado].datos[30] << endl;
        cout << "EDAD: " << registros[indiceEncontrado].datos[31] << endl;
        cout << "ZONA: " << registros[indiceEncontrado].datos[32] << endl;
        cout << "CDR: " << registros[indiceEncontrado].datos[33] << endl;
        cout << "AGENCIA: " << registros[indiceEncontrado].datos[34] << endl;
        cout << "UsodeDatosPers: " << registros[indiceEncontrado].datos[35] << endl;
        cout << "RetriccionPlazoLD: " << registros[indiceEncontrado].datos[36] << endl;
        cout << "TIPO_ZONA: " << registros[indiceEncontrado].datos[37] << endl;
        cout << "GrupoContacto: " << registros[indiceEncontrado].datos[38] << endl;
        cout << "MarcaPEP: " << registros[indiceEncontrado].datos[39] << endl;
    } else {
        cout << "No se encontraron datos para el DNI " << dniBuscado << "." << endl;
    }

    clock_t end = clock();

    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución de la búsqueda: " << elapsed_time << " segundos." << endl;

    
    cout << "Cantidad de saltos realizados: " << saltos << endl;

    archivoCSV.close();  

    return 0;
}