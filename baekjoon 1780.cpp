#include <iostream>
using namespace std;

int n;
int paper[2188][2188];
int d[9][2] = {{0,0}, {0,1}, {0,2},
			   {1,0}, {1,1}, {1,2},
			   {2,0}, {2,1}, {2,2}};
int papernum[3];		// -1, 0, 1으로 채워진 종이의 개수 저장.
						// 해당 수 +1 인덱스에 값을 저장. 
						
void cut(int x, int y, int size){
	int first = paper[x][y];
	bool same = true;
	
	if( size==1 ){
		papernum[first+1]++;
		return;
	}
	
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			if( paper[i][j]!=first){
				same = false;				
			}
		}
	}
	
	if( same ){
		papernum[first+1]++;
		return;
	}
	else{
		for(int i=0; i<9; i++){
			cut(x+d[i][0]*size/3, y+d[i][1]*size/3, size/3);
		}
	}
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>paper[i][j];
		}
	}
	
	cut(1, 1, n);
	for(int i=0; i<3; i++){
		cout<<papernum[i]<<'\n';
	}
	return 0;
}
