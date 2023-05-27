#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0;
long long flag[20000000];
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int i,j,c;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j;j--)
        {
            for(int c=k;c<=n;c++)
            {
                if(pow(j,c)==i && flag[i]!=1)
                {
                    flag[i]=1;
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
