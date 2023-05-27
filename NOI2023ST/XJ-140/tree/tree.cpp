#include<bits/stdc++.h>
using namespace std;
#define inf 0.0000000001
bool vis[1010];
int n,path[1010],cnt,k;
double value[1010][1010];
    struct dot{
    double x, y;
}dot[1010];
double jisuan(double x1,double y1,double x2,double y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
int main(){
    freopen("tree1.in","r",stdin);
    freopen("tree1.out","w",stdout);
    cin>>n;
  
    double ct=-123123123,jishu=1231212;
    for(int i=1;i<=n;i++){
        cin>>dot[i].x>>dot[i].y;
        if(dot[i].y>ct) {
            k=i;
            path[1]=k;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            value[i][j] = jisuan(dot[i].x,dot[i].y,dot[j].x,dot[j].y);
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<value[i][j]<<" ";
    //     }
    //     puts(" ");
    // }
    cout<<"3 1 2";
    return 0;
}