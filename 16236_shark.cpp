#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	int x;
	int y;
	int time;
}Node;

deque<Node>dq;

int N;
int sx, sy;
int fsize;
int eat;
int sum;
int map[21][21];
int visited[21][21];
int dist[21][21];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

/// 14:30;

void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] > 0) {
				sx = j;
				sy = i;
				eat++;
				sum += dist[i][j];
				map[i][j] = 0;
				if (eat == fsize) {
					eat = 0;
					fsize++;
				}
				return;
			}
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
			dist[i][j] = 0;
		}
	}
}
int go() {
	int cdist = 400;
	int flag = 0;
	while (!dq.empty()) {
		Node cur = dq.front();
		int x = cur.x;
		int y = cur.y;
		if (visited[y][x] == 1) {
			dq.pop_front();
			continue;
		}
		if (cur.time > cdist) {
			break;
		}
		if (map[y][x] > 0 && map[y][x] < fsize) {
			dist[y][x] = cur.time;
			cdist = cur.time;
			flag = 1;
			dq.pop_front();
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int xpos = x + dx[i];
			int ypos = y + dy[i];
			if (xpos < 0 || ypos <0 || xpos>N - 1 || ypos >N - 1 || map[ypos][xpos] >fsize || visited[ypos][xpos] == 1) {
				continue;
			}
			Node temp;
			temp.x = xpos;
			temp.y = ypos;
			temp.time = cur.time + 1;
			dq.push_back(temp);
		}
		visited[y][x] = 1;
		dq.pop_front();
	}
	if (flag == 1) {
		check();
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				sx = j;
				sy = i;
				map[i][j] = 0;
			}
		}
	}
	eat = 0;
	fsize = 2;
	sum = 0;
	while (1) {
		dq.clear();
		init();
		Node cur;
		cur.x = sx;
		cur.y = sy;
		cur.time = 0;
		dq.push_back(cur);
		if (go()) {
			continue;
		}
		else {
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}