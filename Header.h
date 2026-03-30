#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <cctype>
#include <set>
#include <algorithm>
#include <map>
#include <sstream>

// проверка ввода
std::string getText();
int getNumber();

// Ввод и вывод контейнера "Vector"
std::vector<int> inputVector();
void outputVector(std::vector<int>& V);
void randomStringVector(std::vector<std::string>& v); // Создание вектора со строками

// заполнение множества
void inputSet(std::set<std::vector<int>>& sett, int n);


void outputMap(std::map<char, int>& m);		 // вывод словаря
void outputMultiMap(std::multimap<int, int>& m);  // вывод мульти-словаря

// Задачи
void task_1();
void task_2();
void task_3();


#endif
