#include <iostream>
#include <cstdio>

const unsigned int Upper = 1000002;

int same_numbers(char* bit_string, int lower, int upper){
	
	for(int i = lower; i < upper; ++i){
		if(bit_string[i] != bit_string[i + 1])
			return 0;
	}

	return 1;
}

int main(){

	char bit_string[Upper];
	int response, a, b, counter, lower, upper;
	int case_num = 1;

	while(scanf("%s %d", bit_string, &counter) == 2){

		std::cout << "Case " << case_num << ":" << std::endl;
		for(int i = 0; i < counter; ++i){

			scanf("%d%d", &a, &b);
			lower = std::min(a, b);
			upper = std::max(a, b);

			response = same_numbers(bit_string, lower, upper);

			if(response)
				std::cout << "Yes" << std::endl;
			else
				std::cout << "No" << std::endl;
		}

		case_num++;
	}

	return 0;
}
