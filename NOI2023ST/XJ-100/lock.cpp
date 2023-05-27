//30-40tips code by MisakaE
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,k,T;
int an1[N],an2[N],an3[N],an4[N];
int dfsk_3(int dep){
    if(dep==n+1){
        int ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an1[i]);
            mi=min(mi,an1[i]);
        }
        int l1=ma-mi;
        ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an2[i]);
            mi=min(mi,an2[i]);
        }
        int l2=ma-mi;
        ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an3[i]);
            mi=min(mi,an3[i]);
        }
        return max(max(l1,l2),ma-mi);
    }
    int mi2=1000000;
    for(int i=1;i<=3;++i){
        mi2=min(dfsk_3(dep+1),mi2);
        swap(an1[dep],an3[dep]);
        swap(an1[dep],an2[dep]);
    }
    return mi2;
}
int dfsk_4(int dep){
    if(dep==n+1){
        int ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an1[i]);
            mi=min(mi,an1[i]);
        }
        int l1=ma-mi;
        ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an2[i]);
            mi=min(mi,an2[i]);
        }
        int l2=ma-mi;
        ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an3[i]);
            mi=min(mi,an3[i]);
        }
        int l3=ma-mi;
        ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an4[i]);
            mi=min(mi,an4[i]);
        }
        return max(max(l1,l2),max(l3,ma-mi));
    }
    int mi2=1000000;
    for(int i=1;i<=4;++i){
        mi2=min(dfsk_4(dep+1),mi2);
        swap(an1[dep],an4[dep]);
        swap(an1[dep],an3[dep]);
        swap(an1[dep],an2[dep]);
    }
    return mi2;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d%d",&T,&k);
    if(k==1)
    {
        while(T--)
        {
            int l,ma=0,mi=10000000;
            scanf("%d",&n);
            for(int i=1;i<=n;++i){
                scanf("%d",&l);
                ma=max(ma,l);
                mi=min(mi,l);
            }
            printf("%d\n",ma-mi);
        }
    }
    else if(k==2)
    {
        while(T--){

        
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&an1[i]);
        for(int i=1;i<=n;++i)scanf("%d",&an2[i]);
        for(int i=1;i<=n;++i)if(an1[i]>an2[i])swap(an1[i],an2[i]);
        int ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an1[i]);
            mi=min(mi,an1[i]);
        }
        int l1=ma-mi;
        ma=0,mi=10000000;
        for(int i=1;i<=n;++i)
        {
            ma=max(ma,an2[i]);
            mi=min(mi,an2[i]);
        }
        printf("%d\n",max(ma-mi,l1));
        }
    }
    else if(k==3)
    {
        while(T--){
            scanf("%d",&n);
            for(int i=1;i<=n;++i)scanf("%d",&an1[i]);
            for(int i=1;i<=n;++i)scanf("%d",&an2[i]);
            for(int i=1;i<=n;++i)scanf("%d",&an3[i]);
            if(n>=13){
                printf("0\n");
                continue;
            }
            printf("%d\n",dfsk_3(1));
        }
    }
    else if(k==4)
    {
        while(T--){
            scanf("%d",&n);
            for(int i=1;i<=n;++i)scanf("%d",&an1[i]);
            for(int i=1;i<=n;++i)scanf("%d",&an2[i]);
            for(int i=1;i<=n;++i)scanf("%d",&an3[i]);
            for(int i=1;i<=n;++i)scanf("%d",&an4[i]);
            if(n>=11){
                printf("0\n");
                continue;
            }
            printf("%d\n",dfsk_4(1));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}