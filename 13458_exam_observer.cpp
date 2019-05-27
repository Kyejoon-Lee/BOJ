#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int arr[1000000];
int N;
int B, C;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] - B <= 0) {
			arr[i] = 0;
			cnt++;
			continue;
		}
		else {
			arr[i] -= B;
			cnt++;
			if (arr[i] % C == 0) {
				cnt += arr[i] / C;
			}
			else {
				cnt += arr[i] / C + 1;
			}
		}
	}
	printf("%lld", cnt);
	return 0;
}