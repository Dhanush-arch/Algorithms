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
const ll UNVISITED= -1;
stack<ll> mystack;
vector<ll> ids, low;
vector<bool> onStack;
ll id=0;
ll sccCount = 0; // NO of SCC

void dfs(ll at){
    mystack.push(at);
    onStack[at] = true;
    ids[at] = low[at] = id++;

    for(auto to: graph[at]){
        if(ids[to] == UNVISITED) dfs(to);
        if(onStack[to])
            low[at] = min(low[at], low[to]);
    }

    if(ids[at] == low[at]){
        while(true){
            ll node = mystack.top(); mystack.pop();
            onStack[node] = false;
            low[node] = ids[at];
            if(node == at) break;
        }
        sccCount++;
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
    ids = vector<ll> (V, UNVISITED);
    low = vector<ll> (V);
    onStack = vector<bool> (V, false);

    for(ll i=0;i<V;i++){
        if(ids[i] == UNVISITED)
            dfs(i);
    }
    cout<<sccCount<<endl;
    for(ll i=0;i<V;i++)
        cout<<ids[i]<<"-->"<<low[i]<<endl;
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