#include <iostream>
#include <string.h>
int main()
{
	int T;	//�׽�Ʈ���̽����� 
	std::cin>>T;
	
	int R;	//�ݺ�Ƚ��
	char s[21];
	
	while(T--){
		std::cin>>R>>s;
		
		int size = strlen(s);
		for(int i=0; i<size; i++){
			for(int j=0; j<R; j++){
				std::cout<<s[i];
			}
		}
		std::cout<<'\n';
	}
	return 0;
}
