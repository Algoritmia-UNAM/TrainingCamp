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

char s[20];
multiset<int> izq, der;

void balancea()
{
	//DEBUG(izq.size());
	//DEBUGLN(der.size());
	while((int)izq.size() < (int)der.size()-1)
	{
		//DEBUGLN("1");
		izq.insert(*der.begin());
		der.erase(der.begin());
	}

	while((int)izq.size() >= (int)der.size()+1)
	{
		//DEBUGLN("2");
		der.insert(*izq.rbegin());
		auto it = izq.end();
		--it;
		izq.erase(it);
	}

	while( izq.size() and der.size() and *izq.rbegin() > *der.begin())
	{
		//DEBUGLN("3");
		auto it = izq.end();
		--it;
		auto jt = der.begin();

		int a = *it;
		int b = *jt;

		izq.erase(it);
		der.erase(jt);
		izq.insert(b);
		der.insert(a);
	}


}

int query()
{
	int res = *der.begin();

	der.erase(der.begin());
	balancea();

	return res;
}

int fast_atoi( const char * str )
{
    int val = 0;
    while( *str ) {
        val = val*10 + (*str++ - '0');
    }
    return val;
}

void insert()
{
	//DEBUG(s);
	int n = fast_atoi(s);
	//DEBUG(s);
	//DEBUGLN(n);

	der.insert(n);
	balancea();
}


int main()
{
	ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
	
	while(cin >> s)
	{
		if(s[0] == '#')
			cout << query() << '\n';
		else
			insert();
	}
	return 0;
}
