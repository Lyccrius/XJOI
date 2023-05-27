#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int id,t;
int n,m;
char a[11][11];
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d %d",&id,&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        int r1x=-1,r1y=-1,r2x=-1,r2y=-1,bx=-1,by=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='O'&&r1x==-1) r1x=i,r1y=j;
                else if(a[i][j]=='O') r2x=i,r2y=j;
                if(a[i][j]=='X') bx=i,by=j;
            }
        }
        if(id>=1&&id<=4)
        {
            int p=1;
            if(a[r1x+1][r1y]!='#'&&r1x+1<=n-1) p=0;
            if(r1x-1>=0&&a[r1x-1][r1y]!='#') p=0;
            if(a[r1x][r1y+1]!='#'&&r1y+1<=m-1) p=0;
            if(r1y+1>=0&&a[r1x][r1y-1]!='#') p=0;
            if(a[r2x+1][r2y]!='#'&&r2x+1<=n-1) p=0;
            if(r2x-1>=0&&a[r2x-1][r2y]!='#') p=0;
            if(a[r2x][r2y+1]!='#'&&r2y+1<=m-1) p=0;
            if(r2y-1>=0&&a[r2x][r2y-1]!='#') p=0;
            if(p==0) printf("Tie\n");
            else printf("Black 0\n");
        }
        else if(m==1)
        {
            int d1=-1,c1=-1,d2=-1,c2=-1;
            for(int i=0;i<bx;i++)
            {
                if(a[i][0]=='#') d1=i;
                if(a[i][0]=='O') c1=i;
            }
            for(int i=n-1;i>bx;i--)
            {
                if(a[i][0]=='#') d2=i;
                if(a[i][0]=='O') c2=i;
            }
            int p1=1,p2=1;
            if(a[r1x+1][r1y]!='#'&&r1x+1<=n-1) p1=0;
            if(r1x-1>=0&&a[r1x-1][r1y]!='#') p1=0;
            if(a[r1x][r1y+1]!='#'&&r1y+1<=m-1) p1=0;
            if(r1y+1>=0&&a[r1x][r1y-1]!='#') p1=0;
            if(a[r2x+1][r2y]!='#'&&r2x+1<=n-1) p2=0;
            if(r2x-1>=0&&a[r2x-1][r2y]!='#') p2=0;
            if(a[r2x][r2y+1]!='#'&&r2y+1<=m-1) p2=0;
            if(r2y-1>=0&&a[r2x][r2y-1]!='#') p2=0;
            if(p1==1&&p2==1) {printf("Black 0\n");continue;}
            if(c1==bx-1||c2==bx+1)     {printf("Red 1\n");continue;}
            if(d1==-1&&c1==-1){printf("Black %d\n",2*bx);continue;}
            if(c1>d1&&(p1==1||p2==1))
            {
                if((c1-bx)%2!=0) printf("Black %d\n",2*(bx-max(d1,0)+1));
            }
            printf("Red ");
            if(d1>c1)
            {
                printf("%d\n",(bx-d1)*2);    
            }
            else
            {
                printf("%d\n",(bx-c1)/2*2+1);
            }
        }
        else if(id>=5&&id<=6)
        {
            int s=0;
            if(r1y>by) s+=r1y-by;
            else s+=by-r1y;
            s+=r1x;
            if(s-1>bx||(s-bx)%2==0)  {printf("Black %d\n",2*bx);continue;}
            if(r1y>by) s=r1y-by;
            else s=by-r1y;
            if(s+1==bx-r1x||s-1==bx-r1x)
            {
                if(r1y==by||r1x==bx)        printf("Red 1\n");
                else if(r1y<by)             printf("Red %d\n",((m-1-r1y)+(bx-r1x))*2-1);
                else if(r1y>by)             printf("Red %d\n",((r1y)+(bx-r1x))*2-1);
            }
            else
            {
                printf("Red %d\n",(max(m-1-r1y,r1y)+(bx-r1x))*2-1);
            }
        }
        else printf("Tie\n");
    }
    return 0;
}