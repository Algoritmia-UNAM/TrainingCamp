#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;
//ios_base::sync_with_stdio(0);//fast entrada/salida ;-)


ll num[10010];
set<ll> prefix;
void solve()
{
	prefix.clear();
	ll n;
	cin >> n;

	string s;
	REP(j, n)
	{
		cin >> s;
		ll previous = 1;// dummy prefix
		REP(i, s.size()-1)
		{
			previous *= 10;
			previous += s[i]-'0';
			//DEBUGLN(previous);
			prefix.insert(previous);
		}

		previous *= 10;
		previous += s[s.size()-1]-'0';
		num[j] = previous;
	}

	REP(i, n)
	{
		//DEBUGLN(num[i]);
		if(prefix.find(num[i]) != prefix.end())
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
	int T;
	cin >> T;
	REP(i, T)
		solve();

	return 0;
}
