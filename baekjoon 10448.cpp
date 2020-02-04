#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> tri;

int main(){
	cin>>t;

	// maxnum 이하의 삼각수까지를 계산해서 tri 벡터에 저장한다. 
	for(int i=1; i*(i+1)/2<1000; i++){
		tri.push_back(i*(i+1)/2);
	}

	for(int i=0; i<t; i++){
		int x;
		cin>>x;
		// 1000 이하의 삼각수의 개수가 적으므로 삼중 포문으로 해결할 수 있다.
		bool possible=false;
		for(int a=0; a<tri.size(); a++){
			for(int b=a; b<tri.size(); b++){
				for(int c=b; c<tri.size(); c++){
					if(x==tri[a]+tri[b]+tri[c]){
						cout<<"1\n";
						possible = true;
					}
					if( possible ) break;
				}
				if( possible ) break;
			}
			if( possible ) break;
		}
		if(!possible) cout<<"0\n";
	}
	
	return 0; 
}
