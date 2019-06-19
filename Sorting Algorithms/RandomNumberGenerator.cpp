#include <bits/stdc++.h>

using namespace std;

const int SIZE = 20;

int main()
{
    srand(time(NULL));

    freopen("../in.txt", "w", stdout);

    printf("%d\n", SIZE);
    for (int i = 1; i <= SIZE; i++) {
        printf("%d\n", rand());
    }

    return 0;
}
