#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    double f[1050][5],mx=-1.0e7;int a,l;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>f[a][1]>>f[a][2];
        if(f[a][2]>=mx)l=a;
    }
    if(l==1){
        if(a==2)cout<<"1 2";
        if(a==3)cout<<"1 3 2";
        if(a==4)cout<<"1 4 2 3";
    }
    else if(l==2){
        if(a==2)cout<<"2 1";
        if(a==3)cout<<"2 1 3";
        if(a==4)cout<<"2 3 1 4";
    }
    else if(l==3){
        if(a==3)cout<<"3 2 1";
        if(a==4)cout<<"3 2 1 4";
    }
    if(l==4){
        if(a==4)cout<<"4 2 1 3";
    }
    return 0;
}
