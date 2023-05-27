#include<bits/stdc++.h>
using namespace std;

int n,m,q,mm[10005][10005],T;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin >> T;
    while(T--)
    {
        memset(mm,0,sizeof(mm));
        cin >> m >> n >> q;
        for(int i=1;i<=q;i++)
        {
            int o,x,c;
            cin >> o >> x >> c;
            if(o==0)
            {
                for(int j=1;j<=m;j++)
                {
                    mm[x][j]=c;
                }
            }
            else if(o==1)
            {
                for(int j=1;j<=n;j++)
                {
                    mm[j][x]=c;
                }                
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout << mm[i][j] << " ";
            }
            cout <<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
