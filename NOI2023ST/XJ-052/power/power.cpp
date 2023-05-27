#include<iostream>
using namespace std;
int n,k;
int p[10000005],pnum,a[10000005][26];
void dod()
{
    int long long i,j,c;
    c=10000000;
    for(i=2;i<=c;i++)
    {
        pnum=0;
        for(j=1;j<=c;j=j*i)
        {
            a[i][++pnum]=j;
        }
        p[i]=pnum;
    }
}
int find(int t)
{
    int i,j;
    for(i=1;i<=100000;i++)
    {
        for(j=1;j<=p[i];j++)
        {
            if(t==a[i][j] && j>k)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int i,j,cnt=1;
    dod();
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        cnt=cnt+find(i);
    }
    cout<<cnt;
    return 0;
}