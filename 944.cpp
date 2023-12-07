#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int square(int num){
	
	return num * num;
}

int check_if_happy(int num){

	int cycle_num = 1, current_num = num, s = 0;
	int result;

	while(current_num != 1 && current_num != 4){

		// Compute s
		while(current_num){
			s += square(current_num%10);
			current_num /= 10;
		}

		current_num = s;
		s = 0;
		cycle_num++;
	}

	result = current_num == 1 ? cycle_num : 0;

	return result;
}

int main(){

	int lower, upper, result;

	// Calculate all pairs of happy_numbers, cycles
	map<int, int> mp;
	for(int i = 1; i <= 99999; i++){
		mp[i] = check_if_happy(i);
	}

	int flag = 0;
	while(scanf("%d %d", &lower, &upper) == 2){
		if(flag)
			puts("");
		flag = 1;

		for(int i = lower; i <= upper; i++){
			result = mp[i];
			if(result != 0)
				printf("%d %d\n", i, result);
		}
	}

	return 0; 
}
