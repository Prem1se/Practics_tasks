#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<int>> &graph, int start, std::vector<int> &visited) {
  visited[start] = 1;
  for (int neighboor : graph[start]) {
    if (!visited[neighboor]) {
      DFS(graph, neighboor, visited);
    }
  }
}


int main() {
  int vertex = 0;  // вершины
  int edges = 0;  // число ребер
  std::cout << "Введите число вершнин: ";
  std::cin >> vertex;
  std::cout << "Введите число рёбер: ";
  std::cin >> edges;

  std::vector<std::vector<int>> graph(vertex);
  for (int i = 0; i < edges; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int components = 0;
  std::vector<int> visited(vertex);
  for (int i = 0; i < vertex; i++) {
    if (!visited[i]) {
      components++;
      DFS(graph, i, visited);
    }
  }
  std::cout << components - 1;
}