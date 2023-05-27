#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100005;
int n,m,q;//line column times
int opt;//direction
//0 line  1 column
int a,b;//number color

void paint(int x,int y,int z)
{
    int m[x+1][y+1]={0};
    for(int i=0;i<z;i++)
    {
        cin>>opt>>a>>b;
        if(opt==0)
        {
            for(int j=1;j<=y;j++)
              m[a][j]=b;
        }
        else
        {
            for(int j=1;j<=x;j++)
              m[j][a]=b;
        }
    }

    //print matrix
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>q;
        paint(n,m,q);
    }

    return 0;
}