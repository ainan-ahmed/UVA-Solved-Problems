#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define PI acos(-1)
#define MX   46345
int primes[MX];
bool flag[MX];
int total=1;
void sieve()
{
    for(int i=4;i<=MX;i+=2)
        flag[i]=1;
    int sq=sqrt(MX)+1;

        for(int i=3;i<=sq;i+=2)
        {
            if(flag[i]==0)
            {
                for(int j=i*i;j<=MX;j+=i)
                {
                    flag[j]=1;
                }



            }
        }
        for(int i=2;i<=MX;i++)
        {
            if(!flag[i]){
                primes[total]=i;
                total++;

            }
        }

}
int main()
{

    // freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    sieve();
   // cout<<primes[1]<<" "<<total<<endl;

    int n,temp;
    while(scanf("%d",&n))
    {
        if(n==0)return 0;
        if(n==-1)
        {
            printf("%d = -1\n",n);
            continue;
        }
        if(n==1)
        {
            printf("%d = 1\n",n);
            continue;
        }
        if(n<0)
                printf("%d = -1 x ",n);
            else
                 printf("%d = ",n);



                 n=abs(n);
                 temp=n;
                 int sum=1;

        for(int i=1;i<total&&primes[i]*primes[i]<=temp;i++)
        {
                while(temp%primes[i]==0)
                {

                    sum*=primes[i];
                    if(sum!=n)
                    printf("%d x ",primes[i]);
                    else
                        printf("%d",primes[i]);
                    temp=temp/primes[i];
                }
        }
        if(temp>1){

                printf("%d",temp);

        }
            printf("\n");

    }


    return 0;
}
