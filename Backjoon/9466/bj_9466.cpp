#include<stdio.h>
#include<stdlib.h>

int group[100001];//그룹이 되었는지 여부
int check[100001];//사이클 탐색용
int stu[100001];//해당 학생잎 누구와 팀이 되고 싶은가

int main()
{
	int t;//테스트케이스
	int *ans;//정답저장용
	scanf("%d", &t);
	ans = (int *)malloc(sizeof(int)*t);
	for (int i = 0; i<t; i++)
	{
		ans[i] = 0;//초기화
		int n;//학생수

		scanf("%d", &n);
		for (int j = 1; j<n + 1; j++)
		{
			scanf("%d", &stu[j]);
			check[j] = 0;
			group[j] = 0;//초기화
		}
		for (int j = 1; j<n + 1; j++)
		{
			if (group[j] == 0)//그룹이 될지 안될지 모르는 상태면
			{
				int temp = j;
				while (j != check[temp])//사이클이 생길때까지 검사
				{
					if (group[temp] == -1)//사이클이 안되는 부분에 들어가면
					{
						break;//while 종료
					}
					check[temp] = j;
					temp = stu[temp];
				}
				/*
				j를 이용해서 j가 가리키는 친구들을 따라가며 check에 j를 넣어둔다
				이때 가리키는 친구의 check가 j면 이미 방문했으므로 사이클이 생겼음을 안다
				이때의 가리킨 놈을 시작으로 가리키는 방향을 찾아가면 사이클을 만들 수 있다.
				*/
				while (group[temp] == 0 && check[temp] == j)//사이클이 생긴 부분을 group이 될 수 있도록 체크함
				{
					group[temp] = 1;
					temp = stu[temp];
				}
				if (group[j] != 1)//그룹이 안되는 j였다면
				{
					group[j] = -1;//안된다고 표시해둠
				}
			}
		}
		for (int j = 1; j<n + 1; j++)
		{
			if (group[j] != 1)
			{
				ans[i]++;
			}
		}//답을 계산함
	}
	for (int i = 0; i<t; i++)
	{
		printf("%d\n", ans[i]);//짠
	}
	return 0;
}
