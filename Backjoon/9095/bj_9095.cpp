#include <iostream>
using namespace std;

int dpArr[12] = { 0, };
void init_dp();
void display();

int main() {
	init_dp();
	display();
}

void init_dp() {
	dpArr[1] = 1;
	dpArr[2] = 2;
	dpArr[3] = 4;

	for (int i = 4; i <= 11; i++)
		dpArr[i] = dpArr[i - 1] + dpArr[i - 2] + dpArr[i - 3];
}
void display() {
	int caseNum;
	cin >> caseNum;
	int* num = new int[caseNum];
	for (int i = 0; i < caseNum; i++)
		cin >> num[i];
	for (int i = 0; i < caseNum; i++)
		cout << dpArr[num[i]] << endl;
}