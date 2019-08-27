#include <iostream>
#include <vector>
using namespace std;

int testCase, n;
int dp[41][2];
void dynamic();
void display();

int main() {
	dynamic();
	display();
	return 0;
}

void dynamic() {
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
}
void display() {
	int testCase;
	vector<pair<int, int>> rlt;

	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		rlt.push_back(make_pair(dp[n][0], dp[n][1]));
	}

	for (auto i : rlt)
		cout << i.first << " " << i.second << endl;
}

