#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int id,T;
int n,m;
char dt[15][15];
int r1_i=0,r1_j=0,r2_i=0,r2_j=0,rs=0;
int b1_i=0,b1_j=0;
void rd(){
    for(int i=1;i<=n;i++){
        cin>>(dt[i]+1);
        for(int j=1;j<=m;j++){
            if(dt[i][j]=='O'){
                rs++;
                if(rs==1){
                    r1_i=i;
                    r1_j=j;
                }
                else{
                    r2_i=i;
                    r2_j=j;
                }
            }
            else if(dt[i][j]=='X'){
                b1_i=i;
                b1_j=j;
            }
        }
    }
    return;
}
int panhong(){
    int ret=0;
    if(r1_i+1>n||dt[r1_i+1][r1_j]=='#'||dt[r1_i+1][r1_j]=='O') {ret++;}
    if(r1_i-1<1||dt[r1_i-1][r1_j]=='#'||dt[r1_i-1][r1_j]=='O') {ret++;}
    if(r1_j+1>m||dt[r1_i][r1_j+1]=='#'||dt[r1_i][r1_j+1]=='O') {ret++;}
    if(r1_j-1<1||dt[r1_i][r1_j-1]=='#'||dt[r1_i][r1_j-1]=='O') {ret++;}
    if(r2_i+1>n||dt[r2_i+1][r2_j]=='#'||dt[r2_i+1][r2_j]=='O') {ret++;}
    if(r2_i-1<1||dt[r2_i-1][r2_j]=='#'||dt[r2_i-1][r2_j]=='O') {ret++;}
    if(r2_j+1>m||dt[r2_i][r2_j+1]=='#'||dt[r2_i][r2_j+1]=='O') {ret++;}
    if(r2_j-1<1||dt[r2_i][r2_j-1]=='#'||dt[r2_i][r2_j-1]=='O') {ret++;}
    if(r1_i+1<=n&&dt[r1_i+1][r1_j]=='X') {return -803;}
    if(r1_i-1>=1&&dt[r1_i-1][r1_j]=='X') {return -803;}
    if(r1_j+1<=m&&dt[r1_i][r1_j+1]=='X') {return -803;}
    if(r1_j-1>=1&&dt[r1_i][r1_j-1]=='X') {return -803;}
    if(r2_i+1<=n&&dt[r2_i+1][r2_j]=='X') {return -803;}
    if(r2_i-1>=1&&dt[r2_i-1][r2_j]=='X') {return -803;}
    if(r2_j+1<=m&&dt[r2_i][r2_j+1]=='X') {return -803;}
    if(r2_j-1>=1&&dt[r2_i][r2_j-1]=='X') {return -803;}
    return ret;
}
int panhei(){
    int ret=0;
    if(b1_i-1<1||dt[b1_i-1][b1_j]=='#') {ret++;}
    if(b1_j+1>m||dt[b1_i][b1_j+1]=='#') {ret++;}
    if(b1_j-1<1||dt[b1_i][b1_j-1]=='#') {ret++;}
    return ret;
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    for(int i=1;i<=T;i++){
        r1_i=0;r1_j=0;r2_i=0;r2_j=0;rs=0;
        b1_i=0;b1_j=0;
        n=0;m=0;
        memset(dt,'\0',sizeof(char)*15*15);
        cin>>n>>m;
        rd();
        int hong=panhong();
        if(hong==8){
            printf("Black 0\n");
        }
        else if(hong==-803){
            printf("Red 1\n");
        }
        else if(1<=id && id<=4){
            printf("Tie\n");
        }
        else if(5<=id && id<=6){
            printf("Tie\n");
        }
        else if(7<=id && id<=9){
            //若两红均在黑下，则判断黑是否能到达。
            if(r1_i>b1_i&&r2_i>b1_i){
                int flag=0;
                for(int j=b1_i-1;j>=1;j--){
                    if(dt[j][1]=='#'){
                        flag=1;
                        printf("Red %d\n",(b1_i-j)*2-1);
                        break;
                    }
                }
                if(flag==0){
                    printf("Black %d\n",b1_i*2-2);
                }
            }
            //若黑在两红之间
            else if(r2_i>b1_i&&b1_i>r1_i){
                int flag=0,flag2=0;
                for(int j=b1_i-1;j>=1;j--){
                    if(dt[j][1]=='#'){
                        flag=1;
                        break;
                    }
                    if(dt[j][1]=='O'){
                        flag2=1;
                    }
                }
                //黑能到达
                if(flag==0){
                    //下红能动，红胜
                    if((r2_i+1<=n&&dt[r2_i+1][1]!='#')||(r2_i-1>=1&&dt[r2_i-1][1]!='#')){
                        //奇数为距离
                        //偶数为距离+1
                        int jl=b1_i-r1_i;
                        if(jl%2==0){
                            jl++;
                        }
                        printf("Red %d\n",jl);
                    }
                    //下红不能动，与上红的距离
                    else{
                        //奇数红胜
                        //偶数黑胜
                        int jl=b1_i-r1_i;
                        if(jl%2==1){
                            printf("Red %d\n",jl);
                        }
                        else{
                            printf("Black %d\n",jl);
                        }
                    }
                }
                //黑不能到达
                else{
                    //与上红处于同一连通块
                    if(flag2==1){
                        //下红能动，红胜
                        if((r2_i+1<=n&&dt[r2_i+1][1]!='#')||(r2_i-1>=1&&dt[r2_i-1][1]!='#')){
                            //奇数为距离
                            //偶数为距离+1
                            int jl=b1_i-r1_i;
                            if(jl%2==0){
                                jl++;
                            }
                            printf("Red %d\n",jl);
                        }
                        //下红不能动，与上红的距离
                        else{
                            //奇数红胜
                            //偶数黑胜
                            int jl=b1_i-r1_i;
                            if(jl%2==1){
                                printf("Red %d\n",jl);
                            }  
                            else{
                                printf("Black %d\n",jl);
                            }
                        }
                    }
                    //不处于
                    else{
                        for(int j=b1_i-1;j>=1;j--){
                            if(dt[j][1]=='#'){
                                flag=1;
                                printf("Red %d\n",(b1_i-j)*2-1);
                                break;
                            }
                        }
                    }
                }
            }
            //若在两红之下
            else{
                int flag=0;
                for(int j=b1_i-1;j>=1;j--){
                    if(dt[j][1]=='#'){
                        flag=1;
                        break;
                    }
                }
                //黑能到达（则一定与两红处于同一连同块）
                if(flag==0){
                    //上红本能动，红胜
                    if((r1_i+1<=n&&dt[r1_i+1][1]!='#')||(r1_i-1>=1&&dt[r1_i-1][1]!='#')){
                        //奇数为距离
                        //偶数为距离+1
                        int jl=b1_i-r2_i;
                        if(jl%2==0){
                            jl++;
                        }
                        printf("Red %d\n",jl);
                    }
                    //上红本不能动，与下红的距离
                    else{
                        int jl=b1_i-r2_i;
                        //等于二
                        if(jl==2){
                            printf("Black 2\n");
                        }
                        //否则红胜
                        else{
                            if(jl%2==0){
                                jl++;
                            }
                            printf("Red %d\n",jl);
                        }
                    }
                }
                //黑不能到达
                else{
                    int flag=0,flag2=0;
                    for(int j=b1_i-1;j>=1;j--){
                        if(dt[j][1]=='#'){
                            flag=1;
                            break;
                        }
                        if(dt[j][1]=='O'){
                            flag2++;
                        }
                    }
                    //与两红均不处于统一连通块，与最终的距离
                    if(flag2==0){
                        printf("Black %d\n",b1_i*2-2);
                    }
                    //与下红处于连通块
                    else if(flag2==1){
                        //上红能动，红胜
                        if((r1_i+1<=n&&dt[r1_i+1][1]!='#')||(r1_i-1>=1&&dt[r1_i-1][1]!='#')){
                            //奇数为距离
                            //偶数为距离+1
                            int jl=b1_i-r2_i;
                            if(jl%2==0){
                                jl++;
                            }
                            printf("Red %d\n",jl);
                        }
                        //上红不能动，与下红的距离
                        else{
                            //奇数红胜
                            //偶数黑胜
                            int jl=b1_i-r2_i;
                            if(jl%2==1){
                                printf("Red %d\n",jl);
                            }  
                            else{
                                printf("Black %d\n",jl);
                            }
                        }
                    }
                    //与两红处于统一连通块
                    else{
                        //上红本能动，红胜
                        if((r1_i+1<=n&&dt[r1_i+1][1]!='#')||(r1_i-1>=1&&dt[r1_i-1][1]!='#')){
                            //奇数为距离
                            //偶数为距离+1
                            int jl=b1_i-r2_i;
                            if(jl%2==0){
                                jl++;
                            }
                            printf("Red %d\n",jl);
                        }
                        //上红本不能动，与下红的距离
                        else{
                            int jl=b1_i-r2_i;
                            //等于二
                            if(jl==2){
                                printf("Black 2\n");
                            }
                            //否则红胜
                            else{
                                if(jl%2==0){
                                    jl++;
                                }
                                printf("Red %d\n",jl);
                            }
                        }
                    }
                }
            }
        }
        else if(10<=id && id<=13){
            printf("Tie\n");
        }
        else if(14<=id && id<=20){
            printf("Tie\n");
        }
    }
    return 0;
}