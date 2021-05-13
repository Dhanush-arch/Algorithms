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
    cin>>V>>E>>S;
    for(ll i=0;i<E;i++){
        ll u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }
    vll dist(V, INT_MAX);
    dist[S] = 0;

    bool hasNegativeCycle = false;

    // for getting the shortest distance from node 'S' to all other nodes
    for(ll u=0;u<V;u++){
        for(auto v: graph[u]){
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                hasNegativeCycle = true;
            }
        }
    }

    for(ll i=0;i<V;i++)
        cout<<i<<" "<<dist[i]<<endl;

    // Nodes affected by Negative Cycle
    for(ll u=0;u<V;u++){
        for(auto v: graph[u]){
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = -1*INT_MAX;
            }
        }
    }

    for(ll i=0;i<V;i++)
	cout<<i<<" "<<dist[i]<<endl;
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
