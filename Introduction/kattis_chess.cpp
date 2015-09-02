#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


int main()
{

    int tt;
    scanf("%d\n", &tt);

    while (tt--)
    {
        char y, x, Y, X;
        scanf("%c %c %c %c\n", &y, &x, &Y, &X);
        y -= 'A'-1; x -= '0'; Y -= 'A'-1; X -= '0';

        if ((y+x)%2 != (Y+X)%2)
            printf("Impossible\n");
        else
        {
            if (x == X and y == Y)
            {
                printf("0 %c %c\n", y+'A'-1, x+'0');
            }
            else
            {
                if (x+y == X+Y or x-y == X-Y)
                    printf("1 %c %c %c %c\n", y+'A'-1, x+'0', Y+'A'-1, X+'0');
                else
                {
                    int xdown, xup, ydown, yup;
                    if (x < X)
                        xdown = x, ydown = y, xup = X, yup = Y;
                    else
                        xdown = X, ydown = Y, xup = x, yup = y;

                    int k1 = (xup-yup-xdown+ydown)/2, k2 = (xup+yup-xdown-ydown)/2;
                    if (ydown-k1 >= 1 and ydown-k1 <= 8 and xdown+k1 >= 1 and xdown+k1 <= 8)
                        printf("2 %c %c %c %c %c %c\n", y+'A'-1, x+'0', ydown-k1+'A'-1, xdown+k1+'0', Y+'A'-1, X+'0');
                    else if (ydown+k2 >= 1 and ydown+k2 <= 8 and xdown+k2 >= 1 and xdown+k2 <= 8)
                        printf("2 %c %c %c %c %c %c\n", y+'A'-1, x+'0', ydown+k2+'A'-1, xdown+k2+'0', Y+'A'-1, X+'0');
                }
            }
        }
    }

    return 0;
}
