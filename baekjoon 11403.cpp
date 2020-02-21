#include <iostream>
using namespace std;

int n;
bool graph[101][101];		// 가중치 없는 방향 그래프 

int main(){
	/* 정점의 개수 n개 입력 */
	cin>>n;
	/* 그래프의 인접 행렬 입력 */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>graph[i][j];
		}
	}
	
	/* n개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력.
	정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1으로, 없으면 0으로. */
	// floyd-washall 알고리즘 적용. 
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if( graph[i][k] && graph[k][j] ){
					graph[i][j] = true;
				}
			}
		}
	}
	
	// 출력 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<graph[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
