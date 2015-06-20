// Artificial Intelligence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string userName;
	string command;
	cout << "Hi, What is your name? "<<endl;
	getline(std::cin, userName);
	cout << endl;

	cout << "It's nice to meet you " << userName << "!" << endl;
	cout << endl;
	cout << "How may I help you?" << endl;
	getline(std::cin, command);
	cout << endl;

	return 0;
}

