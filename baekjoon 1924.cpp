#include <iostream>
int main()
{
	int x, y;
	std::cin>>x>>y;
	int day = y;
	std::string dow[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	for( int i=1; i<x; i++){
		if( i == 2 ){
			day+=28;
		}
		else if ( i==4 || i==6 || i==9 || i==11 ){
			day+=30;
		}
		else{
			day+=31;
		}
	}
	day = (day-1)%7;
	std::cout<<dow[day];
	return 0;
}
