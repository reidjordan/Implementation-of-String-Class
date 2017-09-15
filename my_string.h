#include <iostream>
using namespace std;

class my_string {
private:
    char* ptr;
    int sz;
    int cap;
public:
    int size(); //Returns the # of characters (length) of s
    int capacity(); //Returns length in bytes of allocated memory
    bool empty(); //Checks if string is empty
    char operator[](int i); //Returns char at i w/o bound checking
    char at(int i); //Returns character at i w/ bound checking
    my_string operator+=(my_string q); //Appends q to s
    my_string operator+=(char c); //Appends c to s
    my_string& insert(int i, my_string s); //EXTRA CREDIT: insert s before i in str
    my_string(); //Default constructor
    my_string(int n); // Constructor with n bytes
    my_string(char my_string_arr[]); //Constructor creates string
    my_string(const my_string& s); //Copy constructor
    ~my_string(); //Destructor
    my_string& operator=(my_string q); //Copy assignment
    void inc_memory(char* ptr, int additional_sz); //Increases allocated memory as needed
};

istream& operator>>(istream& is, my_string& s); // reads input to s, stops at whitespace
ostream& operator<<(ostream& os, my_string& my_string); // prints content of string