#include <iostream>
#include <math.h>
#include <cstdlib>
#include <limits>

using namespace std;

double ** approximation(int tabx[], int taby[], int ammount_of_points, int degree_of_polynomial);

int main()
{
	
	int degree_of_polynomial = 2;
	int ammount_of_points = 4;
	int tabx[] = { -4, 0, 2, 4 };
	int taby[] = { 16,0,5,15, };
	
	int degree_of_polynomial1 = 3;
	int ammount_of_points1 = 10;
	int tab1x[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 5 };
	int tab1y[]= { -110, -60, -20, -10, -1.5, 2, 7, 18, 50, 170 };
	
	double** result_of_approximation;
	result_of_approximation = approximation(tabx, taby, ammount_of_points, degree_of_polynomial);


	system("pause");
}

double ** approximation(int tabx[], int taby[], int ammount_of_points, int degree_of_polynomial)
{
	double** result = new double *[degree_of_polynomial + 1];
	for (int i = 0; i <= degree_of_polynomial; i++)
	{
		result[i] = new double[degree_of_polynomial + 2];
	}
	
	for (int j = 0; j <= degree_of_polynomial; j++)
	{
		for (int k = 0; k <= degree_of_polynomial+1; k++)
		{
			result[j][k] =0;
			
		}
	}
	
	
	for (int j = 0; j <= degree_of_polynomial; j++)
	{
		for (int k = 0; k <= degree_of_polynomial + 1; k++)
		{
			if (k == degree_of_polynomial + 1)
			{
				for (int i = 0; i < ammount_of_points; i++)
				{
					double tmp = 0.0;
					tmp = pow(tabx[i], j)*taby[i];
					result[j][k] += tmp;
				}
			}
			else
			{
				for (int i = 0; i < ammount_of_points; i++)
				{
					double tmp =0.0;
					tmp = pow(tabx[i], j)*pow(tabx[i], k);
					result[j][k] += tmp;
				}
			}


		}
	}

	for (int j = 0; j <= degree_of_polynomial; j++)
	{
		for (int k = 0; k <= degree_of_polynomial+1; k++)
		{
			if (k == degree_of_polynomial + 1)
			{
				cout << "  =  " << (double) result[j][k];
			}
			else
			{
				cout << (double) result[j][k] << " a" << k << "  +  ";
			}
			
			
		}
		cout << endl;
	}

	return result;
}