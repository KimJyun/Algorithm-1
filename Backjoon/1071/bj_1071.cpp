#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>
#define SWAP(a,b){a^=b;b^=a;a^=b;}
#define MAX 50

int main(){
	int num;
	int check;
	bool flag = true;
	scanf("%d", &num);

	int* pi = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++)
		scanf("%d", &pi[i]);

	for (int i = 0; i < num; i++){
		for (int j = 0; j < num - 1; j++){
			if (pi[j]>pi[j + 1])
				SWAP(pi[j], pi[j + 1]);
		}
	}
	// bubble sort까지는 문제없고

	for (int i = 0; i < num; i++){
		for (int j = 0; j < num-1; j++){
            flag = true;
			if (pi[j] + 1 == pi[j + 1]){
				for (int k = j + 1; k < num; k++){
					if ((pi[k] != pi[j] + 1)&&(pi[k]!=pi[j])){
						SWAP(pi[j + 1], pi[k]);
						flag = false;
						break;
					}
				}
				if (flag)
					SWAP(pi[j], pi[j + 1]);
			}	
		}
	}






	for (int i = 0; i < num; i++)
		printf("%d ", pi[i]);


	return 0;
}