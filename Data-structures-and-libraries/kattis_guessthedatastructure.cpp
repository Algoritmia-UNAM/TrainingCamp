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

int Q;

void solve()
{
	bool is_stack = true, is_queue = true, is_pq = true;

	stack<int> pila;
	queue<int> cola;
	priority_queue<int> prioridad;

	REP(i, Q)
	{
		int op, x;
		cin >> op >> x;
		if(op == 1)
		{
			pila.push(x);
			cola.push(x);
			prioridad.push(x);
		}
		else
		{
			//DEBUG(pila.size());
			//DEBUG(cola.size());
			//DEBUGLN(prioridad.size());
			if(pila.empty())
			{
				is_stack = is_queue = is_pq = false;
				continue;
			}

			if(pila.top() != x)
				is_stack = false;
			pila.pop();

			if(cola.front() != x)
				is_queue = false;
			cola.pop();

			if(prioridad.top() != x)
				is_pq = false;
			prioridad.pop();

		}
	}

	if( (not is_queue) and (not is_stack) and (not is_pq) )
		printf("impossible\n");
	else if((is_queue) and (not is_stack) and (not is_pq))
		printf("queue\n");
	else if( (not is_queue) and (is_stack) and (not is_pq) )
		printf("stack\n");
	else if((not is_queue) and (not is_stack) and (is_pq))
		printf("priority queue\n");
	else
		printf("not sure\n");
}

int main()
{
	while(scanf("%d", &Q) == 1)
		solve();
	return 0;
}
