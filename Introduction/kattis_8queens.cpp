#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

char chess[10][10];

int main()
{

    For(i, 0, 8)
        scanf("%s", chess[i]);

    bool ok = true;
    int q = 0;
    For(i, 0, 8)
        For(j, 0, 8)
            if (chess[i][j] == '*')
            {
                ++q;
                for(int k = 0; k < 8; ++k)
                {
                    if (k != j and chess[i][k] == '*')
                        ok = false;

                    if (k != i and chess[k][j] == '*')
                        ok = false;

                    if (k > 0)
                    {
                        if (i-k >= 0 and j+k < 8 and chess[i-k][j+k] == '*')
                            ok = false;

                        if (i+k < 8 and j+k < 8 and chess[i+k][j+k] == '*')
                            ok = false;

                        if (i+k < 8 and j-k >= 0 and chess[i+k][j-k] == '*')
                            ok = false;

                        if (i-k >= 0 and j-k >= 0 and chess[i-k][j-k] == '*')
                            ok = false;
                    }
                }

                if (!ok)
                {
                    printf("invalid\n");
                    return 0;
                }
            }

    printf("%s\n", q == 8 ? "valid" : "invalid");

    return 0;
}
