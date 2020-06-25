#include<bits/stdc++.h>
using namespace std;

int knap(int val[],int wt,int n,int sum)
{
	int t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
			if(i==0 || j==0)
			{
				t[i][j] = 0;
			}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(wt[i-1] <= j)
			{
				t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
			}
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}

int main()
{
	int val = [1,2,3];
	int wt = [4,5,6];
	cout<<knap(val,wt,3,10);
}