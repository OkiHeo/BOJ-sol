#include <iostream>
using namespace std;

/* 2748 피보나치 수2 */
int fibo_n;
int fibo_d[91];
int fibo2(int n){
	if( n==0 ) return 0;
	if( n==1 ) return 1;
	if( fibo_d[n]!=0 ) return fibo_d[n];
	return fibo_d[n] = fibo2(n-1)+fibo2(n-2);
} 

/* 1003 피보나치 함수 */
// 시간 제한이 0.25초, 주어지는 fibo_nn은 40보다 작거나 같은 자연수또는 0
// 시간 단축을 위해 규칙을 찾아야 한다. 
int fibo_t, fibo_nn;
long long int fibo_m[41]; 
long long int fibo(int n){
	if( n==-1 ) return 1;		// fibo_nn에 0 이 입력되는 경우를 위해. 
	if( n==0 ) return 0;
	if( n==1 ) return 1;
	if( fibo_m[n]!=0 ) return fibo_m[n];
	return fibo_m[n]=fibo(n-1)+fibo(n-2);
} 

/* 1904 01타일 */
int tile_n;
int tile_d[1000001];
int tile(int n){
	if( n==0 ){
		return 1;
	}
	if( n==1 ){
		tile_d[n]=1;
		return 1;
	}
	if( n==2 ){
		tile_d[n]=2;
		return 2;
	}
	if( tile_d[n]!=0 ) return tile_d[n];
	return tile_d[n] = (tile(n-1)+tile(n-2))%15746;
}

/* 1149 RGB 거리 */
int rgb_n;
int rgb_cost[1001][3];		// [0]:r, [1]:g, [2]:b 비용 
int rgb[1001][3];		// [1]집~[i]집까지 [r/g/b]로 칠하는 비용
void rgb_input(){
	cin>>rgb_n;
	for(int i=1; i<=rgb_n; i++){
		cin>>rgb_cost[i][0]>>rgb_cost[i][1]>>rgb_cost[i][2];
	}
}
void rgbsolve(int rgb_n){
	for(int i=0; i<3; i++){
		rgb[1][i] = rgb_cost[1][i];
	}
	for(int i=2; i<=rgb_n; i++){
		rgb[i][0] = rgb_cost[i][0]+min(rgb[i-1][1], rgb[i-1][2]);
		rgb[i][1] = rgb_cost[i][1]+min(rgb[i-1][0], rgb[i-1][2]);
		rgb[i][2] = rgb_cost[i][2]+min(rgb[i-1][0], rgb[i-1][1]);
	}
	cout<<min(min(rgb[rgb_n][0], rgb[rgb_n][1]), rgb[rgb_n][2])<<'\n';
	return;
} 

/* 1932 정수 삼각형 */
int tri_n;
int tri[501][501];
int trisum[501][501];
void tri_input(){
	cin>>tri_n;
	for(int i=1; i<=tri_n; i++){
		for(int j=1; j<=i; j++){
			cin>>tri[i][j];
		}
	}
}
int tri_solve(int tri_n){
	trisum[1][1] = tri[1][1];
	for(int i=2; i<=tri_n; i++){
		for(int j=1; j<=i; j++){
			if( j==1 ){
				trisum[i][j] = trisum[i-1][j]+tri[i][j];
			}
			else if( j==i ){
				trisum[i][j] = trisum[i-1][j-1]+tri[i][j];
			}
			else{
				trisum[i][j] = max(trisum[i-1][j-1], trisum[i-1][j])+tri[i][j];
			}
		}
	}
	int maxsum=0;
	for(int i=1; i<=tri_n; i++){
		maxsum = max(maxsum, trisum[tri_n][i] );
	}
	return maxsum;
}

/* 2579 계단 오르기 */
int stair_n;
int stair[301];
int stair_max[301][2];
void stair_input(){
	cin>>stair_n;
	for(int i=1; i<=stair_n; i++){
		cin>>stair[i];
	}
} 
int stair_solve(int stair_n){
	stair_max[0][0] = stair_max[0][1] = 0;
	stair_max[1][0] = stair_max[1][1] = stair[1];
	for(int i=2; i<=stair_n; i++){
		stair_max[i][0] = stair_max[i-2][1]+stair[i];
		stair_max[i][1] = max(stair_max[i-1][0], stair_max[i-2][1])+stair[i];
	}
	
	int maxresult = 0;
	maxresult = max(stair_max[stair_n][0], stair_max[stair_n][1]);
	return maxresult;	
}
int main(){
//	/*2748 피보나치 수2*/
//	cin>>fibo_n;
//	cout<<fibo2(fibo_n)<<'\n';
//	/* 1003 피보나치 함수 */ 
//	cin>>fibo_t;
//	for(int i=0; i<fibo_t; i++){
//		cin>>fibo_nn;
//		cout<<fibo(fibo_nn-1)<<' '<<fibo(fibo_nn)<<'\n';
//	}
//	/* 1904 01타일 */
//	cin>>tile_n;
//	cout<<tile(tile_n);
//	/* 1149 RGB 거리 */
//	rgb_input();
//	rgbsolve(rgb_n);
//	/* 1932 정수 삼각형 */
//	tri_input();
//	cout<<tri_solve(tri_n)<<'\n';
	/* 2579 계단 오르기 */
	stair_input();
	cout<<stair_solve(stair_n)<<'\n';
	return 0; 
}
