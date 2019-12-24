#include <iostream>
#include <cstdio>
using namespace std;

int n;		// max 64
int video[65][65];

void compress(int x, int y, int size){
	// �ش������ ù ���� ���� 
	int first = video[x][y];
	bool same = true;
	
	// size�� 1�̶�� ������ ����Ѵ�.(���̻� �����Ҽ������Ƿ�) 
	if( size==1 ){
		cout<<first;
		return;
	}
	
	// ���� �� ���� ù ���� ���ϸ� ���� �ʴٸ� same�� false�� �ٲ۴� 
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			if( first != video[i][j] ){
				same = false;
			}
		}
	}
	
	// ���� �� ��� ���� ���ٸ� ù ���� ����ϰ� �Լ� ���� 
	if( same ){
		cout<<first;
		return;
	}
	// ���� �� ���� ��� ���� �ʴٸ� 4�����Ͽ� ���Ѵ�. 
	else{
		cout<<"(";
		compress(x, y, size/2);					// 2��и� 
		compress(x, y+size/2, size/2);			// 1��и� 
		compress(x+size/2, y, size/2);			// 3��и� 
		compress(x+size/2, y+size/2, size/2);	// 4��и� 
		cout<<")";
	}
	return;
} 

int main(){
	// �Է� 
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){ 
			// �� �ٷ� �Է¹޴� �����͸� �ϳ��ϳ� �迭�� �����Ѵ� 
			scanf("%1d", &video[i][j]);
		}
	}
	// ���� 
	compress(1, 1, n);
	return 0;
}
