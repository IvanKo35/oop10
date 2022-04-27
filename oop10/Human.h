#pragma once
#include <iostream>
#include <string>
using namespace std;

class Human
{
protected:
	string surname;
	string name;
	string midname;
	int age;
public:
	Human() {}
	Human(string name1, string name2, string name3, int age)
	{
		this->surname = name1;
		this->name = name2;
		this->midname = name3;
		this->age = age;
	}
	virtual void print() = 0;
	virtual ~Human() {}
};

class Student : public Human
{
private:
	bool on_lesson;
public:
	Student() {}
	Student(string surname, string name, string midname, int age, bool lesson) : Human(surname, name, midname, age)
	{
		this->on_lesson = lesson;
	}
	void print()
	{
		cout << surname << ' ' << name << ' ' << midname << " " << age
			<< (on_lesson ? ": on lesson" : ": absent") << endl;
	}
};

class Boss : public Human
{
private:
	int number_of_workers;
public:
	Boss() {}
	Boss(string surname, string name, string midname, int age, int number) : Human(surname, name, midname, age)
	{
		this->number_of_workers = number;
	}

	void print()
	{
		cout << surname << ' ' << name << ' ' << midname << ' - ' << age
			<< ': ' << number_of_workers << endl;
	}
};