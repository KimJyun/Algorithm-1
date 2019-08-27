#include <iostream>
#include <algorithm>
using namespace std;

int height, rlt;
int triangle[501][501];
int maxangle[501][501];
void init();
void dynamic();
void display();

int main() {
	init();
	dynamic();
	display();
}

void init() {
	for (int i = 0; i < 501; i++)
		for (int j = 0; j < 501; j++)
			maxangle[i][j] = triangle[i][j] = 0;

	cin >> height;

	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= i; j++)
			cin >> triangle[i][j];
}
void dynamic() {
	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= i; j++)
			maxangle[i][j] = triangle[i][j] + max(maxangle[i - 1][j - 1], maxangle[i - 1][j]);

	rlt = 0;
	for (int i = 1; i <= height; i++)
		rlt = max(rlt, maxangle[height][i]);
}
void display() {
	cout << rlt << endl;
}