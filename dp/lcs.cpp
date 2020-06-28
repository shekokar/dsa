#include<bits/stdc++.h>
using namespace std;

//int t[1001][1001];
int solve(string x,string y,int n,int m)
{
	int t[n+1][m+1];
	for(int i=0;i<n+1;i++)
		t[i][0] = 0;
	for(int i=0;i<m+1;i++)
		t[0][i] = 0;

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(x[i] == y[j])
			{
				t[i][j] = 1+t[i-1][j-1];
			}
			else
			{
				t[i][j] = max(t[i-1][j],t[i][j-1]);
			}
		}
	}
	return t[n][m];

	/*if(n==0 || m==0)
		return 0;
	if(t[n][m]!=-1)
		return t[n][m];
	if(x[n-1] == y[m-1])
		return t[n][m] = 1+solve(x,y,n-1,m-1);
	else
		return t[n][m] = max(solve(x,y,n-1,m),solve(x,y,n,m-1));
*/
}

int main()
{
	string a = "abcdgh";
	string b = "abedfhr";
	//memset(t,-1,sizeof(t));
	cout<<solve(a,b,a.length(),b.length())<<"\n";
	return 0;
}