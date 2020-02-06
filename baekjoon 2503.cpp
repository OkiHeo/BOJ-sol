#include <iostream>
using namespace std;

int n[101][3];		// t�� �ִ밪�� 100�̹Ƿ� 101�� ���. 
bool nums[1000];

int main(){
	int t, answer=0;
	fill_n(nums, 1000, true); 
	cin>>t;
	// t���� �Է��� �޴´�. ��, ��Ʈ����ũ, �� 
	for(int i=0; i<t; i++){
		cin>>n[i][0]>>n[i][1]>>n[i][2];
	}
	
	for(int num=123; num<=999; num++){ 
		int n1=num/100, n2=(num/10)%10, n3=num%10;
		// ���ھ߱����� �߻��� �� ���� num�� ���ؼ��� false üũ�ϰ� ���� num���� �Ѿ��.
		if( n1==0 || n2==0 || n3==0 || n1==n2 || n1==n3 || n2==n3 ){
			nums[num]=false;
			continue;
		}
		
		for(int i=0; i<t; i++){
			int x = n[i][0];
			int x1=x/100, x2=(x/10)%10, x3=x%10;
			int nowst=0, nowba=0;
			// �Է¹��� x�� ���� strike, ball ���� �޴� ���̽��� Ž��.
			// ��ġ�� ���ڰ� ���� ��� strike 
			if( x1 == n1 ) nowst++;
			if( x2 == n2 ) nowst++;
			if( x3 == n3 ) nowst++;
			// ���� ���ڰ� �ٸ� ��ġ�� �ִ� ��� ball 
			if( x1==n2 || x1==n3 ) nowba++;
			if( x2==n1 || x2==n3 ) nowba++;
			if( x3==n1 || x3==n2 ) nowba++;
			 
			// ���� �Է¿� ���� strike, ball������ Ž���� strike, ball������ �������� �ʴٸ� num�� ���ɼ��� ���� ����. 
			if( nowst!=n[i][1] || nowba!=n[i][2] ) {
				nums[num]=false;		// ���� �Է����� ���ɼ��� �ִ� ���� falseüũ 
			}
		}
	}
	
	for(int num=123; num<=999; num++){
		// ���ɼ��� �ִ� num�� ������ ����. 
		if( nums[num]==true ) {
			answer++;
		}
	}
	cout<<answer<<'\n';
	return 0;
}
