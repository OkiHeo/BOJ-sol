#include <iostream>

int hanNum(const int N){
    int cnt=0;
    if(N<100){
        return N;
    }
    else{
        cnt = 99;
        for(int i=100; i<=N; i++){
            int d100, d10, d1, temp;
            temp = i;
            d100 = temp/100;
            d10 = temp/10%10;
            d1 = temp%10;
            
            if((d100-d10) == (d10-d1)){
                cnt++;
            }
        }
        return cnt;
    }
}

int main()
{
    int N;
    do{
    std::cin>>N;
    }while(N<1 || N>1000);
    
    std::cout<<hanNum(N);
    return 0;
}
