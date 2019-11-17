#include <iostream>
int main()
{
	int N;
	std::cin>>N;
	
	// 아래처럼 직접 수열을 구하지 않고
	// 프로그램상에서 모두 해결하자! 
	int r=1;
	int end=1;
	int inc = 6;
	while(1){
		if(N<=end)
			break;
		r++;
		end+=inc;
		inc+=6;
	}
	std::cout<<r;
//	while(1){
//		if( N<= 3*r*r-3*r+1){
//			std::cout<<r;
//			break;
//		}
//		r++;
//	}
	return 0; 
 } 
