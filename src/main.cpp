#include <iostream>
#include "utils/caminhamento.cpp"
#include "utils/grafo.cpp"
#include "utils/permutacao.cpp"

using namespace std;

int main() {
    int numOfvertices;
    int option; 

    cout << "Enter the number of vertices: ";
    cin >> numOfvertices;

    while (numOfvertices <= 0) {
        cout << "Invalid number of vertices! Please enter a positive number: ";
        cin >> numOfvertices;
    }

    bool **adjMatrix = new bool*[numOfvertices]();

    initAdjMatrix(adjMatrix, numOfvertices);

    printAdjMatrix(adjMatrix, numOfvertices);

    do {
        cout << endl << "Choose an option:" << endl;
        cout << "1. Find Cycles using DFS" << endl;
        cout << "2. Find Cycles using Permutation" << endl;
        cout << "0. Exit" << endl;
        cin >> option;

        switch (option) {
            case 1:
                cout << endl << "Enumerating all cycles of the graph..." << endl;
                findCyclesDFS(adjMatrix, numOfvertices); 
                break;
            case 2:
                cout << endl << "Enumerating all cycles of the graph..." << endl;
                findCyclesPermutation(adjMatrix, numOfvertices); 
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 0);

    for (int i = 0; i < numOfvertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}