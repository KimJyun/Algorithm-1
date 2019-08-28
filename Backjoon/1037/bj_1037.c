#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>
#define SWAP(a,b){a^=b;b^=a;a^=b;}

int main(void){

	// 변수 선언부
	int caseNum,rlt;
	int* numArr;


	// 초기화부
	scanf("%d", &caseNum);
	numArr = (int*)malloc(sizeof(int)*caseNum);
	for (int i = 0; i < caseNum; i++){
		scanf("%d", &numArr[i]);
	}

	// 알고리즘부
	for (int i = 0; i < caseNum; i++){
		for (int j = 0; j < caseNum-1; j++){
			if (numArr[j]>numArr[j + 1])
				SWAP(numArr[j], numArr[j + 1]);
		}
	}

	rlt = numArr[0] * numArr[caseNum - 1];

	// 결과 출력부
	printf("%d", rlt);
	return 0;
}