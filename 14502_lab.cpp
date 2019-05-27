#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
/// 13:00;
using namespace std;

int map[9][9];
int visited[9][9];
int N, M, cnt;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

typedef struct {
	int x;
	int y;
}Node;


deque<Node>dq;
deque<Node>vir;


void mapcopy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = map[i][j];
		}
	}
}

void cal() {
	int tnum = 0;
	int size = dq.size();
	for (int i = 0; i < size; i++) {
		Node temp;
		temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
		for (int j = 0; j < 4; j++) {
			int x = temp.x + dx[j];
			int y = temp.y + dy[j];
			if (x <0 || y<0 || x>M - 1 || y>N - 1 || visited[y][x] == 2 || visited[y][x] == 1) {
				continue;
			}
			if (visited[y][x] == 0) {
				Node cur;
				cur.x = x;
				cur.y = y;
				vir.push_back(cur);
				visited[y][x] = 2;
				tnum++;
			}
		}
		while (!vir.empty()) {
			Node cur = vir.front();
			vir.pop_front();
			for (int j = 0; j < 4; j++) {
				int x = cur.x + dx[j];
				int y = cur.y + dy[j];
				if (x <0 || y<0 || x>M - 1 || y>N - 1 || visited[y][x] == 2 || visited[y][x] == 1) {
					continue;
				}
				if (visited[y][x] == 0) {
					Node ct;
					ct.x = x;
					ct.y = y;
					vir.push_back(ct);
					visited[y][x] = 2;
					tnum++;
				}
			}
		}
	}
	if (tnum < cnt) {
		cnt = tnum;
	}
}


void dfs(int cnt, int x, int y) {
	if (cnt == 3) {
		mapcopy();

		cal();
		return;
	}
	for (int i = y; i < N; i++) {
		if (i > y) {
			x = 0;
		}
		for (int j = x; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(cnt + 1, j, i);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	int sum = 0;
	cnt = 64;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				sum++;
			}
			else if (map[i][j] == 2) {
				Node temp;
				temp.x = j;
				temp.y = i;
				dq.push_back(temp);
			}
		}
	}
	dfs(0, 0, 0);
	sum = sum - 3 - cnt;
	printf("%d", sum);
	return 0;
}
///14:00;\