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
#define PI acos(-1)
#define MX  100000001
vector<int>primes;
bool flag[MX];
int ans1=-1,ans2=-1,mn=INT_MAX;
void sieve()
{
    int l=sqrt(MX)+1;
    flag[1]=1;
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

    for(int i=2;i<=MX;i++)
    {
        if(!flag[i])primes.push_back(i);
    }
}
void find_goldbach_conj(int n)
{
    int val=0,i=0;
    vector<int>::iterator tmp;
    tmp=upper_bound(primes.begin(),primes.end(),n/2);
    i=tmp-primes.begin();
  //  cout<<i<<endl;
    while(i>=0)
    {

        val=primes[i];
        --i;

    //cout<<val<<" "<<n-val<<endl;

       if(val==n-val){
            continue;


       }
        if(!flag[n-val])
        {

            ans1=min(val,n-val),ans2=n-ans1;
           return;

        }

    }

}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    sieve();
    int n;
    while(sc(n)!=EOF)
    {
        if(n<=4)
        {
            printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        //if(n==0)return 0;
        if(n%2)
        {


            if(!flag[n-2])
             printf("%d is the sum of 2 and %d.\n",n,n-2);
             else
                 printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        find_goldbach_conj(n);
        if(ans1==-1&&ans2==-1)
            printf("%d is not the sum of two primes!\n",n);
        else
        printf("%d is the sum of %d and %d.\n",n,ans1,ans2);

        ans1=-1,ans2=-1;
        mn=INT_MAX;

    }
    return 0;
}
