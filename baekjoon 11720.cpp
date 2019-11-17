#include <iostream>
int main()
{
    int N;
    std::cin>>N;
    char ch;
    int sum=0;
    for(int i=0; i<N; i++){
    	std::cin>>ch;
		sum+=ch-'0';
	}
    std::cout<<sum<<std::endl;
    return 0;
}
