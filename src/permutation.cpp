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
	cout << "Enter an edge: ";
	while (true) {
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

bool isValidCycle(bool** adjMatrix, vector<int> &vertices, int numOfvertices) {
	for (int i = 0; i < numOfvertices; ++i)	{
		int u = vertices[i];
		int v = vertices[(i + 1) % numOfvertices];
		if (!adjMatrix[u][v])
			return false;
	}
	return true;
}

void findCyclesPermutation(bool **adjMatrix, int numOfvertices) {
	vector<int> vertices(numOfvertices);
	int count = 0;

	// Initialize the vertices
	for (int i = 0; i < numOfvertices; ++i) {
		vertices[i] = i;
	}

	// r = number of vertices in the cycle
	// (a cycle must have at least 3 vertices)
	for (int r = 3; r <= numOfvertices; r++) {
		int tmp = count;
		cout << endl << "Cycles with " << r << " vertices: " << endl;

		vector<bool> select(numOfvertices);
		fill(select.end() - r, select.end(), true);
		do {
			vector<int> combination;
			for (int i = 0; i < numOfvertices; i++) {
				if (select[i]) {
					combination.push_back(vertices[i]);
				}
			}

			do {
				if (isValidCycle(adjMatrix, combination, r)) {
					count++;
					for (int v : combination) {
						cout << char('A' + v) << " ";
					}

					cout << char('A' + combination[0]) << endl;
				}
			} while (next_permutation(combination.begin(), combination.end()));
		} while (next_permutation(select.begin(), select.end()));

		cout << "Total number of cycles with " << r << " vertices: " << count - tmp << endl << endl;
	}

	cout << "-- Total number of cycles: " << count << " --" << endl;
}

int main() {
	int numOfvertices;
	cout << "Enter the number of vertices: ";
	cin >> numOfvertices;

	bool **adjMatrix = new bool *[numOfvertices];
	initAdjMatrix(adjMatrix, numOfvertices);
	printAdjMatrix(adjMatrix, numOfvertices);

	findCyclesPermutation(adjMatrix, numOfvertices);

	// Free the memory
	for (int i = 0; i < numOfvertices; ++i) {
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;

	return 0;
}
