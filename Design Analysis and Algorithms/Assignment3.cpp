#include<bits/stdc++.h>
using namespace std;

class fractional_knapsack{
    vector<pair<double,double>>input;
    int n;
    int w;
    public:
        void accept();
        void display();
        void fract_op();
};

void fractional_knapsack::accept()
{
    cout<<"\nEnter the total number of items : ";
    cin>>n;

    input.resize(n);
    cout<<"\nEnter the weight : ";
    cin>>w;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the profit and weight (For ex. 100 20) : ";
        cin>>input[i].first>>input[i].second;

    }

    sort(input.begin(),input.end(),[](const pair<double,double>&a, const pair<double,double>&b){
        return (a.first/a.second) > (b.first/b.second);
    });


}

void fractional_knapsack::fract_op()
{
    int total_weight=w;
    double ans=0;
    for(const auto& item:input)
    {
        if (item.second<=total_weight)
        {
            total_weight-=item.second;
            ans+=item.first;
        }
        else{
            ans+=item.first*(static_cast<double>(total_weight)/item.second);
        }
    }
    cout<<"\nAnswer : "<<ans<<endl;
}


void fractional_knapsack::display()
{
    cout<<"\nProfit\t\tWeight"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<input[i].first<<"\t\t"<<input[i].second<<endl;

    }
    cout<<"\nFractional Knapsack";
    fract_op();
}

int main()
{
    fractional_knapsack obj;

    int ch=0;
    while(ch<3)
    {
        cout<<"\n***********Fractional Knapsack***************";
        cout<<"\n1.Accept \n2.Display \n3.Exit";
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.accept();
                break;
            case 2:
                obj.display();
                break;
        }
    }
}