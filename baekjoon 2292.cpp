#include <iostream>
int main()
{
	int N;
	std::cin>>N;
	
	// �Ʒ�ó�� ���� ������ ������ �ʰ�
	// ���α׷��󿡼� ��� �ذ�����! 
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
