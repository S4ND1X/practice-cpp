#include <iostream>

using namespace std;

template <typename T>
class dynamicArray
{

private:
    unsigned int size;
    unsigned int capacity;
    T *array;

    void resize()
    {
        T *temp = new T[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        //Delete previously allocated memory
        delete[] array;
        capacity *= 2;
        array = temp;
    }

public:
    dynamicArray()
    {
        //Define array with initial capacity of 16, and current size is 0
        array = new T[16];
        capacity = 16;
        size = 0;
    }

    void push(T item)
    {

        if (size == capacity)
        {
            resize();
        }

        array[size] = item;
        size++;
    }

    T pop()
    {

        if (size <= 0)
        {
            throw out_of_range("Cannot pop, array is empty");
        }

        T last_element = array[size - 1];
        size--;
        return last_element;
    }

    T getAt(int index)
    {
        return (index >= 0 && index < size) ? array[index] : throw out_of_range("Index out of range");
    }

    unsigned int getsize()
    {
        return size;
    }

    unsigned int getcapacity()
    {
        return capacity;
    }

    bool is_empty()
    {
        return size == 0;
    }

    void print_elements()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << ", ";
        }
        cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    dynamicArray<int> vector1;

    //Adding 5 elements to int vector
    vector1.push(10);
    vector1.push(20);
    vector1.push(30);
    vector1.push(40);
    vector1.push(50);

    cout << "Size: " << vector1.getsize() << "\n";
    cout << "Capacity: " << vector1.getcapacity() << "\n";

    vector1.print_elements();

    vector1.pop();
    vector1.pop();
    vector1.pop();
    vector1.pop();

    cout << "Size: " << vector1.getsize() << "\n";
    cout << "Capacity: " << vector1.getcapacity() << "\n";

    vector1.print_elements();
    
    vector1.pop();
    vector1.pop();

    return 0;
}
