#include<iostream>
using namespace std;
void bubblesort (int a[],int n)
{
    int temp;
    for (int i = 0; i<n-1; i++)
    {
        for (int j = 0 ; j<n-1; j++)
        {
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int a[10];
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << " Enter " << n << " integers in any order: " << endl;
    for (int i = 0; i<n ; i++)
    {
        cin >> a[i];

    }
    bubblesort (a,n);
    cout << " Sorted array: ";
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    
    }
    cout << endl;

    return 0 ;

}
/*PS C:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues> cd "c:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues\" ; if ($?) { g++ bubblesort.cpp -o bubblesort } ; if ($?) { .\bubblesort }
Enter the size of the array: 5
 Enter 5 integers in any order: 
21 22 23 34 44
 Sorted array: 21 22 23 34 44 */

