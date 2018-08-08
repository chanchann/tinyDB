#include<iostream>
#include<vector>
using namespace std;

class MyQueue
{
private:
    vector<int> data;
    int p_start;    
public:
    MyQueue()
    {
        p_start=0;
    }

    bool enqueue(int x)
    {
        data.push_back(x);
    }

    bool dequeue()
    {
        if(isEmpty())
        {
            return false;
        }
        p_start++;
        return true;
    }

    int front()
    {
        return data[p_start];
    }

    bool isEmpty()
    {
        return p_start>=data.size();
    }
};

int main()
{
    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    if(!q.isEmpty())
    {
        cout<<q.front()<<endl;
    }
    q.dequeue();
    if(!q.isEmpty())
    {
        cout<<q.front()<<endl;
    }
    return 0;
}