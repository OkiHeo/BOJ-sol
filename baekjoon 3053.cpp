#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
	int R;
	scanf("%d", &R);
	double areaU, areaT;
	areaU = M_PI*R*R;
	areaT = R*R*2;
	printf("%6f\n%6f\n", areaU, areaT);
	return 0;	
}
