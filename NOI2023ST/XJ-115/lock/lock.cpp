#include<bits/stdc++.h>
using namespace std;
int t,n,k,a,b,j,i,l[20005][20005],mo;
int main()
{
    //freopen("lock.in","r",stdin);
    //freopen("lock.out","w",stdout);
    cin>>t>>k;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>l[j][i];
            }
        }
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=n;j++)
            {
                cout<<l[j][i]<<" ";
            }
            printf("\n");
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}