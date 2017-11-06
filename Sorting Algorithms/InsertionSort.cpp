#include <bits/stdc++.h>

using namespace std;

void InsertionSort(vector<int>&A);

int main()
{
    freopen("../in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    FILE *fp;
    clock_t start, finish;
    double elapsed_time;
    vector<int>data;
    int i, v, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        data.push_back(v);
    }

    start = clock();
    InsertionSort(data);
    finish = clock();

    elapsed_time = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("Elapsed time = %lf\n", elapsed_time);

    fp = fopen("../out.txt", "w");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\n", data[i]);
    }
    fclose(fp);

    return 0;
}

void InsertionSort(vector<int>&A)
{
    int i, j, temp, Len;

    Len = A.size();
    for (i = 2; i < Len; i++) {
        temp = A[i];
        j = i - 1;
        while (temp < A[j] && j >= 0) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}
