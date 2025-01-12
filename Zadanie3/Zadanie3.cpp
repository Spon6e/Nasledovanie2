#include <conio.h>
#include <iostream>
using namespace std;

struct pairS {
    int x;
    int y;
};

class Stack{
protected:              
    enum { MAX = 6 };    
    int st[MAX];         
    int top;             
public:
    Stack(){
        top = -1;
    }
    void push(int var){
        st[++top] = var;
    }
    int pop(){
        return st[top--];
    }
};
/////////////////////////////////////////////////////////// 
class Stack2 : public Stack{
public:
    void push(int var){
        if (top >= MAX - 1){
            cout << "\nОшибка: стек полон"; exit(1);
        }
        Stack::push(var);    
    }
    int pop(){
        if (top < 0){
            cout << "\nОшибка: стек пуст\n"; exit(1);
        }
        return Stack::pop(); // вызов функции pop класса Stack(можно без return) 
    }
};
class pairStack : public Stack2{
private:
    pairS N;
public:
    void push(pairS k) {
        if (top + 2 <= MAX - 1) {
            Stack2::push(k.x);
            Stack2::push(k.y);
        }
        else cout << "Две координаты записать не выйдет(\n";
    }
    void pop() {
        cout << "Координата y: " << Stack2::pop() << "\n";
        cout << "Координата х: " << Stack2::pop() << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    pairS Kak;
    Kak.x = 12;
    Kak.y = 10;
    pairStack MMM;
    MMM.push(Kak);
    Kak.x = 122;
    Kak.y = 1520;
    MMM.push(Kak);
    Kak.x = 76;
    Kak.y = 89;
    MMM.push(Kak);
    _getch();
    MMM.push(Kak);
    _getch();
    MMM.pop();
    MMM.pop();
    MMM.pop();
    _getch();
    MMM.pop();
    _getch();
}


