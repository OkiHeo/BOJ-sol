#include <iostream>
using namespace std;

int n, m, p;
bool visit[100001];
int hateToFav[100001];

int search(int now){
	// ���� ä���� �湮ó��. 
	visit[now] = true;
	// ���� ä���� �Ⱦ��ϴ� ����� �ٲ� ä���� next�� ����. 
	int next = hateToFav[now];
	// next==0�� ���� ä���� �Ⱦ��ϴ� ����� ���ٴ� ��. 
	if( next == 0 ) return 0;
	
	// next ä�ο� �湮�� �� �ִٸ� �����ε� ����Ŭ�� �� ��.
	// -1�� ������ش�. 
	if( visit[next] ){
		return -1;
	}
	
	// ���� ä���� �������� �Ⱦ��ϴ� ����� ä���� �������� deep�ϰ� Ž��. 
	int deep = search(next);
	// �� ������ ����Ŭ�� �߻��ϸ� -1�� ����ϰ�, ����Ŭ�� �߻����� �ʴ´ٸ� ä�� ���� Ƚ�� 1 �߰�. 
	return deep==-1?-1:deep+1;
}

int main(){
	cin>>n>>m>>p;
	
	for(int i=0; i<n; i++){
		int fav, hate;
		cin>>fav>>hate;
		// ���� �Էµ� ����� ��ȣ(=� ����� ��ȣ)
		// �Ⱦ��ϴ� ä���� ���� ����� ���� ���̶�� �� �� ���� ���� �Էµ� ����� ä���� �ٲٹǷ�. 
		if( hateToFav[hate]==0 )
			hateToFav[hate] = fav;
	}
	
	cout<<search(p);
	return 0;
}
