#include <iostream>

using namespace std;

int main()

{

int freq[100];

int size, i, j, count;

/* Input size of array */

cout << "Enter size of array: ";

cin >> size;

int arr[size];

/* Input elements in array */

cout << "Enter elements in array: ";

for(i=0; i<size; i++)

{

cin >> arr[i];

/* Initially initialize frequencies to -1 */

freq[i] = -1;

}


for(i=0; i<size; i++)

{

count = 1;

for(j=i+1; j<size; j++)

{

/* If duplicate element is found */

if(arr[i]==arr[j])

{

count++;

/* Make sure not to count frequency of same element again */

//freq[j] = 0;

}

}

/* If frequency of current element is not counted */

if(freq[i] != 0)

{

freq[i] = count;

}

}

/* Print frequency of each element */

cout << "Frequency of all elements of array : ";

for(i=0; i<size; i++)

{

if(freq[i] != 0)

{

cout << arr[i] <<"     " << freq[i] <<  endl;

}
}
}
