#include <iostream>
using namespace std;

int n;
int arr[301];	// 계단에 쓰여 있는 점수 저장. 인덱스 1~300사용 
int sums[301][3];	// [i][1]은 이전에 1칸 이동, [i][2]는 이전에 2칸 이동 

int stair(int n){
	// 첫번째 계단으로 이동하는것은 1칸을 이동하는것, 2칸을 이동하는 것 동일하다. 
	sums[1][1]=sums[1][2] =arr[1];
	for(int i=2; i<=n; i++){
		// 이전에 1칸 이동 -> 무조건 2칸 이동해야함 
		sums[i][1] = sums[i-1][2]+arr[i];
		// 이전에 2칸 이동 -> 1칸 이동, 2칸 이동 모두 가능. 최댓값되는조건으로 진행 
		sums[i][2] = max( sums[i-2][1], sums[i-2][2] ) + arr[i];
	}
	return max(sums[n][1], sums[n][2]); 
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	cout<<stair(n)<<'\n';
	return 0;
} 
