#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void BFS(int** matrix, int numOfVertex, int rootVertex) {

	// 방문여부를 표시할 배열 생성
	int* visitVertex = new int[numOfVertex] {0, };

	// 탐색 결과를 저장할 배열 생성
	vector <int> path;

	// BFS에 사용할 queue 생성
	queue <int> BFSqueue;

	// 맨 처음 시작할 rootVertx를 queue에 추가
	BFSqueue.push(rootVertex);

	// BFS
	while (!BFSqueue.empty()) {

		// queue에서 Vertex를 빼냄
		int vertex = BFSqueue.front();
		BFSqueue.pop();

		// 빼낸 Vertex를 path에 추가
		path.push_back(vertex);

		// 빼낸 Vertex를 방문 여부에 표시
		visitVertex[vertex - 1] = 1;

		// 빼낸 Vertex가 갈 수 있는 Vertex를 queue에 추가
		for (int i = 0; i < numOfVertex; i++) {
			if (matrix[vertex - 1][i] == 1 && visitVertex[i] != 1) {
				BFSqueue.push(i + 1);
				visitVertex[i] = 1;
			}
		}
	}

	// 경로 출력
	for (auto it : path)
		cout << it << " ";
}


void DFS(int** matrix, int numOfVertex, int rootVertex ) {

	// DFS에서 사용할 stack 생성
	stack <int> DFSstack;

	// 경로를 저장할 path 생성
	vector <int> path;

	// 방문여부를 표시할 배열 생성
	int* visitVertex = new int[numOfVertex] {0, };

	// 맨 처음 시작 rootVertex를 stack에 넣음
	DFSstack.push(rootVertex);

	// DFS
	while (!DFSstack.empty()) {
		// stack에서 Vertex를 빼고
		int vertex = DFSstack.top();
		DFSstack.pop();

		// 방문하지 않았으면 
		if (visitVertex[vertex - 1] != 1) {
			// path에 추가하고
			path.push_back(vertex);
			// 방문여부 표시
			visitVertex[vertex - 1] = 1;
		}

		// 그 Vertex가 더 적은 숫자의 Vertex에서 이동 할 수 있으면
		for (int i = numOfVertex - 1; i >= 0; i--) {
			if (matrix[vertex - 1][i] == 1 && visitVertex[i] != 1)
				// stack에 넣음
				DFSstack.push(i + 1);
		}
	}

	// 결과 출력
	for (auto it : path)
		cout << it << " ";
}

int main() {

	// 각 Vertex가 가지고 있는 Edge를 표시하는 Matrix를 생성
	int numOfVertex, numOfEdge, rootVertex;
	cin >> numOfVertex >> numOfEdge >> rootVertex;

	int** matrix = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
		matrix[i] = new int[numOfVertex] {0, };

	// 연결되어 있는 각 Edge를 Matrix에 표시
	for (int i = 0; i < numOfEdge; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		matrix[v1-1][v2-1] = 1;
		matrix[v2-1][v1-1] = 1;
	}

	// DFS
	DFS(matrix, numOfVertex, rootVertex);

	cout << endl;

	// BFS
	BFS(matrix, numOfVertex, rootVertex);

	return 0;
}