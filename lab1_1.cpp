//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include "lab1_1.h"

using namespace std;

//function declarations
int add(int first[10][10], int sec[10][10]);
int subtract(int first[10][10], int sec[10][10]);
int multiply(int first[10][10], int sec[10][10]);


int main() {
	//variables initialization
	int a, b, d, first[10][10], sec[10][10], third[10][10];
	a = b = 2;
	int i = 0;
	int j = 0;
	char c;
	int q = 0;

	ifstream is("input.txt");          //opening the file.
	
	
	while (is.get(c)){          // loop getting single characters
		
		if (c == ','){			//next row separated by ,
			j = 0;				//column for next row intialized with 0
			i++;				//row incremented.
			
		}
		else if (c == '/'){		//second matrix starts after /
			//rows and columns initialize 0
			i = 0;				
			j = 0;
			//check variable to know the idex of matrix
			q = 1;

		}
		else if (c == '.'){   //third matrix starts after .
			//rows and columns initialize 0
			i = 0;
			j = 0;
			//check variable to know the index of matrix
			q = 2;
		}
		if (isdigit(c))  //if the character in file is an int 
		{
			if (q == 0){   //if first matrix
				first[i][j] = int(c - '0');		//save the retrieved character in first array
			}
			else if (q == 1){		//if second matrix
				sec[i][j] = int(c - '0');       //save the retrieved character in second array 
				
			}
			else{			//if third matrix
				third[i][j] = int(c - '0');	    //save the retrieved character in third array 
				
			
			}
			j++;   //column incremented
		}

	}

	is.close();     //file closed
	cout << '\n';
	int r;
	cout << "matrix 1:" << endl;
	//first matrix printed
	for (r = 0; r < 2; r++)
	{
		for (d = 0; d < 2; d++){
			cout << first[r][d] << "\t";
		}
		cout << endl;
	}

	//second matrix printed
	cout << endl;
	cout << "matrix 2:" << endl;
	for (r = 0; r < 2; r++)
	{
		for (d = 0; d < 2; d++){
			cout << sec[r][d] << "\t";
		}
		cout << endl;
	}

	//third matrix printed
	cout << endl;
	cout << "matrix 3:" << endl;
	for (r = 0; r < 2; r++)
	{
		for (d = 0; d < 2; d++){
			cout << third[r][d] << "\t";
		}
		cout << endl;
	}

	while (1){  
		cout << endl;
		cout << "Select one of the operations:" << endl;
		cout << "1:addition of 3 matrices " << endl;
		cout << "2:multiplication of 2 matrices " << endl;
		cout << "3:multiplication and addition of matrices" << endl;
		cout << "4: exit" << endl;
		int opt;

		cin >> opt;   //getting user input
		cout << endl;

		switch (opt){
		case 1:
			//calling add functions
			add(first, sec);
			add(sum1, third);		
			cout << "sum: " << endl;
			//printing the result of first option
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 2; j++)
				{
					cout << sum1[i][j] << '\t';			//sum1 is a global array
				}
				cout << "\n\n";
			}
			break;

		case 2:
			multiply(first, third);
			cout << "multiplication:" << endl;
			//printing the result of second option
			for (i = 0; i < 2; ++i)
			{
				for (j = 0; j < 2; ++j)
				{
					cout << sum2[i][j] << "\t";		//sum2 is a global array
				}
				cout << "\n";
			}
			break;

		case 3:
			multiply(first, sec);
			add(third, sum2);		//sum2 is global array storing result
			//printing the result of third option
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 2; j++)
				{
					cout << sum1[i][j] << '\t';		//add function stores result in a global array sum1
				}
				cout << "\n\n";
			}
			break;

		case 4:
			return 0;		//breaking the infinte loop
		}
	}
	return 0;
}
