class MyCircularQueue
{
private:
    int p_start;
    int size;
    int p_end;
    int* data;
public:
    MyCircularQueue(int k)
    {
        size=k;
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
        return data[p_start%size];
    }
    int Rear()
    {
        if(isEmpty())
            return -1;
        return data[(p_end-1)%size];
    }
    bool enQueue(int value)
    {
        if(isFull())
        {
            return false;
        }
        data[p_end%size]=value;
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
        return p_end==p_start+size;
    }
};
