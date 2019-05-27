#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

///14:30\

int map[51][51];
int N, M, cnt;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int backx[] = { 0,-1,0,1 };
int backy[] = { 1,0,-1,0 };
/// ¼­ 3 ³² 2 µ¿ 1 ºÏ 0
void go(int x, int y, int di) {
	while (1) {
		int flag = 0;
		int xpos;
		int ypos;
		for (int i = 1; i <= 4; i++) {
			xpos = x + dx[(di - i + 4) % 4];
			ypos = y + dy[(di - i + 4) % 4];
			if (xpos<0 || ypos<0 || xpos>M - 1 || ypos>N - 1 || map[ypos][xpos] == 1 || map[ypos][xpos] == -1) {
				continue;
			}
			if (map[ypos][xpos] == 0) {
				di = (di - i + 4) % 4;
				flag = 1;
				map[ypos][xpos] = -1;
				cnt++;
				break;

			}
		}
		if (flag == 1) {
			x = xpos;
			y = ypos;
			continue;
		}
		else if (flag == 0) {
			x = x + backx[di];
			y = y + backy[di];
			if (map[y][x] == 1) {
				break;
			}
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);
	int sx, sy, di;
	cnt = 0;
	scanf("%d %d %d", &sy, &sx, &di);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	map[sy][sx] = -1;
	cnt++;
	go(sx, sy, di);
	printf("%d", cnt);
	return 0;
}
/// 14:54\