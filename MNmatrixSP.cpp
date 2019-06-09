/*************************************************************************
	> File Name: MNmatrixSP.cpp
	> Author: YeGuoSheng
	> Description:M by n number matrix, from the top left to the bottom right, can only go to the top right, right, bottom right
The first and last lines are connected to find the shortest path, and output the line number of the path
	
	5 6
	3 4 1 2 8 6    3 4 1 2 8 9
	6 1 8 2 7 4    6 1 8 2 7 4
	5 9 3 9 9 5    5 9 3 9 9 5
	8 4 1 3 2 6    8 4 1 3 2 6
	3 7 2 8 6 4    3 7 2 1 2 3

	1 2 3 4 4 5    1 2 1 5 4 5
	16
	> Created Time: hu, May 23, 2019 22:11:55 
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;


#define M 12
#define N 110
int m = 5;
int n = 6;
int a[M][N]  ={ {3,4,1,2,8,6} ,{6,1,8,2,7,4} ,{5,9,3,9,9,5}, {8,4,1,3,2,6} ,{3,7,2,8,6,4}  };
int minRow;
int minCol;

int minValue(int i , int j)
//Find the minimum number in the middle and bottom three corresponding Numbers of a[I][j] element, and record the row mark at the same time
{
	int s = (i == 0) ? m - 1: i - 1;
	int x = (i == m - 1) ? 0: i + 1;
	minRow = s;
	minRow = a[i][j+1]  < a[minRow][j+1] ? i : minRow;
	minRow = a[x][j+1] < a[minRow][j+1] ? x :minRow;
	minRow = a[minRow][j+1] == a[s][j+1] && minRow > s ? s: minRow;
	minRow = a[minRow][j+1] == a[i][j+1] && minRow > i ? i: minRow;
	minRow = a[minRow][j+1] == a[x][j+1] && minRow > i ? i: minRow;
	return a[minRow][j+1];
}

void Solve()
{
	int i,j,min;
	for(j = n -2;j >= 0;j--)
	{
		for(i = 0;i < m;i++)
		{
			a[i][j] += minValue(i,j);
		}
	}
	min = a[0][0];
	minRow = 0;
	for(i = 1;i < m ;i++)
	{
		if(a[i][0] < min)
		{
			min = a[i][0];
			minRow = i;
		}
	}
	for(j = 0;j < n;j++)
	{
		cout<<minRow + 1;
		if(j <  n - 1)cout<<" ";
		minValue(minRow,j);
	}
	cout<<endl<<min<<" ";
}
int main()
{
	Solve();
	return 0;
}
