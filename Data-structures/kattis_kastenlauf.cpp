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

class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
	int numSets;
public:
	UnionFind(int N) 
	{
		setSize.assign(N, 1); 
		numSets = N; 
		rank.assign(N, 0);
		p.assign(N, 0); 
		for (int i = 0; i < N; i++) 
			p[i] = i; 
	}

	void assign(int N) // reset 
	{
		setSize.assign(N, 1); 
		numSets = N; 
		rank.assign(N, 0);
		p.assign(N, 0); 
		for (int i = 0; i < N; i++) 
			p[i] = i; 
	}

	int findSet(int i) 
	{ 
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	}

	bool isSameSet(int i, int j) 
	{ 
		return findSet(i) == findSet(j); 
	}

	void unionSet(int i, int j) 
	{ 
		if (!isSameSet(i, j)) 
		{ 
			numSets--; 
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) 
			{ 
				p[y] = x; setSize[x] += setSize[y]; 
			}
			else 
			{ 
				p[x] = y; 
				setSize[y] += setSize[x];
				if (rank[x] == rank[y]) 
					rank[y]++; 
			} 
		} 
	}

	int numDisjointSets() 
	{ 
		return numSets; 
	}
	
	int sizeOfSet(int i) 
	{ 
		return setSize[findSet(i)]; 
	}
};


ii p[100+10];

inline int dist(const ii &a, const ii &b)
{
	return abs(a.X-b.X) + abs(a.Y-b.Y);
}

UnionFind uf(110);

void solve()
{
	int n;
	scanf("%d", &n);

	n+=2;
	uf.assign(n);

	REP(i, n)
	{
		scanf("%d %d", &p[i].X, &p[i].Y);
	}

	REP(i, n)
	{
		FOR(j, i+1, n)
		{
			if(dist(p[i], p[j]) <= 1000)
			{
				//DEBUG(dist(p[i], p[j]));
				//DEBUG(i);
				//DEBUGLN(j);

				uf.unionSet(i, j);
			}
		}
	}

	if(uf.isSameSet(0, n-1))
		printf("happy\n");
	else
		printf("sad\n");
}

int main()
{
	int T;

	scanf("%d", &T);

	REP(i, T)
		solve();

	return 0;
}
