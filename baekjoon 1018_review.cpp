#include <iostream>
using namespace std;

int answer=1000000;
char chess[50][50];

int main(){
	int size1, size2;
	cin>>size1>>size2;
	for(int i=0; i<size1; i++){
		for(int j=0; j<size2; j++){
			cin>>chess[i][j];
		}
	}

	for(int x=0; x<size1-7; x++){
		for(int y=0; y<size2-7; y++){
			int cnt=0;
			for(int sizex=0; sizex<8; sizex++){
				for(int sizey=0; sizey<8; sizey++){
					if( x+sizex >= size1 || y+sizey >=size2 )
						continue;
						
					if( (x+y+sizex+sizey)%2==0 ){
						if( chess[x+sizex][y+sizey]=='W' ){
							cnt++;
						}
					}
					else if( (x+y+sizex+sizey)%2!=0 ){
						if( chess[x+sizex][y+sizey]=='B'){
							cnt++;
						}
					}
				}
			}
			cnt = min(cnt, 64-cnt);
			answer = min(answer, cnt);
		}
	}
	cout<<answer<<'\n';
	return 0;
} 
