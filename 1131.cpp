#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int DFS_light(map<int, vector<int>>, int p, int q){

	return 0;
}

int main(){

	int primes, sets, p, q;
	int squares = 0;

	while(scanf("%d %d", &primes, &sets) == 2){
		
		map<int, vector<int>> collection;

		for(int i = 0; i < sets; i++){
			
			cin >> p;
			cin >> q;

			// Add node p if not availalbe with q in adjacency list
			bool lower = true;
			if(collection.find(p) == collection.end()){
				vector<int> vec;
				vec.push_back(q);
				collection[p] = vec;
				lower = false;
			}

			// Add node q if not available with empty adjacency list
			if(collection.find(q) == collection.end()){
				vector<int> vec;
				collection[q] = vec;
				break;
			}

			if(!lower)
				break;


			// Check if same set already exists
			vector<int> vec = collection[p];
			if(find(vec.begin(), vec.end(), q) != vec.end()){
				squares++;
				break;
			}

			// DFS light

			// Add node to current vec
			vec.push_back(q);
			
		     	// If square found remove nodes
			if(DFS_light(collection, p, q))
				squares++;

		}
	

	cout << squares << endl;
	squares = 0;

	}	

	return 0;
}
