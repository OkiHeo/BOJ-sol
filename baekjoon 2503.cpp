#include <iostream>
using namespace std;

int n[101][3];		// t의 최대값이 100이므로 101을 사용. 
bool nums[1000];

int main(){
	int t, answer=0;
	fill_n(nums, 1000, true); 
	cin>>t;
	// t개의 입력을 받는다. 수, 스트라이크, 볼 
	for(int i=0; i<t; i++){
		cin>>n[i][0]>>n[i][1]>>n[i][2];
	}
	
	for(int num=123; num<=999; num++){ 
		int n1=num/100, n2=(num/10)%10, n3=num%10;
		// 숫자야구에서 발생할 수 없는 num에 대해서는 false 체크하고 다음 num으로 넘어간다.
		if( n1==0 || n2==0 || n3==0 || n1==n2 || n1==n3 || n2==n3 ){
			nums[num]=false;
			continue;
		}
		
		for(int i=0; i<t; i++){
			int x = n[i][0];
			int x1=x/100, x2=(x/10)%10, x3=x%10;
			int nowst=0, nowba=0;
			// 입력받은 x에 대해 strike, ball 판정 받는 케이스를 탐색.
			// 위치와 숫자가 같은 경우 strike 
			if( x1 == n1 ) nowst++;
			if( x2 == n2 ) nowst++;
			if( x3 == n3 ) nowst++;
			// 같은 숫자가 다른 위치에 있는 경우 ball 
			if( x1==n2 || x1==n3 ) nowba++;
			if( x2==n1 || x2==n3 ) nowba++;
			if( x3==n1 || x3==n2 ) nowba++;
			 
			// 현재 입력에 대한 strike, ball개수와 탐색한 strike, ball개수가 동일하지 않다면 num은 가능성이 없는 숫자. 
			if( nowst!=n[i][1] || nowba!=n[i][2] ) {
				nums[num]=false;		// 현재 입력으로 가능성이 있는 수는 false체크 
			}
		}
	}
	
	for(int num=123; num<=999; num++){
		// 가능성이 있는 num의 개수를 센다. 
		if( nums[num]==true ) {
			answer++;
		}
	}
	cout<<answer<<'\n';
	return 0;
}
