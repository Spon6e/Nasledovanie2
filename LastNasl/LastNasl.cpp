#include <iostream> 
#include <conio.h>
#include <locale>
using namespace std;
const int LEN = 80;
// максимальная длина имени 
/////////////////////////////////////////////////////////// 
class student
{
private:
	char school[LEN];
	char degree[LEN];
public:
	void getedu()
	{
		// сведения об образовании 
		// название учебного заведения 
		// уровень образования 
		cout << "  Введите название учебного заведения: ";
		cin >> school;
		cout << "  Введите степень высшего образования\n";
        cout << "  (неполное высшее, бакалавр, магистр, кандидат наук): ";
        cin >> degree;
    }
    void putedu() const
    {
        cout << "\n  Учебное заведение: " << school;
        cout << "\n  Степень: " << degree;
    }
};
/////////////////////////////////////////////////////////// 
class employee            // некий сотрудник 
{
private:
    char name[LEN];     // имя сотрудника 
    unsigned long number; // номер сотрудника 
public:
    void getdata()
    {
        cout << "\n  Введите фамилию: "; cin >> name;
        cout << "  Введите номер: ";     cin >> number;
    }
    void putdata() const
    {
        cout << "\n  Фамилия: " << name;
        cout << "\n  Номер: " << number;
    }
};
/////////////////////////////////////////////////////////// 
class manager : private employee, private student // менеджер 
{
protected:
    char title[LEN];    // должность сотрудника 
    double dues;          // сумма взносов в гольф-клуб 
public:
    void getdata()
    {
        employee::getdata();
        cout << "  Введите должность: "; cin >> title;
        cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\n  Должность: " << title;
        cout << "\n  Сумма взносов в гольф-клуб: " << dues;
        student::putedu();
    }
};
/////////////////////////////////////////////////////////// 
class scientist : private employee, private student // ученый 
{
private:
    int pubs;             // количество публикаций 
public:
    void getdata()
    {
        employee::getdata();
        cout << "  Введите количество публикаций: "; cin >> pubs;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\n  Количество публикаций: " << pubs;
        student::putedu();
    }
};
/////////////////////////////////////////////////////////// 
class laborer : public employee // рабочий 
{
};
/////////////////////////////////////////////////////////// 
class executive :private manager {
private:
    float premia;
    float procent_ak;
public:
    void getdata() {
        manager::getdata();
        cout << "Введите размер премии: ";
        cin >> premia;
        cout << "Введите процент акций которыми владеет данный управляющий: ";
        cin >> procent_ak;
    }
    void putdata() {
        manager::putdata();
        cout << "Размер премии: " << premia << endl;
        cout << "Процент акций которыми владеет: " << procent_ak << endl;
    }
};

int main()
{
    setlocale(LC_ALL,"Russian");
    executive A;
    A.getdata();
    A.putdata();
    _getch();
}