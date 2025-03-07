#pragma once
class Person
{
public:
	Person(const char* s);
	Person(const Person& w);
	~Person();
	void print();
	char* name;
};

