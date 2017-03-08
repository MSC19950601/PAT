// In graph theory, an Eulerian path is a path in a graph which visits every
// edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which
// starts and ends on the same vertex. They were first discussed by Leonhard
// Euler while solving the famous Seven Bridges of Konigsberg problem in 1736.
// It has been proven that connected graphs with all vertices of even degree
// have an Eulerian circuit, and such graphs are called Eulerian. If there are
// exactly two vertices of odd degree, all Eulerian paths start at one of them
// and end at the other. A graph that has an Eulerian path but not an Eulerian
// circuit is called semi-Eulerian. (Cited from
// https://en.wikipedia.org/wiki/Eulerian_path)

// Given an undirected graph, you are supposed to tell if it is Eulerian,
// semi-Eulerian, or non-Eulerian.

// Input Specification:

// Each input file contains one test case. Each case starts with a line
// containing 2 numbers N (<= 500), and M, which are the total number of
// vertices, and the number of edges, respectively. Then M lines follow, each
// describes an edge by giving the two ends of the edge (the vertices are
// numbered from 1 to N).

// Output Specification:

// For each test case, first print in a line the degrees of the vertices in
// ascending order of their indices. Then in the next line print your conclusion
// about the graph -- either "Eulerian", "Semi-Eulerian", or "Non-Eulerian".
// Note that all the numbers in the first line must be separated by exactly 1
// space, and there must be no extra space at the beginning or the end of the
// line.

//图论 欧拉回路。这个坑留着再填
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 510;

int arc[maxn][maxn] = {};
int n, m;
int degree[maxn] = {};
bool visited[maxn] = {false};

void dfs(int index) {
  for (int t = 1; t <= n; t++)
    if (visited[t] = false && arc[index][t] != 0) {
      visited[t] = true;
      dfs(t);
    }
}

int main() {
  std::cin >> n >> m;

  while (m--) {
    int a, b;
    std::cin >> a >> b;
    degree[a]++;
    degree[b]++;
    arc[a][b] = arc[b][a] = 1;
  }

  int ss = 0;
  for (int i = 1; i <= n; i++) {
    printf("%d", degree[i]);
    if (degree[i] % 2 != 0) {
      ss++;
    }
    if (i < n) {
      printf(" ");
    } else {
      printf("\n");
    }
  }

  int f = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
    } else {
      continue;
    }
    f++;
  }



  if (ss == 0) {
    printf("Eulerian\n");
  } else if (ss == 2) {
    printf("Semi-Eulerian\n");
  } else {
    printf("Non-Eulerian\n");
  }
  if (f == 1) {
    printf("Non-Eulerian\n");
    return 0;
  }

  system("pause");
  return 0;
}
