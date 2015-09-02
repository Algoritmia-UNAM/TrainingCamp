#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct booking
{
    int yy, mm, dd, h, m, t;
};

char basura[25];
booking B[10005];
int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool bisiesto(int y)
{
    if (y % 4 != 0)
        return false;

    if (y % 100 != 0)
        return true;

    if (y % 400 != 0)
        return false;

    return true;
}

void suma(booking *b, int c)
{
    For(i, 0, c)
    {
        (b->m)++;
        if (b->m == 60)
        {
            (b->h)++;
            b->m = 0;
        }
        if (b->h == 24)
        {
            (b->dd)++;
            b->h = 0;
        }
        if (b->dd > days[b->mm] + (b->mm == 2 and bisiesto(b->yy)))
        {
            (b->mm)++;
            b->dd = 1;
        }
        if (b->mm > 12)
        {
            (b->yy)++;
            b->mm = 1;
        }
    }
}

bool mycomp(booking A, booking B)
{
    if (A.yy != B.yy)
        return A.yy < B.yy;
    if (A.mm != B.mm)
        return A.mm < B.mm;
    if (A.dd != B.dd)
        return A.dd < B.dd;
    if (A.h != B.h)
        return A.h < B.h;
    if (A.m != B.m)
        return A.m < B.m;
    return A.t < B.t;
}

int main()
{
    //std::ios_base::sync_with_stdio(false);

    int tt;
    scanf("%d", &tt);

    while (tt--)
    {
        int n, c;
        scanf("%d %d\n", &n, &c);

        For(i, 0, 2*n)
        {
            scanf("%s", basura);
            scanf("%d-%d-%d %d:%d ", &B[i].yy, &B[i].mm, &B[i].dd, &B[i].h, &B[i].m);
            B[i].t = 1;

            ++i;
            scanf("%d-%d-%d %d:%d\n", &B[i].yy, &B[i].mm, &B[i].dd, &B[i].h, &B[i].m);
            B[i].t = -1;
            suma(&B[i], c);

            //printf("%d %d %d %d %d\n", B[i].yy, B[i].mm, B[i].dd, B[i].h, B[i].m);
        }

        sort(B, B+2*n, mycomp);

        int ans = 0, act = 0;
        For(i, 0, 2*n)
        {
            act += B[i].t;
            ans = max(ans, act);
        }

        printf("%d\n", ans);
    }

    return 0;
} 
