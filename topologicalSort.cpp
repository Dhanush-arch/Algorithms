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

map<ll, vll> graph;
map<ll, bool> visited;
ll i;
vll ordering;

void dfs(ll x){
	visited[x] = true;
	for(auto y: graph[x]){
		if(!visited[y])
			dfs(y);
	}
	ordering.push_back(x);
	i--;
}

void solve()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
	ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        //graph[b].push_back(a);
    }
    for(auto x: graph){
       if(!visited[x.first]){
	dfs(x.first);
       }
    }
    reverse(all(ordering));
    for(auto x: ordering)
	    cout<<x<<" ";
    cout<<endl;
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
