#include <bits/stdc++.h>

using namespace std;

long long a,b;
bool num[1999999999]={0};
long long sum=0;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin >> a >> b;
    if(a==0)
    {
        cout << "0";
        return 0;
    }
    if(b==0||b==1)
    {
        cout << a;
        return 0;
    }
    sum=1;
    for(long long i=2;i<=a;i++)
    {
        for(long long j=b;int(pow(i,j))<=a;j++)
        {
            long long temp = int(pow(i,j));
            if(!num[temp])
            {
                num[temp]=1;
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}