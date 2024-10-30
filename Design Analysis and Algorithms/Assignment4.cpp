#include<bits/stdc++.h>
using namespace std;

class zero_one{
    vector<pair<int,int>>input;
    vector<vector<int>>ans;
    int n;
    int w;
    public:
        void accept();
        void display();
        void knapsack_op();
};

void zero_one::accept()
{
    cout<<"\nEnter the total number of items : ";
    cin>>n;
    input.resize(n);
    cout<<"\nEnter the total weight : ";
    cin>>w;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the profit and weight (For ex: 60 10) : ";
        cin>>input[i].first>>input[i].second;
    }
    ans.resize(n+1,vector<int>(w+1,0));
}

void zero_one::knapsack_op()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if (i==0 || j==0)
            {
                ans[i][j]=0;
            }
            else if (input[i-1].second<=j)
            {
                ans[i][j]=max(ans[i-1][j],ans[i-1][j-input[i-1].second]+input[i-1].first);
            }
            else{
                ans[i][j]=ans[i-1][j];
            }
        }
    }
    cout<<"\nAnswer : "<<ans[n][w];
}

void zero_one::display()
{
    cout<<"\nProfit\t\tWeight"<<endl;
    for(const auto& item:input)
    {
        cout<<item.first<<"\t\t"<<item.second<<endl;
    }
    knapsack_op();
}

int main()
{
    zero_one obj;
    int ch=0;
    while(ch<3)
    {
        cout<<"\n*************0/1 Knapsack Problem ****************"<<endl;
        cout<<"1.Accept \n2.Display \n3.Exit"<<endl;

        cout<<"Enter the choice : ";
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