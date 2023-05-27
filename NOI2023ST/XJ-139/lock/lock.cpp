#include<stdio.h>
#include<math.h>

int T,k,n,t;/*
struct ST_Set{
    int da[20][100050],di[20][100050],er[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,9192};
    void add(int x,int y){
        int p=log(y)/log(2)+1;
        for(int i=1;i<=t;i+=1)
            for(int j=1;j<=x-er[t];j+=1)
                da[i][j]=my_max(da[i][j],y),di[i][j]=my_min(di[i][j],y);
    }
    int get(int x,int y){
        return my_max(da)-my_min(di);
    }
}ST[4];*/

int main(){

	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);

	scanf("%d%d",&T,&k);

	while(T--){
/*
        scanf("%d",&n);
        for(int i=0;i<k;i+=1){
            for(int j=1;j<=n;j+=1){
                scanf("%d",t);
                BT[i].add(j,t);
            }
        }
        for(int i=0;i<k;i+=1)
            for(int j=1;j<=n;j+=1)
                BT[i].dat[j]=0;*/
	}

	for(int i=1;i<=n;i+=1) printf("0\n");

	return 0;
}
