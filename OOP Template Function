//assignemnt 5
//Implement a function template selection Sort.
//Write a program that inputs, sorts and outputs an integer
//array and a float array.
#include<iostream>
using namespace std;
int n;
const int size=10;
template<class T>
void sel(T A[size])
{
    int i,j,min;
    T temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nSorted array :: ";
    for(i=0;i<n;i++)
    {
        cout<<"  "<<A[i];
    }
}

int main()
{
    int A[size];
    float B[size];
    int i;
   
    cout<<"\nEnter total no of int elements :: ";
    cin>>n;
    cout<<"\nEnter int elements :: ";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sel(A);
   
    cout<<"\n\nEnter total no of float elements :: ";
    cin>>n;
    cout<<"\nEnter float elements :: ";
    for(i=0;i<n;i++)
    {
        cin>>B[i];
    }
    sel(B);
    return 0;
}
