#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int conv[] = {9, 4, 4, 4, 7};

int main()
{
    //std::ios_base::sync_with_stdio(false);

    string line;

    while (true)
    {
        getline(cin, line);

        if (line == "-")
            break;

        double total = 0, fat = 0;
        do{

            stringstream ss;
            ss << line;

            //cout << "[" << line << "]\n";

            int cant[6];
            char tipo[6];

            For(i, 0, 5)
                ss >> cant[i] >> tipo[i];

            double cal = 0, per = 0;
            For(i, 0, 5)
            {
                if (tipo[i] == 'C')
                    cal += cant[i];
                else if (tipo[i] == 'g')
                    cal += cant[i]*conv[i];
                else if (tipo[i] == '%')
                    per += cant[i];
            }

            total += cal;
            For(i, 0, 5)
            {
                if (tipo[i] == '%')
                    total += cant[i]*cal/(double)(100-per);
            }

            if (tipo[0] == 'C')
                fat += cant[0];
            else if (tipo[0] == 'g')
                fat += cant[0]*conv[0];
            else if (tipo[0] == '%')
                fat += cant[0]*cal/(double)(100-per);

        }while(getline(cin, line) and line != "-");

        //printf("%lf %lf\n", total, fat);
        printf("%.0f\%\n", (fat*100)/total);
    }

    return 0;
}
