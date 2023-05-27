#include <bits/stdc++.h>

using namespace std;

long long T,n,m,q,x,c;
bool opt=0;
long long ans[10000][10000]={0};

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin >> T;
    for(long long i=0;i<T;i++)
    {
        cin >> n >> m >> q;
        for(long long j=0;j<q;j++)
        {
            cin >> opt >> x >> c;
            if(opt)
            {
                for(long long k=0;k<n;k++)
                {
                    ans[k][x-1]=c;
                }
            }
            else
            {
                for (long long k=0;k<m;k++)
                {
                    ans[x-1][k]=c;
                }
            }
        }
        for(long long t=0;t<n;t++)
        {
            for(long long tt=0;tt<m;tt++)
            {
                cout << ans[t][tt] << " ";
                ans[t][tt]=0;
            }
            cout << endl;
        }
    }
    return 0;
}