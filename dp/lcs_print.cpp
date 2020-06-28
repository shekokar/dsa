#include<bits/stdc++.h>
using namespace std;

//int t[1001][1001];
string solve(string x,string y,int n,int m)
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
	cout<<t[n][m];
	int i=n,j=m;string s="";
	while(i>0 && j>0)
	{
		if(x[i-1] == y[j-1])
		{
			s+=(x[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i][j-1] > t[i-1][j])
			{
				j--;
			}
			else
				i--;
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<"\n";
	return s;
}

int main()
{
	string a = "abcdgh";
	string b = "abedfhr";
	//memset(t,-1,sizeof(t));
	cout<<solve(a,b,a.length(),b.length())<<"\n";
	return 0;
}