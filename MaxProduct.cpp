/*************************************************************************
	> File Name: MaxProduct.cpp
	> Author: YeGuoSheng
	> Description:  To solve the maximum product problem of positive integers, 
	the positive integer n is divided into the sum of n complementary and different natural Numbers	
	Maximize the product of these natural Numbers
	> Created Time: Wednesday, May 22, 2019 at 20:43:06
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

int n;
int ans = 1;

vector<int>x;
vector<int>::iterator it;

void Solve()
{
	if(n == 1 || n == 2 || n == 3 ||n == 4 )
	{
		cout<<"No solutions!"<<endl;
	}
	else
	{	
		int p = 2 ;
		int Count = 0;
		while( n >= p)
		{
			n -= p;
			x.push_back(p);
			++p;
			Count++;
		}

		if(Count == n)
		{
			for(it = x.begin();it != x.end();it++)
			{
				*it += 1;
			}
		}
		else
		{
			for(it = x.end() -1 ;it != x.begin();it--)
			{
				if(n == 0)
				{
					break;
				}
				else
				{
					*it += 1;
					n--;
				}
			}
		}
	}
}

int main()
{
	cin>>n;
	Solve();
	for(it = x.begin();it != x.end();it++)
	{
		cout<<*it<<" ";
		ans *= *it;
	}
	cout<<endl<<"max multiplication:"<<ans<<endl;
    return 0;
}
