/*************************************************************************
	> File Name: FindMaxAppeareNum.cpp
	> Author: YeGuoSheng
	> Description:  Given n positive integers, write a program to find the maximum number of occurrences. 
	If there are more than one, the one with the smallest output value
	Simple 
	6
	10 1 10 20 30 20

	10
	> Created Time: Saturday, May 25, 2019  21:16:38
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
int arr[MAX]  ={0};

int main()
{
	cin>>n;
	for(int i = 0 ;i < n ;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);

	int pre = arr[0];
	int  num = 1 ;
	int maxn = 0;
	int minnum = 0;
	int j = 1;
	while ( j < n)
	{
		if(j < n && arr[j] == pre)
		{
			num++;
			j++;
		}
		if( num > maxn)
		{
			maxn = num;
			minnum = pre;
		}
		pre = arr[j];
		num = 1;
		j++;
	}
	cout<<minnum<<endl;
    return 0;
}
