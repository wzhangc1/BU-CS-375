#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node
{
	int level;
	int profit;
	double bound;
	int weight;
	string pre;
};

void knapsack(ofstream& fout, int n, int p[], int w[], int c);
void insertionSort(int p[], int w[], int n);
double bound(Node u, int n, int c, int p[], int w[]);

int main(int argc, char *argv[])
{
	ifstream fin;
	int c;
	int n;
	ofstream fout;
	
	fin.open(argv[1]);
	
	fin >> n;
	fin.ignore();
	fin >> c;
	
	int p[n];
	int w[n];
	
	for (int i = 0; i < n; i++)
	{
		fin >> w[i];
		fin.ignore();
		fin >> p[i];
	}
	
	fin.close();
	
	insertionSort(p, w, n);
	
	fout.open(argv[2]);
	
	knapsack(fout, n, p, w, c);
	
	fout.close();
	
	return 0 ;
}

void insertionSort(int p[], int w[], int n) 
{ 
	double r[n];
	
	for (int i = 0; i < n; i++)
	{
		r[i] = (double)p[i] / w[i];
	}
	
	for (int i = 1; i < n; i++)
	{
		double tempR = r[i];
		int tempP = p[i];
		int tempW = w[i];
		
		int j = i-1;
		
		while(j >= 0 && r[j] < tempR)
		{
			r[j+1] = r[j];
			p[j+1] = p[j];
			w[j+1] = w[j];
			j--;
		}
		
		r[j+1] = tempR;
		p[j+1] = tempP;
		w[j+1] = tempW;
	}
} 

void knapsack(ofstream& fout, int n, int p[], int w[], int c) 
{
	int maxProfit = 0;
	int size = 0;
	int tempProfit = 0;
	int totalNodes = 0;
	int totalLeafs = 0;
	Node u;
	Node v;
	queue<Node> Q; 
	
	u.level = -1; 
	u.profit = 0;
	u.weight = 0;
	Q.push(u); 
		
	while (!Q.empty()) 
	{
		u = Q.front(); 
		Q.pop(); 
		
		if (u.level == -1)
		{
			v.level = 0;
		}
		
		totalNodes++;
		
		if (v.level == n-1)
		{
			totalLeafs++;
		}
		
		if (u.level != n-1)
		{
			v.level = u.level + 1; 
			
			v.weight = u.weight + w[v.level]; 
			v.profit = u.profit + p[v.level]; 
			v.pre = u.pre;

			if (v.weight <= c && v.profit > maxProfit)
			{
				maxProfit = v.profit;
			}
			
			v.bound = bound(v, n, c, p, w);
			
			if (v.bound > maxProfit)
			{
				Node temp = v;
				
				temp.pre.append("1");
				
				Q.push(temp);
			}
			
			v.weight = u.weight;
			v.profit = u.profit;
			v.bound = bound(v, n, c, p, w);
			
			if (v.bound > maxProfit)
			{
				Node temp = v;
				
				temp.pre.append("0");
				
				Q.push(temp);
			}
		}
    }
    
    for (int i = 0; i < v.pre.length(); i++)
    {
		if (v.pre.at(i) == '1')
		{
			size++;
			tempProfit += p[i];
		}
	}
	
	if (tempProfit + p[v.pre.length()] == maxProfit)
	{
		size++;
		v.pre.append("1");
	}
	
    fout << n << ',' << maxProfit << ',' << size << endl;
    fout << totalNodes << ',' << totalLeafs << endl;
    
    for (int i = 0; i < v.pre.length(); i++)
    {
		if (v.pre.at(i) == '1')
		{
			fout << w[i] << ',' << p[i] << endl;
		}
	}
}

double bound(Node u, int n, int c, int p[], int w[])
{
	if (u.weight >= c)
	{
        return 0;
	}
	
	double profit_bound = u.profit;
	
	int j = u.level + 1;
	int totweight = u.weight;
	
	while ((j < n) && (totweight + w[j] <= c))
	{ 
		totweight += w[j];
		profit_bound += p[j];
		j++;
	}
	
	if (j < n)
	{
		profit_bound += (c - totweight) * (double)p[j]/w[j];
	}
	
	return profit_bound;
} 
