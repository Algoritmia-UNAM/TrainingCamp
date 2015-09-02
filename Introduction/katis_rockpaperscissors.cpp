#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int win[105], lost[105];
map <pair <string, string>, pair <int, int> > mapa;

int main()
{
    std::ios_base::sync_with_stdio(false);

    mapa[MP("rock", "scissors")] = MP(1, 0);
    mapa[MP("rock", "paper")] = MP(0, 1);
    mapa[MP("rock", "rock")] = MP(0, 0);
    mapa[MP("scissors", "rock")] = MP(0, 1);
    mapa[MP("scissors", "paper")] = MP(1, 0);
    mapa[MP("scissors", "scissors")] = MP(0, 0);
    mapa[MP("paper", "scissors")] = MP(0, 1);
    mapa[MP("paper", "rock")] = MP(1, 0);
    mapa[MP("paper", "paper")] = MP(0, 0);

    int n;
    bool first = true;
    while (cin >> n and n)
    {
        memset(win, 0, sizeof win);
        memset(lost, 0, sizeof lost);

        int k;
        cin >> k;

        int juegos = k*n*(n-1)/2;
        For(i, 0, juegos)
        {
            int p1, p2;
            string s1, s2;

            cin >> p1 >> s1 >> p2 >> s2;
            win[p1] += mapa[MP(s1, s2)].first;
            win[p2] += mapa[MP(s1, s2)].second;

            lost[p1] += mapa[MP(s2, s1)].first;
            lost[p2] += mapa[MP(s2, s1)].second;
        }

        if (!first)
            cout << "\n";

        For(i, 1, n+1)
        {
            if (win[i] + lost[i] == 0)
                cout << "-\n";
            else
                cout << std::fixed << std::setprecision(3) << win[i]/(double)(win[i] + lost[i]) << "\n";
        }

        first = false;
    }


    return 0;
}
