#include<bits/stdc++.h>
using namespace std;
const int M=5010;
int m,n,x,cnt,num1;
int ans[M],ans1[M],a[M];
int l[M],r[M],duan2[M],duan1[M];
void you(int xx){
    for(int i=1;i<=num1;i++){
        if(xx==l[a[i]]){
            ans[r[a[i]]]++;
        }
    }
    return ;
}
void zuo(int yy){
    for(int i=1;i<=num1;i++){
        if(yy==r[a[i]]){
            ans[l[a[i]]]++;
        }
    }
    return ;
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
        duan1[l[i]]=i;
        a[num1++]=i;
        duan2[r[i]]=i;
        if(x>=l[i]&&x<=r[i]){
            ans[l[i]]++;
            ans[r[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(x>=l[i]&&x<=r[i]){
            for(int j=x;j<=r[i];j++){
                if(duan1[j]) you(j);
            }
            for(int j=x;j>=l[i];j--){
                if(duan2[j]) zuo(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]!=0) ans1[++cnt]=i;
    }
    sort(ans1+1,ans1+cnt+1);
    for(int i=1;i<=cnt;i++){
        if(ans1[i]==x) continue;
        cout<<ans1[i]<<" "; 
    }cout<<cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
