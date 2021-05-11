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

map<int, vll> graph;
map<int, bool> visited;

void bfs(int s, vll &lvl){ // bfs method using queue
    queue<int> q;
    q.push(s);
    visited[s] = true;
    lvl[s] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(auto x: graph[v]){
            if(!visited[x]){
                visited[x] = true;
                lvl[x] = lvl[v]++;
                q.push(x);
            }
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    vll level(n);
    for(ll i=0;i<n-1;i++){
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    bfs(0, level);
    cout<<endl;
    cout<<"Depth of the Graph: "<<*max_element(all(level))<<endl;
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
