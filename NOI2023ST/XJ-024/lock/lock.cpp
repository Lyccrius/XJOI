#include<bits/stdc++.h>
using namespace std;
int T,n,num1,num2,cnt,ans=2147483647,k,l[3][50005];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>T>>k;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int a=1;a<=k;a++)
        {
            for(int b=1;b<=n;b++)
            {
                cin>>l[a][b];
            }
        }
        for(int p=1;p<=n;p++)
        {
            for(int q=1;q<=k;q++)
            {
                cnt=-1;
                for(int a=1;a<=k;a++)
                {
                    for(int b=1;b<=n;b++)
                    {
                        num1=max(l[a][b],num1);
                        num2=min(l[a][b],num2);
                    }
                    cnt=max(num1-num2,cnt);
                }
                ans=min(ans,cnt);
                for(int a=2;a<=k;a++)
                {
                    cnt=l[k][p];
                    l[a][p]=l[a-1][p];
                }
                l[1][p]=cnt;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}