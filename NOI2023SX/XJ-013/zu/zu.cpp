#include <bits/stdc++.h>
#define N 11
using namespace std;
int id,T;
int n,m;
char s[N][N];
int X[2],O[2][2];
int f1,f2,f3,f3l=0,f4,f5;//dfzd
int xr[5]={0,-1,0,1,0};
int yr[5]={0,0,-1,0,1};
int x3r[3]={0,1,-1};
int x3rr[3]={0,1,-1};
int step;
void dfsline(int f,int l)
{ 
    if(f==X[0]||l==X[0]) {f3l=1,f3=min(f3,step-1);return ;}
    if(s[X[0]-1][1]==0) {f3=step; return ;}        
    step+=1;
        if(s[X[0]-1][1]!='#') step+=1,X[0]-=1;
    else                  {f3=step; return ;} 
    for(int i=1;i<=2;i++) 
    {
        for(int j=1;j<=2;j++)
        {
            if(s[f+x3r[i]][1]!='#'||f+x3r[i]>0||f+x3r[i]<=n||s[l+x3rr[j]][1]!='#'||l+x3rr[j]>0||l+x3rr[j]<=n)
            dfsline(f+x3r[i],l+x3rr[j]);
        }
    }
    step-=1;
    return ;
}
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    while(T--)
    {
        memset(s,0,sizeof s);memset(O,0,sizeof O);memset(X,0,sizeof X);
        f1=f2=f3=f4=f5=0;
        cin>>n>>m;
        int fx=0,fo=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i]+1;
            if(fx==0&&fo==0)
            for(int j=1;j<=m;j++)
            {
                if(s[i][j]=='X') fx=1,X[0]=i,X[1]=j;
                if(s[i][j]=='O')
                {
                    int k=1;
                    for(k=1;k<=4;k++)
                    {
                        if(s[i+xr[k]][j+yr[k]]!=0&&s[i+xr[k]][j+yr[k]]!='#') break; 
                    }
                    if(k==5) f1++;
                    if(O[0][0]!=0) fo=1,O[1][0]=i,O[1][1]=j;
                    else            O[0][0]=i,O[1][1]=j;
                }
            }
        }
        if(id<=4)
        {
            if(f1==2) cout<<"Black 0"<<endl;
            else      cout<<"Tie"<<endl;
        }
        if(id>=5&&id<=6) cout<<"Red 1145"<<endl;
        if(id>=7&&id<=9) 
        {
            if(f1==2) {cout<<"Black 0"<<endl; continue;}
            f3=0,step=0,f3l=0;
            dfsline(O[0][0],O[1][0]);
            if(f3l==1) cout<<"Red ";
            else       cout<<"Black ";
            cout<<f3<<endl;
        }
    }
    return /*0^_^0*/0;
}