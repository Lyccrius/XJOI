#include<bits/stdc++.h>
using namespace std;
int id,T,n,m,cnt,cnt2;
char a[15][15];
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    if(id==1||id==2||id==3||id==4){
        while(T--){
            cin>>n>>m;
            memset(a,'.',sizeof(a));
            cnt=cnt2=0;
            //side
            for(int i=0;i<=m+1;i++)
                a[0][i]='#',a[n+1][i]='#';
            for(int i=1;i<=n;i++)
                a[i][0]='#',a[i][m+1]='#';
            //cin
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    cin>>a[i][j];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(a[i][j]=='O'&&a[i-1][j]=='O'&&
                        a[i-1][j-1]=='#'&&a[i][j-1]=='#'&&
                        a[i+1][j]=='#'&&a[i][j+1]=='#'&&
                        a[i-1][j+1]=='#'&&a[i-2][j]=='#'){
                            cnt2++;
                            if(cnt2!=0){
                                cout<<"Black"<<' '<<0<<endl;
                                break;
                            }
                        }
                    else if(a[i][j]=='O'&&a[i+1][j]=='O'&&
                        a[i-1][j]=='#'&&a[i][j-1]=='#'&&
                        a[i+1][j-1]=='#'&&a[i+2][j]=='#'&&
                        a[i][j+1]=='#'&&a[i+1][j+1]=='#'){
                            cnt2++;
                            if(cnt2!=0){
                                cout<<"Black"<<' '<<0<<endl;
                                break;
                            }
                        }
                    else if(a[i][j]=='O'&&a[i][j-1]=='O'&&
                        a[i-1][j-1]=='#'&&a[i-1][j]=='#'&&
                        a[i][j-2]=='#'&&a[i][j+1]=='#'&&
                        a[i+1][j-1]=='#'&&a[i+1][j]=='#'){
                            cnt2++;
                            if(cnt2!=0){
                                cout<<"Black"<<' '<<0<<endl;
                                break;
                            }       
                        }
                    else if(a[i][j]=='O'&&a[i][j+1]=='O'&&
                        a[i][j-1]=='#'&&a[i][j+2]=='#'&&
                        a[i-1][j]=='#'&&a[i-1][j+1]=='#'&&
                        a[i+1][j]=='#'&&a[i+1][j+1]=='#'){
                            cnt2++;
                            if(cnt2!=0){
                                cout<<"Black"<<' '<<0<<endl;
                                break;
                            }
                        }
                    else if(a[i][j]=='O'&&
                        a[i-1][j]=='#'&&
                        a[i+1][j]=='#'&&
                        a[i][j-1]=='#'&&
                        a[i][j+1]=='#')
                            cnt++;
                    if(cnt==1)
                        continue;
                    if(cnt==2){
                        cnt2++;
                        if(cnt2!=0){
                            cout<<"Black"<<' '<<0<<endl;
                            break;
                        }
                    }
                }
            }
            if(cnt2==0)
                cout<<"Tie"<<endl;
        }
        return 0;
    }
    else cout<<"Tie"<<endl;
}