#include<bits/stdc++.h>
using namespace std;
struct chees{
    int x,y;
}b,r1,r2;
int id ,T,n,m,ans;
char mp[15][15];
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    while(T--){
        cin>>n>>m;
        int flag=0;
        ans=0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin>>mp[i][j];
                if(mp[i][j]=='X'){
                    b.x=i;
                    b.y=j;
                }else if(mp[i][j]=='O'&&flag==0){
                    r1.x=i;
                    r1.y=j;
                    flag=1;
                }
                else if(mp[i][j]=='O'&&flag==1){
                    r2.x=i;
                    r2.y=j;
                }
            }
        }        
        flag=1;
        if(id>=1&&id<=4){
            if(mp[r1.x-1][r1.y]!='.'&&mp[r1.x][r1.y+1]!='.'&&
               mp[r1.x][r1.y-1]!='.'&&mp[r1.x+1][r1.y]!='.'){
                flag=0;
                continue;
            }
            if(mp[r2.x-1][r2.y]!='.'&&mp[r2.x][r2.y+1]!='.'&&
               mp[r2.x][r2.y-1]!='.'&&mp[r2.x+1][r2.y]!='.'&&
               flag==0){
                cout<<"Black "<<0<<endl;
                continue;
            }
            cout<<"Tie"<<endl;
            continue;
        }
        if(id>=5&&id<=6){
            if(r1.y+1==b.y&&r1.x<b.x){
                cout<<"Red "<<1+2*(m-b.y+b.x-r1.x)<<endl;
                continue;
            }
            else if(r1.y-1==b.y&&r1.x<b.x){
                cout<<"Red "<<1+2*(b.y-1+b.x-r1.x)<<endl;
                continue;
            }else if(r1.y+1==b.y||r1.y-1==b.y){
                cout<<"Red "<<1<<endl;
                continue;
            }
            cout<<"Black "<<2*(b.x-1)<<endl;
            continue;
        }
        ans=0,flag=1;
        if(m==1){
            if(mp[r1.x-1][r1.y]=='X'||mp[r1.x+1][r1.y]=='X'){
                cout<<"Red "<<1<<endl;
                continue;
            }
            if(mp[r2.x-1][r2.y]=='X'||mp[r2.x+1][r2.y]=='X'){
                cout<<"Red "<<1<<endl;
                continue;
            }
            if(mp[r1.x-1][r1.y]!='.'&&mp[r1.x+1][r1.y]!='.'){
                flag=0;
                continue;
            }
            if(mp[r2.x-1][r2.y]!='.'&&mp[r2.x+1][r2.y]!='.'&&
               flag==0){
                cout<<"Black "<<0<<endl;
                continue;
            }
            for(int i=b.x-1;i>=1;i--){
                if(mp[i][1]=='#'){
                    cout<<"Red "<<1+(2*ans)<<endl;
                    break;
                }
                if(mp[i][1]=='O'){
                    if(ans%2==0){
                        cout<<"Red "<<ans+1<<endl;
                        break;
                    }else{
                        cout<<"Red "<<2*ans+1<<endl;
                        break;
                    }
                }
                ans++;
            }
            if(ans==n-2){
                cout<<"Black "<<2*(ans+1)<<endl;
                continue;
            }
            continue;
        }
        if(id>=10&&id<=13){
            cout<<"Tie"<<endl;
            continue;
        }
    }
    return 0;
}
