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
		// �� ���� �߽��� ������ �� 
		if(D == 0){
			if( r1 == r2 ){						// �� ���� ��ġ 
				printf("-1\n");
			}
			else{								// �������� �ٸ� ���ɿ� 
				printf("0\n");
			}
		}
		// �� ���� �߽��� �ٸ� �� 
		else{
			if( (r1+r2)*(r1+r2) == D || (r1-r2)*(r1-r2) == D){			// ����, ���� 
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
