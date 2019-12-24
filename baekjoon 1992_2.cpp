#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n;		// max 64
int video[65][65];
queue<char> q;
void compress(int x, int y, int size){
	int first = video[x][y];
	int same = true;
	if( size==1 ){
        if( first==0 ) q.push('0');
        else if( first==1 ) q.push('1');
        return;
    }
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			if( first != video[i][j] ){
				same = false;
			}
		}
	}
	
	if( same ){
		if( first ==0 ) q.push('0');
		else if( first==1 ) q.push('1');
		return;
	} 
	else{
		q.push('(');
		compress(x, y, size/2);
		compress(x, y+size/2, size/2);
        compress(x+size/2, y, size/2);
		compress(x+size/2, y+size/2, size/2);
		q.push(')');
	}

} 

int main(){
	// 입력 
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%1d", &video[i][j]);
		}
	}
	// 압축 
	compress(1, 1, n);
	// 출력
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
	cout<<'\n';
	return 0;
}
