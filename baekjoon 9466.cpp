#include <iostream>
using namespace std;

// 모든 학생들은 함께하고싶은 학생 선택해야하고,
// 혼자하고 싶은 학생은 자기 자신만 선택할 수도 있다.

int t, n, cnt=0;		// cnt : 사이클에 속하는(팀을 이룬) 정점 개수 
int select[100000];		// [i] : i학생이 누구를 선택했는지 저장. 
bool visit[100000];
bool finished[100000];

void dfs(int i){
	visit[i] = true;		// 방문표시
	int next = select[i];
	if( visit[next]==true ){
		// i가 선택한 학생이 방문'했던'  학생일 때
		if( finished[next]==false ){
			// i가 선택한 학생이 아직 사이클에 포함되지 않은 학생일 때
			int tmp=next;
			while( tmp!=i ){
				cnt++;		// 사이클을 형성하는 학생들을 차례로 포함한다. 
				tmp = select[tmp];
			}
			cnt++;		// i 자기 자신을 사이클에 포함시킨다. 
		} 
	}
	else{
		// i가 선택한 학생을 아직 방문하지 않았다면 방문한다. 
		dfs(next);
	}
	finished[i] = true;
}

int main(){
	/* 테스트케이스의 개수 T 입력 */
	cin>>t;
	for(int T=0; T<t; T++){
		/* 학생의 수 n입력. 2<=n<=100,000 */
		cin>>n;
		// 각 학생이 선택한 학생을 입력한다. 
		for(int i=0; i<n; i++){
			int x; cin>>x;
			select[i] = x-1;		// 입력은 인덱스 1부터 시작하도록 들어오므로. 
		}
		// visit, team 배열 초기화 
		fill(visit, visit+n, false);
		fill(finished, finished+n, false);
		/* 어느 프로젝트 팀에도 속하지 않는 학생 수를 구한다. */
		cnt=0; 
		for(int i=0; i<n; i++){
			if( visit[i]==false )
				dfs(i);
		}
		cout<<n-cnt<<'\n';
	}
	return 0;
}
