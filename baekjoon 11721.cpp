#include <iostream>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    
    int i=0;
    while(true){
        for(int j=0; j<10; j++){
            if( i+j<str.length() )
            cout<<str[i+j];
            else
                return 0;
        }
        cout<<'\n';
        i+=10;
    }
    return 0;
}
