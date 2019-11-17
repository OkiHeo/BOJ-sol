#include <iostream>
int main()
{
    int N;    // 수의 개수
    std::cin>>N;
    int data[1001];
    for(int num=0; num<N; num++){
        std::cin>>data[num];
    }
    
    int i, j, temp, index, min=1001;
    for(i=0; i<N; i++){
        min = 1001;
        for(int j=i; j<N; j++){
            if(min>data[j]){
                min = data[j];
                index = j;
            }
        }
        temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
    
    for(i=0; i<N; i++){
        std::cout<<data[i]<<'\n';
    }
    return 0;
}
