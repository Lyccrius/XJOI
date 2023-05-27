//nopts code by Curlin
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int sid,n,k,m,cnt,sum;
int p[N],head[N],xmax[N],num[N],res[N];
struct member{
    int x,v;
}a[N];
struct edge{
    int to,nxt;
}e[N];
void strtree(int x,int y){
    e[++cnt].to=y;
    e[cnt].nxt=head[x];
    head[x]=cnt;
}
void mianA(){

}
void mianB(){

}
void mianAB(){

}
void mianC(){
    sum=num[1]; 
    res[1]=num[1]-1;
    for(int i=2;i<=n;i++){
        if(num[i]==0){
            if(res[p[i]]>0) res[p[i]]--,sum++;
            else res[p[i]]--;
        }
        else if(res[p[i]]>0) res[i]=res[p[i]]+num[i]-1,sum++;
        else res[i]=num[i]-1,sum++;
    }
    cout<<sum<<" ";
    for(int i=1;i<=m;i++){
        int kop;
        cin>>kop;
        if(kop==1){
            int x,v;
            cin>>x>>v;
            k++;
            num[x]++;
            if(num[x]==1) sum++;
            else{
                res[x]++;
                if(res[x]==1) sum++,res[x]--;
            }
        }
        else{
            int id;
            cin>>id;
            int kx=a[id].x;
            num[kx]--;
            if(num[kx]==0){
                if(res[p[kx]]) res[p[kx]]--;
                else sum--;
            }
        }
        /*int now=1;
        sum=min(num[1],now);
        res=max(num[1]-now,0);
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            int ak=0,pp=0,lo=0;
            for(int i=head[u];i;i=e[i].nxt){
                int j=e[i].to;
                ak+=num[j];
                pp++;
                if(num[j]==0) lo++;
                q.push(j);
            }
            if(res>lo){
                sum+=pp;
                res+=ak-pp;
            }
            else{
                sum+=pp+res-lo;
                res=0;
            }
        }*/
        cout<<sum<<" ";
    }
    exit(0);
}
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    cin>>sid;
    cin>>n>>k>>m;
    for(int i=2;i<=n;i++){
        cin>>p[i];//the department up on i is p[i]
        strtree(p[i],i);
    }
    for(int i=1;i<=k;i++){
        cin>>a[i].x>>a[i].v;//x is the department and v is his ability
        if(xmax[a[i].x]<a[i].v) xmax[a[i].x]=a[i].v;
        num[a[i].x]++;
    }
    switch (sid){
        case 6:
            mianB();
            break;
        case 8:
            mianA();
            break;
        case 9:
            mianAB();
            break;
        case 10:
            mianA();
            break;
        case 12:
            mianC();
            break;
        case 13:
            mianB();
            break;
        default:
            break;
    }
    for(int i=1;i<=m;i++){
        int kop;
        cin>>kop;
        if(kop==1){
            int x,v;
            cin>>x>>v;
            k++;
            a[k].x=x;
            a[k].v=v;
        }
        else{
            int id;
            cin>>id;
            int kx=a[id].x;
            if(xmax[kx]==a[id].v){
                //xmax[kx]=scmax(kx);
            }
        }
    }
}