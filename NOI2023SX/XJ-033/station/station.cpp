#include <bits/stdc++.h>
using namespace std;
    struct B
    {
        int l,r;
    };
    B b[200005];
bool key[200005],f[200005];
int cnt,k1,k2;
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    int n,m,x;

    cin>>n>>m>>x;
    int a[n+5],c[n+5],result[n+5];
memset(a,0,sizeof(a));

    for(int i=1;i<=m;++i){
        cin>>b[i].l>>b[i].r;
    }
if(x==1){
 key[x]=1;
    a[0]=x;
    k1++;
for(int g=0;g<=n;++g){   
        if(k1<g)break;
    for(int i=1;i<=m;++i){
if(b[i].l<=a[g]&&b[i].r>a[g]&&f[i]==0){
    f[i]=1;
    result[cnt]=b[i].r;
    cnt++;
    for(int j=a[g];j<=b[i].r;++j){
        if(key[j]!=1){
            key[j]=1;
            a[k1]=j;
            k1++;
        }
    }
}
    }}
sort(result,result+cnt);
for(int i=0;i<cnt;++i){if(result[i]!=result[i-1]&&result[i]!=x)cout<<result[i]<<" "; }
    fclose(stdin);
    fclose(stdout);
    return 0;
}   

    key[x]=1;
    a[0]=x;
    k1++;
    for(int g=0;g<=n;++g){
    
        if(k1<g)break;
    for(int i=1;i<=m;++i){
if(b[i].l<a[g]&&b[i].r>=a[g]&&f[i]==0){
    f[i]=1;
    result[cnt]=b[i].l;
    cnt++;
    for(int j=a[g];j>=b[i].l;--j){
        if(key[j]!=1){
            key[j]=1;
            a[k1]=j;
            k1++;
        }
    }
}
    }}
memset(a,0,sizeof(a));
memset(f,0,sizeof(f));
k1=0,a[0]=x;
k1++;
for(int g=0;g<=n;++g){
    
        if(k1<g)break;
    for(int i=1;i<=m;++i){
if(b[i].l<=a[g]&&b[i].r>a[g]&&f[i]==0){
    f[i]=1;
    result[cnt]=b[i].r;
    cnt++;
    for(int j=a[g];j<=b[i].r;++j){
        if(key[j]!=1){
            key[j]=1;
            a[k1]=j;
            k1++;
        }
    }
}
    }}
sort(result,result+cnt);
for(int i=0;i<cnt;++i){if(result[i]!=result[i-1]&&result[i]!=x)cout<<result[i]<<" "; }
    fclose(stdin);
    fclose(stdout);
    return 0;
}