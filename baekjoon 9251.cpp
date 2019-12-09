/*

문제 
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
입력

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
출력

첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

*/

#include <iostream>
#include <string>
using namespace std;

#define MAX 1000
string stra, strb;
int c[MAX+1][MAX+1];		// 0으로 채워진 행과 열을 앞에 추가. 

void input(){
	cin>>stra;
	cin>>strb;
}

int findLCS(string stra, string strb){
	// stra와 strb의 문자열을 하나하나 비교. 
	for(int i=1; i<=stra.length(); i++){
		for(int j=1; j<=strb.length(); j++){
			// 현재 비교하는 문자열이 같지 않으면
			// 이 위치 전까지 존재하는 lCS 중 가장 긴 수를 유지한다. 
			if( stra[i-1]!=strb[j-1] ){
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
			else{
				// stra[i-1]==strb[j-1]
				// stra, strb 각각 한 문자열 전까지 lCS길이에 1을 추가한다. 
				c[i][j] = c[i-1][j-1]+1; 
			}
		}
	}
	return c[stra.length()][strb.length()];
}

int main(){
	input();
	cout<<findLCS(stra, strb);
	return 0;	
}
