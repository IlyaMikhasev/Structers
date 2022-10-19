// Персональный шаблон
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end);
template <typename T>
void show_arr(T arr[], const int length);
struct date {
	int day{};// =int day=0;
	int month{};
	int year{};
};
struct person {
	std::string name = "noname";
	date birthday;
	int salary = 0;
};
struct persona {
	std::string name;
	int age = 0;
	const int coins[5]{};
};
void show_person(person& P){
	std::cout << "Имя " << P.name << '\n';
	std::cout << "дата рождениия: " << P.birthday.day << '.' <<
		P.birthday.month << '.' <<
		P.birthday.year << "\n\n";

}
void show_persona(persona& P) {
	std::cout << "Имя " << P.name << '\n';
	std::cout << "Возраст: " << P.age << '\n';
	std::cout << "Монеты: ";
	for (int i = 0; i < 5; i++)
		std::cout << P.coins[i] << ' ';
	std::cout << "\n";

}
inline int year_of_birth(persona& P, int year) {
	return year - P.age;
}
//создается перемменная в памяти , которая копируется в переменную(неправильное использование)
person input_person() {
	person tmp;
	std::cout << "Введите имя: ";
	std::cin.ignore();
	getline(std::cin, tmp.name);
	std::cout << "Введите дату рождения: ";
	std::cin >> tmp.birthday.day >>
				tmp.birthday.month >>
				tmp.birthday.year;
	std::cout << "Введите зарплату: ";
	std::cin >> tmp.salary;
	return tmp;
}
//заполняется сразу в нужную нам переменную
void fill_person(person& P) {
	std::cout << "Введите имя: ";
	//std::cin.ignore();//почему то сьедает первую букву
	getline(std::cin, P.name);
	std::cout << "Введите дату рождения: ";
	std::cin >> P.birthday.day >>
		P.birthday.month >>
		P.birthday.year;
	std::cout << "Введите зарплату: ";
	std::cin >> P.salary;
}
int cash(persona& P) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum+=P.coins[i];
	return sum;
}
struct point {
	double x = 0;
	double y = 0;
};
int compare_distanse(point& p1, point& p2) {
	double dist1 = sqrt(pow(0 - p1.x, 2) + pow(0 - p1.y, 2));
	double dist2 = sqrt(pow(0 - p2.x, 2) + pow(0 - p2.y, 2));
	if (dist1 > dist2)
		return 1;
	if (dist1 < dist2)
		return-1;
	return 0;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//обьвление struct person для ее реализации создаеться обьекты per1,per2.
	/*
	struct person {
		std::string name="noname";
		int age=18;
		std::string position="Delevopment";
		int salary=15000;
	}per1, per2{"Freddy",47,"Screemer",23000};
	//обращение к полям обьекта структуры
	per1.name = "Ser Smith";
	per1.age = 23;
	//per1.position = "Direct";
	per1.salary = 3500;
	std::cout << "Имя: " << per1.name << '\n';
	std::cout << "Возраст: " << per1.age << '\n';
	std::cout << "Должность: " << per1.position << '\n';
	std::cout << "Зарплата: " << per1.salary << "\n\n";
	std::cout << "Имя: " << per2.name << '\n';
	std::cout << "Возраст: " << per2.age << '\n';
	std::cout << "Должность: " << per2.position << '\n';
	std::cout << "Зарплата: " << per2.salary << "\n\n";
	per1={"Sheldon",31,"Doctor",45000};//изменение всего содержимого обьекта структыры
	per2 = per1;//прямое присваивание полей обьекта per1 к полям обьекта per20
	person per3{"Dilan",28,"police",45000};//альтернативный способ создания обьекта структуры
	std::cout << "Имя: " << per3.name << '\n';
	std::cout << "Возраст: " << per3.age << '\n';
	std::cout << "Должность: " << per3.position << '\n';
	std::cout << "Зарплата: " << per3.salary << '\n';
	*/
	//струкутуры person и date
	/*
	person per4;
	per4.name = "Larry";
	//per4.birthday.day = 1;
	//per4.birthday.month = 4;
	//per4.birthday.year = 1990;
	per4.birthday = { 1, 4, 1990 };
	per4.salary = 50000;
	person per5{
		"Genry",
		{2,6,1987},
		45000
	};
	person* pper5 = &per5;
	std::cout << "Имя " << pper5->name << '\n';
	std::cout << "дата рождениия: " << pper5->birthday.day << '.' <<
		pper5->birthday.month << '.' <<
		pper5->birthday.year << "\n\n";
	show_person(per4);
	//person per6 = input_person();
	person per6;
	fill_person(per6);
	show_person(per6);
	*/
	//задача1. персона с монетами
	/*
	std::cout << "Задача 1\n Объект: \n";
	persona A{ "Kira",
				18,
				{1,2,3,4,2} 
	};
	show_persona(A);
	std::cout << "Год рождения: " << year_of_birth(A, 2022) << '\n';
	std::cout << "Общие сбережения: " << cash(A) << "\n";
	*/
	//Задача 2.Координаты
	std::cout << "ТОчка А: ";
	point A = { 4.5,-1.3 };
	std::cout << A.x << ", " << A.y << '\n';
	point B = { 6.1,0.9 };
	std::cout <<"Точка B: " << B.x << ", " << B.y << '\n';
	std::cout << compare_distanse(A, B);



	return 0;
}
//заполнение массива
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}