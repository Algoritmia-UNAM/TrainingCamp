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

UnionFind uf(100000); // just to reserve enough memory
int id_idx = 0;
unordered_map<string, int> mapa;

int idFriend(const string& s)
{
	if(mapa.find(s) != mapa.end())
		return mapa[s];
	else
		return mapa[s] = id_idx++;
}

void solve()
{
	int N;

	cin >> N;
	//DEBUGLN(N);
	uf.assign(N+N+1);
	id_idx = 0;
	mapa.clear();

	string f1, f2; 
	REP(i, N)
	{
		cin >> f1 >> f2;
		int idf1 = idFriend(f1);
		int idf2 = idFriend(f2);
		//DEBUG(f1);
		//DEBUG(idf1);
		//DEBUG(f2);
		//DEBUGLN(idf2);
		uf.unionSet(idf1, idf2);
		cout << uf.sizeOfSet(idf1) << '\n';
	}

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
