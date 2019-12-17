#include <iostream>
using namespace std;

/* 2748 �Ǻ���ġ ��2 */
int fibo_n;
int fibo_d[91];
int fibo2(int n){
	if( n==0 ) return 0;
	if( n==1 ) return 1;
	if( fibo_d[n]!=0 ) return fibo_d[n];
	return fibo_d[n] = fibo2(n-1)+fibo2(n-2);
} 

/* 1003 �Ǻ���ġ �Լ� */
// �ð� ������ 0.25��, �־����� fibo_nn�� 40���� �۰ų� ���� �ڿ����Ǵ� 0
// �ð� ������ ���� ��Ģ�� ã�ƾ� �Ѵ�. 
int fibo_t, fibo_nn;
long long int fibo_m[41]; 
long long int fibo(int n){
	if( n==-1 ) return 1;		// fibo_nn�� 0 �� �ԷµǴ� ��츦 ����. 
	if( n==0 ) return 0;
	if( n==1 ) return 1;
	if( fibo_m[n]!=0 ) return fibo_m[n];
	return fibo_m[n]=fibo(n-1)+fibo(n-2);
} 

/* 1904 01Ÿ�� */
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

/* 1149 RGB �Ÿ� */
int rgb_n;
int rgb_cost[1001][3];		// [0]:r, [1]:g, [2]:b ��� 
int rgb[1001][3];		// [1]��~[i]������ [r/g/b]�� ĥ�ϴ� ���
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

/* 1932 ���� �ﰢ�� */
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

/* 2579 ��� ������ */
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

/* 1463 1�� ����� */
int make1_n;
int make1_cnt;
int make1_d[1000001];
void make1_input(){
	cin>>make1_n;
}
int make1_solve(int n){
	make1_d[1] = 0;
	make1_d[2] = 1;
	make1_d[3] = 1;
	
	for(int i=4; i<=make1_n; i++){
		// 1�� �� ���, 2�� ���� ���, 3���� ���� ��� �� �ּ� ����Ƚ���� ������ �� ����. 
		make1_d[i] = make1_d[i-1]+1;
		if( i%2==0 ){
			make1_d[i] = min(make1_d[i], make1_d[i/2]+1);
		}
		if( i%3==0 ){
			make1_d[i] = min(make1_d[i], make1_d[i/3]+1);
		}
	}
	return make1_d[n]; 
}
int make1_solve_topdown(int n){
	for(int i=1; i<=n; i++){
		make1_d[i] = 2000000000;
	}
	make1_d[n] = 0;
	
	for(int i=n; i>0; i--){
		if( i%3==0 ){
			make1_d[i/3] = min(make1_d[i]+1, make1_d[i/3]);
		}
		if( i%2==0 ){
			make1_d[i/2] = min(make1_d[i]+1, make1_d[i/2]);
		}
		make1_d[i-1] = min(make1_d[i]+1, make1_d[i-1]);
	}
	return make1_d[1];
}

/* 10844 ���� ��� �� */
int easyStair_n;
int easyStair_d[101][10];		// [n][i] n�ڸ���, i�� ������ ��ܼ��� ���� 
void easyStair_input(){
	cin>>easyStair_n;
}
int easyStair(int n){
	for(int i=1; i<=9; i++)
		easyStair_d[1][i] = 1;
	easyStair_d[1][0] = 0;
	 for(int i=2; i<=n; i++){
	 	easyStair_d[i][0] = easyStair_d[i-1][1];
		easyStair_d[i][9] = easyStair_d[i-1][8];
		for(int j=1; j<9; j++){
			easyStair_d[i][j] = (easyStair_d[i-1][j-1]+easyStair_d[i-1][j+1])%1000000000;
		}	 
	 }
	int sum=0;
	for(int i=0; i<10; i++){
		sum = (sum+easyStair_d[n][i])%1000000000;
	}
	return sum;
}

