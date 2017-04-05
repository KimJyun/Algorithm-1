#include <iostream>
#include <vector>
using namespace std;

vector<int>* graph;
pair<int, int> person;
int* visit;
int chonsu = 0;
int flag = true;


void dfs(int v) {
	visit[v]++;
	if (v == person.second) {
		flag = false;
		cout << chonsu;
		return;
	}

	for (int i = 0; i < graph[v].size(); i++) {
		if (!visit[graph[v][i]]) {
			chonsu++;
			dfs(graph[v][i]);
			chonsu--;
		}
	}

}

int main() {

	int n, m;

	cin >> n;
	graph = new vector<int>[n+1];
	cin >> person.first >> person.second;
	cin >> m;
	visit = new int[n] {0, };

	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(person.first);
	if (flag)
		cout << -1;

	return 0;
}