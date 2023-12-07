#include <iostream>
#include <cstdio>

using namespace std;

int catcher_missile(){

	int max_interceptions = 0;

	return max_interceptions;
}

int main(){

	int first_input, height, A[10000];
	int num_missiles = 0;
	int test_num = 0;	

	while(1){
		
		num_missiles = 0;
		cin >> first_input; 
		if(first_input < 0)
			break;

		A[num_missiles] = first_input;
		num_missiles++;
		test_num++;
		while(cin >> height){
			
			if(height < 0)
				break;

			A[num_missiles] = height;
			num_missiles++;
		}

		int Missile[num_missiles + 1][num_missiles +1];
		
		// Base
		for(int i = 0; i <= num_missiles; i++){
			for(int j = 0; j <= num_missiles; j++){
				Missile[j][i] = 0;
				Missile[i][j] = 0;
			}
		}

		// Iterate over the current height of the missile
		for(int j = 1; j <= num_missiles; j++){

			// Calculate the index of max interceptions that 
			// can end up at current height A[j-1]
			int current_max_until_current_heigth = 0;
			for(int i = 0; i < j; i++){	
				if(A[j-1] < A[i-1]){

					// Current missile is = current heigth
					// Check in the same row if higher missels drop down to increase
					if(current_max_until_current_heigth < Missile[j][i] + 1)
						current_max_until_current_heigth = Missile[j][i] + 1;
				}
			}

			if(current_max_until_current_heigth == 0)
				current_max_until_current_heigth = 1;

			for(int i = j; i <= num_missiles; i++)
				Missile[i][j] = current_max_until_current_heigth;
		}

		int max_number_of_missiles = 0;
		for(int j = 0; j <= num_missiles; j++){
			if(max_number_of_missiles < Missile[num_missiles][j])
				max_number_of_missiles = Missile[num_missiles][j];
		}

		cout << "Test #" << test_num << ":"; << endl;
		cout << "  maximum possible interceptions: " << max_number_of_missiles << "\n" << endl;

	}
	return 0;
}
