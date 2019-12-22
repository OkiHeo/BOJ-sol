#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
int num[100];
vector<int> prime;

int gcd(int a, int b){
	return a%b?gcd(b, a%b):b;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	sort(num, num+n);
	int Gcd = num[1]-num[0];	
	for(int i=2; i<n; i++){
		Gcd = gcd(Gcd, num[i]-num[i-1]);
	}

	// 최대공약수의 약수 찾기!!
	// 약수를 찾으면 하나씩 prime 벡터에 넣는다. 
	for(int i=1; i*i<=Gcd; i++){
		if( Gcd%i==0 ){
			prime.push_back(i);
			if( i==1 ) prime.pop_back();
			if(Gcd/i==i) continue;
			prime.push_back(Gcd/i);
		}
	}
	sort(prime.begin(), prime.end());
	for(int i=0; i<prime.size(); i++){
		cout<<prime[i]<<' ';
	}
	return 0;
}
