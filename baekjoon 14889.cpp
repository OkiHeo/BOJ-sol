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
				start.push_back(i);		// visit�� �������� start�� 
			else
				link.push_back(i);		// �ٸ� ��������link��. 
		}
		
		// �� ���� �ɷ�ġ ���� ���ϱ�. 
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
	
	// n��° �������� Ž���Ѵ�. 
	for(int i=n; i<N; i++){
		if(visit[i]==true) continue;
		visit[i] = true;
		makeTeam(i+1, cnt+1);
		// ���� �Ѹ��� �̰� �� ������ ���� ��Ȳ���� ������� ���� ���� ã�� 
		// makeTeam(i+1, cnt+1)���� ȣ���� ��� for�� ������ if�� ������ �ϳ� ���� �� �ִ�. 
		visit[i] = false;
	}
}

int main(){
	scanf("%d", &N);
	
	// �Է� 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &S[i][j]);
		}
	}
	// �ɷ�ġ���� �� �ּҰ� ���ϱ�
	makeTeam(0,0);
	printf("%d", minS);
	
	return 0;
}
