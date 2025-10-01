#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;
    int length;
    
public:
    MyString() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    
    MyString() {
        delete[] str;
    }
    
    void replace(int index, int count, const char* newStr) {
        if (index < 0 || index >= length) return;
        
        int newStrLen = strlen(newStr);
        int newLength = length - count + newStrLen;
        
        char* temp = new char[newLength + 1];
        
        strncpy(temp, str, index);
        strcpy(temp + index, newStr);
        strcpy(temp + index + newStrLen, str + index + count);
        
        delete[] str;
        str = temp;
        length = newLength;
    }
    
    MyString substr(int start, int end) {
        if (start < 0 || end > length || start >= end) {
            return MyString("");
        }
        
        int subLen = end - start;
        char* temp = new char[subLen + 1];
        strncpy(temp, str + start, subLen);
        temp[subLen] = '\0';
        
        MyString result(temp);
        delete[] temp;
        return result;
    }
    
    bool empty() {
        return length == 0;
    }
    
    void insert(int index, const char* insertStr) {
        if (index < 0 || index > length) return;
        
        int insertLen = strlen(insertStr);
        int newLength = length + insertLen;
        
        char* temp = new char[newLength + 1];
        
        strncpy(temp, str, index);
        strcpy(temp + index, insertStr);
        strcpy(temp + index + insertLen, str + index);
        
        delete[] str;
        str = temp;
        length = newLength;
    }
    
    void print() {
        cout << str << endl;
    }
};

int main() {
    setlocale(0, "");
    
    MyString str1("idk");
    str1.print();
    
    MyString str2("idk");
    str2.replace(8, 3, "idk");
    str2.print();
    
    MyString str3("xd");
    MyString sub = str3.substr(0, 7);
    sub.print();
    
    MyString str4("xd");
    MyString str5("");
    cout << str4.empty() << endl;
    cout << str5.empty() << endl;
    
    MyString str6("xd");
    str6.insert(7, "xd ");
    str6.print();
    
    return 0;
}
