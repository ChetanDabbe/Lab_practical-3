#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int freq;
    node* left;
    node* right;

    node(char c, int d)
    {
        ch=c;
        freq=d;
        left=NULL;
        right=NULL;
    }
};



class huffman{
    vector<pair<char,int>>input;
    int n;
    node* root;
    public:
        huffman()
        {
            n=0;
            root=NULL;
        }
        void accept();
        void display();
        void encode();
        void code_generation(string, node*, unordered_map<char,string>&);

        void decode(string&);

};
struct compare{
    bool operator()(node* a, node* b)
    {
        return a->freq > b->freq;
    }
};

void huffman::accept()
{
    cout<<"\nEnter the total number of entries : ";
    cin>>n;
    input.resize(n);
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the character and frequency (For ex. c 5) : ";
        cin>>input[i].first>>input[i].second;
    }

    sort(input.begin(),input.end(), [](const pair<char,int>&a, const pair<char,int>&b){
        return a.second<b.second;
    });

}

void huffman::encode()
{
    priority_queue<node*, vector<node*>, compare>minheap;

    for(int i=0;i<n;i++)
    {
        node* newNode=new node(input[i].first,input[i].second);
        minheap.push(newNode);
    }

    while(minheap.size() > 1)
    {
        node* leftChild=minheap.top();
        minheap.pop();
        node* rightChild=minheap.top();
        minheap.pop();

        int result=leftChild->freq + rightChild->freq;

        node* curr=new node('\0',result);
        curr->left=leftChild;
        curr->right=rightChild;
        minheap.push(curr);

    }
    root=minheap.top();
    unordered_map<char,string>huffman_codes;
    code_generation("", root, huffman_codes);
    cout<<"\nEncoded string : "<<endl;
    string encoded_string="";
    for(const auto &item:input)
    {
        cout<<item.first<<"  "<<huffman_codes[item.first]<<endl;
        encoded_string+=huffman_codes[item.first];
    }
    decode(encoded_string);
}

void huffman::decode(string& encode)
{
    node* curr=root;
    string decoded_data="";
    for(char c: encode)
    {
        if (c=='0')
        {
            curr=curr->left;
        }
        if (c=='1')
        {
            curr=curr->right;
        }
        if (curr->left==NULL && curr->right==NULL)
        {
            decoded_data+=curr->ch;
            curr=root;
        }
    }
    cout<<"\nDecoded string : "<<decoded_data<<endl;
}


void huffman::code_generation(string code, node* curr, unordered_map<char,string>&huffman)
{
    if (!curr)
        return;
    if (curr->left==NULL || curr->right==NULL)
    {
        huffman[curr->ch]=code;
    }
    code_generation(code+"0",curr->left,huffman);
    code_generation(code+"1",curr->right,huffman);

}


void huffman::display()
{
    cout<<"\nCharacter\tFrequency"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<input[i].first<<" \t\tS"<<input[i].second<<endl;
    }
    encode();
}

int main()
{
    huffman obj;
    int ch=0;
    while(ch<3)
    {
        cout<<"\n***********HUFFMAN ENCODING AND DECODING*****************"<<endl;
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