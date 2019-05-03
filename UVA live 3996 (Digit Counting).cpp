#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define MX              100005
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define pr(a)           printf("%d\n",a)
int cnt[10];
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,a,temp;
    string s;
    sc(n);
    stringstream ss;
    while(n--)
    {
        sc(a);
        for(int i=1;i<=a;i++)
        {
            temp=i;
            while(temp>0)
            {
                cnt[temp%10]++;
                temp/=10;
            }
        }
    for(int i=0;i<=9;i++){

        printf("%d",cnt[i]);
        if(i!=9)printf(" ");
    }
        printf("\n");
    memset(cnt,0,sizeof(cnt));
    }
    return 0;
}
