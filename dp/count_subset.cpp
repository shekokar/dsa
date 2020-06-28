#include<bits/stdc++.h>
using namespace std;

int subset_sum(int wt[],int n,int sum)
{
	int t[n+1][sum+1];
	for(int i=0;i<sum+1;i++)
		t[0][i] = 0;
	for(int i=0;i<n+1;i++)
		t[i][0] = 1;

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(wt[i-1] <= j)
			{
				t[i][j] = t[i-1][j-wt[i-1]] + t[i-1][j];
			}
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}

int main()
{
	int arr[] = {4,5,6};
	cout<<subset_sum(arr,3,10);
}