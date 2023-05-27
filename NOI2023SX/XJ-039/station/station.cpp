#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int br[200005]={0}, el[200005]={0};
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    memset(br, 0, sizeof(br));
    memset(el, 0x3f, sizeof(el));
    scanf("%d%d%d",&n,&m,&x);
    for(int i = 1; i <= m; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        br[l] = max(br[l], r);
        el[r] = min(el[r], l);
    }
    int minx = x, maxx = x;
    for(int i = x-1; i >= 1; i--)
        if(minx <= br[i])
            minx = i;
    for(int i = x+1; i <= n; i++)
        if(el[i] <= maxx)
            maxx = i;
    
    for(int i = 1; i <= x-1; i++)
        if(minx <= br[i])
            printf("%d ",i);
    for(int i = x+1; i <= n; i++)
        if(el[i] <= maxx)
            printf("%d ",i);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
