#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define PI acos(-1)
#define MX  20000004
int primes[MX];
bool flag[MX];
pii pr[200009];
int total=0,pos=1;
int sieve()
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

                if(total!=0&&primes[total-1]+2 ==primes[total])
                {
                    pr[pos]=mkp(primes[total-1],primes[total]);
                    //cout<<pr[pos].first<<" "<<pr[pos].second<<endl;
                    pos++;
                }
                total++;


            }
        }

}
int main()
{

    // freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    sieve();
    int n;
   // cout<<pos<<endl;
    while(sc(n)!=EOF)
    {
        printf("(%d, %d)\n",pr[n].first,pr[n].second);


    }


    return 0;
}
