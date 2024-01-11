#include <iostream>

const unsigned int N = 100000;

int main(){

	int year;
	unsigned int *male_bees = new unsigned int[N];
	unsigned int *female_bees = new unsigned int[N];

	male_bees[0] = 0;
	female_bees[0] = 1;
	for(unsigned int i = 1; i < N; ++i){
		female_bees[i] = male_bees[i - 1] + 1;
		male_bees[i] = male_bees[i - 1] + female_bees[i - 1];
	}

	while(1){
		
		std::cin >> year;
		if(year == -1)
			break;

		std::cout << male_bees[year] << " " << male_bees[year] + female_bees[year] << std::endl;
	}

	delete[] male_bees;
	delete[] female_bees;

	return 0;
}
