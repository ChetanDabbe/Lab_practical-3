#include<bits/stdc++.h>
using namespace std;

class fibonacci{
    vector<int>memo;
    public:
        fibonacci():memo(1000,-1){};
        int recursive_fib(int n);
        void non_recursive(int n);
};

int fibonacci::recursive_fib(int n)
{
    if (n==0 || n==1)
        return n;
    
    if (memo[n]!=-1)
    {
        return memo[n];
       
    }
    memo[n]=recursive_fib(n-1)+recursive_fib(n-2);
    return memo[n];
}

void fibonacci::non_recursive(int n) {
    if (n <= 0) {
        cout << "-1";
        return;
    }

    int a = 0;
    int b = 1;

    cout << a;
    if (n > 1) {
        cout << ", " << b;
    }

    for (int i = 2; i < n; i++) {
        int c = a + b;
        cout << ", " << c;
        a = b;
        b = c;
    }
    
    cout << endl;
}

int main()
{
    fibonacci obj;
    int number;
    cout<<"\nEnter the number of elements want in fibonacci series : ";
    cin>>number;

    int ch=0;

    while(ch<3)
    {
        cout<<"\n*****************FIBONACCI SERIES*****************"<<endl;
        cout<<"\n1.Recursive Fibonacci \n2.Non-recursive Fibonacci";

        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                for(int i=0;i<number;i++)
                {
                    cout<<obj.recursive_fib(i)<<", ";
                }
                
                break;

            case 2:
                obj.non_recursive(number);
                break;

        }
    }

}