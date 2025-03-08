#include <iostream>
#include <sstream>
#include <set>
#include "caminhamento.h"

using namespace std;

void DFSUtil(bool** adjMatrix, int numOfvertices, int vertex, bool* visited, int* path, int pathIndex, int startVertex, set<string>& foundCycles) {
    if (pathIndex >= numOfvertices) return; 

    visited[vertex] = true;
    path[pathIndex] = vertex;
    pathIndex++;

    // Explora todos os vizinhos do vértice atual
    for (int i = 0; i < numOfvertices; i++) {
        if (adjMatrix[vertex][i]) { // Se há uma aresta entre vertex -> i
            if (!visited[i]) {
                DFSUtil(adjMatrix, numOfvertices, i, visited, path, pathIndex, startVertex, foundCycles);
            } else if (i == startVertex && pathIndex > 2) {
                // encontramos um ciclo válido (volta ao início e tem pelo menos 3 vértices)

                stringstream cycle;
                for (int j = 0; j < pathIndex; j++) {
                    cycle << char('A' + path[j]) << " ";
                }
                cycle << char('A' + startVertex); // fecha o ciclo

                string cycleString = cycle.str();

                // se o ciclo ainda não foi encontrado, imprime e armazena
                if (foundCycles.find(cycleString) == foundCycles.end()) {
                    cout << "Cycle found: " << cycleString << endl;
                    foundCycles.insert(cycleString);
                }
            }
        }
    }

    visited[vertex] = false;
}

void findCyclesDFS(bool** adjMatrix, int numOfvertices) {
    if (!adjMatrix) return; // evita acesso a um ponteiro nulo

    bool* visited = new bool[numOfvertices](); // array de vértices visitados
    int* path = new int[numOfvertices]; // array para armazenar o caminho atual
    set<string> foundCycles; // armazenar os ciclos encontrados

    for (int i = 0; i < numOfvertices; i++) {
        DFSUtil(adjMatrix, numOfvertices, i, visited, path, 0, i, foundCycles);
    }

    cout << "Total number of cycles: " << foundCycles.size() << endl;

    delete[] visited;
    delete[] path;
}