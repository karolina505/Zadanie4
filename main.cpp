#include <iostream>
#include <cassert>
#include "singlelist.hpp"

void test_push_and_size() {
    SingleList<int> list;
    assert(list.empty() == true);
    assert(list.size() == 0);

    list.push_back(10);
    assert(list.empty() == false);
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);

    list.push_front(5);
    assert(list.size() == 2);
    assert(list.front() == 5);
    assert(list.back() == 10);
}

void test_pop() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    assert(list.size() == 3);
    
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 2);
    
    list.pop_back();
    assert(list.size() == 1);
    assert(list.back() == 2);
    
    list.pop_back();
    assert(list.empty() == true);
    assert(list.size() == 0);
}

void test_copy_and_assignment() {
    SingleList<int> list1;
    list1.push_back(100);
    list1.push_back(200);

    SingleList<int> list2(list1); 
    assert(list2.size() == 2);
    assert(list2.front() == 100);
    assert(list2.back() == 200);

    list1.push_back(300);
    assert(list1.size() == 3);
    assert(list2.size() == 2); 

    SingleList<int> list3;
    list3 = list1; 
    assert(list3.size() == 3);
    assert(list3.back() == 300);
    
    list3.clear();
    assert(list3.empty() == true);
    assert(list3.size() == 0);
    assert(list1.size() == 3); 
}

void test_reverse() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.reverse();
    assert(list.front() == 3);
    assert(list.back() == 1);
    
    list.pop_front(); 
    assert(list.front() == 2);
}

int main() {
    std::cout << "Rozpoczynam testy..." << "\n";
    
    test_push_and_size();
    test_pop();
    test_copy_and_assignment();
    test_reverse();
    
    SingleList<int> moja_lista;
    moja_lista.push_back(10);
    moja_lista.push_back(20);
    moja_lista.push_front(5);
    std::cout << "Zawartosc mojej pokazowej listy to: ";
    moja_lista.display();
    
    std::cout << "Wszystkie testy zaliczone pomyslnie!" << "\n";
    return 0;
}