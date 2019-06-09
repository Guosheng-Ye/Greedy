/*************************************************************************
	> File Name: Cow.cpp
	> Author: YeGuoSheng
	> Description:  There are n cows on the farm, each milked at a certain time [b,e], and only one cow per place
Give a plan for each cow
	1 2 3 4 5 6 7
	1 2 5 8 4 12 11
	4 5 7 9 10 13 15
	> Created Time: Wednesday, May 22, 2019 03:51:23
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

struct Cow
{
	int no;
	int b;
	int e;
	bool operator < (const Cow &c)const
	{
		if(e == c.e)
		{
			return b <= c.b;
		}
		else
		{
			return e <= c.e;
		}		
	}
};

Cow cow[MAX] ={0};
int ans[MAX] = {0};

void Solve()
{
	int num = 1;
	for(int i = 0 ;i < n;i++)
	{
		if(ans[i] == 0)
		{
			ans[i] = num;
			int preend = cow[i].e;
			for(int j= i + 1;j< n;j++)
			{
				if(cow[j].b >= preend && ans[j] == 0)
				{
					ans[j] = num;;
					preend = cow[j].e;
				}
			}
			num ++;
		}
	}
}

int main()
{
	cin>>n;
	for(int i = 0; i< n; i++)
	{
		cow[i].no = i + 1;
		cin>>cow[i].b>>cow[i].e;
	}
	sort(cow,cow+n);
	Solve();
	for(int i = 0 ;i < n;i++)
	{
		cout<<cow[i].no <<" -> "<<ans[i]<<" ";
		cout<<endl;
	}
    return 0;
}
