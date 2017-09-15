#include "my_string.h"
#include <stdexcept>
//my_string.cpp

int my_string::size() { //Returns the # of characters (length) of s
    return sz;
}

int my_string::capacity() { //Returns length in bytes of allocated memory
    return cap;
}

bool my_string::empty() { //Checks if string is empty
    if (sz == 0)
        return true;
    return false;
}

char my_string::operator[](int i) { //Returns char at i w/o bound checking
    return ptr[i];
}

char my_string::at(int i) //Returns character at i w/ bound checking
{
    if (i >= sz or i < 0)
        throw out_of_range("Out of range");
    return ptr[i];
}

my_string my_string::operator+=(my_string q) { //Appends q to s
    int q_size = q.size();
    int required_cap = q_size + sz;
    if (cap < required_cap)//Checks if space is allocated
        inc_memory(ptr, q_size); //Allocate memory for q if needed
    else
        sz = sz + q_size; //Adds size of q to sz if allocation is not needed
    
    int starting = sz - q_size;
    int ending = sz;
    int j = 0;
    for (int i = starting; i < ending; i++) { //Adds q to the end of s
        ptr[i] = q[j];
        j++;
    }
    
    return ptr;
}

my_string my_string::operator+=(char c) { //Appends char c to s
    int required_cap = sz + 1;
    if (cap < required_cap) //Checks if space is allocated
        inc_memory(ptr, 1); //Allocate memory for c if needed
    else
        sz = sz + 1; //Adds size of c(1) to sz if allocation is not needed
    
    int i = sz - 1;
    ptr[i] = c;
    
    return ptr;
}

my_string& my_string::insert(int i, my_string s) { //Extra Credit
    int s_size = s.size();
    if (cap < sz + s_size) //Checks if space is allocated
        inc_memory(ptr, s_size);
    else
        sz = sz + s_size;
    
    int x = 0;
    for (int y = i; x < s.size(); y++) {
        for (int a = sz; a >= i; a--) { //Moves each element forward
            ptr[a+1] = ptr[a];
        }
        ptr[y] = s[x];
        x++;
    }
    return *this;
}

my_string::my_string() { // Default constructor
    cap = 0;
	sz = 0;
    ptr = new char[0];
}

my_string::my_string(int n) { // Constructor with n allocated memory
    cap = n;
	sz = 0;
    ptr = new char[n];
}

my_string::my_string(char my_string_arr[]) { //Constructor creates string from char[] string
    int len = 0;
    int i = 0;
    
    while (my_string_arr[i] != '\0') {
        i++;
        len++;
    }
    
    sz = len;
    cap = sz;
    ptr = new char[cap]; //Allocates memory for string
    
    for (int i = 0; i < sz; i++) {
        ptr[i] = my_string_arr[i];
    }
}

my_string::my_string(const my_string& s) { // Copy constructor
    sz = s.sz;
    cap = s.cap;
    ptr = new char[cap];
    
    for (int i = 0; i < sz; i++) {
        ptr[i] = s.ptr[i];
    }
}

my_string::~my_string() { // Destructor
    delete [] ptr;
    ptr = NULL;
    sz = 0;
    cap = 0;
}

my_string& my_string::operator=(my_string q) { // Copy assignment
    int q_size = q.size();
    if (q_size > cap) //Checks if space is allocated
        inc_memory(ptr, q_size); //Increases memory allocated if needed
    else
        sz = sz + q_size;
    
    for (int i = 0; i < q_size; i++) {
        ptr[i] = q.at(i);
    }
    
    return *this;
}


void my_string::inc_memory(char* ptr, int additional_sz) { //Allocates more memory if needed
    sz = sz + additional_sz;
    while (cap < sz) {
        if (cap == 0)
            cap++;
        cap *= 2;
    }
	
	ptr = new char[cap];
    
}

ostream& operator<<(ostream& os, my_string& my_string) { //Overloaded output operator
    for (int i = 0; i < my_string.size(); i++) {
        os << my_string.at(i);
    }
    
    return os;
}

istream& operator>>(istream& is, my_string& s) { //Overloaded input operator
    char* ptr = new char[300];
    is >> ptr;
    s = my_string(ptr);
    delete[] ptr;
    return is;
}