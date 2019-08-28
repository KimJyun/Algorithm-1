#include <iostream>
#include <string>
using namespace std;

// 0. 백준 1780 _ 종이의 개수 _ divide and conquer
// 1. String 으로 입력받는다.
// 2. 각각을 파싱해서 matrix로 만든다.
// 3. 9등분 이므로, 전화번호 다이얼기준으로 1~9 구역을 나눈다.
// 4. 각각 시작 col, row를 부터 pixel 만큼 읽는 함수를 작성하고,
// 5. 처음에 모두 같으면 해당 수를 count 한다.

int numOfPaper;
int* rlt;
int** matrix;

void init();
void countPaper(int, int, int);
bool check(int, int, int);
void display();


int main() {
	init();
	countPaper(0, 0, numOfPaper);
	display();
	return 0;

}

void init() {
	string temp;
	rlt = new int[3]{ 0, };
	cin >> numOfPaper;
	matrix = new int* [numOfPaper];
	for (int i = 0; i < numOfPaper; i++) {
		matrix[i] = new int[numOfPaper];
		for (int j = 0; j < numOfPaper; j++) 
			cin >> matrix[i][j];
	}
}

void countPaper(int col, int row, int pixel) {
	if (!check(col, row, pixel)) {
		// 1번 구역
		countPaper(col, row, pixel / 3);
		// 2번 구역
		countPaper(col, row + pixel / 3, pixel / 3);
		// 3번 구역
		countPaper(col, row + pixel / 3 * 2, pixel / 3);
		// 4번 구역
		countPaper(col + pixel / 3, row, pixel / 3);
		// 5번 구역
		countPaper(col + pixel / 3, row + pixel / 3, pixel / 3);
		// 6번 구역
		countPaper(col + pixel / 3, row + pixel / 3 * 2, pixel / 3);
		// 7번 구역
		countPaper(col + pixel / 3 * 2, row, pixel / 3);
		// 8번 구역
		countPaper(col + pixel / 3 * 2, row + pixel / 3, pixel / 3);
		// 9번 구역
		countPaper(col + pixel / 3 * 2, row + pixel / 3 * 2, pixel / 3);
	}
}

bool check(int col, int row, int pixel) {
	int checkValue = matrix[col][row];
	for (int i = 0; i < pixel; i++)
		for (int j = 0; j < pixel; j++)
			if (matrix[col + i][row + j] != checkValue)
				return false;
	rlt[checkValue + 1]++;
	return true;
}

void display() {
	for (int i = 0; i < 3; i++)
		cout << rlt[i] << endl;
}