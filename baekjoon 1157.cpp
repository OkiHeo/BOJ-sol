#include <iostream>
#include <stdio.h>
#include <string.h>
int main()
{
	char words[1000001];
	scanf("%s", &words);
	
	int alpha[26] = {0};
	
	int size = strlen(words);
	int comp, count=0;
	
	for(int i=0; i<size; i++){
		if( char(words[i]) >= 'a' && char(words[i])<='z'){
			comp = (int)(words[i] - 'a');	
		}
		else{
			comp = (int)(words[i] - 'A');
		}
		alpha[comp] +=1; 
	}
	
	int maxCount = 0, maxIdx;
	for(int i=0; i<26; i++){
		if( maxCount < alpha[i]){
			maxCount = alpha[i];
			maxIdx = i;
		}
	}
	
	// count ������ maxCount���� ���� ���� �߰��ϸ� count���� �ø��� 
	for(int i=0; i<26; i++){
		if( alpha[i] == maxCount ){
			count++;
		}
		if( count>1){
			printf("?");
			return 0;
		}
	}
	
	printf("%c", maxIdx+'A');
	return 0;
}
