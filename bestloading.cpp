/*************************************************************************
	> File Name: bestloading.cpp
	> Author: YeGuoSheng
	> Description:  There are n containers to be loaded on a W cargo ship, 
	and now we have to select as many boxes as possible to be loaded on the cargo ship

	5 2 6 4 3
	W = 10
	> Created Time: Wednesday, May 22, 2019 at 20:11:22
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

#define MAX 20
int n;
int w[MAX] ;
int W;
int best[MAX];
int sumw= 0;

void Solve()
{
	int manx = 0;
	for(int i = 0 ;i < n  && w[i] < W; i ++)
	{
		best[i] = 1;
		W-=w[i];
		sumw += w[i];
	}
}

using namespace std;

int main()
{
	cin>>W;
	cin>>n;
	memset(w,0,sizeof(w));
	for(int i = 0; i < n ;i ++)
	{
		cin>>w[i];
	}
	sort(w,w+n);
	Solve();
	for(int i = 0 ;i < n;i++)
	{
		cout<<w[i]<<" ";
		if(best[i])
		{
			cout<<"select ";
		}
		cout<<endl;
	}
	cout<<sumw<<endl;
    return 0;
}
