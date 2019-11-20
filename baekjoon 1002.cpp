#include <iostream>
#include <stdio.h>
#include <cmath>

int main()
{
	int T;
	int x1, y1, r1, x2, y2, r2;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double D = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		// 두 원의 중심이 동일할 때 
		if(D == 0){
			if( r1 == r2 ){						// 두 원이 일치 
				printf("-1\n");
			}
			else{								// 반지름이 다른 동심원 
				printf("0\n");
			}
		}
		// 두 원의 중심이 다를 때 
		else{
			if( (r1+r2)*(r1+r2) == D || (r1-r2)*(r1-r2) == D){			// 외접, 내접 
				printf("1\n");
			}
			else if( (r1-r2)*(r1-r2) < D && (r1+r2)*(r1+r2) > D){
				printf("2\n");
			}
			else{
				printf("0\n");
			}	
		}
	}
	return 0;
}
