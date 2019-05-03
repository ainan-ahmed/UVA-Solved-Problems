#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10000001
vector<char>ans;
bool taken[31];
string s;
   int n;
   int l;
void backtrack()
{

    if(ans.size()==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<l;i++)
    {
        if(ans.size()>0&&ans[ans.size()-1] > s[i])continue;
        if(!taken[i])
        {

            taken[i]=true;
            ans.push_back(s[i]);
            backtrack();
            taken[i]=false;
            ans.pop_back();
            while(s[i]==s[i+1])i++;
        }

    }

}
int main()
{

  // freopen("input.txt","r",stdin);
   //   freopen("output.txt","w",stdout);
   while(cin>>s>>n)
   {
    memset(taken,false,sizeof(taken));
    ans.clear();
   sort(s.begin(),s.end());
   l=s.length();
    backtrack();
   }
    return 0;
}
