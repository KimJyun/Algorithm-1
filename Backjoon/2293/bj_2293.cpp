#include <iostream>
#include <algorithm>
using namespace std;

int qsort_func(const void*, const void*);

int main() {

	// 변수 선언부
	int n, k;
	int* coin;
	int* dp;

	// 변수 초기화부
	cin >> n >> k;
	dp = new int[k+1] {0, };
	coin = new int[n] {0, };
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	
	// 맨 처음 초기값
	dp[0] = 1; // 0원을 만드는 방법의수 = 아무것도 선택하지 않음 = 1가지

	// coin 배열을 오름차순으로 정렬
	qsort(coin, n, sizeof(int), qsort_func);

	// Algorithm
	for (int i = 0; i < n; i++)   // coin[i] = 반복문 돌려볼 coin이 되는거다.
		for (int j = coin[i]; j <= k; j++) 
			dp[j] += dp[j - coin[i]];

	// 결과 출력부
	cout << dp[k];

	return 0;
}


int qsort_func(const void* elem1, const void* elem2) {
	int rlt;
	if (*(int*)elem1 > *(int*)elem2)
		rlt = 1;
	else
		rlt = 0;
	return rlt;
}