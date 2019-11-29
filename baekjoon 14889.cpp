#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N;
int S[20][20];
bool visit[20]={false,};
int minS=987654321;

void makeTeam(int n, int cnt){
	if( cnt == N/2 ){
		vector<int> start, link;
		 
		for(int i=0; i<N; i++){
			if( visit[i]==true )
				start.push_back(i);		// visit한 선수들은 start팀 
			else
				link.push_back(i);		// 다른 선수들은link팀. 
		}
		
		// 두 팀의 능력치 차이 구하기. 
		int teamStart=0, teamLink=0;
		for(int i=0; i<start.size(); i++){
			for(int j=i+1; j<start.size(); j++){
				int startX = start[i], startY = start[j];
				int linkX = link[i], linkY = link[j];
				teamStart+=S[startX][startY]+S[startY][startX];
				teamLink+=S[linkX][linkY]+S[linkY][linkX];
			}
		}
		minS = min(minS, abs(teamStart-teamLink));
		return;
	}
	
	// n번째 선수부터 탐색한다. 
	for(int i=n; i<N; i++){
		if(visit[i]==true) continue;
		visit[i] = true;
		makeTeam(i+1, cnt+1);
		// 선수 한명을 뽑고 그 선수를 뽑은 상황에서 재귀적을 다음 선수 찾기 
		// makeTeam(i+1, cnt+1)으로 호출할 경우 for문 내부의 if문 실행을 하나 줄일 수 있다. 
		visit[i] = false;
	}
}

int main(){
	scanf("%d", &N);
	
	// 입력 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &S[i][j]);
		}
	}
	// 능력치합의 차 최소값 구하기
	makeTeam(0,0);
	printf("%d", minS);
	
	return 0;
}
