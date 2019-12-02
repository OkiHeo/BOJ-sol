#include <iostream>
using namespace std;
 
int nums[100001];
int main(){
	int k;	// 입력받을 정수의 개수 
	int idx=-1;
	cin>>k;
	
	// k개의 줄에 정수를 1개씩 입력받음 
	for(int i=0; i<k; i++){
		int tmp;
		cin>>tmp;
		// 입력받은 수가 0이 아니면 해당 수를 쓴다. 
		if( tmp!=0 ){
			idx++;
			nums[idx]=tmp;
			continue;
		}
		// 입력받은 수가 0이면 가장 최근에 쓴 수를 지운다. 
		else{
			idx--;
			continue;
		}
	}
	
	// 최종적으로 남은 수들의 합을 출력. 
	int sum=0;
	for(int i=0; i<=idx; i++){
		sum+=nums[i];
	}
	cout<<sum<<'\n';
	return 0;
}
