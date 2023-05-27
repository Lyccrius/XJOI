#include <iostream>
using namespace std;
int sid,n,k,m,w[100100],p[200100][2],pl[100100],b[100100],ps[200100];//way people
void find()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0) continue; 
        if(b[i]==1)
        {
            for(int j=1;j<=k;j++)
            {
                if(p[j][0]==i)
                {
                    ans+=p[j][1];
                    pl[j]=1;
                    break;
                }
            }
        int cnt=0;
        for(int j=1;j<=k;j++)
            {
                if(p[j][0]==i&&p[j][1]>cnt)
                {
                    pl[j]=1;
                    cnt=p[j][1];
                }
            }
        }   
    }
    cout<<ans<<" ";
}
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    cin>>sid>>n>>k>>m;
    for(int i=2;i<=n;i++)
    for(int i=1;i<=k;i++)
    {
        cin>>p[i][0]>>p[i][1];
        b[p[i][0]]++;
    }
    find();
    for(int i=1;i<=m;i++)
    {
        int a1;
        cin>>a1;
        if(a1==1)
        {
            int x,v;
            cin>>x>>v;
            b[x]++;
            k++;
            p[k][0]=x,p[k][1]=v;
        }
        else{
            int id;
            cin>>id;
            b[p[id][0]]--;
            p[id][0]=p[id][1]=-1;
        }
        find();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}