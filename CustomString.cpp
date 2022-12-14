//
// Created by Xiaodong Liu on 8/19/22.
//
#include "CustomString.h"

namespace ns{
    void ns::string::incCapacity() {
        while(cap <= len){
            cap <<= 1;
        }

        char *newStr = new char[cap];
        strcpy(newStr, str);
        delete [] str;
        str = newStr;
        for(size_t i = len+1; i < cap; ++i){
            *(newStr+i) = '\0';
        }
    }

    void ns::string::initCapacity() {
        cap = 1;
        while(cap <= len){
            cap <<= 1;
        }
        str = new char[cap];
        for(size_t i = len; i < cap; ++i){
            *(str+i) = '\0';
        }
    }
    ns::string::string():len(0) {
        initCapacity();
    }

    string::~string() {
        delete [] str;
    }

    string::string(const char *s): len(strlen(s)) {
        initCapacity();
        strcpy(str, s);
    }
    string::string(const char* s, size_t n) {
        len = min(strlen(s), n);
        initCapacity();
        strncpy(str, s, len);
    }

    string::string(size_t n, char c): len(n){
        initCapacity();
        for(int i = 0; i < n; ++i){
            str[i] = c;
        }
    }

    string::string(const string &other): len(other.len), cap(other.cap), str(strdup(other.str)) {
    }
    string::string(const string &other, size_t pos, size_t _len) {
        pos = min(other.length(), pos);
        if(_len == npos){
            this->len = other.length()-pos;
        }else{
            this->len = min(pos+_len, other.length())-pos;
        }
        initCapacity();
        strncpy(str, other.str+pos, this->len);
    }

    string::string(string &&other) noexcept: len(other.len), str(other.str), cap(other.cap){
        other.str = nullptr;
    }

    string::string(initializer_list<char> il): len(il.size()) {
        initCapacity();
        auto it = il.begin();
        int i = 0;
        while(it != il.end()){
            str[i++] = *it++;
        }
    }
    size_t string::length() const noexcept{
        return len;
    }

    size_t string::capacity() const {
        return cap;
    }

    bool string::empty() const noexcept {
        return len == 0;
    }
    void string::push_back(char c) {
        if(++len == cap){
            incCapacity();
        }
        str[len-1] = c;
    }
    void string::pop_back() {
        if(!empty()){
            str[--len] = '\0';
        }
    }
    void string::clear() noexcept{
        delete [] str;
        len = 0;
        initCapacity();
    }

    string &string::append(const string &other) {
        int oldLen = len;
        len += other.len;
        if(len >= cap){
            incCapacity();
        }
        strcpy(str+oldLen, other.str);
        return *this;
    }

    const char *string::c_str() const noexcept {
        return str;
    }

    string &string::operator=(const string &other) {
        if(this != &other){
            len = other.len;
            initCapacity();
            strcpy(str, other.str);
        }
        return *this;
    }

    string &string::operator=(string &&other) noexcept{
        if(this != &other){
            delete [] str;
            len = other.len;
            cap = other.cap;
            str = other.str;
            other.str = nullptr;
        }
        return *this;
    }

    char &string::operator[](size_t pos) {
        pos = ((unsigned long long)pos)%len;
        return str[pos];
    }

    string string::operator+(const string &other) {
        string res;
        res.append(*this);
        res.append(other);
        return res;
    }

    string &string::operator+=(const string &other) {
        append(other);
        return *this;
    }

    bool string::operator==(const ns::string &other) {
        return strcmp(this->str, other.str) == 0;
    }
}