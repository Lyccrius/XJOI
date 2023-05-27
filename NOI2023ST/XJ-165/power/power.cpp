#include <iostream>
using namespace std;
long long ans=1,p[(int)1e7];
bool pan(int a)
{
    for(int i=1;i<=ans;i++)
    {
        if(a==p[i]) return 0;
    }
    return 1;
}
int pow(int a,int b)
{
    int x;
    x=1;
    for(int i=1;i<=b;i++)
    {
        x*=a;
    }
    return x;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
    }
    else if(k>=n) cout<<1;
    else
    {
        for(long long i=2;pow(i,k)<=n;i++)
        {
            int c;
            for(long long j=k;;j++)
            {
                c=pow(i,j);
                if(c>n) break;
                if(pan(c))
                {
                    p[ans]=c;
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}