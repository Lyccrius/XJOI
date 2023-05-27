#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		int n,m,q,a[100004][100004];
		for(int j = 0;j < n; j++){
            for(int v = 0; v < m; v++){
                a[j][v] = 0;
            }
        }
		scanf("%d%d%d",&n,&m,&q);
        for(int j = 1; j <= q; j++){
            int opt,x,c;
            scanf("%d%d%d",&opt,&x,&c);
            if(opt == 0){
                for(int v = 0; v < m; v++){
                    a[j][x] = c;
                }
            }else{
                for(int v = 0; v < n; v++){
                    a[x][j] = c;
                }
            }
        }
        for(int j = 0;j < n; j++){
            for(int v = 0; v < m; v++){
                printf("%d ",a[j][v]);
            }
            printf("\n");
        }
	}
	return 0;
}
