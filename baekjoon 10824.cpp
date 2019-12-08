#include <iostream>
using namespace std;

long long int A,B,C,D;

void input(){
	cin>>A>>B>>C>>D;
}

long long int solve(){
	int t=10;
	while(t<=B) t*=10;
	A = A*t+B;
	
	t=10;
	while(t<=D) t*=10;
	C = C*t+D;
	
	return A+C;
}

int main(){
	input();
	cout<<solve();
	return 0;
}
