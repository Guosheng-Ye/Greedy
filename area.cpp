/*************************************************************************
	> File Name: arer.cpp
	> Author: YeGuoSheng
	> Description:  
	I'm going to represent the interval of coordinates I minus 1, I on the x axis and give me n different integers 
	and now I'm going to draw m lines covering all the intervals
	The condition is that each line is arbitrarily long but the number of line segments drawn should be the shortest and not more than m (1< m < 50).
	Cinput :
	5 3     (n,m)
	1 3 8 5 11
	Output :
	7
	> Created Time: Tue, May 28, 2019 03:58:39
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
int n;
int m;

struct area
{
	int left;
	int right;
	int prearea;
	bool operator  < (const area & x)const
	{
		return right < x.right;
	}
}X[MAX];

struct Cmp
{
	bool operator () (const area&a,const area&b)const
	{
		return a.prearea <= b.prearea;
	}	
};

int main()
{

	int minLength = 0;//Minimum length of covered line segment
	X[0].right = X[0].left = X[0].prearea = 0;
	cin>>n;
	cin>>m;
	for(int i = 1; i<=n; i++)
	{
		cin>>X[i].right;
		X[i].left = X[i].right -1 ;	
	}

	sort(X+1,X+n+1);
	for(int i = 1; i<= n; i++)
	{
		X[i].prearea = X[i].left - X[i-1].right;
	}
	// for(int i = 1; i<= n; i++)
	// {
	// 	cout<<X[i].left<<" "<<X[i].right<<" "<<X[i].prearea<<endl;
	// }
	sort(X+1,X+n+1,Cmp());//Sort by interval size

 	// for(int i = 1; i<= n; i++)
	// {
	// 	cout<<X[i].left<<" "<<X[i].right<<" "<<X[i].prearea<<endl;
	// }
	int l = n;
	for(int t = 1;t < m ; t ++)
	{
		minLength += (X[l].right - X[l].left);
		l--;
	}

	for(int i = 1;i <= (n - m + 1);i++)
	{
		minLength +=  (  (X[i].right - X[i].left) + X[i].prearea );
	}
	cout<<minLength<<endl;
    return 0;
}
