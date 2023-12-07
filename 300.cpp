#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){

	// 19 Months of Haab
	map<string, int> haab;	
	haab["pop"] = 0;
	haab["no"] = 1;
	haab["zip"] = 2;
	haab["zotz"] = 3;
	haab["tzec"] = 4;
	haab["xul"] = 5;
	haab["yoxkin"] = 6;
	haab["mol"] = 7;
	haab["chen"] = 8;
	haab["yax"] = 9;
	haab["zac"] = 10;
	haab["ceh"] = 11;
	haab["mac"] = 12;
	haab["kankin"] = 13;
	haab["muan"] = 14;
	haab["pax"] = 15;
	haab["koyab"] = 16;
	haab["cumhu"] = 17;
	haab["uayet"] = 18;

	// 20 Days of Tzolkin (without +1 offset)
	string tzolkin [20] = {
		"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",
		"ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
	};	

	// Haab year
	int haab_day;
	string haab_month;
	int year;

	// Tzolkin year
	int tzolkin_day_number;
	string tzolkin_day_name;

	int num_of_dates;
	cin >> num_of_dates;
	cout << num_of_dates << endl;

	for(int i = 0; i < num_of_dates; i++){
		
		cin >> haab_day;
		cin.ignore(1, '.');
		cin >> haab_month >> year;

		long days = haab_day + haab[haab_month] * 20 + year * 365;
		cout << days % 13 + 1 << " " << tzolkin[days % 20] << " "  << days / 260 << endl;
	}
	
	return 0;
}
