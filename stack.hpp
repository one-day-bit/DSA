using namespace std;
class IntStack
{
private:
    int *data;
    int capacity;
    int topIndex;

    void resize()
    {
        int newCapacity = capacity * 2;
        int *newData = new int[newCapacity];
        for (int i = 0; i < capacity; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    IntStack() : capacity(10), topIndex(-1)
    {
        data = new int[capacity];
    }

    ~IntStack()
    {
        delete[] data;
    }

    void push(int value)
    {
        if (topIndex == capacity - 1)
        {
            resize();
        }
        data[++topIndex] = value;
    }

    int pop()
    {
        if (empty())
        {
            throw "Stack is empty";
        }
        return data[topIndex--];
    }

    bool empty() const
    {
        return topIndex == -1;
    }
};
