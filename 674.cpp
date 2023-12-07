#include <cstdio>
#include <iostream>

using namespace std;

int main(){

	int N = 7490;
	static int Coins[4] = {5, 10, 25, 50};
	int Count[N] = {1, 1, 1, 1, 1};	
	
	for(int j = 5; j < N; j++)
		Count[j] = Count[j - 1];

	for(int j = 0; j < 4; j++)
		for(int i = Coins[j]; i < N; i++){
			Count[i] += Count[i - Coins[j]];
		}

	int index;
	while(scanf("%d", &index) == 1)
		printf("%d\n", Count[index]);

	return 0;
}
