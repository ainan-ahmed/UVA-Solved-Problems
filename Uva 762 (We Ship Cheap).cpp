#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 100001
map<string,vector<string> > edges ;
map<string,bool> visited;
map<string,string> parent;
map<string,int> level;
void bfs(string source)
{
    string u,v;
    queue<string>q;
    q.push(source);
    level[source]=0;
    visited[source]=true;
    parent[source]=source;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        int l=edges[u].size();
        for(int i=0; i<l; i++)
        {
            if(visited[edges[u][i]]==false)
            {
                string temp=edges[u][i];
                visited[temp]=true;
                level[temp]=level[u]+1;
                parent[temp]=u;
                q.push(temp);
            }
        }

    }

}
void shortest_path(string s,string s1)
{
    vector<string>v;
    v.push_back(s1);
    string s2;
    while(s1!=s)
    {
        // cout<<"asd"<<endl;
        if(parent[s1].empty()){
                 printf("No route\n");
           return ;
        }
        s2 += s1;
        s1=parent[s1];
        s2+=s1;
        v.push_back(s1);



    }





    int l=s2.length();
    reverse(s2.begin(),s2.end());
    for(int i=0;i<l;i+=4)
    {
        cout<<s2[i+1]<<s2[i]<<" "<<s2[i+3]<<s2[i+2]<<endl;
    }

}
int main()
{

   // freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);
    int n,c=0;
    string s,s1;
    while( scanf("%d",&n)!=EOF)
    {
        c++;
        for(int i=1; i<=n; i++)
        {
            cin>>s>>s1;
            edges[s].push_back(s1);
            edges[s1].push_back(s);
        }

        cin>>s>>s1;

        bfs(s);
        if(c!=1)printf("\n");
        shortest_path(s,s1);
        edges.clear();
        visited.clear();
        parent.clear();
        level.clear();

    }


    return 0;
}
