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

struct compare
{
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		if(a.X == b.X )
			return a.Y < b.Y;
		else 
			return a.X > b.X;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
	string tag, cltag, word;
	set<pair<int, string>, compare > rank;
	unordered_map<string, int> dict;
	deque<string> lista;

	int day = 0;
	while(cin >> tag)
	{
		if(tag == "<text>")
		{

			while(cin >> word)
			{
				if(word == "</text>")
					break;
				if(word.size() >= 4)
				{

					lista.push_back(word);
					dict[word]++;
					auto it = rank.find(MP(dict[word]-1, word));
					if(it != rank.end())
					{
						rank.erase(it);
						rank.insert(MP(dict[word], word));
					}
					else
						rank.insert(MP(dict[word], word));
					
				}

			}
			lista.push_back("-");
			if(day >= 7)
			{
				while(lista.front() != "-")
				{
					word = lista.front();
					lista.pop_front();
					dict[word] = max((dict[word])-1,0);
					rank.erase(MP(dict[word]+1, word));
					rank.insert(MP(dict[word], word));
				}
				lista.pop_front();
			}
			day++;
		}
		else
		{
			int n;
			cin >> n >> cltag; 

			int prev = (*rank.begin()).X;
			auto it = rank.begin();
			int i = 0;
			cout << "<top " << n << ">" << "\n";

			while((*it).X == prev or i < n)
			{
				cout << (*it).Y << " " << (*it).X << "\n";

				prev =  (*it).X;
				++it;
				i++;

			}
			cout << "</top>" << "\n";
		}
	}

	return 0;
}
