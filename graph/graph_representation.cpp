//undirected graph
#include<iostream>
#include<vector>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
return 0;
}

//directed graph
#include<iostream>
#include<vector>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
return 0;
}

//weighted graph  store weight with position in a pair
