#include <iostream>
#include <stdio.h>

typedef struct Point{
	int x;
	int y;
}Point;

int main()
{
	Point p[3];
	for(int i=0; i<3; i++){
		scanf("%d %d", &p[i].x, &p[i].y);	
	}
	
	int newx, newy;
	// newx를 구하자 
	if(p[0].x == p[1].x){
		newx = p[2].x;
	}
	else if(p[0].x == p[2].x){
		newx = p[1].x;
	}
	else if(p[1].x==p[2].x){
		newx = p[0].x;
	}
	// newy를 구하자 
	if(p[0].y == p[1].y){
		newy = p[2].y;
	}
	else if(p[0].y == p[2].y){
		newy = p[1].y;
	}
	else if(p[1].y==p[2].y){
		newy = p[0].y;
	}
	printf("%d %d\n", newx, newy);
	
	return 0;
}
