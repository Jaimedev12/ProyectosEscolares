
// Linked Lists example

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> numbers;
    list<int>::iterator it = numbers.begin();
    
    numbers.push_back(6);
    //{6}
    numbers.push_front(5);
    //{5,6}
    numbers.push_back(7);
    //{5,6,7}
    numbers.push_front(4);
    //{4,5,6,7}
    
    cout << numbers.front() << endl;
    cout << numbers.back() << endl;
    
    it = numbers.begin();
    numbers.insert(it, 9);
    
    for (it = numbers.begin(); it != numbers.end(); it++){
        //printf("%c", *it);
        cout << *it << " ";
    }
    
}
