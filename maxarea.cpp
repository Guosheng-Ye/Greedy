/*************************************************************************
	> File Name: maxarea.cpp
	> Author: YeGuoSheng
	> Description:  Given n closed intervals, remove as few intervals as possible, leaving the most number of intervals that do not intersect
	3
	10 20
	15 10
	20 15

	2
	> Created Time: Tue, 21 May 2019 20:06:32
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

struct area
{
	int b;
	int e;
	bool operator < (const area & s)const
	{
		if(e == s.e)
		{
			return b < s.b;
		}
		else
		{
			return e < s.e;
		}
		
	} 
};

area arr[MAX] = {0};

int Solve()
{
	int Count = 0;
	int preend = 0;
	for(int i = 0 ; i < n;i ++)
	{
		if(arr[i].b > preend)
		{
			Count++;
			preend = arr[i].e;
		}
	}
	return n - Count;
}

int main()
{
	cin>>n;
	int x;
	int y;
	for(int i = 0 ;i < n;i ++)
	{
		cin>>x;
		cin>>y;
		if(x > y)
		{
			swap(x,y);
		}
		arr[i].b = x;
		arr[i].e = y;
	}
	sort(arr,arr+n);
	cout<<Solve();
    return 0;
}
