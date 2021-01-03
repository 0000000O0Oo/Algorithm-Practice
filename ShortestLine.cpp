//This one comes from the book algorithmic thinking, and has been taken from a programming tournament. 

PROBLEM
//There are n lines of people waiting for food, and the number of people waiting
//in each line is known. Then, each of m new people will arrive, and they
//will join the shortest line (the line with the fewest number of people). Our
//task is to determine the number of people in each line that each of the m
//people joins.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//n lines of people waiting for food
//m new people will arrive


int shortest_line_index(int lines[], int n) {
	int j;
	int shortest = 0;
	for (j = 1; j < n; j++)
		if (lines[j] < lines[shortest])
			shortest = j; 
	return shortest;
}

void solve(int lines[], int n, int m) {
	int i, shortest;
	for (i = 0; i < m; i++) {
		shortest = shortest_line_index(lines, n);
		printf("Shortest Line %d : %d\n", i + 1, lines[shortest]);
		lines[shortest]++; // Incrementation
	}
}

#define MAX_LINES 100
int main(void) {
	int lines[MAX_LINES];
	int n, m, i;
	scanf_s("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &lines[i]);
	}
	solve(lines, n, m);
	return 0;
}
