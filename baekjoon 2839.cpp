#include <iostream>
int main(){
	int N;
	std::cin>>N;
	
	int x, y;		// 3x+5y == N인 x와 y를 찾아야함 
	
	for( y=N/5; y>=0; y--){
		for( x=N/3; x>=0; x--){
			if( 3*x+5*y == N ){
				std::cout<<x+y;
				return 0;
			}
		}
	}
	// 위의 for문에서 x,y>=0이 반복조건이므로 탈출은 x,y=-1이 된다. 
	if( x==-1 && y==-1 ){
		std::cout<<"-1";
	}
	return 0;
}
