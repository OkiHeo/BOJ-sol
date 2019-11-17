#include <iostream>
int main()
{
	long long int X;
	std::cin>>X;
	
	int no=0;
	int up, down;
	int num=0;
	
	while(1){
		num++;
		if( num %2 == 0 ){
			up = 1;
			down = num;
		}
		else{
			up = num;
			down = 1;
		}
		
		for( int i=0; i<num; i++){
			no++;
			if( no == X ){
				std::cout<<up<<'/'<<down;
				return 0;
			}
			if( num % 2 == 0 ){
				up++;
				down--;	
			}
			else{
				up--;
				down++;
			}
		}
	}
	
	return 0;
}
