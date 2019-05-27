#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


typedef struct {
	int x;
	int y;

}Node;

vector<int>v;
vector<Node>home;
vector<Node>chicken;

/// 15:45;
int N, M;
int map[51][51];
int tmap[51][51][14];
int sum;

void check() {
	int tcnt = 0;
	for (int i = 0; i < home.size(); i++) {
		int tt = 450;
		for (int j = 0; j < v.size(); j++) {
			if (tmap[home[i].y][home[i].x][v[j]] < tt) {
				tt = tmap[home[i].y][home[i].x][v[j]];
			}
		}
		tcnt += tt;
	}
	if (tcnt < sum) {
		sum = tcnt;
	}
}

void cal() {
	for (int i = 0; i < home.size(); i++) {
		Node cur = home[i];
		for (int j = 0; j < chicken.size(); j++) {
			Node temp = chicken[j];
			tmap[cur.y][cur.x][j] = abs(cur.x - temp.x) + abs(cur.y - temp.y);
		}
	}
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < chicken.size(); k++) {
				tmap[i][j][k] = 0;
			}
		}
	}
}

void dfs(int cnt, int num) {
	if (cnt == M) {
		check();
		return;
	}
	if (num == chicken.size()) {
		return;
	}
	v.push_back(num);
	dfs(cnt + 1, num + 1);
	v.pop_back();
	dfs(cnt, num + 1);

}
int main() {
	v.clear();
	home.clear();
	chicken.clear();
	sum = 1e10;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				Node cur;
				cur.x = j;
				cur.y = i;
				home.push_back(cur);
			}
			if (map[i][j] == 2) {
				Node cur;
				cur.x = j;
				cur.y = i;
				chicken.push_back(cur);
			}
		}
	}
	init();
	cal();
	dfs(0, 0);
	printf("%d", sum);
	return 0;
}