#include <iostream>
#include <stdio.h>
void tri(int a, int b, int c){
	if(a>b){
		if(a>c){
			if(a*a == b*b+c*c){
				printf("right\n");
			}else printf("wrong\n");
		}
		else{
			if(c*c == a*a+b*b){
				printf("right\n");
			}else printf("wrong\n");
		}
	}else{
		if(b>c){
			if(b*b == a*a+c*c){
				printf("right\n");
			}else printf("wrong\n");
		}
		else{
			if(c*c == a*a+b*b){
				printf("right\n");
			}else printf("wrong\n");
		}
	}
}
int main()
{
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if( a==0 && b==0 && c==0 ) break;
		tri(a, b, c);
	}
	return 0;
}
