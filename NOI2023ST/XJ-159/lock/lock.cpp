#include <bits/stdc++.h>

using namespace std;

long long T,k,locked[3][150000],MAX[3]={0},MIN[3]={999999999999,999999999999,999999999999},delta[3]={0},ALL_MAX=0,n;
long long dp_max[3][900000]={0},dp_min[3][900000]={0};
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> T >> k;
    for(long long t=0;t<T;t++)
    {
        cin >> n;
        for(long long i=0;i<n;i++)
        {
            for(long long j=0;j<k;j++)
            {
                cin >> locked[i][j];
                if(locked[i][j]>MAX[i])
                {
                    MAX[i]=locked[i][j];
                    delta[i]=MAX[i]-MIN[i];
                    dp_max[0][i]=MAX[i];
                }
                if(locked[i][j]<MIN[i])
                {
                    MIN[i]=locked[i][j];
                    delta[i]=MAX[i]-MIN[i];
                    dp_min[0][i]=MAX[i];
                }
                if(delta[i]>ALL_MAX)
                {
                    ALL_MAX=delta[i];
                }
            }
        }
        if(ALL_MAX==0)
        {
            cout << "0";
        }
        cout << ALL_MAX;
    }
    return 0;
}