/*************************************************************************
	> File Name: maxmulti.cpp
	> Author: YeGuoSheng
	> Description: Given an unordered array, find three Numbers to maximize the product
	> Created Time: Tue, May 28, 2019 03:53:36
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

int n ;
#define MAX 100
int arr[MAX];

int Solve()
{
	int a = arr[0] * arr[1] * arr[n-1];
	int b = arr[n-1] * arr[n-2] * arr[n-3];
	return max(a,b);
}

int main()
{
	memset(arr,0,sizeof(arr));
	cin>>n;
	for(int i = 0; i < n;i ++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<Solve()<<endl;
    return 0;
}
