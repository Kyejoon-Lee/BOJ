#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	int age;
	int num;
}Node;

deque<Node>dq[11][11];
int nut[11][11];
int curnut[11][11];
int tnut[11][11];
int N, M, K;
int tmap[11][11];
int dx[] = { -1,0,1 };
int dy[] = { -1,0,1 };


void ss() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int size = dq[i][j].size();
			for (int k = 0; k < size; k++) {
				Node temp = dq[i][j].front();
				dq[i][j].pop_front();
				int num = temp.num;
				int set = 0;
				if (temp.age * temp.num <= curnut[i][j]) {
					curnut[i][j] -= temp.age * temp.num;
					temp.age++;
					if (temp.age % 5 == 0) {
						for (int a = 0; a < 3; a++) {
							for (int b = 0; b < 3; b++) {
								int xpos = j + dx[a];
								int ypos = i + dy[b];
								if (ypos <1 || xpos <1 || xpos >N || ypos >N || (a == 1 && b == 1)) {
									continue;
								}
								tmap[ypos][xpos] += temp.num;
							}
						}
					}
					dq[i][j].push_back(temp);
				}
				else {
					for (int n = 0; n < num; n++) {
						if (temp.age <= curnut[i][j]) {
							curnut[i][j] -= temp.age;
							temp.num--;
							set++;
						}
						else {
							tnut[i][j] += temp.num*(temp.age / 2);
							if (set > 0) {
								temp.age++;
								temp.num = set;
								if (temp.age % 5 == 0) {
									for (int a = 0; a < 3; a++) {
										for (int b = 0; b < 3; b++) {
											int xpos = j + dx[a];
											int ypos = i + dy[b];
											if (ypos <0 || xpos <0 || xpos >N || ypos >N || (a == 1 && b == 1)) {
												continue;
											}
											tmap[ypos][xpos] += temp.num;
										}
									}
								}
								dq[i][j].push_back(temp);
							}
							break;
						}
					}
				}
			}
			curnut[i][j] += tnut[i][j];
			tnut[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tmap[i][j] >0) {
				Node cur;
				cur.age = 1;
				cur.num = tmap[i][j];
				dq[i][j].push_front(cur);
				tmap[i][j] = 0;
			}
			curnut[i][j] += nut[i][j];
		}
	}

}



int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &nut[i][j]);
			curnut[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		Node cur;
		cur.num = 1;
		scanf("%d %d %d", &a, &b, &cur.age);
		dq[a][b].push_back(cur);
	}
	for (int i = 0; i < K; i++) {
		ss();
	}
	int all = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			while (!dq[i][j].empty()) {
				Node cur = dq[i][j].front();
				dq[i][j].pop_front();
				all += cur.num;
			}
		}
	}
	printf("%d", all);
	return 0;
}