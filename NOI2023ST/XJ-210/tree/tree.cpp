#include<bits/stdc++.h>
using namespace std;

int n;
double x[10010],y[10010];
double d[10100][10100];

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    if(n==1)cout<<1;
    if(n==2){
        if(y[1]>=y[2])cout<<1<<2;
        else cout<<2<<1;
    }
    if(n==3){
        d[1][2]=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
        d[3][2]=sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]));
        d[1][3]=sqrt((x[1]-x[3])*(x[1]-x[3])+(y[1]-y[3])*(y[1]-y[3]));
        if(d[1][2]>d[1][3]){
            if(y[1]>=y[2]&&y[1]>=y[3])cout<<1<<3<<2;
            else if(y[2]>=y[1]&&y[2]>=y[3]&&y[1]>=y[3])cout<<2<<3<<1;
            else if(y[3]>=y[1]&&y[3]>=y[2])cout<<3<<1<<2;
            else if(y[2]>=y[1]&&y[2]>=y[3]&&y[1]>=y[3])cout<<2<<3<<1;
        }
        else{
            if(y[1]>=y[2]&&y[1]>=y[3])cout<<1<<2<<3;
            else if(y[2]>=y[1]&&y[2]>=y[3])cout<<2<<1<<3;
            else if(y[3]>=y[1]&&y[3]>=y[2]&&y[1]>=y[3])cout<<3<<1<<2;
            else if(y[2]>=y[1]&&y[1]>=y[3])cout<<2<<1<<3;
        }
    }

    return 0;
}