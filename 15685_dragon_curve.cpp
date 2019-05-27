#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int>v;

int map[101][101] = { 0 };
int N, x, y;
int check = 0;
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
void curving() {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		int d = v.at(size - i - 1);
		d = (d + 1) % 4;
		if (d == 0) {
			x = x + 1;
		}
		if (d == 1) {
			y = y - 1;
		}
		if (d == 2) {
			x = x - 1;
		}
		if (d == 3) {
			y = y + 1;
		}
		map[y][x] = 1;
		v.push_back(d);
	}
}

void checking() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			int flag = 0;
			for (int k = 0; k < 4; k++) {
				int xpos = j + dx[k];
				int ypos = i + dy[k];
				if (map[ypos][xpos] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				check++;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int d, g;
		v.clear();
		scanf("%d %d %d %d", &x, &y, &d, &g);
		v.push_back(d);
		for (int j = 0; j <= g; j++) {
			if (j == 0) {
				map[y][x] = 1;
				if (d == 0) {
					x = x + 1;
				}
				if (d == 1) {
					y = y - 1;
				}
				if (d == 2) {
					x = x - 1;
				}
				if (d == 3) {
					y = y + 1;
				}
				map[y][x] = 1;
				continue;
			}
			curving();
		}
	}
	checking();
	printf("%d", check);
	return 0;
}