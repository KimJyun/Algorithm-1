#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

int main(void){
	
	// 변수 선언부
	char* color[10] = { "black", "brown", "red", "orange", "yellow",
		"green", "blue", "violet", "grey", "white" };
	char input[3][7];
	int index[3];
	unsigned long long int rlt;


	// 초기화부
	for (int i = 0; i < 3; i++)
		scanf("%s", &input[i]);

	
	// 알고리즘부
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			if (!strcmp(input[i], color[j]))
				index[i] = j;
		}
	}

	rlt = (index[0] * 10 + index[1])*pow(10,index[2]);
	
	// 결과 출력부
	printf("%lld", rlt);
	return 0;
}