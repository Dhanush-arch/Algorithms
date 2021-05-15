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

map<ll, vector<ll>> graph;
ll id=0;
vector<pair<ll, ll>> bridges;
vector<bool> visited;
vector<ll> ids, low;
vector<bool> isArticulation;

ll rootNodeOutEdgeCount;

void dfs(ll at, ll parent){ // For bridges
    visited[at] = true;
    id++;
    ids[at] = low[at] = id;

    for(auto to : graph[at]){
        if(to == parent) continue;
        if(!visited[to]){
            dfs(to, at);
            low[at] = min(low[at], low[to]);
            if(ids[at] < low[to]){
                bridges.push_back({at, to});
            }
        }
        else {
            low[at] = min(low[at], ids[to]);
        }
    }
}


void dfs_art(ll root, ll at, ll parent){ // For articulation Points
    if(root == parent) rootNodeOutEdgeCount++;
    visited[at] = true;
    id++;
    ids[at] = low[at] = id;

    for(auto to : graph[at]){
        if(to == parent) continue;
        if(!visited[to]){
            dfs_art(root, to, at);
            low[at] = min(low[at], low[to]);
            if(ids[at] <= low[to]){
                isArticulation[at] = true;
            }
        }
        else {
            low[at] = min(low[at], ids[to]);
        }
    }
}

void solve()
{
    ll V, E;
    cin>>V>>E;
    for(ll i=0;i<E;i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    // To find Bridges in the Graph
    ids = low = vector<ll> (V);
    visited = vector<bool> (V, false);
    for(ll i=0;i<V;i++){
        if(!visited[i])
            dfs(i, -1);
    }

    // To find Articulation Points in the Graph
    ids = low = vector<ll> (V);
    visited = isArticulation = vector<bool> (V, false);
    for(ll i=0;i<V;i++){
        if(!visited[i]){
            rootNodeOutEdgeCount = 0;
            dfs_art(i, i, -1);
            isArticulation[i] = (rootNodeOutEdgeCount > 1);
        }
    }

    // Bridges
    for(auto x: bridges)
        cout<<x.first<<"-->"<<x.second<<endl;

    // Articulation Points
    for(ll i=0; i<V; i++){
        if(isArticulation[i])
            cout<<i<<endl;
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