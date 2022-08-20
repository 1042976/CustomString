//
// Created by Xiaodong Liu on 8/19/22.
//

#ifndef CUSTOMSTRING_CUSTOMSTRING_H
#define CUSTOMSTRING_CUSTOMSTRING_H
#include <cstdio>
#include <initializer_list>
#include <cstring>
using namespace std;

class CustomString{
private:
    size_t len;
    size_t capacity;
    char* str;
    void initCapacity();
    void incCapacity();
public:
    static const size_t npos = -1;
    //default
    CustomString();

    //destructor
    ~CustomString();

    //copy constructor
    CustomString(const CustomString& other);

    //substring constructor
    CustomString(const CustomString& other, size_t pos, size_t len = npos);

    //move constructor
    CustomString(CustomString&& other) noexcept;



    //c-string
    CustomString(const char* s);
    CustomString(const char* s, size_t n);

    //fill constructor
    CustomString(size_t n, char c);

    CustomString(initializer_list<char> il);

    //range constructor
    template<class InputIterator>
    CustomString(InputIterator first, InputIterator last);

    //get length()
    size_t length() const noexcept;

    //push back a character
    void push_back(char c);

    //pop back a character
    void pop_back();

    //clear to be an empty string
    void clear() noexcept;
    //append a string
    CustomString& append(const CustomString& other);

    //copy assignment operator
    CustomString& operator=(const CustomString& other);

    //move assignment operator
    CustomString& operator=(CustomString&& other) noexcept;

    //get reference to a character
    char& operator[] (size_t pos);

    //plus
    CustomString operator+ (const CustomString& other);

    //append additional characters
    CustomString& operator+= (const CustomString& other);

};

template<class InputIterator>
CustomString::CustomString(InputIterator first, InputIterator last):len(1) {
    while(first != last){
        push_back(*first++);
    }
}
#endif //CUSTOMSTRING_CUSTOMSTRING_H
