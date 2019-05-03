#include <bits/stdc++.h>
using namespace std;
#define mkp             make_pair
#define pii             pair<int,int>
#define MX              100005
#define PI              acos(-1)
#define sc(a)           scanf("%d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define pr(a)           printf("%d\n",a)
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b,c,d;
    char ch;
    pii Clock[5];
    sc(n);
    for(int i=1;i<=n;i++)
    {
        cin>>Clock[1].first>>ch>>Clock[1].second;
        cin>>Clock[2].first>>ch>>Clock[2].second;
        cin>>Clock[3].first>>ch>>Clock[3].second;
        cin>>Clock[4].first>>ch>>Clock[4].second;
        printf("Case %d: ",i);
        a=Clock[1].first*60+Clock[1].second;
        b=Clock[2].first*60+Clock[2].second;
        c=Clock[3].first*60+Clock[3].second;
        d=Clock[4].first*60+Clock[4].second;
        if((c>a&&c<=b)||c==a||c<a&&d>=a)
        {
            printf("Mrs Meeting\n");
        }
        else{
            printf("Hits Meeting\n");
        }




    }

    return 0;
}
