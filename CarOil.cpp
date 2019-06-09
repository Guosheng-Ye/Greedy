/*************************************************************************
	> File Name: CarOil.cpp
	> Author: YeGuoSheng
	> Description:
The car can travel d (d = 7 km) after filling up the tank. However, there are several gas stations on the way asking how to fill up the tank to minimize the total number of refueling

	Array a stores the distance between each gas station {2,7,3,6}, indicating a total of n= 4 gas stations from 0 to n-1
	> Created Time: Saturday, May 25, 2019 at 22:13:03
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

int d;
int n;
int arr[MAX] = {0};
int Count = 0;

void Solve()
{
	for(int i = 0 ;i < n;i++)
	{
		if(arr[i] > d)
		{
			cout<<"No solutions "<<endl;
			return ;
		}
	}
	int sum  = 0 ;
	for(int i = 0 ;i < n;i++)
	{
		sum += arr[i];
		if(sum > d)
		{
			cout<<"Pull soil in :" << i -1 <<endl;
			Count ++;
			sum = arr[i];
		}
	}
}

int main()
{
	cin>>n;
	for(int i =0 ;i < n;i ++)
	{
		cin>>arr[i];
	}
	cin>>d;
	Solve();
	cout<<Count<<endl;
    return 0;
}
