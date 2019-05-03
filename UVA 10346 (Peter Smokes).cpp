#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10001
int main()
{

   //  freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int n,k,c;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        c=n;
        while(n>=k)
        {
            c+=n/k;
            n=(n/k)+(n%k);
        }
        printf("%d\n",c);
    }
    return 0;
}
