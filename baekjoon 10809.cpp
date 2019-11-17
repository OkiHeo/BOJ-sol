#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char word[101];
    cin>>word;
    
    int alpha[26];
    for(int i=0; i<26; i++){
    	alpha[i]=-1;
	}
    
    int size = strlen(word);
	for(int i=0; i<size; i++){
		if(alpha[(int)(word[i]-'a')]==-1){
			alpha[(int)(word[i]-'a')]=i;
		}
	}
	
	for(int i=0; i<26; i++){
		cout<<alpha[i]<<' ';	
	}
    
    return 0;    
}
