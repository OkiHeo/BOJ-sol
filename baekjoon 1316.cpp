#include <iostream>

std::string word;
int alpha[26];
int main()
{
	int N, cnt=0, i;
	std::cin>>N;
	
	while(N--){
		std::cin>>word;
		std::fill_n(alpha, 26, 0);
		alpha[word[0]-97] = 1;
		for(i=1; i<word.length(); i++){
			if( word[i-1] != word[i] ){
				int idx = word[i]-97;
				if( alpha[idx]==0 )
					alpha[idx]++;
				else
					break;
			}
		}
		if( i == word.length() ){
			cnt++;
		}
	}
	std::cout<<cnt;
	return 0;
}
