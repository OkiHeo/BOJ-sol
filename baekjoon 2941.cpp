#include <iostream>
int main()
{
	std::string s;
	std::cin>>s;
	int num=0, i=0;
	while(i<s.length()){
		if( s[i]=='c' && (s[i+1]=='=' || s[i+1]=='-')){
			num++;
			i = i+2;
		}
		else if( s[i]=='d' && s[i+1]=='z'&&s[i+2]=='='){
			num++;
			i = i+3;
		}
		else if(s[i]=='d'&&s[i+1]=='-'){
			num++;
			i = i+2;
		}
		else if(s[i]=='s'&&s[i+1]=='='){
			num++;
			i = i+2;
		}
		else if(s[i]=='z'&&s[i+1]=='='){
			num++;
			i = i+2;
		}else if(s[i]=='l'&&s[i+1]=='j'){
			num++;
			i = i+2;
		}else if(s[i]=='n'&&s[i+1]=='j'){
			num++;
			i = i+2;
		}
		else{
			num++;
			i++;
		}
	}
	std::cout<<num;
	return 0;
}
