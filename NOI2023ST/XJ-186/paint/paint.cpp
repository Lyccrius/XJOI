#include<bits/stdc++.h>
using namespace std;
int a[100005][1000005],s[100005],n,m,q;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int opt,t,i,j,poi,x,c,hh,ll,yan,xia;
    cin>>t;
    while(t--)
    {
        //memset(h,0,sizeof(h));
        memset(a,0,sizeof(a));
        //memset(l,0,sizeof(l));
        queue<int>h,l;
        cin>>n>>m>>q;
        for(i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                h.push(c*10+x);
                s[i]=0;
            }
            else
            {
                l.push(c*10+x);
                s[i]=1;
            }
        }
        for(i=1;i<=q;i++)
        if(s[i]==0)
        {
            yan=h.front()/10;
            xia=h.front()%10;
            h.pop();
            for(j=1;j<=m;j++)
            a[xia][j]=yan;
        }
        else
        {
            yan=l.front()/10;
            xia=l.front()%10;
            l.pop();
            for(j=1;j<=n;j++)
            a[j][xia]=yan;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}