/*************************************************************************
	> File Name: MinActicities.cpp
	> Author: YeGuoSheng
	> Description: Suppose there are enough venues to arrange some activities, n activities are numbered 1 ~ n, 
	and each activity has bi starting time
And end time ei, design an effective greedy algorithm to find the minimum number of sessions
	> Created Time: thu May 23, 2019 21:53:54
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

#define MAX 10
int n ;
struct meet
{
	/* data */
	int bi;
	int ei;
	bool operator < (const meet & m) const
	{
		if(ei == m.ei)
		{
			return bi <= m.bi;
		}
		else
		{
			return ei <= m.ei;
		}
		
	}
};

meet Meet[MAX] ={0};
bool vis[MAX] = {0};
int main()
{
	int Count = 0;
	cin>>n;
	for(int i = 0 ;i < n;i++)
	{
		cin>>Meet[i].bi>>Meet[i].ei;
	}
	sort(Meet,Meet+n);
	int preend = 0;
	for(int i = 0 ;i < n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			preend = i;
			for(int j = preend + 1;j < n;j++)
			{
				if(Meet[j].bi >= Meet[preend].ei && !vis[j])
				{
					preend = j;
					vis[j] = 1;
				}
			}
			Count ++;
		}
	}
	cout<<Count<<endl;
    return 0;
}
