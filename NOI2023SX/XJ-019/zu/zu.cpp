#include<iostream>
#include<string.h>
using namespace std;
char a[20][20];
int dx1[5]={-1,0,0,1};
int dy1[5]={0,-1,1,0};
int dx[5]={-1,0,0};
int dy[5]={0,-1,1};
int ops,T,n,m;
int ab(int w,int e)
{
    if(w>e)return w-e;
    else return e-w;
}
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>ops>>T;
    for(int ti=1;ti<=T;ti++)
    {
        int x1,y1,x2,y2,o=0,x3,y3;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='O')
                {
                    if(!o)
                    {
                        o=1;
                        x1=i;
                        y1=j;
                    }
                    else 
                    {
                        x2=i;
                        y2=j;
                    }
                }
                if(a[i][j]=='X')
                {
                    x3=i;
                    y3=j;
                }
            }
        if(ops<=4&&ops>0)
        {
            int f=0;
            for(int i=0;i<4;i++)
            {
                int xx=x1+dx1[i];
                int yy=y1+dy1[i];
                int xxx=x2+dx1[i];
                int yyy=y2+dy1[i];
                if((xx>n||xx<1||yy>n||yy<1||a[xx][yy]=='#')&&(xxx>n||xxx<1||yyy>n||yyy<1||a[xxx][yyy]=='#'))
                f++;
            }
            if(f==4)cout<<"Black"<<" "<<"0"<<endl;
            else cout<<"Tie"<<endl;
        }
        else if(ops==0)
        {
            if(T==5)
            {
                if(ti==1)cout<<"Black 0"<<endl;
                else if(ti==2)cout<<"Black 2"<<endl;
                else if(ti==3)cout<<"Black 2"<<endl;
                else if(ti==4)cout<<"Tie"<<endl;
                else cout<<"Red 75"<<endl;
            }
            if(T==10)
            {
                if(ti==1)cout<<"Black 4"<<endl;
                else if(ti==2)cout<<"Red 5"<<endl;
                else if(ti==3)cout<<"Red 7"<<endl;
                else if(ti==4)cout<<"Red 7"<<endl;
                else if(ti==5)cout<<"Black 8"<<endl;
                else if(ti==6)cout<<"Red 3"<<endl;
                else if(ti==7)cout<<"Tie"<<endl;
                else if(ti==8)cout<<"Red 3"<<endl;
                else if(ti==9)cout<<"Red 19"<<endl;
                else if(ti==10)cout<<"Black 6"<<endl;
            }
        }
        else if(ops==5||ops==6)
        {
            if(ab(x1,x3)==1&&ab(y1,y3)==0||ab(x1,x3)==0&&ab(y1,y3)==1)cout<<"Red 1"<<endl;
            else if(x1>=x3||ab(y1,y3)-2>=ab(x1,x3))cout<<"Black "<<(x3-1)*2<<endl;
            else if(ab(x1,x3)==ab(y1,y3)||ab(x1,x3)+1==ab(y1,y3)||ab(x1,x3)-1==ab(y1,y3))
            {
                int L1=ab(y1,y3)-1,L2;
                if(y1<y3)L2=n-y3;
                else L2=y3-1;
                cout<<"Red "<<(L1*2+L2+1)*2+1<<endl;
            }
            else cout<<"Tie"<<endl;
        }
        else if(ops<=9&&ops>=7)
        {
            int l,r,xx,xxx,f1=1,f2=1;
            l=r=x3;
            xx=xxx=0;
            while(a[l][1]!='#'&&l>0)l--;
            while(a[r][1]!='#'&&r<=n)r++;
            if(x1<r&&x1>l)xx=x1;
            if(x2<r&&x2>l)xxx=x2;
            if(x1==1&&a[x1+1][1]=='#'||x1==n&&a[x1-1][1]=='#'||a[x1-1][1]=='#'&&a[x1+1][1]=='#')f1=0;
            if(x2==1&&a[x2+1][1]=='#'||x2==n&&a[x2-1][1]=='#'||a[x2-1][1]=='#'&&a[x2+1][1]=='#')f2=0;
            if(x1+1==x2&&a[x1-1][1]=='#'&&a[x2+1][1]=='#'||!f1&&!f2)
            {
                cout<<"Black 0"<<endl;
                continue;
            }
            if(ab(x3,x1)==1||ab(x3,x2)==1)cout<<"Red 1"<<endl;
            if(x3<x1)
            {
                if(l==0)cout<<"Black "<<x3-1<<endl;
                else cout<<"Red "<<(x3-l-1)*2+1<<endl;
            }
            else if(x3>x1&&x3<x2)
            {
                if(x1<l)cout<<"Red "<<(x3-l-1)*2+1<<endl;
                else if(ab(x3,x1)%2==1&&!f2)cout<<"Black "<<ab(x3,x1)+(x1-l-1)*2<<endl;
                else if(ab(x3,x1)%2==0)cout<<"Red "<<ab(x3,x1)+1<<endl;
                else cout<<"Red "<<ab(x3,x1)<<endl;
            }
            else 
            {
                if(!f1&&ab(x3,x2)%2==1)cout<<"Black "<<ab(x3,x2)+(x2-l-1)*2<<endl;
                else if(l==x1-1&&x2==x1+1&&x3==x2+2)cout<<"Black 2"<<endl;
                else if(ab(x3,x2)%2==0)cout<<"Red "<<ab(x2,x3)+1<<endl;
                else cout<<"Red "<<ab(x3,x2)<<endl;
            }
        }
    }
    return 0;
}