/*************************************************************************
	> File Name: DiskSCAN.cpp
	> Author: YeGuoSheng
	> Description:  DiskSCAN
	Simple :
	98,183,37,122,14,124,65,67,
	startnum = 53;
	Output:
	236
	> Created Time: Saturday, May 25, 2019 at 16:37:16
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
#include<cmath>
using namespace std;

#define MAX 101
#define INF 0x3f3f3f3f

int n = 8;
int C = 53;
struct NodeType
{
	int no;
	int place;
};

NodeType A[MAX] = { {1,98},{2,183} ,{3,37},{4,122},{5,14},{6,124},{7,65},{8,67}};

int ans =  0;
bool flag[MAX];

bool cmp (NodeType a,NodeType b)
{
	if( a.place < b.place)return true;
	return false;
}

void Find(int i,int &minp,int &mind)//Find the most recently accessed location minp
{
	int minleftp = INF;
	int minleftd = INF;
	int minrightp = INF;
	int minrightd = INF;
	int j = i - 1;
	int k = i + 1;
	while( j >= 0 && flag[j]==true)
	{
		j --;//Look to the left for an unaccessed location i
	}
	if(j >= 0)//find seccess 
	{
		minleftp = j;
		minleftd = A[i].place - A[j].place;
	}
	while(k <= n && flag[k] == true)
	{
		k++;//Look to the right for an unaccessed location k
	}
	if( k <= n)//find success 
	{
		minrightp = k;
		minrightd = A[k].place -A[i].place;
	}
	if(minleftd < minrightd)//The comparison finds the most recent unaccessed location
	{
		mind = minleftd;
		minp = minleftp;
	}
	else
	{
		mind = minrightd;
		minp = minrightp;
	}	
}

int Solve()
{
	sort(A,A+n+1,cmp);
	int i;
	for( i =0 ;i <= n;i++)//find start location
	{
		if(A[i].place == C)
		{
			break;
		}
	}
	flag[i] = true;
	cout<<"cur location :"<<A[i].place<<"answer no :"<<A[i].no;
	for(int k = 0; k < n;k++)
	{
		int minp;
		int mind;
		find(i,minp,mind);
		cout<<"move to "<<A[minp].place<< "answer no "<<A[minp].no<<"move dist "<<mind<<endl;
		flag[minp] = true;
		ans += mind;
		i = minp;
	}
	return ans;
}

int main()
{
	A[n].no = 0;
	A[n].place = C;
	memset(flag,0,sizeof(flag));
	cout<<Solve();
	return 0;
}

/*
int n;
int arr[MAX] = {INF};
int sum = 0 ;
int startnum = 0;

void Delete(int a[],int x)
{
	int lastarrindex;
	int t;
	for( t = 0 ;t <= n+1 ;t ++)
	{
		if( arr[t] == INF)
		{
			lastarrindex = t-1;//count  the arr elems' num 
		}
	}
	if(x == 0)
	{
		for(int i = 0 ; i < lastarrindex;i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	else if (x == lastarrindex)
	{
		arr[lastarrindex] = INF;
	}
	else
	{
		for(int i = x ;i < lastarrindex;i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}

void Solve()
{
	int startnumIndex; 
	for(int i = 0 ; i <= n ;i++)
	{
		if(arr[i] == startnum)
		{
			startnumIndex = i;
		}
	}
	if(startnumIndex == 0 || startnumIndex == n)
	{
		sum = (arr[n] - arr[0]) ;
		return ;	
	}
	else
	{
		while(n--)
		{
			int lastarr;
			int k = startnumIndex;
			if( k == 0)//find the lastarr
			{
				for(int z = 0 ; z<= n ;z++)
				{
					if(arr[z] == INF)
					{
						lastarr = z-1;
						sum += arr[lastarr] - arr[0];
						return ;
					}
				}
			}
			if(arr[k+1] == INF)
			{
				sum += arr[k] - arr[0];
				return;
			}

			int a = fabs( arr[startnumIndex-1] - arr[startnumIndex]);
			int b = fabs( arr[startnumIndex] - arr[startnumIndex+1]);
			sum += min(a,b);
			if(a < b)
			{
				Delete(arr,k);
				startnumIndex = k - 1;
			}
			else//a >= b
			{
				Delete(arr,k);
				startnumIndex = k + 1;
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i = 0 ;i < n ;i++)
	{
		cin>>arr[i];
	}
	cin>>startnum;
	arr[n] = startnum;
	sort(arr,arr+n+1);
	for(int i = 0 ;i <=  n ;i++)
	{
		cout<<arr[i];
	}
	Solve();
	cout<<sum<<endl;
    return 0;
}
*/
