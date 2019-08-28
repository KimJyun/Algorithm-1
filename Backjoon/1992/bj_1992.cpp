#include <iostream>
#include <string>
using namespace std;

int N;
int matrix[66][66] = { 0, };

void init();
void quadTree(int,int,int);
bool check(int, int, int);

int main() {
	init();
	quadTree(1,1,N);
	return 0;
}

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= N; j++)
			matrix[i][j] = temp[j - 1] - 48;
	}
}

void quadTree(int col, int row, int pixel) {
	if (check(col,row,pixel)) {
		cout << matrix[col][row];
		return;
	}
	else {
		cout << "(";
		quadTree(col, row, pixel / 2);
		quadTree(col, row + pixel / 2, pixel / 2);
		quadTree(col + pixel / 2, row, pixel / 2);
		quadTree(col + pixel / 2, row + pixel / 2, pixel / 2);
		cout << ")";
	}
}

bool check(int col, int row, int pixel) {
	int temp = matrix[col][row];
	for (int i = 0; i < pixel; i++)
		for (int j = 0; j < pixel; j++) 
			if (matrix[col + i][row + j] != temp)
				return false;
	return true;
}

