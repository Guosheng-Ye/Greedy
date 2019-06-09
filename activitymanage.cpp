/*************************************************************************
	> File Name: activitymanage.cpp
	> Author: YeGuoSheng
	> Description:  Scheduling issues.
	12
	12 15
	2 13
	8 12
	8 11
	6 10
	5 9
	3 8
	5 7
	0 6
	3 5
	1 4

	> Created Time: Wednesday, May 22, 2019 03:33:07
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
struct Action
{
	int b;
	int e;
	bool operator < (const Action & s)const
	{
		return e <= s.e;
	}
};
int n ;
Action a[MAX] = {0}; 
bool flag[MAX];
int Count = 0;

void Solve()
{
	memset(flag ,0,sizeof(flag));
	sort(a,a+n);
	int  preend = 0;
	for(int i = 0 ;i < n ;i++)
	{
		if(a[i].b >= preend)
		{
			flag[i] = true;
			preend = a[i].e;
		}
	}
}

int main()
{
	cin>>n;
	for(int i = 0;i <n; i++)
	{
		cin>>a[i].b>>a[i].e;
	}
	Solve();
	for(int i = 0; i< n;i++)
	{
		if(flag[i])
		{
			cout<<a[i].b<<" "<<a[i].e<<" ";
			Count++;
			cout<<endl;
		}
		
	}
	cout<<Count<<endl;
    return 0;
}
