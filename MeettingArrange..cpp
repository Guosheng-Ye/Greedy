/*************************************************************************
	> File Name: MeettingArrange.cpp
	> Author: YeGuoSheng
	> Description:  There is A group of meeting A and A group of meeting room B. A[I] indicates the number of participants in meeting I
B[j] represents the maximum number of people that meeting room j can accommodate. If and only if A[I] <= b[j], the JTH conference room can be used to arrange the ith meeting
. Given arrays A and B, ask how many meetings you can hold at most
A[] = {1,2,3}, B[] = {3,2,4} => 3
A[] = {3,4,3,1},B[] = {1,2,2,6} => 2

	> Created Time: Saturday, May 25, 2019 04:58:59
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

#define MAX 5
int n;
int A[MAX] = {0};
int B[MAX] = {0};
int Count = 0;


int main()
{
	cin>>n;
	for(int i = 0;i < n;i ++)
	{
		cin>>A[i];
	}
	for(int j = 0;j < n;j++)
	{
		cin>>B[j];
	}
	sort(A,A+n);
	sort(B,B+n);
	int a;
	int b;
	for( a = 0,b = 0; a < n && b < n; a++,b++)
	{
		if(A[a] > B[b])
		{
			a--;
			continue;
		}
		else 
		{
			Count++;
			continue;
		}
	}
	cout<<Count<<endl;
    return 0;

}
