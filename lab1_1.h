using namespace std;
//global array storing results
int sum1[10][10];
int sum2[10][10];

//add function
int add(int first[10][10], int sec[10][10]){
	int i, j;
	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{
			sum1[i][j] = first[i][j] + sec[i][j];
		}
	}
	return 0;
}

//subtract function
int subtract(int first[10][10], int sec[10][10]){
	int i, j;
	int sum[10][10];
	cout << "subtract:" << endl;
	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{
			sum[i][j] = sec[i][j] - first[i][j];
			cout << sum[i][j] << '\t';
		}
		cout << "\n\n";
	}
	return 0;
}

//multiply function
int multiply(int first[10][10], int sec[10][10]){
	int i, j, k;
	for (i = 0; i<2; ++i)
	{
		for (j = 0; j<2; ++j)
		{
			sum2[i][j] = 0;
			for (k = 0; k<2; ++k)
				sum2[i][j] = sum2[i][j] + (first[i][k] * sec[k][j]);
		}
	}
	return 0;
}