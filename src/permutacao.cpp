#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void initAdjMatrix(bool** adjMatrix, int numOfvertices) {
    for (int i = 0; i < numOfvertices; i++) {
        adjMatrix[i] = new bool[numOfvertices]();
    }

    cout << endl << "Enter the adjacency matrix: (v1 v2) (0 0 to stop)" << endl;
    char v1, v2;
    while (true) {
        cout << "Enter an edge: ";
        cin >> v1 >> v2;

        if (v1 == '0' && v2 == '0') {
            break;
        }

        if (v1 == v2) {
            cout << "Loops are not allowed in simple graphs! Please enter a valid edge." << endl;
            continue;
        }

        int i = v1 - 'A';
        int j = v2 - 'A';
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true; // Undirected graph
    }
}

void printAdjMatrix(bool** adjMatrix, int numOfvertices) {
    cout << endl << "The adjacency matrix is: " << endl;
    for (int i = 0; i < numOfvertices; i++) {
        for (int j = 0; j < numOfvertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isCycle(bool** adjMatrix, vector<int>& vertices, int numOfvertices) {
    for (int i = 0; i < numOfvertices; ++i) {
        int u = vertices[i];
        int v = vertices[(i + 1) % numOfvertices];
        if (!adjMatrix[u][v]) return false;
    }
    return true;
}

int countCyclesPermutation(bool** adjMatrix, int numOfvertices) {
    vector<int> vertices(numOfvertices);
    for (int i = 0; i < numOfvertices; ++i) vertices[i] = i;

    int cycleCount = 0;
    do {
        if (isCycle(adjMatrix, vertices, numOfvertices)) {
            cycleCount++;
        }
    } while (next_permutation(vertices.begin(), vertices.end()));

    return cycleCount;
}

void findCyclesPermutation(bool** adjMatrix, int numOfvertices) {
    vector<int> vertices(numOfvertices);
    for (int i = 0; i < numOfvertices; ++i) vertices[i] = i;

    cout << "\nCycles found using vertex permutation:\n";
    do {
        if (isCycle(adjMatrix, vertices, numOfvertices)) {
            for (int v : vertices) cout << char('A' + v) << " ";
            cout << char('A' + vertices[0]) << endl;
        }
    } while (next_permutation(vertices.begin(), vertices.end()));
}

int main() {
    int numOfvertices;
    cout << "Enter the number of vertices: ";
    cin >> numOfvertices;

    bool **adjMatrix = new bool*[numOfvertices];
    initAdjMatrix(adjMatrix, numOfvertices);
    printAdjMatrix(adjMatrix, numOfvertices);

    int cycleCount = countCyclesPermutation(adjMatrix, numOfvertices);
    findCyclesPermutation(adjMatrix, numOfvertices);
    cout << "\nTotal number of cycles found: " << cycleCount << endl;
    
    for (int i = 0; i < numOfvertices; ++i) delete[] adjMatrix[i];
    delete[] adjMatrix;
    return 0;
}
