#include <cstdio>
#include <iostream>
using namespace std;
double sq(double s){
    double t=s;
    for(int i=1;i<=128;i++){
        t=(t+s/t)/2;
    }
    return t;
}
int n;
int k=1;
double x[1100],y[1100];
double a1=0,a0=0;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        if(y[i]>y[k]) k=i;
    }
    for(int i=0;i<n-1;i++){
        int i11=(k+i)%n,i12=(k+i+1)%n;
        int i01=(k-i+n)%n,i02=(k-i-1+n)%n;
        double xx1=x[i12]-x[i11];
        double xx0=x[i02]-x[i01];
        double yy1=y[i12]-y[i11];
        double yy0=y[i02]-y[i01];
        a1+=sq(xx1*xx1+yy1*yy1);
        a0+=sq(xx0*xx0+yy0*yy0);
    }
    if(a1<a0){
        for(int i=0;i<n;i++){
            printf("%d ",((k+i)%n)+1);
        }
    }
    else{
        for(int i=0;i<n;i++){
            printf("%d ",((k-i+n)%n)+1);
        }
    }
    return 0;
}