/*

���� 
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.
�Է�

ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.
���

ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.

*/

#include <iostream>
#include <string>
using namespace std;

#define MAX 1000
string stra, strb;
int c[MAX+1][MAX+1];		// 0���� ä���� ��� ���� �տ� �߰�. 

void input(){
	cin>>stra;
	cin>>strb;
}

int findLCS(string stra, string strb){
	// stra�� strb�� ���ڿ��� �ϳ��ϳ� ��. 
	for(int i=1; i<=stra.length(); i++){
		for(int j=1; j<=strb.length(); j++){
			// ���� ���ϴ� ���ڿ��� ���� ������
			// �� ��ġ ������ �����ϴ� lCS �� ���� �� ���� �����Ѵ�. 
			if( stra[i-1]!=strb[j-1] ){
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
			else{
				// stra[i-1]==strb[j-1]
				// stra, strb ���� �� ���ڿ� ������ lCS���̿� 1�� �߰��Ѵ�. 
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
