/*************************************************************************
	> File Name: woodensticks.cpp
	> Author: YeGuoSheng
	> Description:There are n sticks to be processed, each of which has two parameters: length L and weight W
It takes a minute for the machine to process the first stick, if the current ones are L and W, and the subsequent ones are L' and W '
And if L <= L' and W <= W 'then it doesn't take any extra time or it takes an extra minute
Minimum processing time required for the stick
	(9,4) (2,5) (1,2) (5,3) (4,1)  => min time = 2 
	(4,1) -> (5,3) -> (9,4) -> (1,2) -> (2,5)
	cin
	3
	5
	4 9 5 2 2 1 3 5 1 4
	3
	2 2 1 1 2 2
	3
	1 3 2 2 3 1
	output;
	2
	1
	3
	> Created Time: Tue, May 28, 2019 04:50:02
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

#define MAX 10005
int t;
int n;

struct woodensticks
{
	int Begin;
	int End;
	bool operator < (const woodensticks & s)const
	{
		if(End == s.End)//W
		{
			return Begin <= s.Begin;//Sort by L increment
		}
		else
		{
			return End <= s.End;//Otherwise W increments sort
		}
	}
};

woodensticks arr[MAX];
int vis[MAX]; 

int main()
{
	cin>>t;
	while(t --)
	{
		int Count = 1 ;
		memset(arr,0,sizeof(arr));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i = 1;i <= n; i++)
		{
			cin>>arr[i].Begin>>arr[i].End;
		}
		sort(arr + 1,arr + n + 1); 
		for(int i = 1; i <= n;i ++)
		{
			if(vis[i] == 0)//The current stick is not considered
			 {
				vis[i] = 1;
				int prebeg = arr[i].Begin;
				int preend = arr[i].End;//record W and L
				for(int j = i + 1; j <= n;j++)//for the next
				{
					if(arr[j].Begin >= prebeg && arr[j].End >= preend && vis[j]== 0)//Find the nearest L<=L',W<=W'
					{
						vis[j] = 1;//record 
						preend = arr[j].End;
						prebeg = arr[j].Begin;//Update and repeat until the end returns to the original unconsidered continue greedy choice
					}
				}
				Count ++;
			}
		}
		cout<<Count-1<<endl;
	}	
    return 0;
}
