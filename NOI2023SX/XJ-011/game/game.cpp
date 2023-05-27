#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int fb[m+10];
        int a[n+10][4],b[n+10][4],bb[n+10][4];
        vector<int> f[m+10];
        for(int i=1;i<=m;i++)
        {
            fb[i]=0;
        }
        int x=0,q=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i][0]);
            if(a[i][0]==1) scanf("%d",&a[i][1]);
            else scanf("%d %d",&a[i][1],&a[i][2]);
        }
        int p=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i][0]);
            if(b[i][0]==1) scanf("%d",&b[i][1]),f[b[i][1]].push_back(i),bb[i][1]=f[b[i][1]].size();
            else scanf("%d %d",&b[i][1],&b[i][2]),f[b[i][1]].push_back(i),f[b[i][2]].push_back(i),bb[i][1]=f[b[i][1]].size(),bb[i][2]=f[b[i][2]].size();
            if(b[i][0]==1)
            {
                fb[b[i][1]]++;
                if(fb[b[i][1]]>1) q=-1;
                if(a[i][1]==b[i][1]||a[i][0]==2&&a[i][2]==b[i][1]) x++;
            }
            if(b[i][1]==i&&b[i][2]%n==(i+1)%n||b[i][2]==i&&b[i][1]%n==(i+1)%n);
            else p=0;
        }
        if(q==-1)
        {
            printf("-1\n");
            continue;
        }
        if(p==1)
        {
            int ans1=0,ans2=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i][1]==i||a[i][0]==2&&a[i][2]==i) ans1++; 
            }
            for(int i=1;i<=n-1;i++)
            {
                if(a[i][1]==i+1||a[i][0]==2&&a[i][2]==i+1) ans2++; 
            }
            if(a[n][1]==1||a[n][0]==2&&a[n][2]==1) ans2++;
            printf("%d\n",min(ans1,ans2));
            continue;
        }
        int l=n;
        int u=0;
        while(1)
        {
            for(int i=1;i<=l;i++)
            {
                if(i>n) break;
                if(b[i][0]==1)
                {
                    u++;
                    for(int j=0;j<f[b[i][1]].size();j++)
                    {
                        if(b[f[b[i][1]][j]][0]==2)
                        {
                            if(b[f[b[i][1]][j]][1]==b[i][1])
                            {
                                fb[b[f[b[i][1]][j]][2]]++;
                                if(fb[b[f[b[i][1]][j]][2]]>1) q=-1;
                                if(a[f[b[i][1]][j]][1]==b[f[b[i][1]][j]][2]||a[f[b[i][1]][j]][0]==2&&a[f[b[i][1]][j]][2]==b[f[b[i][1]][j]][2]) x++;
                                b[f[b[i][1]][j]][1]=b[f[b[i][1]][j]][2];
                            }
                            if(b[f[b[i][1]][j]][2]==b[i][1])
                            {
                                fb[b[f[b[i][1]][j]][1]]++;
                                if(fb[b[f[b[i][1]][j]][1]]>1) q=-1;
                                if(a[f[b[i][1]][j]][1]==b[f[b[i][1]][j]][1]||a[f[b[i][1]][j]][0]==2&&a[f[b[i][1]][j]][2]==b[f[b[i][1]][j]][1]) x++;
                            }
                            b[f[b[i][1]][j]][0]=1;
                        }
                    }
                    while(b[n][0]==1) n--;
                    b[i][0]=b[n][0];
                    b[i][1]=b[n][1];
                    b[i][2]=b[n][2];
                    a[i][0]=a[n][0];
                    a[i][1]=a[n][1];
                    a[i][2]=a[n][2];
                    n--;
                }
            }
            if(u==0) break;
        }
        for(int i=1;i<=n;i++)
        {
            if(fb[b[i][1]]==1&&fb[b[i][2]]==1)
            {
                q=-1;
                break;
            }
            if(fb[b[i][1]]==1)
            {
                fb[b[i][2]]++;
                if(a[i][1]==b[i][2]||a[i][0]==2&&a[i][2]==b[i][2]) x++;
            }
            if(fb[b[i][2]]==1)
            {
                fb[b[i][1]]++;
                if(a[i][1]==b[i][1]||a[i][0]==2&&a[i][2]==b[i][1]) x++;
            }
        }
        if(q==-1)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",x);
    }
    return 0;
}