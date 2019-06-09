/*************************************************************************
	> File Name: RepositoryLocation.cpp
	> Author: YeGuoSheng
	> Description: 
	(2,4) (5,3) (6,6)
	repository location (3,5)
	> Created Time: Sunday, May 26, 2019 15:03:12
	solution :Order the x coordinates of n stores incrementally, 
	and the coordinates satisfying are the middle digits
	Y in the same way
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

#define MAX 100
int m = 8;
int n = 3;
int x[MAX] = {2,5,6};
int y[MAX] = {4,3,6};


int QucikSelect(int a[],int s,int t,int k)//Find the KTH smallest element in a[s...t] sequence
{
	int i = s;
	int j = t;
	int temp;
	if (s < t)//There are at least two elements in the interval
	{
		temp = a[s];//Use the first record of the interval as the reference
		while(i != j)//The two ends scan in the middle alternately until I ==j
		{
			while(j > i  && a[j] >= temp)
			{
				j--;//Scan from right to left to find the first keyword less than temp a[I]
			} 
			a[i] = a[j];//Move a[j] forward to a[I] position
			while(i < j && a[i] <= temp)
			{
				i++;//Scan left to right to find the first keyword greater than temp a[I]
			}
			a[j] = a[i];//After a[I], move to the position of a[j]
		}
		a[i] = temp;
		if(k - 1==i)return a[i];
		else if(k - 1 < i)return QucikSelect(a,s,i-1,k);//Left interval recursive search
		else return QucikSelect(a,i+1,t,k);//Right interval recursive search
	}
	else if(s == t && s == k - 1 )//There's only one element in the interval and it's a[k-1]
	{
		return a[k - 1];
	}
}

int main()
{
	int midx;
	int midy;
	if( n % 2 == 0)
	{
		midx = QucikSelect(x,0,n-1,n/2);
		midy = QucikSelect(y,0,n-1,n/2);
	}
	else
	{
		midx = QucikSelect(x,0,n-1,n/2+1);
		midy = QucikSelect(y,0,n-1,n/2+1);
	}
	cout<<"Location :("<<midx<<","<<midy<<" )"<<endl;
    return 0;
}
