// BeakJoon Algorithm 2261�� _ ���� ����� ����
#define INF 999999999
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��������
vector<pair<int, int>> coord;

// �Լ� ��� (�����)
bool compare_x(const pair<int, int>&, const pair<int, int>&);
bool compare_y(const pair<int, int>&, const pair<int, int>&);
int distance(pair<int, int> a, pair<int, int> b);
int divideCoord(int start, int end);

int main() {

	// 1. x��ǥ �������� �����Ѵ�
	// 2. ������ ������
	// 3. ���� �����ʿ��� �ִ� �Ÿ��� �̴´�.
	// 4. �׸��� ������ �����Ϳ��� x��ǥ �������� d���� ���� ���� �̰�
	// 5. �� ���� ���� ���� ���� �ٽ� y��ǥ�� �������� d���� ���� ���� �̴´�.
	// 6. ������ ���� �̴ϸغ��� ������ ��ü�Ѵ�.

	// ���� �����
	int n, rlt;

	// ���� �ʱ�ȭ��
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

	// Algorithm
	sort(coord.begin(), coord.end(), compare_x);
	rlt = divideCoord(0, n - 1);

	// ��� ��º�
	cout << rlt << endl;
	return 0;
}



// �Լ� ������
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
	if (start == end)				// start�� end ������ �������
		return INF;
	else if (start + 1 == end)		// start�� end �� �ΰ��� ���ϰ��
		return distance(coord[start], coord[end]);
	else if (start + 2 == end) {	// start�� end���̿� 3���� ���ϰ��
		int d1 = distance(coord[start], coord[start + 1]);
		int d2 = distance(coord[start + 1], coord[end]);
		int d3 = distance(coord[start], coord[end]);
		int temp = min(d1, d2);
		return min(temp, d3);
	}
	int mid = (start + end) / 2;
	int minDistance_left = divideCoord(start, mid - 1);
	int minDistance_right = divideCoord(mid + 1, end);
	int minDistance = min(minDistance_left, minDistance_right); // �¿쿡�� �ּҰ��� �̰�

																// ���� mid�� ���� minDistance �ȿ��ִ� x��ǥ�� �ִ´�.
	vector<pair<int, int>> pickDistance;

	for (int i = start; i < mid; i++) {	// ����
		if (pow(coord[mid].first - coord[i].first, 2) < minDistance)
			pickDistance.push_back(make_pair(coord[i].first, coord[i].second));
	}


	for (int i = mid; i <= end; i++) { 	// ������
		if (pow(coord[i].first - coord[mid].first, 2) < minDistance)
			pickDistance.push_back(make_pair(coord[i].first, coord[i].second));
	}

	// �������� y��ǥ �������� sort
	sort(pickDistance.begin(), pickDistance.end(), compare_y);

	// �̾� ���� ���鳢���� y��ǥ�� �Ÿ��� minDistance ���� ������ �Ÿ����
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
