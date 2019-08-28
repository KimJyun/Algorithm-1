#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>

int main(void){

	int num,rlt = 0;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < num; i++){
		int sosu = 0;
		for (int j = 1; j < arr[i]; j++){
			if (arr[i] % j == 0)
				sosu++;
		}
		if (sosu == 1)
			rlt++;
	}

	printf("%d", rlt);
	return 0;
}