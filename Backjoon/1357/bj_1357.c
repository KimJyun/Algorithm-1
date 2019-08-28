#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define SWAP(a,b){a^=b;b^=a;a^=b;}

int Rev(int num){
	// 1000보다 같거나 작으므로, 모든 자리수는 4자리 이하다.
	int numArr[4] = { 0, };
	int revArr[4] = { 0, };
	int rlt = 0, start = 0;

	for (int i = 0; i < 4; i++){
		numArr[i] = num / pow(10, 3 - i);
	}

	for (int i = 3; i > 0; i--){
		if (numArr[i] && (numArr[i] > 9)){
			numArr[i] -= numArr[i - 1] * 10;
		}
	}

	for (int i = 0; i < 4; i++){
		if (numArr[i] != 0)
			break;
		else
			start++;
	}

	for (int i = 0; i < 4; i++){
		revArr[i] = numArr[3 - i];
	}

	for (int i = 0; i < (4-start); i++){
		rlt += revArr[i] * pow(10, 3 - i - start);
	}
	
	return rlt;
}

int main(void){
	
	// 변수 선언부
	int num1,num2,rlt;

	// 초기화부
	scanf("%d%d", &num1,&num2);

	// 알고리즘부
	rlt = Rev(Rev(num1)+Rev(num2));

	// 결과 출력부
	printf("%d", rlt);
	return 0;
}