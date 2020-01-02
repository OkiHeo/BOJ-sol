#include <iostream>
using namespace std;

int n, k;
int coin[101];            // 인덱스 1~100 사용 
int count[10001];        // [k]원을 만드는 경우의 수 저장. 

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }
    
    count[0]=1;            // 0원을 만드는 경우의 수 1. 
    
    // 1번인덱스의 coin부터 시작.
    // 가치 k를 만드는 경우의 수를 구해서 count[k]에 누적한다. 
    for(int i=1; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            count[j] += count[j-coin[i]];
        }
    }
    cout<<count[k]<<'\n';
    return 0;
}
