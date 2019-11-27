#include <iostream>
#include <cstdio>
using namespace std;

int N;
int count;			// ���� ���� �� �ִ� ����� �� 
bool col[15];		// �ε��� : ���� ��ȣ. �� ���� ���� �����ϴ°�. 
bool *dup;
bool *ddown;

void findQueen(int n){
	if( n==N ){		// n�� ���� ����Ŵ. 0~n-1���� ���� �Ϸ������� 
		count++;	// count ���� 
	}
	else{
		for(int i=0; i<N; i++){
			if( col[i] ) continue;
			if( dup[n+i] || ddown[N-1+n-i]) continue;
			col[i] = dup[n+i] = ddown[N-1+n-i] = true;
			findQueen(n+1);
			col[i] = dup[n+i] = ddown[N-1+n-i] = false;
		}
	} 
}

int main(){
	scanf("%d", &N);
	dup = new bool[2*N-1];
	ddown = new bool[2*N-1];
	
	findQueen(0);
	
	printf("%d", count);		// ���� ���� �� �ִ� ����� �� ��� 
	delete[] dup;
	delete[] ddown;
	return 0;
}
