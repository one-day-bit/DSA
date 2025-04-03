using namespace std;
class IntQueue
{
private:
    int *data;
    int capacity;
    int head;
    int tail;
    int count;

    void resize()
    {
        int newCapacity = capacity * 2;
        int *newData = new int[newCapacity];

        for (int i = 0; i < count; i++)
        {
            newData[i] = data[(head + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
        head = 0;
        tail = count;
    }

public:
    IntQueue() : capacity(10), head(0), tail(0), count(0)
    {
        data = new int[capacity];
    }

    ~IntQueue()
    {
        delete[] data;
    }

    void push(int value)
    {
        if (count == capacity)
        {
            resize();
        }
        data[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    int pop()
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        int value = data[head];
        head = (head + 1) % capacity;
        count--;
        return value;
    }

    bool empty() const
    {
        return count == 0;
    }
};
