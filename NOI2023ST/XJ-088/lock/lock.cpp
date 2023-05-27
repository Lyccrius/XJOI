                                                                                                                                  using namespace std;
int a[50010][4];
int ad[50010][4],ax[50010][4];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int x,y;
    scanf("%d%d",&x,&y);
    while(x--){
         int n;
         scanf("%d",&n);
         int d,sm;
         int s=50010;
         for(int i=1;i<=n;i++){
           int dd=-1,xx=50010;
           for(int j=1;i<=y;j++){
             scanf("%d",&a[i][j]);
             if(dd<=a[i][j]){
               dd=a[i][j];
               d=i;
             }
             if(xx>a[i][j]){
               xx=a[i][j];
               sm=i;
             }
           }
           int x1=y-d,x2=sm-1;
           for(int j=1;j<=y;j++){
                ad[i][(j+x1)%4]=a[i][j],ax[i][(j+x2)%4]=a[i][j];
           }
         }
         for(int j=1;j<=y;j++){
           int dmaxn=-1,xmaxn=-1,dminn=50010,xminn=50010;
           for(int i=1;i<=n;i++){
             dmaxn=max(ad[i][j],dmaxn);
             xmaxn=max(ax[i][j],xmaxn);
             dminn=min(ad[i][j],dminn);
             xminn=min(ax[i][j],xminn);
           }
           s=min(dmaxn-dminn,min(s,xmaxn-xminn));
         }
         printf("%d\n",s);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
