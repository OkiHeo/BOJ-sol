#include <iostream>
int main()
{
	int A, B;
	std::cin>>A>>B;
	
	int A100 = A/100;
	int A10 = A%100/10;
	int A1 = A%10;
	
	int B100 = B/100;
	int B10 = B%100/10;
	int B1 = B%10;
	
	int newA = A1*100 + A10*10 + A100;
	int newB = B1*100 + B10*10 + B100;
	
	if(newA>newB){
		std::cout<<newA;
	}
	else
		std::cout<<newB;
		
	return 0;
}
