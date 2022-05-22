#include <iostream>
using namespace std;


void reverse(int a[], int n, int k1, int k2)
{
    int temp;
    if (k1 > n)
    {
        cout << "Invalid k";
        return;
    }


    for (int i = 0; i < k2/2; i++){
         temp = a[i];
         a[i] = a[k2 - i - 1];
         a[k2 - i - 1] = temp;}
}

// Driver program
int main()
{
    int a[] = {5, 8, 34, 55, 2, 6,8,34,1,23,5};
    int n = sizeof(a) / sizeof(int);
    int k1, k2;
    cin>>k1>>k2;
    reverse(a, n, k1, k2);

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}
