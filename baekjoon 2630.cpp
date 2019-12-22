#include <iostream>
using namespace std;

int n;
bool paper[129][129];	// �ε��� 1~128�� ����Ѵ�. 
int white=0, blue=0;
int d[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}}; 

bool sameColor(int x, int y, int size){
	// (x,y)���� �����ϴ� size*size�� ��� ���� ������ ĥ�����ִ��� üũ 
	bool start = paper[x][y];
	bool flag = true;
	// (1,1)���� �����ؼ� size�� 8�ΰ��, 1,..., 1+8-1����. 
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			 if( start != paper[i][j] )
			 	flag = false;
		}
	}
	
	// ��� ���� ���ٸ� 
	if( flag ){
		if(start==0)	// �� ���� ����̶�� �� ������+1 
			white++;
		else			// �� ���� �Ķ����̶�� �Ķ� ������+1 
			blue++;
	}
	// ��� ���� ���� �ʴٸ� 
	if( !flag ){
		// 4����ؼ� ���� ������ ���� �� ���Ѵ�. 
		for(int i=0; i<4; i++){
			sameColor(x+d[i][0]*size/2, y+d[i][1]*size/2, size/2);
		}
	}
	return flag;
}

void input(){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>paper[i][j];
		}
	}
}

int main(){
	input();
	sameColor(1, 1, n);
	cout<<white<<'\n'<<blue<<'\n';
	return 0;
}
