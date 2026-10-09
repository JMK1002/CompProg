//
// Created by JMKov on 4/30/2023.
//
#include <iostream>
using namespace std;

int main()
{
    long long n, x, y;
    cin>>n;
    while(cin>>n>>x>>y){
        cout<<max(n,((n-1)/(2*x))*(x+y)+((n-1)/2%x)+1)<<endl;
    }
}