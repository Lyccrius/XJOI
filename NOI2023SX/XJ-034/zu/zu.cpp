#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int id,T;
int m,n;
int h1,h2;
int minn=1e5;
int red1,red2;
int min(int aaa,int bbb)
{
    if(aaa>bbb) return bbb;
    else return aaa;
}
void solve(int l,int r,int sum,int lr)
{
    //printf("%d %d %d\n",l,r,sum);
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
    freopen("zu2.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d %d\n",&id,&T);
    int flg=0;
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d\n",&n,&m);
        if(m==1)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&a[j][0]);
                if(j!=n) scanf("\n");
                if(a[j][0]=='O')
                {
                    if(red1==0) red1=j;
                    else if(red2==0) red2=j;
                    //printf("%d %d\n",red1,red2);
                }
                else if(a[j][0]=='X')
                {
                    h1=j;
                    h2=0;
                }
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%s",a[j]);
                for(int k=0;k<=m;k++)
                {
                    if(a[j][k]=='O')
                    {
                        if(a[j-1][k]!='.'&&a[j+1][k]!='.'&&a[j][k+1]!='.'&&a[j][k-1]!='.')
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
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                printf("%d %c",j,a[i][j]);
            }
            printf("\n");
        }
        */
        //printf("%d %d %d",h1,red1,red2);
        if(m==1)
        {
            if(h1+1<red1&&h1+1<red2)
            {
                printf("Black %d\n",2*(h1-1));
                continue;
            }
            else if(h1+1==red1||h1+1==red2||h1-1==red1||h1-1==red2)
            {
                printf("Red 1\n");
                continue;
            }
        }
        if(flg==2) printf("Black 0\n");
        else printf("Tie\n");
        flg=0;
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

        

0 1
4 5
O#...
##..#
#O#..
.#..X
*/