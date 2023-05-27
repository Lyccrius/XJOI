#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int a[55];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for(int i=1;i<=t;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("♿ ♿\n");
    }
    return 0;
}