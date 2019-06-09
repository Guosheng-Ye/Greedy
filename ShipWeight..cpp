/*************************************************************************
	> File Name: ShipWeight.cpp
	> Author: YeGuoSheng
	> Description:  There are n people in the ship problem, each person has a weight, and the maximum load of each ship is C
With a maximum of two people on board, the least used boat takes everyone
Input:
C 150
W: 50, 65, 58, 72, 78, 53, 82
	> Created Time: Wednesday, May 22, 2019 at 21:33:2
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

#define MAX 20
int node[MAX]= {0};
int C;
int n;


int main()
{
	cin>>C;
	cin>>n;
	int Count = 0;
	for(int z = 0 ; z < n;z ++)
	{
		cin>>node[z];
	}
	sort(node,node+n);
	int i;
	int j;
	for( i = 0, j = n - 1; i <= j ;i ++,j--)
	{
		if(node[i] + node[j] <= C  &&i != j)
		{
			Count ++;
		}
		else // >C
		{
			Count++;
			--i;
		}
		if(i == j)
		{
			Count ++;
		}
	}
	cout<<Count<<endl;
    return 0;
}
