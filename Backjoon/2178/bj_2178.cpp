#include <iostream>
#include <string>
#include <queue>
using namespace std;

int rltCol, rltRow;
queue< pair<int, int> > coord;
int matrix[102][102] = { 0, };

void init();
void bfs();
void push_change(int,int,int);
void display();

int main() {
	init();
	bfs();
	display();
	return 0;
}

void init() {

	string* tempStr;
	cin >> rltCol >> rltRow;
	tempStr = new string[rltCol];

	for (int i = 0; i < rltCol; i++)
		cin >> tempStr[i];

	for (int i=1; i<=rltCol; i++)
		for (int j = 1; j <= rltRow; j++)
			matrix[i][j] = int(tempStr[i - 1][j - 1]) - 48;
}

void bfs() {

	coord.push( make_pair(1,1) );

	while ( !coord.empty() ) {
		int col = coord.front().first;
		int row = coord.front().second;
		int value = matrix[col][row];
		coord.pop();

		if (col == rltCol && row == rltRow)
			break;

		// 상
		if (matrix[col - 1][row] == 1)
			push_change(col - 1, row, value);

		// 하
		if (matrix[col + 1][row] == 1)
			push_change(col + 1, row, value);

		// 좌
		if (matrix[col][row - 1] == 1)
			push_change(col, row - 1, value);

		// 우
		if (matrix[col][row + 1] == 1)
			push_change(col, row + 1, value);

		matrix[col][row] = 0;
	}
}

void push_change(int col, int row, int value) {
	coord.push(make_pair(col, row));
	matrix[col][row] += value;
}

void display() {
	cout << matrix[rltCol][rltRow];
}