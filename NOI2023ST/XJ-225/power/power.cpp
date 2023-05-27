#include<stdio.h>
#include<map>
#include<math.h>
long long n,cnt;
int k;
struct node
{
    long long a;
    int b;
    bool operator < (const node a)const
    {
        return true; 
    }
};
std::map<node,long long>powers;
std::map<long long,bool>vis;
long long power(long long a,int b)
{
    //printf("calcing %lld^%d\n",a,b);
    node tmp;
    tmp.a=a;
    tmp.b=b;
    if(powers[tmp]!=0)
    {
        return powers[tmp];
    }
    if(a==0)return powers[tmp]=0;
    if(a==1)return powers[tmp]=1;
    if(b==1)return powers[tmp]=a;
    if(b==0)return powers[tmp]=1;
    return powers[tmp]=power(a,b-1)*a;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%lld %d",&n,&k);
    if(k==1)
    {
        printf("%lld\n",n);
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        //if(power(i,k)>n)continue;
        if(std::pow(i,k)>n)continue;
        for(int j=k;;j++)
        {
            //long long tmp=power(i,j);
            long long tmp=(long long)std::pow(i,j);
            //printf("= %lld\n",tmp);
            if(tmp>n)
            {
                break;
            }
            if(vis[tmp]==true)break;
            else
            {
                vis[tmp]=true;
                cnt++;
                //printf("%lld\n",cnt);
            }
        }
    }
    printf("%lld\n",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}