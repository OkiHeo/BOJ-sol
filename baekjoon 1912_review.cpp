#include <iostream>
using namespace std;

int serial[100001];
int sum[100001];
int n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>serial[i];
    }
    
    sum[0] = serial[0];
    int maxResult=-100000;
    for(int i=1; i<n; i++){
        sum[i] = max(sum[i-1]+serial[i], serial[i]);
        maxResult = max(maxResult, sum[i]);
    }
    cout<<maxResult<<'\n';
    return 0;
}
