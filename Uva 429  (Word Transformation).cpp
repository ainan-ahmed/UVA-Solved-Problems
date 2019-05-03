#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 100001
map<string,vector<string> > edges ;
map<string,bool> visited;
map<string,int> level;
int bfs(string source,string target)
{
    string u,v;
    queue<string>q;
    q.push(source);
    level[source]=0;
    visited[source]=true;

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
                if(temp==target)
                {
                    return level[temp];
                }

                q.push(temp);
            }
        }

    }
    return 0;
}
bool compare(string s,string s1)
{
    int c=0,l=s.length();
    if(s.length()!=s1.length())return false;
    for(int i=0; i<l; i++)
    {
        if(s[i]!=s1[i])c++;
    }
    if(c==1)return true;
    else
        return false;
}
int main()
{

   // freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    vector<string>vs;
    int t;
    string s,s1;
    scanf("%d",&t);
    while( t--)
    {
        while(cin>>s)
        {
            if(s=="*")break;
            vs.push_back(s);
        }
        int l=vs.size();

        for(int i=0; i<l; i++)
        {
            for(int j=i+1; j<l; j++)
            {
                if(compare(vs[i],vs[j]))
                {
                    edges[vs[i]].push_back(vs[j]);
                    edges[vs[j]].push_back(vs[i]);
                }
            }
        }
		getchar();
		string str;
        while(getline(cin,str))
        {
        	if(str == "") {
        		break;
        	}
        	int i;
        	int len = str.length();
        	s = "",s1 = "";
        	for(i = 0; str[i] != ' '; i++)
        		s += str[i];
        	for(int j = i+1; j < len; j++)
        		s1 += str[j];
           
            cout<<s<<" "<<s1<<" "<<bfs(s,s1)<<endl;
            visited.clear();
            level.clear();
        }
    
        edges.clear();

        vs.clear();
        if(t!=0)printf("\n");
       


    }



    return 0;
}