/* 2156 ������ �ý� */
int wine_n;
int wine[10001];
int wine_d[10001][3];		// i��° ���α��� ���� �� �ִ�� ���Ǽ��ִ� ���� �� 
// [0]: ����x, [1]: ����1��, [2]: ����2�� 
void wine_input(){
	cin>>wine_n;
	for(int i=1; i<=wine_n; i++){
		cin>>wine[i];
	}
}
int wine_solve(int n){
	for(int i=1; i<=n; i++){
		// ��� ���̽� �������� �������� �ʴ� ������ �� �� �ִ�. 
		wine_d[i][0] = max(wine_d[i-1][0], max(wine_d[i-1][1], wine_d[i-1][2]));
		// �������� ���� �����ְ� 1���� �Ƿ��� ���� 0�� ���¿��� �� �� ���ø� �ȴ�. 
		wine_d[i][1] = wine_d[i-1][0] + wine[i];
		// �������� 1�� ���� ���¿��� �� �� �� ���ø� �������� �� �� ���� ���°� �ȴ�. 
		wine_d[i][2] = wine_d[i-1][1] + wine[i];
	}
	// ���� ������ ���� ���� ���� ���̽��� ã�Ƽ� ����Ѵ�. 
	int maxsum=0;
	for(int i=1; i<=n; i++){
		maxsum = max(maxsum, wine_d[i][0]);
		maxsum = max(maxsum, wine_d[i][1]);
		maxsum = max(maxsum, wine_d[i][2]);
	}
	return maxsum;
}

/* 11053 ���� �� �����ϴ� �κ� ���� */
int incserial_n;
int incserial[1001];
int incserial_d[1001];		// i��°���� �����ϴ� ���� �� �����ϴ� ���� ���� ���� 
void incserial_input(){
	cin>>incserial_n;
	for(int i=1; i<=incserial_n; i++){
		cin>>incserial[i];
	}
}
int incserial_solve(int n){
	int result=0;
	for(int i=1; i<=n; i++)
		incserial_d[i] = 1;
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			if( incserial[j] < incserial[i]){
				incserial_d[i] = max(incserial_d[j]+1, incserial_d[i]);
			}
		}
		result = max(result, incserial_d[i]);
	}
	
	return result;
}

/* 11054 ���� �� ������� �κ� ���� */
int bitserial_n;
int bitserial[1001];
int bitserial_u[1001];
int bitserial_d[1001];
void bitserial_input(){
	cin>>bitserial_n;
	for(int i=1; i<=bitserial_n; i++){
		cin>>bitserial[i];
	}
}
int bitserial_solve(int n){
	for(int i=1; i<=n; i++){
		bitserial_d[i]=1;
		bitserial_u[i]=1;
	}
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			if( bitserial[j] < bitserial[i] ){
				bitserial_u[i] = max(bitserial_u[i], bitserial_u[j]+1);
			}
		}
	}
	for(int i=n; i>0; i--){
		for(int k=n; k>i; k--){
			if( bitserial[i]>bitserial[k]){
				bitserial_d[i] = max(bitserial_d[k]+1, bitserial_d[i]);
			}
		}
	}
	
	int result=0;
	for(int i=1; i<=n; i++){
		result = max(result, bitserial_u[i]+bitserial_d[i]-1);
	}
	return result;
}


int main(){
//	/*2748 �Ǻ���ġ ��2*/
//	cin>>fibo_n;
//	cout<<fibo2(fibo_n)<<'\n';
//	/* 1003 �Ǻ���ġ �Լ� */ 
//	cin>>fibo_t;
//	for(int i=0; i<fibo_t; i++){
//		cin>>fibo_nn;
//		cout<<fibo(fibo_nn-1)<<' '<<fibo(fibo_nn)<<'\n';
//	}
//	/* 1904 01Ÿ�� */
//	cin>>tile_n;
//	cout<<tile(tile_n);
//	/* 1149 RGB �Ÿ� */
//	rgb_input();
//	rgbsolve(rgb_n);
//	/* 1932 ���� �ﰢ�� */
//	tri_input();
//	cout<<tri_solve(tri_n)<<'\n';
//	/* 2579 ��� ������ */
//	stair_input();
//	cout<<stair_solve(stair_n)<<'\n';
//	/* 1463 1�� ����� */
//	make1_input();
//	cout<<make1_solve(make1_n)<<'\n';
//	cout<<make1_solve_topdown(make1_n)<<'\n';
//	/* 10844 ���� ��� ��  */
//	easyStair_input();
//	cout<<easyStair(easyStair_n)<<'\n';
//	/* 2156 ������ �ý� */
//	wine_input();
//	cout<<wine_solve(wine_n)<<'\n';
//	/* 11053 ���� �� �����ϴ� �κм��� */
//	incserial_input();
//	cout<<incserial_solve(incserial_n)<<'\n';
//	/* 11054 ���� �� ������� �κ� ���� */
//	bitserial_input();
//	cout<<bitserial_solve(bitserial_n)<<'\n'; 

	return 0; 
}
