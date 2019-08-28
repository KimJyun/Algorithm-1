#include <iostream>
#include <algorithm>
using namespace std;

int* min_Arr;

void exec(int n) {
	if (n == 1)
		min_Arr[1] = 1;
	else {
		for (int i = 1; i < n; i++) {
			int temp = i*i;
			if (temp > n)
				break;
			else if (temp == n) {
				min_Arr[n] = 1;
				break;
			}
			else if (min_Arr[n - temp] == -1)
				exec(n - temp);

			if (i==1)
				min_Arr[n] = min_Arr[n - temp] + 1;
			else
				min_Arr[n] = min(min_Arr[n], min_Arr[n - temp] + 1);
			
		}
	}
}


int main() {

	// 어떤 수 n이 주어지면 
	int n;
	cin >> n;

	// min_Arr에 해당 수의 최소 제곱 개수가 담겨있는 index가 다다다닥 담겨야한다.
	min_Arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		min_Arr[i] = -1;

	// 한 함수 안에서 다른 함수를 부를테니
	// reculsive 로 구현하는게 좋을 것 같다.
	exec(n);

	// 그 다음 n번째 index의 값을 출력하면 끝 !
	cout << min_Arr[n];

	return 0;
}