#include <iostream>
#include <algorithm>
using namespace std;

int num;
int factor[50];

int main(){
	cin>>num;
	for(int i=0; i<num; i++){
		cin>>factor[i];
	}
	sort(factor, factor+num);
	int result = factor[0] * factor[num-1];
	cout<<result;
	return 0;
}
