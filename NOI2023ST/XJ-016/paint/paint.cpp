#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,q,T;
	int a[1010][1010];
	int opt,x,c;
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while(T--){
		cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=0;
			}
			while(q--){
				cin>>opt>>x>>c;
				if(opt==1){
					for(int i=1;i<=n;i++){
						a[i][x]=c;
					}
				}
				else{
					for(int i=1;i<=m;i++){
						a[x][i]=c;
					}
				}
			}   
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					printf("%d ",a[i][j]);
				}
				printf("\n");
			}
        }   
    }
    return 0;
}
