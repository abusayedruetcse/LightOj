#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t,cas,n,data[101][101];
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                cin>>data[i][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                cin>>data[i+n][j];

            }
        }
        for(int i=2*n-2,j=1;i>=n;i--,j++)
    {
        data[i][0]+=data[i+1][0];
        data[i][j]+=data[i+1][j-1];
    }
    for(int i=2*n-3;i>=n;i--)
    {
        for(int j=1;j<2*n-1-i;j++)
        {
            data[i][j]+=max(data[i+1][j-1],data[i+1][j]);
        }
    }
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            data[i][j]+=max(data[i+1][j],data[i+1][j+1]);
        }
    }
        printf("Case %d: %d\n",cas,data[1][0]);

    }


    return 0;
}

