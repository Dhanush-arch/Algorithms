#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
const long double PI = acos(-1);
const ll mod = 1e9 + 7; // 10^9 + 7
#define INF 1000000000 // Infinity value

//predefined functions
int power(ll x, ll y, ll m);  //  (x^y)%m

map<ll, vector<ll>> graph, transposedGraph;
vector<bool> visited;
stack<ll> mystack;

void dfs(ll at){
    visited[at] = true;
    for(auto to: graph[at]){
        if(!visited[to])
            dfs(to);
    }
    mystack.push(at);
}

void transpose(map<ll, vector<ll>> &tgraph){
    for(auto at: tgraph){
        for(auto to: tgraph[at.first])
            transposedGraph[to].push_back(at.first);
    }
}

void dfs_f(ll at){
    visited[at] = true;
    cout<<at<<" ";
    for(auto to: transposedGraph[at]){
        if(!visited[to])
            dfs_f(to);
    }
}

void solve()
{
    ll V, E;
    cin>>V>>E;
    for(ll i =0;i<E;i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    // Kosaraju's Algorithm
    // step-1: dfs traversal of the graph and push the nodes after dfs into stack
    visited = vector<bool> (V, false);
    for(ll i=0;i<V;i++){
        if(!visited[i])
            dfs(i);
    }

    // step-2: transpose the graph
    // i.e., 1->2 ==> 1<-2
    // stored as transposedGraph
    transpose(graph);

    // step-3: dfs again the graph and print the nodes
    // This prints the SCCs of the graph
    visited = vector<bool> (V, false);
    while(!mystack.empty()){
        ll node = mystack.top(); mystack.pop();
        if(!visited[node]){
            dfs_f(node);
            cout<<endl;
        }
    }
}

int power(ll x, ll y, ll m){ //  (x^y)%m
   ll res = 1;
   x = x%m;
   while(y>0){
      if(y&1)
         res = (res*x)%m;
      y = y/2;
      x = (x*x)%m;
   }
   return res;
}

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--)
   {
      solve();
   }

   // solve();

   #ifndef ONLINE_JUDGE
   cerr<<"Executed In: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   #endif
      return 0;
}