#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int N, M;
char map[10][11];
char tmap[10][11];
int arr[10];
int cnt;
int bx, by, rx, ry;
void mapcopy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmap[i][j] = map[i][j];
		}
	}
}
/// up down left right
void go() {
	int btx = bx;
	int bty = by;
	int rtx = rx;
	int rty = ry;
	for (int i = 0; i < 10; i++) {
		int flag = 0;
		if (arr[i] == 0) {
			if (bty <= rty) {
				int j = 1;
				while (1) {
					if (tmap[bty - j][btx] == '.') {
						j++;
					}
					else if (tmap[bty - j][btx] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty - j + 1][btx] = 'B';
						bty = bty - j + 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[rty - j][rtx] == '.') {
						j++;
					}
					else if (tmap[rty - j][rtx] == 'O') {
						if (cnt > i) {
							cnt = i;
						}
						return;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty - j + 1][rtx] = 'R';
						rty = rty - j + 1;
						break;
					}
				}
			}
			else {
				int j = 1;
				while (1) {
					if (tmap[rty - j][rtx] == '.') {
						j++;
					}
					else if (tmap[rty - j][rtx] == 'O') {
						flag = 1;
						tmap[rty][rtx] = '.';
						break;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty - j + 1][rtx] = 'R';
						rty = rty - j + 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[bty - j][btx] == '.') {
						j++;
					}
					else if (tmap[bty - j][btx] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty - j + 1][btx] = 'B';
						bty = bty - j + 1;
						break;
					}
				}
			}
			if (flag == 1) {
				if (cnt > i) {
					cnt = i;
					return;
				}
			}
		}
		if (arr[i] == 1) {
			if (bty >= rty) {
				int j = 1;
				while (1) {
					if (tmap[bty + j][btx] == '.') {
						j++;
					}
					else if (tmap[bty + j][btx] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty + j - 1][btx] = 'B';
						bty += j - 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[rty + j][rtx] == '.') {
						j++;
					}
					else if (tmap[rty + j][rtx] == 'O') {
						if (cnt > i) {
							cnt = i;
						}
						return;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty + j - 1][rtx] = 'R';
						rty += j - 1;
						break;
					}
				}
			}
			else {
				int j = 1;
				while (1) {
					if (tmap[rty + j][rtx] == '.') {
						j++;
					}
					else if (tmap[rty + j][rtx] == 'O') {
						flag = 1;
						tmap[rty][rtx] = '.';
						break;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty + j - 1][rtx] = 'R';
						rty += j - 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[bty + j][btx] == '.') {
						j++;
					}
					else if (tmap[bty + j][btx] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty + j - 1][btx] = 'B';
						bty += j - 1;
						break;
					}
				}
			}
			if (flag == 1) {
				if (cnt > i) {
					cnt = i;
					return;
				}
			}
		}
		if (arr[i] == 2) {
			if (btx <= rtx) {
				int j = 1;
				while (1) {
					if (tmap[bty][btx - j] == '.') {
						j++;
					}
					else if (tmap[bty][btx - j] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty][btx - j + 1] = 'B';
						btx = btx - j + 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[rty][rtx - j] == '.') {
						j++;
					}
					else if (tmap[rty][rtx - j] == 'O') {
						if (cnt > i) {
							cnt = i;
						}
						return;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty][rtx - j + 1] = 'R';
						rtx = rtx - j + 1;
						break;
					}
				}
			}
			else {
				int j = 1;
				while (1) {
					if (tmap[rty][rtx - j] == '.') {
						j++;
					}
					else if (tmap[rty][rtx - j] == 'O') {
						flag = 1;
						tmap[rty][rtx] = '.';
						break;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty][rtx - j + 1] = 'R';
						rtx = rtx - j + 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[bty][btx - j] == '.') {
						j++;
					}
					else if (tmap[bty][btx - j] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty][btx - j + 1] = 'B';
						btx = btx - j + 1;
						break;
					}
				}
			}
			if (flag == 1) {
				if (cnt > i) {
					cnt = i;
					return;
				}
			}
		}
		if (arr[i] == 3) {
			if (btx >= rtx) {
				int j = 1;
				while (1) {
					if (tmap[bty][btx + j] == '.') {
						j++;
					}
					else if (tmap[bty][btx + j] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty][btx + j - 1] = 'B';
						btx = btx + j - 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[rty][rtx + j] == '.') {
						j++;
					}
					else if (tmap[rty][rtx + j] == 'O') {
						if (cnt > i) {
							cnt = i;
						}
						return;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty][rtx + j - 1] = 'R';
						rtx = rtx + j - 1;
						break;
					}
				}
			}
			else {
				int j = 1;
				while (1) {
					if (tmap[rty][rtx + j] == '.') {
						j++;
					}
					else if (tmap[rty][rtx + j] == 'O') {
						flag = 1;
						tmap[rty][rtx] = '.';
						break;
					}
					else {
						tmap[rty][rtx] = '.';
						tmap[rty][rtx + j - 1] = 'R';
						rtx = rtx + j - 1;
						break;
					}
				}
				j = 1;
				while (1) {
					if (tmap[bty][btx + j] == '.') {
						j++;
					}
					else if (tmap[bty][btx + j] == 'O') {
						return;
					}
					else {
						tmap[bty][btx] = '.';
						tmap[bty][btx + j - 1] = 'B';
						btx = btx + j - 1;
						break;
					}
				}
			}
			if (flag == 1) {
				if (cnt > i) {
					cnt = i;
					return;
				}
			}

		}
	}
}

void dfs(int num, int pre) {
	if (num == 10) {
		mapcopy();
		go();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (i == pre) {
			continue;
		}
		arr[num] = i;
		dfs(num + 1, i);
	}
}

int main() {
	cnt = 11;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'B') {
				by = i;
				bx = j;
			}
			if (map[i][j] == 'R') {
				rx = j;
				ry = i;
			}
		}
	}
	dfs(0, -1);
	if (cnt == 11) {
		cnt = -2;
	}
	printf("%d", cnt + 1);

}
