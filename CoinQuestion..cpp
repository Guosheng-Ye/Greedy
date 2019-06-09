/*************************************************************************
	> File Name: CoinQuestion.cpp
	> Author: YeGuoSheng
	> Description:  There are 1 cent, 2 cent, 5 cent, 10 cent, 50 cent and 100 cent COINS, 
	and now I'm going to pay W dollars with these COINS,
	How many COINS is the minimum required
	> Created Time: Wednesday, May 22, 2019 at 20:20:55
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


int money[6] = {1,2,5,10,50,100};
int W;
int Count = 0;

void Solve()
{
	int rw = W;
	for(int i = 5 ;i >= 0 ;i --)
	{
		if(rw == 0)
		{
			break;
		}
		int A = rw / money[i];
		if(A != 0)
		{
			rw -= (money[i] * A);
			Count+=A;
		}
		else
		{
			continue;
		}	
	}
}

int main()
{
    cin>>W;
	Solve();
	cout<<Count<<endl;
    return 0;
}
