//
// Created by Xiaodong Liu on 8/19/22.
//
#include "CustomString.h"

void CustomString::incCapacity() {
    size_t k = 1;
    while(k <= len){
        k <<= 1;
    }
    char *newStr = new char[k];
    strcpy(newStr, str);
    delete [] str;
    str = newStr;
    for(size_t i = len+1; i < capacity; ++i){
        *(newStr+i) = '\0';
    }
}

void CustomString::initCapacity() {
    size_t k = 1;
    while(k <= len){
        k <<= 1;
    }
    str = new char[k];
    for(size_t i = len; i < k; ++i){
        *(str+i) = '\0';
    }
}
CustomString::CustomString():len(0) {
    initCapacity();
}

CustomString::~CustomString() {
    delete [] str;
}

CustomString::CustomString(const char *s): len(strlen(s)) {
    initCapacity();
    strcpy(str, s);
}
CustomString::CustomString(const char* s, size_t n): len(n) {
    initCapacity();
    strncpy(str, s, n);
}

CustomString::CustomString(size_t n, char c): len(n){
    initCapacity();
    for(int i = 0; i < n; ++i){
        str[i] = c;
    }
}

CustomString::CustomString(const CustomString &other): len(other.len), capacity(other.capacity), str(strdup(other.str)) {
}
CustomString::CustomString(const CustomString &other, size_t pos, size_t len):len(len) {
    initCapacity();
    strncpy(str, other.str+pos, len);
}

CustomString::CustomString(CustomString &&other) noexcept: len(other.len), str(other.str), capacity(other.capacity){
    other.str = nullptr;
}

CustomString::CustomString(initializer_list<char> il): len(il.size()) {
    initCapacity();
    auto it = il.begin();
    int i = 0;
    while(it != il.end()){
        str[i++] = *it;
    }
}
size_t CustomString::length() const noexcept{
    return len;
}
void CustomString::push_back(char c) {
    if(len+1 == capacity){
        incCapacity();
    }
    str[len++] = c;
}
void CustomString::pop_back() {
    str[--len] = '\0';
}
void CustomString::clear() noexcept{
    delete [] str;
    len = 0;
    initCapacity();
}

CustomString &CustomString::append(const CustomString &other) {
    int oldLen = len;
    len += other.len;
    if(len >= capacity){
        incCapacity();
    }
    strcpy(str+oldLen, other.str);
    return *this;
}

CustomString &CustomString::operator=(const CustomString &other) {
    if(this != &other){
        len = other.len;
        initCapacity();
        strcpy(str, other.str);
    }
    return *this;
}

CustomString &CustomString::operator=(CustomString &&other) noexcept{
    if(this != &other){
        delete [] str;
        len = other.len;
        capacity = other.capacity;
        str = other.str;
        other.str = nullptr;
    }
    return *this;
}

char &CustomString::operator[](size_t pos) {
    return str[pos];
}

CustomString CustomString::operator+(const CustomString &other) {
    CustomString res;
    res.append(*this);
    res.append(other);
    return res;
}

CustomString &CustomString::operator+=(const CustomString &other) {
    append(other);
    return *this;
}