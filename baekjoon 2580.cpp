#include <cstdio>
#include <cstdlib>

// 모두 비워진 스도쿠 판 준비 
int sdoku[9][9];

// 행, 열, 3x3블록에 각 숫자가 존재하는지 체크할 bool 배열
bool checkR[9][10];
bool checkC[9][10];
bool checkS[9][10];

int zeros[81];
int n;

int fx(int i, int j){
	return i/3*3+j/3;
}

void solve(int idx){
	// 스도쿠 판의 모든 빈칸에 대해서 조사를 끝냈을 때 
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
		// 행, 열, 3x3블록 중 하나에라도 해당 숫자가 존재하면 다음 수로 넘어간다  
		if( checkR[x][num] || checkC[y][num] || checkS[fx(x, y)][num] )
			continue;
		checkR[x][num] = checkC[y][num] = checkS[fx(x, y)][num] = true;
		sdoku[x][y] = num;
		solve(idx+1);		// dfs 
		sdoku[x][y] = 0;	// 백트래킹 
		checkR[x][num] = checkC[y][num] = checkS[fx(x, y)][num] = false;
	}
}

int main()
{
	for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            scanf("%d", &sdoku[i][j]);
            int tmp = sdoku[i][j];
            // 빈칸의 정보를 i*9+j 로 압축하여 저장한다. 
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
