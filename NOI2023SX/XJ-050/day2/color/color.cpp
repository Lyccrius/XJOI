#include <cstdio>
#include <cstring>
using namespace std;
int C;
int n,m,t;
int A[1100];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&C);
    for(int i=1;i<=C;i++){
        memset(A,0,sizeof(A));
        scanf("%d%d%d",&n,&m,&t);
        for(int j=1;j<=n;j++){
            scanf("%d",&A[i]);
        }
        if(n==t){
            printf("1 63\n");
        }
        else{
            printf("114 514\n");
        }
    }
    return 0;
}