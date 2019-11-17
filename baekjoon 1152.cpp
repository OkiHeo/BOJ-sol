#include <iostream>
#include <string.h>

int main()
{
	char s[1000001];
	std::cin.getline(s, 1000001, '\n');
	int count = 1;
	if( s[0] == ' '){
		count = 0;
	}
	
	for( int i=0; i<strlen(s); i++){
		if( s[i] == ' '){
			count++;
		}
	}
	
	if( s[strlen(s)-1]==' '){
		count--;
	}
	
	std::cout<<count<<'\n';
	return 0;
}
