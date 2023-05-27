#include <iostream>
#include <cstring>
using namespace std;
int l[100050][3];
int r[100050][3];
int pan(int a,int b)
{
    if(l[a][2]>r[b][2])
    {
        return l[a][1];
    }
    else return r[b][1];
}
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        int n,m,p,i;
        cin>>n>>m>>p;
        for(i=1;i<=p;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a==1)
            {
                cin>>r[b][1];
                r[b][2]=i;
            }
            if(a==0)
            {
                cin>>l[b][1];
                l[b][2]=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<pan(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}