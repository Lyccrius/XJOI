#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int T,k;
int n;
int a[5][55000];
int retnk[10]={0,114514,25,12,12};
int bailan(int i){
    if(i>n){
        long long tc=-1;
        for(int j=1;j<=k;j++){
            long long tmax=-1,tmin=1145141919810;
            for(int qwq=1;qwq<=n;qwq++){
                if(a[j][qwq]<tmin){
                    tmin=a[j][qwq];
                }
                if(a[j][qwq]>tmax){
                    tmax=a[j][qwq];
                }
            }
            if(tmax-tmin>tc){
                tc=tmax-tmin;
            }
        }
        return tc;
    }
    long long tans=1145141919810;
    for(int j=0;j<k;j++){
        long long temp=bailan(i+1);
        if(temp<tans){
            tans=temp;
        }
        int aq1=a[1][i];
        for(int QAQ=1;QAQ<k;QAQ++){
            a[QAQ][i]=a[QAQ+1][i];
        }
        a[k][i]=aq1;
    }
    return tans;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d%d",&T,&k);
    for(int i=1;i<=T;i++){
        memset(a,0,sizeof(a)*5*55000);
        scanf("%d",&n);
        for(int j=1;j<=k;j++){
            for(int qwq=1;qwq<=n;qwq++){
                scanf("%d",&a[j][qwq]);
            }
        }
        if(n<retnk[k]){
            cout<<bailan(1)<<endl;
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}