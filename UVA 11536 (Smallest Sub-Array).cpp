#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define vii             vector<int>
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define scll(a)         scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define PI acos(-1)
#define MX  1000001
bool flag[MX];
int store[MX];
int pos[MX];
int next_pos[MX];
int ans=INT_MAX;
int main()
{

    // freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int n,t,k,m;
    sc(t);
    for(int tc=1;tc<=t;tc++)
    {
        sc3(n,m,k);
        printf("Case %d: ",tc);
        store[1]=1;
        store[2]=2;
        store[3]=3;
        for(int i=4;i<=n;i++)
        {
            store[i]=(store[i-1]+store[i-2]+store[i-3])%m+1;
        }
        mmset(pos,-1);
        mmset(flag,0);
        ans=INT_MAX;
        for(int i=n;i>=1;i--)
        {
            next_pos[i]=pos[store[i]];
            pos[store[i]]=i;
        }

        int low=1,high=-1,cnt=0;
        for(int i=1;i<=n;i++)
        {
                if(store[i]<=k&&!flag[store[i]])
                {
                    cnt++;
                    flag[store[i]]=1;
                }
                if(cnt==k)
                {
                    high=i;
                    break;
                }

        }
        if(high==-1)
        {
            printf("sequence nai\n");
            continue;
        }
        ans=high-low+1;

        while(low<high)
        {
            if(store[low]>k)low++;
            else if(next_pos[low]==-1)break;
            else if(next_pos[low]<=high)low++;
            else
            {
                high=next_pos[low];
                low++;
            }
            ans=min(ans,high-low+1);

        }


    Pr(ans);

    }

    return 0;
}
