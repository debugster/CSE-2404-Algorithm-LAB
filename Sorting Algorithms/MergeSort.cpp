#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int>&A, int beg, int mid, int end);
void MergeSort(vector<int>&A, int beg, int end);

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
    MergeSort(data, 0, n - 1);
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

void Merge(vector<int>&A, int beg, int mid, int end)
{
    vector<int>Left;
    vector<int>Right;
    int i, j, k;

    for (i = beg; i <= mid; i++) {
        Left.push_back(A[i]);
    }

    for (i = mid + 1; i <= end; i++) {
        Right.push_back(A[i]);
    }

    for (i = 0, j = 0, k = beg; i < Left.size() && j < Right.size(); ) {
        if (Left[i] < Right[j]) {
            A[k] = Left[i];
            i++;
        }
        else {
            A[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < Left.size()) {
        A[k++] = Left[i++];
    }

    while (j < Right.size()) {
        A[k++] = Right[j++];
    }
}

void MergeSort(vector<int>&A, int beg, int end)
{
    if (beg == end) {
        return;
    }

    int mid;

    mid = floor((beg + end) / 2);

    MergeSort(A, beg, mid);
    MergeSort(A, mid + 1, end);
    Merge(A, beg, mid, end);
}
