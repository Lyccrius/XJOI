#include<bits/stdc++.h>
using namespace std;
double dis(double xx,double yy,double xxx,double yyy){
    return sqrt(pow(xx-xxx,2)+pow(yy-yyy,2));
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    double x[10];
    double y[10];
    cin>>n;
    if(n==3){
        cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
        double maxx=max(y[1],max(y[2],y[3]));
        if(maxx==y[1]){
            double dis1=dis(x[1],x[2],y[1],y[2])+dis(x[2],x[3],y[2],y[3]);
            double dis2=dis(x[1],x[3],y[1],y[3])+dis(x[3],x[2],y[3],y[2]);
            if(dis1<=dis2){
                cout<<1<<' '<<2<<' '<<3;
                return 0;
            }
            else{
                cout<<1<<' '<<3<<' '<<2;
                return 0;
            }
        }
        if(maxx==y[2]){
            double dis1=dis(x[2],x[1],y[2],y[1])+dis(x[1],x[3],y[1],y[3]);
            double dis2=dis(x[2],x[3],y[2],y[3])+dis(x[3],x[1],y[3],y[1]);
            if(dis1<=dis2){
                cout<<2<<' '<<1<<' '<<3;
                return 0;
            }
            else{
                cout<<2<<' '<<3<<' '<<1;
                return 0;
            }
        }
        if(maxx==y[3]){
            double dis1=dis(x[3],x[1],y[3],y[1])+dis(x[1],x[2],y[1],y[2]);
            double dis2=dis(x[3],x[2],y[3],y[2])+dis(x[2],x[1],y[2],y[1]);
            if(dis1<=dis2){
                cout<<3<<' '<<1<<' '<<2;
                return 0;
            }
            else{
                cout<<3<<' '<<2<<' '<<1;
                return 0;
            }
        }
    }
}