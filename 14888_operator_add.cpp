#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

int input[12];
int cal[4];
int visited[11];

int N;
int size = 0;
int mini = 2000000000;
int maxi = -2000000000;

int boom() {
	int cnt = input[0];
	for (int i = 0; i < size - 1; i++) {
		if (visited[i] == 0) {
			cnt += input[i + 1];
		}
		if (visited[i] == 1) {
			cnt -= input[i + 1];
		}
		if (visited[i] == 2) {
			cnt = cnt * input[i + 1];
		}
		if (visited[i] == 3) {
			if (input[i + 1] == 0) {
				return false;
			}
			if ((cnt < 0 && input[i + 1] < 0) || (cnt > 0 && input[i + 1] > 0)) {
				cnt = cnt / input[i + 1];
			}
			else {
				cnt = -(abs(cnt) / abs(input[i + 1]));
			}
		}
	}
	return cnt;
}

void queing(int time) {
	if (time == size - 1) {
		int temp = boom();
		if (maxi < temp) {
			maxi = temp;
		}
		if (mini > temp) {
			mini = temp;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cal[i] > 0) {
			visited[time] = i;
			cal[i]--;
			queing(time + 1);
			cal[i]++;
		}
	}
}

int main() {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	size = i;
	for (int j = 0; j < 4; j++) {
		scanf("%d", &cal[j]);
	}
	queing(0);
	printf("%d\n%d", maxi, mini);
	return 0;
}
