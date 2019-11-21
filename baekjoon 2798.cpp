#include <cstdio>

int main()
{
	int N, M;
	scanf("%d %d\n", &N, &M);
	int *cards = new int[N];
	for(int i=0; i<N; i++){
		scanf("%d", &cards[i]);
	}
	int max=0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			for(int k=j+1; k<N; k++){
				int sum = cards[i]+cards[j]+cards[k];
				if( sum<=M && max < sum ){
					max = sum;
				}
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
