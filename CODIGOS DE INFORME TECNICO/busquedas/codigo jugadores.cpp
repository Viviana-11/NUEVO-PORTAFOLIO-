#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> // Para atoi

using namespace std;

// Definición de la estructura del nodo
struct Player {
    int id;
    string name;
    int score;
    Player* next;
};

// Función para crear un nuevo nodo
Player* createNode(int id, string name, int score) {
    Player* newNode = new Player();
    newNode->id = id;
    newNode->name = name;
    newNode->score = score;
    newNode->next = nullptr;
    return newNode;
}

// Función para agregar un nodo al final de la lista
void appendNode(Player*& head, int id, string name, int score) {
    Player* newNode = createNode(id, name, score);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Player* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Función para calcular la puntuación promedio
double calculateAverage(Player* head) {
    double sum = 0;
    int count = 0;
    Player* temp = head;
    while (temp != nullptr) {
        sum += temp->score;
        count++;
        temp = temp->next;
    }
    return (count == 0) ? 0 : sum / count;
}

// Función para encontrar al jugador con la puntuación más alta
Player* findHighestScore(Player* head) {
    if (head == nullptr) return nullptr;
    Player* highest = head;
    Player* temp = head->next;
    while (temp != nullptr) {
        if (temp->score > highest->score) {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

// Función para encontrar al jugador con la puntuación más baja
Player* findLowestScore(Player* head) {
    if (head == nullptr) return nullptr;
    Player* lowest = head;
    Player* temp = head->next;
    while (temp != nullptr) {
        if (temp->score < lowest->score) {
            lowest = temp;
        }
        temp = temp->next;
    }
    return lowest;
}

// Función para eliminar jugadores con puntuaciones por debajo del promedio
void removeBelowAverage(Player*& head, double average) {
    Player* temp = head;
    Player* prev = nullptr;
    while (temp != nullptr) {
        if (temp->score < average) {
            if (prev != nullptr) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            Player* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Función para liberar memoria de la lista
void freeMemory(Player*& head) {
    Player* temp = head;
    while (temp != nullptr) {
        Player* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = nullptr;
}

// Función principal
int main() {
    Player* head = nullptr;
    ifstream inputFile("jugadores.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: No se pudo abrir el archivo 'jugadores.txt'." << endl;
        return 1;
    }

    string line;
    // Leer datos desde el archivo
    while (getline(inputFile, line)) {
        int id, score;
        string name;
        size_t firstSpace = line.find(' ');
        size_t lastSpace = line.rfind(' ');

        id = atoi(line.substr(0, firstSpace).c_str());
        name = line.substr(firstSpace + 1, lastSpace - firstSpace - 1);
        score = atoi(line.substr(lastSpace + 1).c_str());

        appendNode(head, id, name, score);
    }
    inputFile.close();

    // Calcular la puntuación promedio
    double average = calculateAverage(head);
    cout << "Puntuación promedio de los jugadores: " << average << endl;

    // Encontrar al jugador con la puntuación más alta y más baja
    Player* highest = findHighestScore(head);
    Player* lowest = findLowestScore(head);

    if (highest != nullptr) {
        cout << "Mayor puntuación: JugadorID=" << highest->id 
             << ", Nombre=" << highest->name 
             << ", Score=" << highest->score << endl;
    }

    if (lowest != nullptr) {
        cout << "Menor puntuación: JugadorID=" << lowest->id 
             << ", Nombre=" << lowest->name 
             << ", Score=" << lowest->score << endl;
    }

    // Medir tiempo para eliminar jugadores por debajo del promedio
    clock_t start = clock();
    removeBelowAverage(head, average);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo para eliminar jugadores por debajo del promedio: " << elapsed << " segundos." << endl;

    // Liberar memoria
    freeMemory(head);

    return 0;
}
