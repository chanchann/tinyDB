#include<iostream>
using namespace std;

class MyCircularQueue
{
private:
    int p_start;
    int p_end;
    int* data;
public:
    MyCircularQueue(int k)
    {
        data=new int[k];
        p_start=0;
        p_end=0;
    }
    ~MyCircularQueue()
    {
        delete[] data;
    }
    int Front()
    {  
        if(isEmpty())
            return -1;
        return data[p_start%getLength(data)];
    }
    int Rear()
    {
        if(isEmpty())
            return -1;
        return data[(p_end-1)%getLength(data)];
    }
    bool enQueue(int value)
    {
        if(isFull())
        {
            cout<<"FULL"<<endl;
            return false;
        }
        cout<<"p_end:"<<p_end<<endl;
        data[p_end%getLength(data)]=value;
        p_end++;
        return true;
    }

    bool deQueue()
    {
        if(isEmpty())
            return false;
        p_start++;
        return true;
    }

    bool isEmpty()
    {
        return p_start==p_end;
    }

    bool isFull()
    {
        cout<<"p_end="<<p_end<<"p_start+len="<<p_start+getLength(data)<<endl;
        return p_end==p_start+getLength(data);
    }

    int getLength(int* arr)
    {
        cout<<"length="<<sizeof(arr)/sizeof(arr[0])<<endl;
        return sizeof(arr)/sizeof(arr[0]);
    }
};

int main()
{
    MyCircularQueue* cir=new MyCircularQueue(4);
    cout<<cir->enQueue(1)<<endl;
    cout<<cir->enQueue(2)<<endl;
    cout<<cir->enQueue(3)<<endl;
    cout<<cir->enQueue(4)<<endl;
    cout<<cir->Rear()<<endl;
    cout<<cir->Front()<<endl;
    return 0;
}