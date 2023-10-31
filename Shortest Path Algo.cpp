#include<bits/stdc++.h>
using namespace std;
int main()
{
    int src,n,e,a,b,w;
    cout<<"Enter number of vertices in the graph: ";
    cin>>n;
    cout<<"Enter number of edges in the graph: ";
    cin>>e;
    vector<vector<int>> adj[n];
    int i,j;
    for(i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        vector<int> u,v;
        v.push_back(b);
        v.push_back(w);
        adj[a].push_back(v);
        u.push_back(a);
        u.push_back(w);
        adj[b].push_back(u);
    }
    cout<<"Enter the source vertex: ";
    cin>>src;
    set<pair<int,int>> st;
    vector<int> dist;
    for(i=0;i<n;i++)
    dist.push_back(INT_MAX);
    dist[src]=0;
    st.insert({0,src});
    int par[n];
    par[src]=-1;
    while(st.size())
    {
        pair<int,int> p=*st.begin();
        int cur_dist=p.first;
        int cur=p.second;
        st.erase(st.begin());
        for(i=0;i<adj[cur].size();i++)
        {
            if(cur_dist+adj[cur][i][1]<dist[adj[cur][i][0]])
            {
                par[adj[cur][i][0]]=cur;
                dist[adj[cur][i][0]]=cur_dist+adj[cur][i][1];
                st.insert({dist[adj[cur][i][0]],adj[cur][i][0]});
            }
        }
    }
    int dest,fdest;
    cout<<"Enter the destination Vertex: ";
    cin>>dest;
    fdest=dest;
    string path="";
    // path+=to_string(src);
    // path+="->"
    //path+=to_string(dest);
    //path+=" - ";
    while(dest!=-1)
    {
        path+=to_string(dest);
        path+="-";
        dest=par[dest];
    }
    path.pop_back();
    reverse(path.begin(),path.end());
    cout<<"Shorest distance between "<<src<<" and "<<fdest<<" is "<<dist[fdest]<<endl;
    cout<<"Shortest Path between "<<src<<" and "<<fdest<<" is ";
    cout<<path;
}