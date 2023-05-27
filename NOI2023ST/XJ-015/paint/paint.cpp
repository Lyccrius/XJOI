#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+10;
bool opt[N];
int x[N], c[N];

int main(){
 	int t, n, m, q, opt1, x1, c1, idx, tot;
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
    scanf("%d", &t); 
    while(t--){
        scanf("%d%d%d", &n, &m, &q);
        memset(opt, 0, sizeof(opt));
        memset(x, 0, sizeof(x));
        memset(c, 0, sizeof(c));
        idx = 1;
        while(q--){
            scanf("%d%d%d", &opt1, &x1, &c1);
			opt[idx] = opt1;
			x[idx] = x1;
			c[idx] = c1;
			idx++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
				tot = 0;
				for(int k = 1; k < idx; k++){
					if(opt[k] && x[k] == j)tot = c[k];
					if(!opt[k] && x[k] == i)tot = c[k];
				}
                printf("%d ", tot);
            }
            printf("\n");
        }
    }
	return 0;
}
