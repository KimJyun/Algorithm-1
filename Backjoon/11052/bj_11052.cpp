#pragma warning (disable:4996)

#include <iostream>
#include <algorithm>
using namespace std;

// 변수선언 
// setPrice = 정해진 세트가격 , maxPrice = n개일때 최대가격
int* setPrice;
int* maxPrice;

void exec(int n) {
	if (n == 1)
		maxPrice[n] = setPrice[n];
	else {
		for (int i = 1; i < n; i++) {
			if (maxPrice[n - i] == -1) {
				exec(n - i);
			}
			maxPrice[n] = max(maxPrice[n], setPrice[n]);
			maxPrice[n] = max(maxPrice[n], setPrice[i] + maxPrice[n - i]);
		}
	}

}

int main() {

	// 변수선언
	// n = 남은 붕어빵 개수
	int n;

	// 변수 초기화
	scanf("%d", &n);
	setPrice = new int[n + 1];
	maxPrice = new int[n + 1];
	for (int i = 1; i < n + 1; i++) {
		cin >> setPrice[i];
		maxPrice[i] = -1;
	}

	// maxPrice 배열에 주르르륵 값 입력
	exec(n);

	// 결과 출력
	cout << maxPrice[n];

	return 0;
}