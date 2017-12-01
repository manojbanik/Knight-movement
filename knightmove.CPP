//	Finding movements of a knight

#include<iostream.h>
#include<stdlib.h>

#define	N	8

//FILE *f1;

int board[N][N] = {{0}};
int rx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int cx[] = {1, 2, 2, 1, -1, -2, -2, -1};

void knight(int i, int j, int move);

void main(void)
{
	int row, col;

	cout << "\tGive initial row & column :: ";
	cin >> row >> col;

	board[row-1][col-1] = 1;

	knight(row-1, col-1, 1);

}

void knight(int i, int j, int move)
{
	int k;

	if(move == 64) {
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++)
				cout << board[i][j] << "\t";
			cout << "\n";
		}

		//exit(0);
	}
	else {

		for(k=0; k<8; k++) {
			if((i+rx[k] > -1 && i+rx[k] < 8) &&
			   (j+cx[k] > -1 && j+cx[k] < 8) && !board[i+rx[k]][j+cx[k]]) {

					board[i+rx[k]][j+cx[k]] = move+1;
					knight(i+rx[k], j+cx[k], move+1);
			}
		}

		board[i][j] = 0;

	}


}