#include <iostream>
int main()
{
	int data[3];
	for(int i=0; i<3; i++){
		std::cin>>data[i];	
	}
	
	int i, j, temp, min, idx;
	for( i=0; i<3; i++){
		min = 99999999;
		for(j=i; j<3; j++){
			if(min>data[j]){
				min = data[j];
				idx = j;
			}
		}
		temp = data[i];
		data[i] = data[idx];
		data[idx] = temp;
	}
	
	for(i=0; i<3; i++){
		std::cout<<data[i]<<' ';
	}
	return 0;
}
