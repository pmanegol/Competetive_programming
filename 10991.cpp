#include <cmath>
#include <iostream>

#define CONV 180 / M_PI

using namespace std;

int calculate_angle_law_of_cosines(){
	
	return 0;
}

double area_of_sector(double angle, double radius){
	
	return (angle / 360) * M_PI * radius * radius;
}

double area_of_triangle(double h, double w){
	
	return (h * w) / 2;	
}

double degree_from_radian(double radian){

	return radian * CONV;
};

int main(){
	
	int num_cases = 0;
	double r1, r2, r3;
	
	// Angles
	double Alpha, alpha, beta, gamma;

	// Sides of triangle
	double a, b, c, x1, x2, y;
	double a_square, b_square, c_square;

	// Sectors
	double S1, S2, S3;

	// Area of triangle
	double D;

	// Area to be calculated
	double G;

	cin >> num_cases;

	for(int i = 0; i < num_cases; ++i){
		
		cin >> r1 >> r2 >> r3;
		
		c = r1 + r2;
		b = r1 + r3;
		a = r2 + r3;

		a_square = a * a;
		b_square = b * b;
		c_square = c * c;

		Alpha = acos((b_square + c_square - a_square) / (2 * b * c));
		alpha = degree_from_radian(Alpha);
		beta = degree_from_radian(acos((a_square + c_square - b_square) / (2 * a * c)));
		gamma = 180 - alpha - beta;
		
		S1 = area_of_sector(alpha, r1);
		S2 = area_of_sector(beta, r2);
		S3 = area_of_sector(gamma, r3);

		y = sin(Alpha) * b;
		x1 = sqrt(b_square - y * y);
		x2 = c - x1;

		D = area_of_triangle(y, x1) + area_of_triangle(y, x2);

		G = D - S1 - S2 - S3;

		printf("%.6lf\n", G);

	};
	
	return 0;
}
