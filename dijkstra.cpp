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

//predefined functions
int power(ll x, ll y, ll m);  //  (x^y)%m

map<ll, vector<pair<ll, ll>>> graph;

void solve()
{
    ll V, E, S;
    // V - no of nodes
    // E - no of Edges
    // S - source node [0-V)
    cin>>V>>E>>S;
    for(ll i=0;i<E;i++){
        ll u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    // Dijkstra's algorithm for shortest distance from a given source to all nodes
    vll dist(V, INT_MAX);
    dist[S] = 0;
    map<ll , bool> visited;
    // pair<distance, node>
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, S});

    while(!pq.empty()){
        pair<ll, ll> node = pq.top();
        ll d = node.first;
        ll u = node.second;
        pq.pop();
        visited[u] = true;
        if(d > dist[u]) continue;
        for(auto v: graph[u]){
           if(!visited[v.first]){
                if(dist[u] + v.second < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
           }
        }
    }
    for(ll i=0;i<dist.size();i++){
        cout<<i<<"\t"<<dist[i]<<endl;
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
   //freopen("error.txt", "w", stderr);
   //freopen("output.txt", "w", stdout);
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
