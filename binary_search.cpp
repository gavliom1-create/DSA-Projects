#include<iostream>
using namespace std;
int binary_search(int a[], int n, int x)
{
    int first = 0, last =n-1,mid;
    while (first <= last){
        mid= (first + last )/2;
        if (a[mid]==x)return(mid);
        else if (a[mid]<x) first = mid+1;
        else last = mid-1;
    }
    return(-1);
}
int main()
{
    int a[20];
    int n;
    cout << "how many elements: ";
    cin >> n;
    cout << "Enter "<< n  << " elements: ";
    
    for (int i=0; i<n; i++){
        cin >> a[i];

    }

    int x;
    cout << "Enter Element to search: ";
    cin >> x;

    int location = binary_search(a,n,x);
    
    if (location == -1){
        cout << " Element not found ";
    }else{
        cout << " Element found at index " << location;
    }
    return (0);
}

/*PS C:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues> cd "c:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues\" ; if ($?) { g++ binary_search.cpp -o binary_search } ; if ($?) { .\binary_search }
how many elements: 10
Enter 10 elements: 1 2 3 4 5 6 7 8 9 10
Enter Element to search: 6
 Element found at index 5*/
