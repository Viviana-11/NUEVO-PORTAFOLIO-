#include <iostream>
#include <string>
#include <cstdlib>   // Para usar rand()
#include <ctime>     // Para usar time() como semilla
using namespace std;

// Definir la estructura 'node' para almacenar nombre y código de matrícula
struct node {
    string name;         // Nombre del estudiante
    string codigo;       // Código de matrícula del estudiante
    node* next;          // Puntero al siguiente nodo
};

// Función para generar un código de matrícula aleatorio
string generarCodigo() {
    string codigo;
    string caracteres = "0123456789";  
    for (int i = 0; i < 6; ++i) {
        int indice = rand() % caracteres.size();  
        codigo += caracteres[indice]; 
    }
    return codigo;
}

//  nombre aleatorio
string generarNombre() {
    string nombres[] = {"Juan Perez", "Ana Garcia", "Carlos Gomez", "Maria Lopez", "Pedro Ruiz", "Luisa Vargas", "Antonio Mendez", "Laura Torres", "Javier Herrera", "Elena Diaz"};
    return nombres[rand() % 10];  
}

int main() {
    srand(time(0));  
    // Crear el primer nodo
    node* head = new node();
    head->name = generarNombre();
    head->codigo = generarCodigo();
    head->next = nullptr;

    node* current = head;

    // Crear los siguientes 101 nodos
    for (int i = 1; i < 102; ++i) {
        node* newNode = new node();
        newNode->name = generarNombre();
        newNode->codigo = generarCodigo();
        newNode->next = nullptr;

        current->next = newNode;  
        current = newNode;        
    }

    current = head;
    int count = 1;
    while (current != nullptr) {
        cout << "Estudiante " << count << ": Nombre: " << current->name << ", Codigo: " << current->codigo << endl;
        current = current->next;
        count++;
    }

    current = head;
    while (current != nullptr) {
        node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
