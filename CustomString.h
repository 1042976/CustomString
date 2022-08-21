//
// Created by Xiaodong Liu on 8/19/22.
//

#ifndef CUSTOMSTRING_CUSTOMSTRING_H
#define CUSTOMSTRING_CUSTOMSTRING_H
#include <cstdio>
#include <initializer_list>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

namespace ns{
    class string{
    private:
        size_t len;
        size_t capacity;
        char* str;
        void initCapacity();
        void incCapacity();
    public:
        static const size_t npos = -1;
        //default
        string();

        //destructor
        ~string();

        //copy constructor
        string(const string& other);

        //substring constructor
        string(const string& other, size_t pos, size_t _len = npos);

        //move constructor
        string(string&& other) noexcept;



        //c-string
        string(const char* s);
        string(const char* s, size_t n);

        //fill constructor
        string(size_t n, char c);

        string(initializer_list<char> il);

        //range constructor
        template<class InputIterator>
        string(InputIterator first, InputIterator last);

        //get length
        size_t length() const noexcept;

        //get capacity
        size_t getCapacity() const;

        //is empty or not
        bool empty() const noexcept;

        //push back a character
        void push_back(char c);

        //pop back a character
        void pop_back();

        //clear to be an empty string
        void clear() noexcept;
        //append a string
        string& append(const string& other);

        //convert to c-string
        const char* c_str() const noexcept;

        //copy assignment operator
        string& operator=(const string& other);

        //move assignment operator
        string& operator=(string&& other) noexcept;

        //get reference to a character
        char& operator[] (size_t pos);

        //plus
        string operator+ (const string& other);

        //append additional characters
        string& operator+= (const string& other);

        //equal
        bool operator == (const string& other);

    };

    template<class InputIterator>
    string::string(InputIterator first, InputIterator last):len(1) {
        while(first != last){
            push_back(*first++);
        }
    }
}

#endif //CUSTOMSTRING_CUSTOMSTRING_H
