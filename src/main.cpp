#include <iostream>
#include "utils/caminhamento.cpp"
#include "utils/grafo.cpp"

using namespace std;

int main() {
	int numOfvertices;

	cout << "Enter the number of vertices: ";
	cin >> numOfvertices;

	bool **adjMatrix = new bool*[numOfvertices];

	initAdjMatrix(adjMatrix, numOfvertices);

	printAdjMatrix(adjMatrix, numOfvertices);
}