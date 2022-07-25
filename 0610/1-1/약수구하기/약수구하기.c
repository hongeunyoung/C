#include <stdio.h>

int main(void) {
	int N, K;
	int count = 0, answer = 0;

	scanf_s("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			count++;

			//K번째 약수를 만나면 answer에 그 약수를 저장하고 for문 종료.
			if (count == K) {
				answer = i;
				break;
			}
		}
	}

	//answer 초기화를 0으로 해서 K번째 약수가 없으면 0이 출력되도록 한다.
	printf("%d", answer);
	return 0;
}