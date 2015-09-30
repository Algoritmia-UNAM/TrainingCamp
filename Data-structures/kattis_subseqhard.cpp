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

map<ll, ll> s;

void solve()
{
	ll n;

	scanf("%lld", &n);
	s.clear();

	ll accum = 0LL;
	ll res = 0;

	s.insert( MP(0LL, 1LL) );
	FOR(i, 1, n+1)
	{
		ll k;
		scanf("%lld", &k);

		accum += k;



		if(s.find(accum) != s.end())
			s[accum] = s[accum] + 1;
		else
			s[accum] = 1;

		if(s.find(accum - 47LL) != s.end())
		{
			res += s[accum-47];
		}
	}

	printf("%lld\n", res);

}

int main()
{
	int T;

	scanf("%d", &T);

	REP(i, T)
		solve();

	return 0;
}
