#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

deque<int>dq;


int map[21][21];
int dice[7] = { 0 };
int N, M, x, y, K;

void rolling() {
	int arr[5];
	arr[0] = 6;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 2;
	arr[4] = 5;

	while (!dq.empty()) {
		int di = dq.front();
		dq.pop_front();
		if (di == 1) {
			if (x + 1 >= M) {
				continue;
			}
			else {
				arr[2] = arr[0];
				arr[0] = arr[1];
				arr[1] = 7 - arr[2];
				if (map[y][x + 1] == 0) {
					map[y][x + 1] = dice[arr[0]];
				}
				else {
					dice[arr[0]] = map[y][x + 1];
					map[y][x + 1] = 0;
				}
				printf("%d\n", dice[7 - arr[0]]);
				x = x + 1;
			}
		}
		else if (di == 2) {
			if (x < 1) {
				continue;
			}
			else {
				arr[1] = arr[0];
				arr[0] = arr[2];
				arr[2] = 7 - arr[1];
				if (map[y][x - 1] == 0) {
					map[y][x - 1] = dice[arr[0]];
				}
				else {
					dice[arr[0]] = map[y][x - 1];
					map[y][x - 1] = 0;
				}
				printf("%d\n", dice[7 - arr[0]]);
				x = x - 1;
			}
		}
		else if (di == 3) {
			if (y < 1) {
				continue;
			}
			else {
				arr[4] = arr[0];
				arr[0] = arr[3];
				arr[3] = 7 - arr[4];
				if (map[y - 1][x] == 0) {
					map[y - 1][x] = dice[arr[0]];
				}
				else {
					dice[arr[0]] = map[y - 1][x];
					map[y - 1][x] = 0;
				}
				printf("%d\n", dice[7 - arr[0]]);
				y = y - 1;
			}

		}
		else {
			if (y + 1 >= N) {
				continue;
			}
			else {
				arr[3] = arr[0];
				arr[0] = arr[4];
				arr[4] = 7 - arr[3];
				if (map[y + 1][x] == 0) {
					map[y + 1][x] = dice[arr[0]];
				}
				else {
					dice[arr[0]] = map[y + 1][x];
					map[y + 1][x] = 0;
				}
				printf("%d\n", dice[7 - arr[0]]);
				y = y + 1;
			}
		}
	}
}

int main() {
	dq.clear();
	for (int i = 0; i < 7; i++) {
		dice[i] = 0;
	}
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		int temp;
		scanf("%d", &temp);
		dq.push_back(temp);
	}
	rolling();
	return 0;

}