#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
int map[21][21];
int N;
int cpos[21];
int res;
void cal() {
	int t1 = 0;
	int t2 = 0;
	for (int i = 1; i <= N; i++) {
		if (cpos[i] == 0) {
			for (int j = 1; j <= N; j++) {
				if (cpos[j] == 0) {
					t1 += map[i][j];
				}
			}
		}
		else {
			for (int j = 1; j <= N; j++) {
				if (cpos[j] == 1) {
					t2 += map[i][j];
				}
			}
		}
	}
	if (res > abs(t1 - t2)) {
		res = abs(t1 - t2);
	}
}

void dfs(int cnt, int pos) {
	if (cnt == N / 2) {
		cal();
		return;
	}
	if (cnt > N / 2 || N - pos <N / 2 - cnt) {
		return;
	}
	cpos[pos] = 1;
	dfs(cnt + 1, pos + 1);
	cpos[pos] = 0;
	dfs(cnt, pos + 1);
}

int main() {
	res = 400000;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 1);
	printf("%d", res);
	return 0;
}