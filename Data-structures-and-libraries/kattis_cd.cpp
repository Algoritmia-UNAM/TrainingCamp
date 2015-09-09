#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<bool> vb;

int N, M;
set<int> poseo;

int caso = 0;

void solve()
{
	caso++;

	poseo.clear();
	int u;
	int cont=0;
	REP(i, N)
	{
		scanf("%d", &u);
		poseo.insert(u);
	}
	REP(i, M)
	{
		scanf("%d", &u);
		if(poseo.find(u) != poseo.end())
			cont++;
	}
	printf("%d\n", cont);
}


int main()
{
	while(scanf("%d %d", &N, &M)==2 and N+M)
		solve();
	return 0;
}
