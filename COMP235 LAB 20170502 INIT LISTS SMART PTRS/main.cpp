#define prog 2
#if(prog == 1)

#include <initializer_list>
#include <iostream>
using namespace std;
/*
 Question 1:
 Implement a stack template to include a constructor that takes a C++11 initializer list as a parameter:
 */

template<class T>
class MyStack
{
public:
    MyStack();
    //TO DO (1): Add a constructor with a C++11 initializer_list parameter
    MyStack(initializer_list<T> init_list);
    
    void push(T p_newItem);
    void pop();
    T top(); // reference topmost item
    
private:
    int capacity = 5;
    T *m_arr = new T[capacity];
    int m_size = 0;
    //Helper Function:
    //    To prevent pushing beyond capacity
    void doubleCapacity();
};

template<class T>
MyStack<T>::MyStack() {/* blank constructor */};

template<class T>
MyStack<T>::MyStack(initializer_list<T> init_list) {
    // construct an object with init list provided
    for (auto itr = init_list.begin(); itr != init_list.end(); itr++) {
        // push each itr item into the object storage array
        push(*itr);
    }
};

template<class T>
void MyStack<T>::push(T p_newItem) {
    if (m_size >= capacity)
        doubleCapacity();
    this->m_arr[m_size++] = p_newItem;
};

template<class T>
void MyStack<T>::pop() {
    this->m_arr[m_size--] = NULL;
};

template<class T>
void MyStack<T>::doubleCapacity() {
    this->capacity *= 2;
    
};

template<class T>
T MyStack<T>::top() {
    return m_arr[m_size - 1];
};

#include <iostream>
//TO DO (2): Add other necessary headers
#include <memory>
using namespace std;

int main(){
    
    cout << "Integer stack...\n";
    MyStack<int> stk1;
    
    for (int i = 0; i < 10; i++)
        stk1.push(i + 1);
    
    
    for (int i = 0; i < 10; i++)
    {
        cout << stk1.top() << ' ';
        stk1.pop();
    }
    
    cout << "\nFloating-point stack...\n";
    MyStack<double> stk2;
    
    for (int i = 0; i < 10; i++) {
        stk2.push(1.5 * (i + 1));
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << stk2.top() << ' ';
        stk2.pop();
    }
    
    cout << "\nCharacter stack constructed with C++11 initializer list...\n";
    MyStack<char> stk3{ 'C', 'O', 'M', 'P', ' ', '2', '3', '5' };
    
    for (int i = 0; i < 8; i++)
    {
        cout << stk3.top() << ' ';
        stk3.pop();
    }
    cout << endl;
    
    return 0;
}

#elif(prog == 2)
/*********
 PROGRAM 2
 *********/
/*
 Implement a singly-linked list using smart pointers
 */

#include <iostream>
#include <memory>
using namespace std;


int main() {
    
    cout << "Singly linked list with smart pointers...\n";
    

    
    return 0;
    
} 

#endif 
