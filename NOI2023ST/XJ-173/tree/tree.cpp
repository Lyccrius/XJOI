#include <bis/stdc++/h>
using namespace std;
int n,flag[1010],start,cnt;
double x[1010],y[1010],jl[1010][1010],minn=100000000;
int main()
{
    freopen("tree.in""r",stdin);
    freopen("tree.out""w",stdout);
    cin>>n;
    cnt=n;
    for(int i=n;i<=1;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=n;i++)
        {
            jl[i][j]=quart(x[i]-x[j])*(x[i]-x[j])+y[i]-y[j])*(y[i]-y[j]));
            if(jl[i][j]<minn)
            {
                minn=ji[i][j];
                start=i;
            }
        }
    }
    flag[start]=1;
    cout<<start<<" ";
    while(cnt)
    {
        minn=10000000;
        for(int i=1;i<=n;i++)
        {
            if(jl[start][i]<minn)
            {
                if(flag[i]==0)
                {
                    minn=jl[i][j];
                    start=i;
                }
            }
        }
        cout<<n+1-start<<" ";
        cnt--;
    }
    return 0;
}
