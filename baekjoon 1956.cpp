#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321
vector<pair<int, int> > city[401];

int main(){
	// �Է� 
	int v, e;
	cin>>v>>e;
	for(int i=0; i<e; i++){
		int start, end, dist;
		cin>>start>>end>>dist;
		city[start].push_back(make_pair(end, dist));
	}
	
	/* ���� ������ ���� ���� ���� ����Ŭ�� ã��,
	   �ּ� ����Ŭ�� ���� ������ ���� ���
	   � ��θ� ã�� ���� �Ұ����� ��쿡�� -1�� ���
	*/

	// s[i][j]���� i���ÿ��� j���÷� ���� �ִܰŸ� ���� 
	int s[v+1][v+1];
	// s �迭�� ��� INF�� �ʱ�ȭ. 
	for(int i=0; i<=v; i++)
		fill_n(s[i], v+1, INF);
	
	// �Է¹��� ���� �� ���� ���θ� s�� �����Ѵ�. 
	for(int i=1; i<=v; i++){
		for(int j=0; j<city[i].size(); j++){
			s[i][city[i][j].first] = city[i][j].second;
		}
	}
	
	// i ���ÿ��� ����ؼ� k���ø� ���� j���÷� ���� �ִܰŸ� ��� 
	for(int k=1; k<=v; k++){		// ��� k�� ���İ���! 
		for(int i=1; i<=v; i++){
			for(int j=1; j<=v; j++){
				// i���� ����ؼ� k�� ���� j�� �����Ѵ�.
				if( s[i][k]==INF || s[k][j]==INF ) continue;
				if( s[i][k] + s[k][j] < s[i][j] ){
					s[i][j] = s[i][k] + s[k][j];
 				} 
			}
		}
	}
	
	// s[i][i]���� i���ÿ��� ����ؼ� i���÷� �����ϴ� �ִܰŸ� ����.
	// s[i][i]�� 0���� �ʱ�ȭ�����ʰ� INF�� �ʱ�ȭ�����Ƿ�
	// ����Ŭ�� �����Ǵ� ��쿡�� i���ÿ��� ����ؼ�
	// ���Ƽ� �ٽ� i���÷� ���ƿ��� ����� �ִܰŸ��� ����ȴ� 
	int mincycle = 987654321;
	for(int i=1; i<=v; i++){
		mincycle = min( mincycle, s[i][i]);
	}
	
	// ���� ���� ���� ���� ���� ����Ŭ�� ���� ���� �� mincycle 
	if( mincycle !=INF ){
		cout<<mincycle<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}
	return 0; 
}
