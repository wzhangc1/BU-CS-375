#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Data
{
	char arrow;
	int value;
};

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
	
	int numOfRows = first.length() + 1;
	int numOfCols = second.length() + 1;
	
	Data table[numOfRows][numOfCols];
    
    for (int col = 0; col < numOfCols; col++)
    {
		table[0][col].value = 0;
	}
   
    for (int row = 1; row < numOfRows; row++)
    {
		table[row][0].value = 0;
		
		for (int col = 1; col < numOfCols; col++)
		{
			time++;
			
			if (first.at(row-1) == second.at(col-1))
			{
				table[row][col].value = table[row-1][col-1].value + 1;
				table[row][col].arrow = 'D';
			}
			else if (table[row-1][col].value > table[row][col-1].value)
			{
				table[row][col].value = table[row-1][col].value;
				table[row][col].arrow = 'U';
			}
			else
			{
				table[row][col].value = table[row][col-1].value;
				table[row][col].arrow = 'L';
			}
		}
	}
	
	fout.open(argv[3]);
	
	if (numOfRows-1 <= 10 && numOfCols-1 <= 10)
	{
		for (int row = 0; row < numOfRows; row++)
		{
			for (int col = 0; col < numOfCols; col++)
			{
				fout << table[row][col].value << ' ';
			}
			
			fout << endl;
		}
		
		string temp = "";
		string lcs = "";
		int row = numOfRows-1;
		int col = numOfCols-1;
		
		while (row != 0 && col != 0)
		{
			if (table[row][col].arrow == 'L')
			{
				col--;
			}
			else if (table[row][col].arrow == 'U')
			{
				row--;
			}
			else if (table[row][col].arrow == 'D')
			{
				temp = lcs;
				lcs = first.at(row-1);
				lcs.append(temp);
				
				col--;
				row--;
			}
		}
		
		fout << lcs << endl;
	}
	else
	{
		fout << table[numOfRows-1][numOfCols-1].value << endl;
	}
	
	fout << time << endl;
	
	fout.close();
	
	return 0 ;
}

