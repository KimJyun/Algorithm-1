#pragma warning (disable:4996)
#include <stdio.h>

int main(void){
	
	// 변수 선언부
	int num, numBuf, rlt = 0;
	int check = 0;

	// 초기화부
	scanf("%d", &num);
	numBuf = num;

	// 알고리즘부
	while (1){

		if (numBuf == 0)
			break;

		if (numBuf < 0){
			rlt = -1;
			break;
		}

		else if (numBuf % 5 == 0){
			check = 1;
			break;
		}

		else{
			numBuf -= 3;
			rlt++;
		}
	}

	if (check)
		rlt += (numBuf / 5);


	// 결과 출력부
	printf("%d", rlt);
	return 0;
}