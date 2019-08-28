#include <iostream>
#include <queue>
using namespace std;

void bfs(int**, int, int);
int findCC(int**,int,int);

int main() {
	int caseNum;
	cin >> caseNum;

	int*** matrixArray = new int**[caseNum];
	pair<int, int>* elem = new pair<int, int>[caseNum];
	for (int i = 0; i < caseNum; i++) {
		int row, col, k;
		cin >> row >> col >> k;
		elem[i].first = row;
		elem[i].second = col;
		matrixArray[i] = new int*[col+2];
		for (int j = 0; j < col+2; j++)
			matrixArray[i][j] = new int[row+2]{ 0, };
		for (int j = 0; j < k; j++) {
			pair<int, int> coord;
			cin >> coord.first >> coord.second;
			matrixArray[i][coord.second+1][coord.first+1] = 1;
		}
	}

	for (int i = 0; i < caseNum; i++) {
		int rlt = findCC(matrixArray[i], elem[i].second, elem[i].first);
		cout << rlt << endl;
	}
	return 0;
}

void bfs(int** matrix, int col, int row) {
	matrix[col][row] = 0;
	// 상
	if ( matrix[col - 1][row])
		bfs(matrix, col - 1, row);
	// 하
	if( matrix[col+1][row] )
		bfs(matrix, col + 1, row);
	// 좌
	if( matrix[col][row-1] )
		bfs(matrix, col, row - 1);
	// 우 
	if( matrix[col][row+1] )
		bfs(matrix, col, row + 1);
}

int findCC(int** matrix, int col, int row) {
	int rlt = 0;
	for (int i = 1; i < col+1; i++) 
		for (int j = 1; j < row+1; j++) 
			if (matrix[i][j]) {
				rlt++;
				bfs(matrix, i, j);
			}
	return rlt;
}