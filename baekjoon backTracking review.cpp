#include <iostream>
#include <cmath> 
#include <vector>
using namespace std;

/* N과 M문제 */ 
int n, m;
int visit[8];
vector<int> v;
void dfs1(int cnt){
	if( cnt==m ){
		cout<<"DFS1\n";
		for(int i=0; i<m; i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for(int i=1; i<=n; i++){
		if( visit[i]==true ) continue;
		visit[i] = true;
		v.push_back(i);
		dfs1(cnt+1);
		visit[i] = false;
		v.pop_back();
	}
}
void dfs2(int cnt, int idx){
	if( cnt==m ){
		cout<<"DFS2\n";
		for(int i=0; i<m; i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for(int i=idx+1; i<=n; i++){
		if( visit[i]==true) continue;
		visit[i] = true;
		v.push_back(i);
		dfs2(cnt+1, i);
		visit[i] = false;
		v.pop_back();
	}
}
void dfs3(int cnt){
	if( cnt==m ){
		cout<<"DFS3\n";
		for(int i=0; i<m; i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for(int i=1; i<=n; i++){
		if( visit[i]==m) continue;
		visit[i]++;
		v.push_back(i);
		dfs3(cnt+1);
		visit[i]--;
		v.pop_back();
	}
} 
void dfs4(int cnt, int idx){
	if( cnt==m ){
		cout<<"DFS4\n";
		// 비내림차순만 출력해야한다. 
		for(int i=0; i<m-1; i++){
			if( v[i]>v[i+1] ) return;
		}
		for(int i=0; i<m ;i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for(int i=idx+1; i<=n; i++){
		if( visit[i]==m) continue;
		visit[i]++;
		v.push_back(i);
		dfs4(cnt+1, idx);
		visit[i]--;
		v.pop_back();
	}
}
/* 스도쿠 문제 */
int sdoku[9][9];
bool sq[9][10], ver[9][10], hor[9][10];
int numOfzeros;
int zeros[81];
void sdokuinput(){
	cout<<"스도쿠 입력\n";
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>sdoku[i][j];
			sq[(i/3)*3+j/3][sdoku[i][j]] = true;
			ver[j][sdoku[i][j]] = true;
			hor[i][sdoku[i][j]] = true;
			if( sdoku[i][j]==0 ){
				zeros[numOfzeros] = i*9+j;
				numOfzeros++;
			}
		}
	}
}
void solveSdoku(int idx){
	if( idx==numOfzeros ){
		cout<<"스도쿠 출력\n";
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout<<sdoku[i][j]<<' ';
			}
			cout<<'\n';
		}
		return;
	}
	
	int x = zeros[idx]/9;
	int y = zeros[idx]%9;
	for(int i=1; i<10; i++){
		if( sq[(x/3)*3+y/3][i] || ver[y][i] || hor[x][i] ) continue;
		sq[(x/3)*3+y/3][i]=ver[y][i]=hor[x][i] = true;
		sdoku[x][y] = i;
		solveSdoku(idx+1);
		sdoku[x][y] = 0;
		sq[(x/3)*3+y/3][i]=ver[y][i]=hor[x][i] = false;
	}
}
/* 연산자 끼워넣기 */
int insertnum;
int insertnums[12];
int op[4];
int minResult = 1000000001, maxResult = -1000000001;
void inputinsertop(){
	cin>>insertnum;
	for(int i=0; i<insertnum; i++){
		cin>>insertnums[i];
	}
	for(int i=0; i<4; i++){
		cin>>op[i];
	}
}
void solveinsertop(int result, int cnt){
	if( cnt==insertnum-1 ){
		minResult = min(minResult, result);
		maxResult = max(maxResult, result);
		return;
	}
	for(int i=0; i<4; i++){
		if( op[i]>0 ){
			op[i]--;
			if( i==0 ){
				solveinsertop(result + insertnums[cnt+1], cnt+1);
			}
			if( i==1 ){
				solveinsertop(result - insertnums[cnt+1], cnt+1);
			}
			if( i==2 ){
				solveinsertop(result * insertnums[cnt+1], cnt+1);
			}
			if( i==3 ){
				solveinsertop(result / insertnums[cnt+1], cnt+1);
			}
			op[i]++;		// 백트래킹 
		}
	}
}
/* 스타트와 링크 */
int people;
int S[20][20];
int visitpeople[20] = {false,};
int minS=2000000000;
void inputStartnLink(){
	cin>>people;
	for(int i=0; i<people; i++){
		for(int j=0; j<people; j++){
			cin>>S[i][j];
		}
	}
}
void solveStartnLink(int n, int cnt){
	if( cnt==people/2 ){
		vector<int> start, link;
		for(int i=0; i<people; i++){
			if( visitpeople[i]==true){
				start.push_back(i);
			}
			else{
				link.push_back(i);
			}
		}
		
		int startSum=0, linkSum=0;
		for(int i=0; i<cnt; i++){
			for(int j=i+1; j<cnt; j++){
				int startX=start[i], startY=start[j];
				int linkX=link[i], linkY=link[j];
				startSum+=S[startX][startY]+S[startY][startX];
				linkSum+=S[linkX][linkY]+S[linkY][linkX];
			}
		}
		minS = min(minS, abs(startSum-linkSum));
		return;
	}
	
	for(int i=n; i<people; i++){
		if( visitpeople[i]==true) continue;
		visitpeople[i] = true;
		solveStartnLink(i+1, cnt+1);
		visitpeople[i] = false;			// 백트래킹 
	}
}
int main(){
// n과m문제 
	cin>>n>>m;
	dfs1(0);
	dfs2(0,0);
	dfs3(0);
	dfs4(0,0);
	cout<<'\n';
// sdoku
	sdokuinput();
	solveSdoku(0);
// 연산자 끼워넣기
 	inputinsertop();
 	solveinsertop(insertnums[0], 0);
 	cout<<maxResult<<'\n'<<minResult<<'\n'; 
// 스타트와 링크
	inputStartnLink();
	solveStartnLink(0,0);
	cout<<minS<<'\n'; 
	return 0;	
} 
