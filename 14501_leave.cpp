#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	int day;
	int dis;
	int money;
}Node;

vector<Node>dq;
vector<Node>v;
int N;
int cont = 0;
void cal() {
	int sum = 0;
	for (int i = 0; i < dq.size(); i++) {
		sum += dq[i].money;
	}
	if (sum > cont) {
		cont = sum;
	}
}

void dfs(int cnt) {
	if (cnt == N) {
		cal();
		return;
	}
	if (cnt > N) {
		return;
	}
	Node cur = v[cnt];
	dq.push_back(cur);
	dfs(cnt + cur.day);
	dq.pop_back();
	dfs(cnt + 1);
}

int main() {
	cont = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		Node temp;
		scanf("%d %d", &temp.day, &temp.money);
		v.push_back(temp);
	}
	dfs(0);
	printf("%d", cont);
}