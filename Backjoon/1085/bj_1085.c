#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>

int main(void){
	int x, y, w, h, rlt, rltX=0, rltY=0;
	int check[2] = {0,0};
	scanf("%d%d%d%d", &x, &y, &w, &h);

	while (1){
		if (x <= w / 2){
			if (x-rltX != 0)
				rltX++;
			else
				check[0] = 1;
		}
		else{
			if (rltX+x != w)
				rltX++;
			else
				check[0] = 1;
		}

		if (y <= h / 2){
			if (y-rltY != 0)
				rltY++;
			else
				check[1] = 1;
		}
		else{
			if (rltY+y != h)
				rltY++;
			else
				check[1] = 1;
		}

		if (check[0]&&check[1])
			break;
	}

	if (rltX >= rltY)
		rlt = rltY;
	else
		rlt = rltX;

	printf("%d", rlt);
	return 0;
}