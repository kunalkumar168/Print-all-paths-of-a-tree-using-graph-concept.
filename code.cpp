#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ulli unsigned long long int 
#define pii pair<int,int>
#define pui pair<ll,ll>

using namespace std;
void addnode(vector <ll> *adj,ll s,ll e)
{
    adj[s].pb(e);
    adj[e].pb(s);
}

void dfs(vector <ll> *adj,bool *visit,ll u,ll *path,ll &pathind,ll v)
{
    visit[u]=true;
    path[pathind]=u;
    pathind++;
    if(u==v)
    {
        for(ll i=0;i<pathind;i++)
            cout<<path[i]<<" ";
    }
    for(auto i:adj[u])
    {
        if(visit[i]==false)
        {
            dfs(adj,visit,i,path,pathind,v);
        }
    }
    
    pathind--; //bactrack
    visit[u]=false; //backtrack
}
void dfsUtil(vector <ll> *adj,ll n,ll v)
{
    bool *visit=new bool[n];
    memset(visit,false,sizeof(visit));
    ll path[n];
    ll pathind=0;
    dfs(adj,visit,0,path,pathind,v);
    
}
int main()
{
    ll n=15;
    vector <ll> adj[n];
    //Test example for binary tree.
    addnode(adj,0,1);
    addnode(adj,0,2);
    addnode(adj,1,3);
    addnode(adj,1,4);
    addnode(adj,2,5);
    addnode(adj,2,6);
    addnode(adj,3,7);
    addnode(adj,3,8);
    addnode(adj,4,9);
    addnode(adj,4,10);
    addnode(adj,5,11);
    addnode(adj,5,12);
    addnode(adj,6,13);
    addnode(adj,6,14);
    
    
    for(ll i=1;i<n;i++)
    {
        cout<<"Path between root and node = "<<i<<" = ";//Printing all path from root to other nodes.
        dfsUtil(adj,n,i);
        cout<<endl;
    }

    
    return 0;
}
