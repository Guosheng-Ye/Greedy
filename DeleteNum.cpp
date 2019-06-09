/*************************************************************************
	> File Name: DeleteNum.cpp
	> Author: YeGuoSheng
	> Description:  Delete number problem given a total of n positive integer d, remove any k (k<=n) number
The remaining digits form a new positive integer according to the original order. 
For the given n-bit positive integers d and k, find the deletion scheme with the smallest remaining digits
	> Created Time: Saturday, May 25, 2019 21:25:25 
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<cstring>
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
#define MAX 50


void Delk(char a[],int k)
{
	int i;
	int m = strlen(a);
	// if( k >= m)
	// {
	// 	a = "";
	// 	return ;
	// }
	while( k > 0)
	{
		for(i = 0 ;i < m - 1 && a[i] <= a[i+1];i ++);//Find an increasing sequence
		cout<<"Delete a[i] = " <<a[i]<<endl;
		strcpy(a + i, a+ i +1);//delete a[i]
		k--;
		m--;
	}
		while( m > 1 && a[0] == '0')
		{
			strcpy(a,a  + 1 );
		}
	
}

void longtostr(long d,char a[])
{
	int i,n = 0;
	char tmp;
	while( d > 0)
	{
		a[n++] = '0' + d % 10;
		d /= 10;
	}
	a[n] = '\0';
	for(i = 0 ;i < n/2;i++)//reverse £¬put all d's number in a[0]
	{
		tmp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = tmp;
	}
}
long strtolong(char a[])
{
	int i,m = strlen(a);
	long d = 0;
	for(i = 0 ;i < m ;i ++)
	{
		d = d*10+ (a[i] - '0');
	}
	return d;
}


int main()
{
	char a[MAX];
	long d = 0;
	cin>>d;
	int k = 0;
	cin>>k;
	longtostr(d,a);
	Delk(a,k);
	d = strtolong(a);
	cout<<"After :" <<d<<endl;
    return 0;
}
