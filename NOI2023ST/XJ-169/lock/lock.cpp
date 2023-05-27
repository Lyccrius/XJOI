#include <bits/stdc++.h>
using namespace std;
int m(int a[],int n)
{
    int maxt=a[0];
    int mint=a[0];
    for(int i=0;i<n;i++)
    {
        maxt=max(maxt,a[i]);
        mint=min(mint,a[i]);
    }
    return maxt-mint;
}
int maxs(int a[],int n)
{
    int maxt=a[0];
    for(int i=0;i<n;i++)
    {
        maxt=max(maxt,a[i]);
    }
    return maxt;
}
int mins(int a[],int n)
{
    int maxt=a[0];
    for(int i=0;i<n;i++)
    {
        maxt=min(maxt,a[i]);
    }
    return maxt;
}
int main()
{
    freopen("lock1.in","r",stdin);
    freopen("lock1.out","w",stdout);
    int T,k;
    cin>>T>>k;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        int a[k][n];
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int tim[n+1];
        memset(tim,0,n);
        int c[int (pow(n,k))];
        int tag=0;
        while(tim[n+1]!=k)
        {
            int b[k];
            for(int i=0;i<k;i++)
            {
                b[i]=m(a[k],i);
            }
            c[tag]=maxs(b,n);
            tag++;
            tim[n]++;
            int z[k];
            for(int i=0;i<k;i++)
            {
                z[i]=a[i][0];
            }
            a[0][0]=z[k];
            for(int i=1;i<k;i++)
            {
                a[i][0]=z[i-1];
            }
            for(int j=0;j<=n;j++)
            {
                if(tim[j]==k)
                {
                    tim[j+1]++;
                    int z[k];
                    for(int i=0;i<k;i++)
                    {
                        z[i]=a[i][j];
                    }
                    a[0][j]=z[k];
                    for(int i=1;i<k;i++)
                    {
                        a[i][j]=z[i-1];
                    }
                }
            }
        }
        cout<<mins(c,tag)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}