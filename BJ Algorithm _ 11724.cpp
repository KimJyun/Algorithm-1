#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>* graph;
int* visit;

bool compareVector(const int& a, const int& b);
void dfs(int v);

int main() {
	
	int numV, numE, rlt = 0;

	cin >> numV >> numE;
	graph = new vector<int>[numV + 1];
	visit = new int[numV + 1];
	for (int i = 1; i <= numE; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= numV; i++) {
		sort(graph[i].begin(), graph[i].end(), compareVector);
		visit[i] = 0;
	}

	for (int i = 1; i <= numV; i++)
		if (!visit[i]) {
			dfs(i);
			rlt++;
		}

	cout << rlt;
	return 0;
}

bool compareVector(const int& a, const int& b) { return a < b; }

void dfs(int v) {
	visit[v] = 1;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visit[graph[v][i]])
			dfs(graph[v][i]);
	}
}