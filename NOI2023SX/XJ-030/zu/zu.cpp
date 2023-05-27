#include<bits/stdc++.h>
using namespace std;
int id,T,n,m,x0,x1,x2,y0,y1,y2;
int c[20];
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    for(int o=1;o<=T;o++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i];
                if(c[i]=='O'){
                    x0=i;
                    y0=j;
                }
                if(c[i]=='X'||x1==0){
                    x1=i;
                    y1=j;
                }
                else if(c[i]=='X'){
                    x2=i;
                    y2=j;
                }
            }
        }
        if(c[x1+1]=='#'&&c[x1-1]=='#'&&c[x2+1]=='#'&&c[x2-1]=='#'){
            cout<<"Black 0"<<endl;
            continue;
        }
        if(x0<x1&&x0<x2){
            int x=0;
            int ju=min(x1-x0,x2-x0);
            for(int i=x0-1;i>=1;i--){
                if(c[i]=='#'){
                    x=i;
                    break;
                }
            }
            if(x!=0){
                int xju=x0-x-1;
                if(x1-1==x0||x2-1==x0) cout<<"Red 1"<<endl;
                else if(ju<=xju) cout<<"Red "<<ju+xju+xju<<endl;
                else cout<<"Red "<<2*xju<<endl;
            }
            else{
                int xju=x0-1;
                if(x1-1==x0||x2-1==x0) cout<<"Red 1"<<endl;
                else if(ju>xju) cout<<"Black "<<2*xju<<endl;
                else cout<<"Black "<<xju+xju+ju-1;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}