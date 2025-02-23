#include <iostream>
#include <vector>
using namespace std;

/**
 * Função auxiliar para o algoritmo DFS.
 * 
 * @param adjMatrix Matriz de adjacência do grafo.
 * @param numOfvertices Número de vértices no grafo.
 * @param vertex Vértice atual sendo visitado.
 * @param visited Vetor que indica se um vértice foi visitado ou não.
 */
void DFSUtil(bool** adjMatrix, int numOfvertices, int vertex, vector<bool>& visited) {
  // Marca o vértice atual como visitado
  visited[vertex] = true;
  cout << "Visited vertex: " << char('A' + vertex) << endl;

  // Percorre todos os vértices adjacentes ao vértice atual
  for (int i = 0; i < numOfvertices; i++) {
    // Se houver uma aresta e o vértice ainda não foi visitado
    if (adjMatrix[vertex][i] && !visited[i]) {
      DFSUtil(adjMatrix, numOfvertices, i, visited); // Chama DFS recursivamente
    }
  }
}

  
/**
 * Realiza o caminhamento no grafo usando o algoritmo DFS.
 * 
 * @param adjMatrix Matriz de adjacência do grafo.
 * @param numOfvertices Número de vértices no grafo.
 * @param startVertex Vértice inicial para o caminhamento.
 */
void DFS(bool** adjMatrix, int numOfvertices, char startVertex) {
  // Vetor para marcar os vértices visitados
  vector<bool> visited(numOfvertices, false);

  // Converte o vértice inicial de char para índice 
  /* 
    (
      A -> 0, 
      B -> 1, 
      C -> 2, 
      D -> 3, 
      etc.
    )
  */

  int startIndex = startVertex - 'A';

  // Verifica se o vértice inicial é válido
  if (startIndex < 0 || startIndex >= numOfvertices) {
    cout << "Invalid start vertex!" << endl;
    return;
  }

  // Chama a função auxiliar para iniciar o DFS
  DFSUtil(adjMatrix, numOfvertices, startIndex, visited);
}