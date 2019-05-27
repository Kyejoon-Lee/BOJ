#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	int x;
	int y;
	int di;
	int mode;

}Node;

vector<Node>v;
vector<Node>tv;
int N, M;
int cnt;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int map[9][9];
int visited[9][9];

void mapcopy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = map[i][j];
		}
	}
}

void cal() {
	for (int i = 0; i < tv.size(); i++) {
		Node cur = tv[i];
		int t = 1;
		if (cur.mode == 1) {
			while (1) {
				int xpos = cur.x + t * dx[cur.di];
				int ypos = cur.y + t * dy[cur.di];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
		}
		else if (cur.mode == 2) {
			int t = 1;
			while (1) {
				int xpos = cur.x + t * dx[cur.di];
				int ypos = cur.y + t * dy[cur.di];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
			t = 1;
			while (1) {
				int xpos = cur.x + t * dx[cur.di + 2];
				int ypos = cur.y + t * dy[cur.di + 2];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
		}
		else if (cur.mode == 3) {
			int t = 1;
			while (1) {
				int xpos = cur.x + t * dx[cur.di];
				int ypos = cur.y + t * dy[cur.di];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
			t = 1;
			while (1) {
				int xpos = cur.x + t * dx[(cur.di + 1) % 4];
				int ypos = cur.y + t * dy[(cur.di + 1) % 4];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
		}
		else if (cur.mode == 4) {
			int t = 1;
			while (1) {
				int xpos = cur.x + t * dx[cur.di];
				int ypos = cur.y + t * dy[cur.di];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
			t = 1;
			while (1) {
				int xpos = cur.x + t * dx[(cur.di + 1) % 4];
				int ypos = cur.y + t * dy[(cur.di + 1) % 4];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
			t = 1;
			while (1) {
				int xpos = cur.x + t * dx[(cur.di + 2) % 4];
				int ypos = cur.y + t * dy[(cur.di + 2) % 4];
				if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
					break;
				}
				visited[ypos][xpos] = -1;
				t++;
			}
		}
		else if (cur.mode == 5) {
			for (int j = 0; j < 4; j++) {
				int t = 1;
				while (1) {
					int xpos = cur.x + t * dx[j];
					int ypos = cur.y + t * dy[j];
					if (xpos <0 || ypos <0 || xpos >M - 1 || ypos >N - 1 || visited[ypos][xpos] > 0) {
						break;
					}
					visited[ypos][xpos] = -1;
					t++;
				}
			}
		}
	}
	int tcnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				tcnt++;
			}
		}
	}
	if (tcnt < cnt) {
		cnt = tcnt;
	}
}

void dfs(int num) {
	if (num == v.size()) {
		mapcopy();
		cal();
		return;
	}
	Node temp = v[num];
	if (v[num].mode == 2) {
		for (int i = 0; i < 2; i++) {
			temp.di = i;
			tv.push_back(temp);
			dfs(num + 1);
			tv.pop_back();
		}
	}
	else if (v[num].mode == 5) {
		temp.di = 0;
		tv.push_back(temp);
		dfs(num + 1);
		tv.pop_back();
	}
	else {
		for (int i = 0; i < 4; i++) {
			temp.di = i;
			tv.push_back(temp);
			dfs(num + 1);
			tv.pop_back();
		}
	}
}

int main() {
	v.clear();
	tv.clear();
	cnt = 100;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > 0 && map[i][j] < 6) {
				Node cur;
				cur.x = j;
				cur.y = i;
				cur.mode = map[i][j];
				v.push_back(cur);
			}
		}
	}
	dfs(0);
	printf("%d\n", cnt);
	return 0;
}