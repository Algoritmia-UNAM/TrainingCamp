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

#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
	FenwickTree() {}
  	// initialization: n + 1 zeroes, ignore index 0
	FenwickTree(int n) { ft.assign(n + 1, 0); }

	int rsq(int b) {                                     // returns RSQ(1, b)
    	int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    	return sum; 
    }

	int rsq(int a, int b) {                              // returns RSQ(a, b)
    	return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
    }

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v) {                    // note: n = ft.size() - 1
    	for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; 
    }
};

int v[100010];

int main()
{
	int n;

	scanf("%d", &n);

	FenwickTree izq(n+10), der(n+10);

	REP(i, n)
	{	
		scanf("%d", &v[i]);

		der.adjust(v[i], 1);
	}

	ll res  = 0;

	REP(i, n)
	{
		der.adjust(v[i], -1);

		res +=  (ll)((ll) izq.rsq(v[i]+1, n) * (ll)der.rsq(v[i]-1)); 
		// take into account that 10**5 * 10**5 > |MAX_INT|


		izq.adjust(v[i], 1);
	}



	printf("%lld\n", res);

	return 0;
}
