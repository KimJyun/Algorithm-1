#include <iostream>
using namespace std;

void initialization(int* dpArr, int N) {
	dpArr[0] = 1;                             // 좌석이 0개일 때 곱해서 누적 시킬꺼라 0이 아닌 1.
	dpArr[1] = 1;
	dpArr[2] = 2;
	for (int i = 3; i <= N; i++)
		dpArr[i] = dpArr[i - 1] + dpArr[i - 2];
}

int main() {
	
	// 변수 선언부
	int N, M;
	int* dpArr;
	int* checkArr;                            // 고정석 표시해서 좌석 수 자를 것.
	int* fixArr;

	// 변수 초기화부
	cin >> N >> M;
	dpArr = new int[N + 1]{ 0, };
	checkArr = new int[N + 1]{ 0, };
	
	for (int i = 0; i < M; i++) {             // 고정석 받아서 그 좌석은 -1로 고정
		int temp;
		cin >> temp;
		checkArr[temp] = -1;
	}

	// Algorithm
	initialization(dpArr,N);                  // dp 배열 초기화
                                              // dpArr[n] = n개의 좌석이 바뀔 수 있는 경우의 수
	int numOfSeat = 0;                        // 좌석 수를 일시작으로 저장 할 변수
	int rlt = 1;                              // 결과값 저장
	for (int i = 1; i <= N; i++) {            // 1번 좌석부터 시작해서
		if (checkArr[i] == -1) {              // 고정석(-1)이면
			rlt *= dpArr[numOfSeat];          // 결과에 dp 값을 누적시키고
			numOfSeat = 0;                    // 다시 그 다음 부터 좌석 개수를 셈
		}
		else if (i == N && checkArr[i] != -1) // 마지막이면 
			rlt *= dpArr[numOfSeat+1];        // 자신의 값을 더해서 누적시키고 종료
		else                                  // 고정석이 아니면   
			numOfSeat++;
	}
	
	cout << rlt;
	return 0;
}