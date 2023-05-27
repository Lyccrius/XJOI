#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T,k;
    scanf("%d%d",&T,&k);
    while(T--){
        int n;
        scanf("%d",&n);
        int min=0x3f3f3f3f;
        int max=0;
        for(int i=1;i<=n;i++){
            int t;
            scanf("%d",&t);
            if(t<min) min=t;
            if(t>max) max=t;
        }
        printf("%d\n",max-min);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}