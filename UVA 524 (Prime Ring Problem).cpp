#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 32
vector<int>ans;
bool taken[17];
int n;
int primes[MX];
bool flag[MX];
void sieve()
{
    for(int i=4;i<=MX;i+=2)
        flag[i]=1;
    int sq=sqrt(MX)+1;
            int total=0;
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
            if(!flag[i])
                primes[total++]=i;
        }

}
void backtrack()
{

    if(ans.size()==n)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=0)printf(" ");
            printf("%d",ans[i]);

        }
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {

        if(!taken[i])
        {
            int temp=ans.size();

            if(temp==n-1)
                temp=1;
           else if(temp!=0)
                temp=ans[temp-1];



            if(!flag[temp+i])
            {
                if(ans.size()>0&&flag[ans[ans.size()-1]+i])continue;
            taken[i]=true;
            ans.push_back(i);
            if(ans[0]!=1)return;
            backtrack();
            taken[i]=false;
            ans.pop_back();
            }
        }

    }

}
int main()
{

  // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
   sieve();
    int k=1;
   while(cin>>n)
   {
       if(k!=1)
        printf("\n");
    memset(taken,false,sizeof(taken));
    ans.clear();
    printf("Case %d:\n",k++);
    backtrack();

   }
    return 0;
}
