#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

class String
{
private:
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
};

/////////////////////////////////////////////////////////// 
int main()
{
    setlocale(LC_ALL, "Russian");
    String s1;                 
    char xstr[] = "Ура, товарищи! "; 
    s1 = xstr;              
    s1.display();   
    String s2 = "Мы победим! "; 
    cout << static_cast<char*>(s2);
    cout << xstr << endl;
    return 0;
}

