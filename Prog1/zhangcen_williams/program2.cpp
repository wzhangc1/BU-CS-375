#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int lcs(string X, string Y, int m, int n, int &time);

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
	
	fout.open(argv[3]);
	fout << lcs(first, second, first.length(), second.length(), time) << endl;
	fout << time << endl;
	fout.close();
	
	return 0; 
}

int lcs(string first, string second, int m, int n, int &time) 
{
	time++;
	
	if (m == 0 || n == 0)
	{
		return 0;
	}
	else
	{
		if (first.at(m-1) == second.at(n-1)) 
		{
			return 1 + lcs(first, second, m-1, n-1, time);
		}
		else
		{
			return max(lcs(first, second, m, n-1, time), lcs(first, second, m-1, n, time));
		}
	}
} 
