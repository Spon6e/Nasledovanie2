#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstring>
#include <conio.h>

using namespace std;

class String
{
protected:
    enum { SZ = 80 };        
    char str[SZ];         
public:
    String()
    {
        str[0] = '\x0';
    }
    String(const char s[])
    {
        strcpy(str, s);
    } 
    void display() const
    {
        cout << str;
    }

    operator char* ()
    {
        return str;
    }
    //virtual ~String() {
     //   delete[] str; // Освобождаем выделенную память
    //    cout << "Base destructor called" << endl;
   // }
};

class Pstring : public String {
public:
    Pstring(const char s[]);
};
Pstring::Pstring(const char s[]) {
    if (strlen(s) > SZ - 1) {
        for (int i = 0; i < SZ - 1; i++) {
            str[i] = s[i];
        }
        str[SZ - 1] = '\x0';
    }
    else strcpy(str, s);
}
/////////////////////////////////////////////////////////// 
int main()
{
    setlocale(LC_ALL, "Russian");
    //String s1;                 
    //char xstr[] = "Ура, товарищи! "; 
    //s1 = xstr;              
    //s1.display();   
    //String s2 = "Мы победим! ";
    //cout << static_cast<char*>(s2);
    //cout << xstr << endl;
    Pstring A("Я рисую, я Ван Гог ");
    Pstring B("Эта строка имеет очень большую длину и мы можем быть уверены, что она не уместится в отведенный буфер, что приведет к непредсказуемым последствиям.");
    _getch();
    cout << static_cast<char*>(A) << static_cast<char*>(B);
    _getch();
    return 0;
}

