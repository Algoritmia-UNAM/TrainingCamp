#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

char s[10005];

int main()
{

    scanf("%s", s);

    int n = strlen(s), up = 0, down = 0, like = 0;
    For(i, 1, n)
    {
        if (i > 1)
        {
            if (s[i] == 'D')
                up += 2;
            if (s[i] == 'U')
                down += 2;
            if (s[i] != s[i-1])
                ++like;
        }
        else
        {
            if (s[0] != s[1])
                ++up, ++down, ++like;
        
            if (s[1] == 'D')
                ++up;
            if (s[1] == 'U')
                ++down;
        }
    }

    printf("%d\n%d\n%d\n", up, down, like);

    return 0;
} 
