#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define long long       LL
#define pii             pair<int,int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define pr(a)           printf("%d\n",a)
#include <bits/stdc++.h>
#define PI acos(-1)
#define MX 1000001
int primes[MX];
bool flag[MX];
int ans1=-1,ans2=-1,mx=INT_MIN;
void sieve()
{
    int l=sqrt(MX)+1;
    for(int i=4;i<=MX;i+=2)flag[i]=1;
    for(int i=3;i<=l;i++)
    {
        if(flag[i]==0)
        {
            for(int j=i*3;j<=MX;j+=i)
            {
                flag[j]=1;
            }
        }

    }
    int k=0;
    for(int i=1;i<=MX;i++)
    {
        if(!flag[i])primes[k++]=i;
    }
}
void find_goldbach_conj(int n)
{
    int ans=0;
    for(int i=2;i<=n/2;i++)
    {
        if(!flag[i]&&!flag[n-i])
        {
            if(mx<((n-i)-i)){
            ans1=i,ans2=n-i;
            mx=((n-i)-i);
            }

        }
    }

}
int main()
{

    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    sieve();
    int n;
    while(sc(n))
    {
        if(n==0)return 0;
        find_goldbach_conj(n);
        if(ans1==-1&&ans2==-1)
            printf("Goldbach's conjecture is wrong.\n");
        else
        printf("%d = %d + %d\n",n,ans1,ans2);
        mx=INT_MIN;


    }
    return 0;
}
