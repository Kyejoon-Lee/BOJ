#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<deque>
using namespace std;

typedef struct {
	int x;
	int y;

}Node;
deque<Node>dq;
deque<Node>tq;

int N, L, R;

int map[50][50];
int visited[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int flag;
int cnt = 0;

void go() {
	int sum = 0;
	int num = 0;
	while (!tq.empty()) {
		Node temp = tq.front();
		tq.pop_front();
		num++;
		sum += map[temp.y][temp.x];
		visited[temp.y][temp.x] = 1;
		for (int i = 0; i < 4; i++) {
			int xpos = temp.x + dx[i];
			int ypos = temp.y + dy[i];
			if (xpos<0 || ypos <0 || xpos>N - 1 || ypos >N - 1 || visited[ypos][xpos] >0) {
				continue;
			}
			if (abs(map[ypos][xpos] - map[temp.y][temp.x]) >= L && abs(map[ypos][xpos] - map[temp.y][temp.x]) <= R) {
				Node cur;
				cur.x = xpos;
				cur.y = ypos;
				tq.push_back(cur);
				dq.push_back(cur);
				visited[ypos][xpos] = 1;
			}
		}
	}
	int size = dq.size();
	if (size > 1) {
		flag = 1;
	}
	sum = sum / num;
	while (!dq.empty()) {
		Node cur = dq.front();
		dq.pop_front();
		visited[cur.y][cur.x] = sum;
	}
}
int get() {
	flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				dq.clear();
				tq.clear();
				Node cur;
				cur.x = j;
				cur.y = i;
				dq.push_back(cur);
				tq.push_back(cur);
				go();
			}
		}
	}

	if (flag == 1) {
		cnt++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = visited[i][j];
				visited[i][j] = 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}

}


int main() {
	cnt = 0;
	dq.clear();
	tq.clear();
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < 2000; i++) {
		if (!get()) {
			break;
		}
	}
	printf("%d", cnt);
	return 0;
}