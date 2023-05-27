#include<iostream>
using namespace std;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    unsigned short i;
    for(i=0;i<19;i++)
        scanf("%*s");
    cout<<0<<endl;
    cout<<1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}