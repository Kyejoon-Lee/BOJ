#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

///15:15;
using namespace std;

int map[102][102];
int N, K, L;
int dx[] = { 0,1,0,-1,0 };
int dy[] = { 0 ,0,-1,0,1 };
typedef struct {
	int di;
	int time;
}Node;

deque<Node>dq;
int cnt;
void go() {
	int time = 0;
	int di = 1;
	int hx = 1;
	int hy = 1;
	int ex = 1;
	int ey = 1;
	while (!dq.empty()) {
		Node cur = dq.front();
		dq.pop_front();
		for (int i = time; i < cur.time; i++) {
			int xpos = hx + dx[di];
			int ypos = hy + dy[di];
			if (map[ypos][xpos] == 1) {
				map[ypos][xpos] = 0;
				map[hy][hx] = -di;
			}
			else if (map[ypos][xpos] < 0 || xpos == 0 || ypos == 0 || xpos == N + 1 || ypos == N + 1) {
				cnt = i + 1;
				return;
			}
			else if (map[ypos][xpos] == 0) {
				map[hy][hx] = -di;
				int tt = map[ey][ex];
				map[ey][ex] = 0;
				ey = ey + dy[-tt];
				ex = ex + dx[-tt];
			}
			hy = ypos;
			hx = xpos;

		}
		di = (di + cur.di) % 4;
		if (di == 0) {
			di = 4;
		}
		time = cur.time;
	}
}

int main() {
	dq.clear();
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d %d", &y, &x);
		map[y][x] = 1;
	}
	scanf("%d", &L);
	Node temp;
	for (int i = 0; i < L; i++) {
		int time;
		char di;
		scanf("%d %c", &time, &di);
		if (di == 'L') {
			temp.di = 1;
		}
		else {
			temp.di = -1;
		}
		temp.time = time;
		dq.push_back(temp);
	}
	temp.time = temp.time + 110;
	dq.push_back(temp);
	go();
	printf("%d", cnt);
	return 0;
}