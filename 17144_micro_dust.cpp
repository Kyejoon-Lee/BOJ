#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	int x;
	int y;
}Node;

deque<Node>dq;


int map[51][51];
int temp[51][51];
int R, C, T;
int uy, dy;
int px[] = { 0,0,-1,1 };
int py[] = { -1,1,0,0 };

void init(int n) {
	if (n == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				temp[i][j] = 0;
			}
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = 0;
			}
		}
	}
}

void spread() {
	init(1);
	int size = dq.size();
	for (int i = 0; i < size; i++) {
		Node cur = dq.front();
		dq.pop_front();
		int cnt = 0;
		if (map[cur.y][cur.x] / 5 > 0) {
			for (int i = 0; i < 4; i++) {
				int xpos = cur.x + px[i];
				int ypos = cur.y + py[i];
				if (xpos < 0 || ypos <0 || xpos >C - 1 || ypos >R - 1 || (xpos == 0 && (ypos == uy || ypos == dy))) {
					continue;
				}
				if (temp[ypos][xpos] == 0) {
					Node t;
					t.x = xpos;
					t.y = ypos;
					dq.push_back(t);
				}
				temp[ypos][xpos] += (map[cur.y][cur.x] / 5);
				cnt++;
			}
			if (temp[cur.y][cur.x] == 0) {
				dq.push_back(cur);
			}
			temp[cur.y][cur.x] += map[cur.y][cur.x] - (map[cur.y][cur.x] / 5) * cnt;
		}
		else {
			if (temp[cur.y][cur.x] == 0) {
				dq.push_back(cur);
			}
			temp[cur.y][cur.x] += map[cur.y][cur.x];
		}
	}
}
void move() {
	init(0);
	int size = dq.size();
	for (int i = 0; i < size; i++) {
		Node cur = dq.front();
		dq.pop_front();
		if (cur.x == 0) {
			if (cur.y < uy) {
				if (cur.y == uy - 1) {
					continue;
				}
				else {
					map[cur.y + 1][cur.x] = temp[cur.y][cur.x];
					cur.y++;
					dq.push_back(cur);
					continue;
				}
			}
			else {
				if (cur.y == dy + 1) {
					continue;
				}
				else {
					map[cur.y - 1][cur.x] = temp[cur.y][cur.x];
					cur.y--;
					dq.push_back(cur);
					continue;
				}
			}
		}
		if (cur.x == C - 1) {
			if (cur.y <= uy) {
				if (cur.y != 0) {
				
					map[cur.y - 1][cur.x] = temp[cur.y][cur.x];
					cur.y--;
					dq.push_back(cur);
					continue;
				}
			}
			else {
				if (cur.y != R - 1) {

					map[cur.y + 1][cur.x] = temp[cur.y][cur.x];
					cur.y++;
					dq.push_back(cur);
					continue;
				}
			}
		}
		if (cur.y == 0 || cur.y == R - 1) {
			if (cur.x == 0) {
				continue;
			}
			map[cur.y][cur.x - 1] = temp[cur.y][cur.x];
			cur.x--;
			dq.push_back(cur);
			continue;
		}
		if (cur.y == dy || cur.y == uy) {
			if (cur.x == C - 1) {
				continue;
			}
			map[cur.y][cur.x + 1] = temp[cur.y][cur.x];
			cur.x++;
			dq.push_back(cur);
			continue;
		}
		map[cur.y][cur.x] = temp[cur.y][cur.x];
		dq.push_back(cur);
	}
}

int main() {
	uy = -1;
	dy = -1;
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				if (uy < 0) {
					uy = i;
				}
				else {
					dy = i;
				}
			}
			else if (map[i][j] > 0) {
				Node cur;
				cur.x = j;
				cur.y = i;
				dq.push_back(cur);
			}
		}
	}
	for (int i = 0; i < T; i++) {
		spread();
		move();
	}
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cnt += map[i][j];
		}
	}
	printf("%d", cnt);
	return 0;
}