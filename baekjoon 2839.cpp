#include <iostream>
int main(){
	int N;
	std::cin>>N;
	
	int x, y;		// 3x+5y == N�� x�� y�� ã�ƾ��� 
	
	for( y=N/5; y>=0; y--){
		for( x=N/3; x>=0; x--){
			if( 3*x+5*y == N ){
				std::cout<<x+y;
				return 0;
			}
		}
	}
	// ���� for������ x,y>=0�� �ݺ������̹Ƿ� Ż���� x,y=-1�� �ȴ�. 
	if( x==-1 && y==-1 ){
		std::cout<<"-1";
	}
	return 0;
}
