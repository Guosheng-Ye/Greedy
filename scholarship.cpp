/*************************************************************************
	> File Name: scholarship.cpp
	> Author: YeGuoSheng
	> Description:  V has n courses this year, no. 0-n-1, and v must have at least avg average.
Each course is composed of average score and test score. Now we know the average product of each course. If we want to increase the score of a course by 1 point, we need to spend bi time on review
If you don't review, of course, zero points, then in order to get the scholarship, figure out at least how much time it takes little v
	Input;
	4
	80 5
	70 2
	90 3
	60 1
	100 92.5
	0
	Output:
	30
	> Created Time: Tue, May 28, 2019 05:42:21
	Solutions:Rank them in increasing order according to the unit review time b and get full marks until the score reaches the average grade
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
#define MAX 201
int n;

struct score
{
	/* data */
	int ai;
	int bi;
	bool operator < (const score & s)const
	{
		return  bi < s.bi;//Review time increasing sort
	}
};

score A[MAX];
int r;
double avg;
int effort = 0;

void Solve()
{
	int Sums = (int) n * avg;//The total score you need to achieve
	int cursum = 0;
	for(int i = 0 ; i< n; i ++)//Total points for existing courses
	{
		cursum += A[i].ai;
	}
	sort(A,A + n);
	for(int j = 0; j< n;j++)
	{
		if(cursum >= Sums)//Score reached, end of selection
		{
			break;
		}
	
		int cur = cursum;
		cursum += min(Sums - cursum ,r - A[j].ai);
		effort += A[j].bi * min(Sums-cur,r - A[j].ai);
	}
}
int main()
{
	while(cin>>n && n != 0 )
	{
		for(int i = 0;i < n; i++)
		{
			cin>>A[i].ai>>A[i].bi;
		}
		cin>>r>>avg;
		Solve();
		cout<<effort<<endl;
	}
	return 0;
}

