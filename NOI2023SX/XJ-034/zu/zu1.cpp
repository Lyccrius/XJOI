#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int id,T;
int m,n;
int h1,h2;
int minn=1e5;
int min(int aaa,int bbb)
{
    if(aaa>bbb) return bbb;
    else return aaa;
}
void solve(int l,int r,int sum,int lr)
{
    printf("%d %d %d\n",l,r,sum);
    if(l==1)
    {
        minn=min(sum,minn);
        sum=0;
        return;
    }
    if(lr==2)
    {
        if(a[l-1][r]=='.') solve(l-1,r,++sum,0);
        if(a[l][r-1]=='.') solve(l,r-1,++sum,2);
    }
    else if(lr==1)
    {
        if(a[l-1][r]=='.') solve(l-1,r,++sum,0);
        if(a[l][r+1]=='.') solve(l,r+1,++sum,1);
    }
    else
    {
        if(a[l-1][r]=='.') solve(l-1,r,++sum,0);
        if(a[l][r-1]=='.') solve(l,r-1,++sum,2);
        if(a[l][r+1]=='.') solve(l,r+1,++sum,1);
    }
    
}  
int main()
{
    scanf("%d %d",&id,&T);
    int flg=0;
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d",&m,&n);
        for(int j=1;j<=n;j++)
        {
            /*
            for(int k=1;k<=m;k++)
            {
                scanf("%c ",&a[j][k]);
                if(a[j][k]=='O')
                {
                    if(a[j-1][k]!='.'&&a[j+1][k]!='.'&&a[j][k-1]!='.'&&a[j][k+1]!='.')
                    {
                        flg++;
                    }
                }
                else if(a[j][k]=='X')
                {
                    h1=j;
                    h2=k;
                    printf("1");
                }
                
            }
            */
           scanf("%s",a[j]);
           for(int k=1;k<=m;k++)
           {
                if(a[j][k]=='O')
                {
                    if(a[j-1][k]!='.'&&a[j+1][k]!='.'&&a[j][k-1]!='.'&&a[j][k+1]!='.')
                    {
                        flg++;
                    }
                }
                else if(a[j][k]=='X')
                {
                    h1=j;
                    h2=k;
                }
                
            }
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
        */
        //printf("%d %d ",h1,h2);
        //if(flg==2)
        {
            solve(h1,h2,0,0);
        }
        printf("%d ",minn);
    }
    return 0;
}
/*
0 1
5 5
.....
.....
..O..
#..#.
O#.X.
*/