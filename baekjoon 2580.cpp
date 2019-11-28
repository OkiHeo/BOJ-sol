#include <cstdio>
#include <cstdlib>

// ��� ����� ������ �� �غ� 
int sdoku[9][9];

// ��, ��, 3x3��Ͽ� �� ���ڰ� �����ϴ��� üũ�� bool �迭
bool checkR[9][10];
bool checkC[9][10];
bool checkS[9][10];

int zeros[81];
int n;

int fx(int i, int j){
	return i/3*3+j/3;
}

void solve(int idx){
	// ������ ���� ��� ��ĭ�� ���ؼ� ���縦 ������ �� 
	if( idx==n ){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				printf("%d ", sdoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int x = zeros[idx]/9;
	int y = zeros[idx]%9;
	
	for(int num=1; num<10; num++){
		// ��, ��, 3x3��� �� �ϳ����� �ش� ���ڰ� �����ϸ� ���� ���� �Ѿ��  
		if( checkR[x][num] || checkC[y][num] || checkS[fx(x, y)][num] )
			continue;
		checkR[x][num] = checkC[y][num] = checkS[fx(x, y)][num] = true;
		sdoku[x][y] = num;
		solve(idx+1);		// dfs 
		sdoku[x][y] = 0;	// ��Ʈ��ŷ 
		checkR[x][num] = checkC[y][num] = checkS[fx(x, y)][num] = false;
	}
}

int main()
{
	for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            scanf("%d", &sdoku[i][j]);
            int tmp = sdoku[i][j];
            // ��ĭ�� ������ i*9+j �� �����Ͽ� �����Ѵ�. 
            if (!tmp) zeros[n++] = i*9+j;
            else {
                checkR[i][tmp] = true;
                checkC[j][tmp] = true;
                checkS[fx(i,j)][tmp] = true;
            }
        }
    }
    solve(0);
    return 0;
}
