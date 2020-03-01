I, Williams Zhang Cen, have done this assignment completely on my own. I have not copied it, nor
have I given my solution to anyone else. I understand that if I am involved in plagiarism or
cheating I will have to sign an official form that I have cheated and that this form will be stored in
my official university record. I also understand that I will receive a grade of 0 for the involved
assignment for my first offense and that I will receive a grade of “F” for the course for any
additional offense.

Run:
	make
	./BestFirstSearch input.txt output.txt

Use:
	Array
	Struct
	Queue

Time:
	O(2^n)

Classes:
	None

Functions:

	Main - calls knapsack
	knapsack - calculates highest profit
	insertionSort - sort items by density
	bound - calculates highest bound

Variables
	c - capacity
	fin - input file
	fout - output file
	n - problem size
	
	maxProfit - maximum profit
	size - size of the solution
	totalNodes - total number of nodes
	totalLeafs - total number of leaves
	Q - queue
	u - node
	v - node
