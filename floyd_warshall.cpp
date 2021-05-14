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
#define INF 1000000000
void solve()
{
    ll V, E;
    cin>>V>>E;
    vector<vector<int>> graph(V, vector<int> (V, INF));
    for(ll i=0;i<E;i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;
        v--;
        graph[u][v] = w;
    }

    // Floyd Warshall Algo to find all pair shortest distance O(V^3)
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }


    for(auto x: graph){
        for(auto y:x)
            cout<<y<<" ";
       cout<<endl;
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
