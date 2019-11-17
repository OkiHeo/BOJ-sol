#include <iostream>
#include <stdio.h>
#include <cmath>
int main()
{
	long long V, A, B;
	scanf("%lld %lld %lld", &A, &B, &V);
	printf("%d", ((V-B-1)/(A-B))+1);
	return 0;
}
