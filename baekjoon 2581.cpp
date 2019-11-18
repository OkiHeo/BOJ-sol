#include <iostream>
#include <stdio.h>
bool prime(int n){
	if( n<2 )
		return false;
	for(int i=2; i*i<=n; i++){
		if( n%i == 0 )
			return false;
	}
	return true;
}

int main()
{
	int M, N;
	std::cin>>M>>N;
	
	int sum=0, min=10001;
	for(int i=M; i<=N; i++){
		if(prime(i)){
			sum+=i;
			if(min>i)
				min = i;
		}
	}
	if( sum != 0 ){
		printf("%d\n%d", sum, min);
	}
	else{
		printf("-1");
	}
	return 0;
}
