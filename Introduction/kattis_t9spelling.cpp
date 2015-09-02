#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int tecla[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
int veces[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
string s;

int main()
{
    int tt, caso = 1;
    scanf("%d", &tt);

    cin.ignore(100, '\n');

    while (tt--)
    {
        getline(cin, s);

        printf("Case #%d: ", caso++);
        int n = s.size();
        For(i, 0, n)
        {
            if (s[i] == ' ')
            {
                if (i > 0 and s[i-1] == ' ')
                    printf(" ");
                printf("0");
            }
            else
            {
                int x = s[i]-'a';
                if (i > 0 and tecla[x] == tecla[s[i-1]-'a'])
                    printf(" ");

                For(j, 0, veces[x])
                    printf("%d", tecla[x]);
            }
        }
        printf("\n");
    }

    return 0;
}
