#include<iostream>
#include<algorithm>  
#include<stdio.h>
#include<string.h>
using namespace std;
#define LL long long
#define MAXN 10010
LL k,n;
LL a[MAXN][MAXN];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    LL T;
    cin>>T>>k;
    while(T--)
    {
        LL ans=0,q;
        memset(a,0,sizeof(a));
        cin>>n;
        q=k*n;
        for(LL i=1;i<=k;i++)
            for(LL j=1;j<=n;j++)
                cin>>a[i][j];
        for(LL i=2;i<=k*q;i++)
        {
            int nmsl=0;
            if(nmsl==1)
            {
                continue;
                nmsl=0;
            }
            for(LL j=1;j<=n;j++)
            {
                if(a[i][j]==a[i][j-1])
                {
                    q--;
                    nmsl=1;
                    continue;
                }      
                int tmp=a[i][j];
                a[i][j]=a[(i%k)+1][j];
                a[(i%k)+1][j]=tmp;
            }
        }
        int flag=0;
        for(LL i=1;i<=k;i++)
        {
            for(LL j=2;j<=n;j++)
            {
                if(a[i][j-1]==a[i][j])flag++;
            }
        }
        if(flag-k==k)cout<<"0"<<endl;
        else cout<<abs(q)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}