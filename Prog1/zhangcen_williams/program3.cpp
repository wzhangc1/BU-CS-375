#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const int maximum = 1000; 

int lcs(string first, string second, int m, int n, int dp[][maximum], int &time);

int main(int argc, char *argv[])
{
	ifstream fin;
	int time = 0;
	ofstream fout;
	string first;
	string second;
	
	fin.open(argv[1]);
	fin >> first;
	fin.close();
	
	fin.open(argv[2]);
	fin >> second;
	fin.close();
	
	int dp[first.length()][maximum];
	
	for(int i = 0; i < first.length(); i++)
	{
		for (int j = 0; j < maximum; j++)
		{
			dp[i][j] = -1;
		}
	}
	
	fout.open(argv[3]);
	fout << lcs(first, second, first.length(), second.length(), dp, time) << endl;
	fout << time << endl;
	fout.close();
	
	return 0; 
}

int lcs(string first, string second, int m, int n, int dp[][maximum], int &time)
{
	time++;
	
	if (m == 0 || n == 0)
	{
		return 0;
	}
	else
	{
		if (dp[m-1][n-1] != -1)
		{
			return dp[m-1][n-1];
		}
		if (first.at(m-1) == second.at(n-1))
		{
			dp[m-1][n-1] = 1 + lcs(first, second, m-1, n-1, dp, time);
			
			return dp[m-1][n-1];
		} 
		else
		{
			dp[m-1][n-1] = max(lcs(first, second, m, n-1, dp, time), lcs(first, second, m-1, n, dp, time));
			
			return dp[m-1][n-1];
		}
	}
}
