#include  "String.h"

String::String(const char *cstring) {
    assign(cstring);
}

String::String(const String &string) {
    assign(string.m_cstring);
}

String::~String() {
    assign(NULL);
}

String &String::operator=(const char *cstring) {
    return assign(cstring);
}

String &String::operator=(const String &string) {
    return assign(string.m_cstring);
}

String &String::assign(const char *cstring) {
    if (this->m_cstring == cstring) {
        return *this;
    }
    if (this->m_cstring) {
        delete[] this->m_cstring;
        this->m_cstring = NULL;
    }
    if (cstring)
    {   
        this->m_cstring = new char[strlen(cstring) + 1] {};
        strcpy(this->m_cstring, cstring);
    }
    return *this;
    
}s