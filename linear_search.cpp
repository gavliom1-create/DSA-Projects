#include<iostream>
using namespace std;
int linear_search(int a[], int n, int x)
{
    for(int i=0; i<n; i++){
        if(a[i] == x)
            return(i);
        
    }return(-1);
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

    int location = linear_search (a,n,x);
    
    if (location == -1){
        cout << " Element not found ";
    }else{
        cout << " Element found at index " << location;
    }
    return (0);
}
/*PS C:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues> cd "c:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues\" ; if ($?) { g++ linear_search.cpp -o linear_search } ; if ($?) { .\linear_search }
how many elements: 10
Enter 10 elements: 1 2 3 4 5 6 7 8 9 22
Enter Element to search: 6
 Element found at index 5*/





