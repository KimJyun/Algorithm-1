// BeakJoon Algorithm 2261번 _ 가장 가까운 두점
#define INF 999999999
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전역변수
vector<pair<int, int>> coord;

// 함수 목록 (선언부)
bool compare_x(const pair<int, int>&, const pair<int, int>&);
bool compare_y(const pair<int, int>&, const pair<int, int>&);
int distance(pair<int, int> a, pair<int, int> b);
int divideCoord(int start, int end);

int main() {

	// 1. x좌표 기준으로 정렬한다
	// 2. 반으로 가르고
	// 3. 왼쪽 오른쪽에서 최단 거리를 뽑는다.
	// 4. 그리고 반으로 가른것에서 x좌표 기준으로 d보다 작은 점을 뽑고
	// 5. 그 작은 점만 뽑은 것을 다시 y좌표로 정렬한후 d보다 작은 점을 뽑는다.
	// 6. 위에서 뽑은 미니멈보다 작으면 교체한다.

	// 변수 선언부
	int n, rlt;

	// 변수 초기화부
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

	// Algorithm
	sort(coord.begin(), coord.end(), compare_x);
	rlt = divideCoord(0, n - 1);

	// 결과 출력부
	cout << rlt << endl;
	return 0;
}



// 함수 구현부
bool compare_x(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

bool compare_y(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int distance(pair<int, int> a, pair<int, int>b) {
	int pow_x = (int)pow(b.first - a.first, 2);
	int pow_y = (int)pow(b.second - a.second, 2);
	return pow_x + pow_y;
}

int divideCoord(int start, int end) {
	if (start == end)				// start와 end 두점이 같은경우
		return INF;
	else if (start + 1 == end)		// start와 end 딱 두개의 점일경우
		return distance(coord[start], coord[end]);
	else if (start + 2 == end) {	// start와 end사이에 3개의 점일경우
		int d1 = distance(coord[start], coord[start + 1]);
		int d2 = distance(coord[start + 1], coord[end]);
		int d3 = distance(coord[start], coord[end]);
		int temp = min(d1, d2);
		return min(temp, d3);
	}
	int mid = (start + end) / 2;
	int minDistance_left = divideCoord(start, mid - 1);
	int minDistance_right = divideCoord(mid + 1, end);
	int minDistance = min(minDistance_left, minDistance_right); // 좌우에서 최소값을 뽑고

																// 먼저 mid로 부터 minDistance 안에있는 x좌표를 넣는다.
	vector<pair<int, int>> pickDistance;

	for (int i = start; i < mid; i++) {	// 왼쪽
		if (pow(coord[mid].first - coord[i].first, 2) < minDistance)
			pickDistance.push_back(make_pair(coord[i].first, coord[i].second));
	}


	for (int i = mid; i <= end; i++) { 	// 오른쪽
		if (pow(coord[i].first - coord[mid].first, 2) < minDistance)
			pickDistance.push_back(make_pair(coord[i].first, coord[i].second));
	}

	// 뽑은것을 y좌표 기준으로 sort
	sort(pickDistance.begin(), pickDistance.end(), compare_y);

	// 뽑아 놓은 점들끼리의 y좌표의 거리가 minDistance 보다 작으면 거리계산
	for (int i = 0; i < pickDistance.size(); i++) {
		for (int j = i + 1; j < pickDistance.size(); j++) {
			int pow_y = pow(pickDistance[j].second - pickDistance[i].second, 2);
			if (minDistance > pow_y) {
				int checkDistance = distance(pickDistance[j], pickDistance[i]);
				if (minDistance > checkDistance)
					minDistance = checkDistance;
			}
		}
	}

	return minDistance;
}
