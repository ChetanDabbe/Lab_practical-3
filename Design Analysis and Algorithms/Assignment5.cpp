#include <bits/stdc++.h>
using namespace std;

class N_queen
{
    vector<vector<string>> board;
    vector<vector<vector<string>>> solutions;
    int n;

public:
    N_queen(int size)
    {
        n = size;
        board.resize(n, vector<string>(n, ". "));
    }
    void solve(int);
    bool isvalid(int, int);
    void display();
};

bool N_queen::isvalid(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == "Q ")
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == "Q ")
            return false;
    }

    for (int i = row, k = col; i >= 0 && k < n; i--, k++)
    {
        if (board[i][k] == "Q ")
            return false;
    }

    return true;
}

void N_queen::solve(int row)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isvalid(row, col))
        {
            board[row][col] = "Q ";
            solve(row + 1);
            board[row][col] = ". ";
        }
    }
}

void N_queen ::display()
{
    // board[0][0] = "Q ";
    solve(0);
    if (solutions.empty())
    {
        cout << "\nNo solution exists";
        return;
    }
    int cnt = 0;
    for (const auto &solution : solutions)
    {
        cout << "\nSolution " << cnt+1 << " : " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j] << "  ";
            }
            cout << endl;
        }
        cnt++;
        cout<<endl;
    }

    cout<<"\nTotal solutions : "<<solutions.size()<<endl;
}

int main()
{
    int size;
    cout << "\nEnter the size of N_queen matrix : ";
    cin >> size;
    N_queen obj(size);
    obj.display();
}