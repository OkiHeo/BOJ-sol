#include <iostream>
using namespace std;

int n, k;
int coin[101];            // �ε��� 1~100 ��� 
int count[10001];        // [k]���� ����� ����� �� ����. 

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }
    
    count[0]=1;            // 0���� ����� ����� �� 1. 
    
    // 1���ε����� coin���� ����.
    // ��ġ k�� ����� ����� ���� ���ؼ� count[k]�� �����Ѵ�. 
    for(int i=1; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            count[j] += count[j-coin[i]];
        }
    }
    cout<<count[k]<<'\n';
    return 0;
}
