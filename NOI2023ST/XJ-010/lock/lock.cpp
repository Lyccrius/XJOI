/*#include<iostream>
using namespace std;
int n,C=2147483648;
int lock[5][10005];
int T,k;
void down(int a)
{
    for(int i=n;i>=0;i--)
    {
        lock[a][i]=lock[a][i-1];
    }
    lock[a][0]=lock[a][n];
    return;
}
void dfs(int now)
{
    for(int i=1;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=lock[i]-lock[i-1];
            if(c<C) C=c;
        }
    }
    if(now==n*k) return;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            dfs(now+1);
            down(k);
            dfs(now+1);
        }
        
    }
}
int main()
{
//    freopen("lock.in","r",stdin);
//    freopen("lock.out","w",stdout);
    cin>>T>>k;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin>>lock[j][i];
            }
        }
        dfs(0);
    }
 //   fclose(stdin);
 //   fclose(stdout);
    return 0;
}
*/
#include<iostream>
using namespace std;
int n,C=2147483648;
int lock[5][10005];
int T,k;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>T>>k;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin>>lock[j][i];
            }
        }
        int aa,bb;
        aa=rand()%k;
        for(int i=0;i<100;i++) C=C%8+3;
        bb=rand()%n;
        int a=lock[aa][bb];
        for(int i=0;i<100;i++) C=C%8+3;
        aa=rand()%k;
        for(int i=0;i<100;i++) C=C%8+3;
        bb=rand()%n;
        int b=lock[aa][bb];
        if(a-b>0) cout<<a-b<<endl;
        else cout<<b-a<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}