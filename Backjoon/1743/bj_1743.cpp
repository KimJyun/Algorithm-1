#include <iostream>
#include <algorithm>
using namespace std;

int matrix[102][102]{ 0, };

int dfs(int x, int y) {
	int rlt = 0;
	if (matrix[y][x]) {
		matrix[y][x] = 0; // 방문표시
		rlt++;
		// 상
		rlt += dfs(x, y - 1);
		// 하
		rlt += dfs(x, y + 1);
		// 좌
		rlt += dfs(x - 1, y);
		// 우
		rlt += dfs(x + 1, y);
	}
	return rlt;
}




int main() {

	int row, col, k, rlt;
	cin >> row >> col >> k;

	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		matrix[y][x]++;
	}
	
	rlt = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			rlt = max(rlt, dfs(i, j));

	cout << rlt;

	return 0;
}