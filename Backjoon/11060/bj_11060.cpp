#define INF 1001
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// 변수 선언부
	int N;
	int* jumpPower;
	int* minJump;

	// 변수 초기화부
	cin >> N;
	jumpPower = new int[N];
	minJump = new int[N];

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		jumpPower[i] = temp;
		minJump[i] = INF;
	}
	
	// Algorithm
	minJump[0] = 0;     // 초기조건

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= jumpPower[i]; j++) {
			if (i+j >= N)
				break;
			minJump[i+j] = min(minJump[i+j], minJump[i] + 1);
		}
	}

	// 결과 출력부
	if (minJump[N-1] == INF)
		cout << -1;
	else
		cout << minJump[N-1];
    
	return 0;
}
