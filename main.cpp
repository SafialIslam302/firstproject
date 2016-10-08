#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
double h=0.09 ,arr[100], num;

double first(double arr[],int x)
{
    double array[100];
    for(int i=0;i<=x;i++)
    {
        array[i]=log(arr[i]);
    }
    double x1=0.0,x2=0.0,x3=0.0,x4=0.0;
    x1= array[0] + array[x];
    x2=x1/2;
    for(int i=1;i<x;i++)
        x3=x3+array[i];
    x4=h *(x2+x3);
    cout<<x4<<endl;
}
double second(double arr[],int x)
{
    double array[100];
    for(int i=0;i<=x;i++)
    {
        array[i]=log(arr[i]);
    }
    double x1=0.0,x2=0.0,x3=0.0,x4=0.0,x5=0.0;
    x1= array[0] + array[x];
    for(int i=1;i<x;i+=2)
        x2=x2+array[i];
    for(int i=2;i<x-1;i+=2)
        x3=x3+array[i];
    x4=x1 + (4 * x2 )+ (2 * x3);
    x5= (x4 * h )/3.0;
    cout<<x5<<endl;
}
double third(double arr[],int x)
{
    double array[100];
    for(int i=0;i<=x;i++)
    {
        array[i]=log(arr[i]);
    }
    double x1=0.0,x2=0.0,x3=0.0,x4=0.0,x5=0.0;
    x1= array[0] + array[x];
    for(int i=1;i<x;i++)
    {
        if((i%3)==0)    // change
            continue;
        x2=x2+array[i];
    }
    for(int i=3;i<x-2;i+=3)
        x3=x3+array[i];
    x4=x1 + (3 * x2 )+ (2 * x3);
    x5= (3 * h * x4)/8.0;
    cout<<x5<<endl;
}
int main()
{
    double low=2.2,upper=5.6;
    arr[0]=low;  //first element
    int x=0,y=1;
    while(arr[x]<=upper)
    {
        ++x;
        arr[x] = low + (y*h);
        y++;
        if(arr[x]==upper)
            break;
    }
    cout<<endl;
    for(int i=0;i<=x;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    first(arr,x);
    second(arr,x);
    third(arr,x);
}
