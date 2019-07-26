#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#define LogFileName  "..\\Debuglog.txt"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
using namespace std;


class LogWriter
{
private :
	ofstream myfile;

	static LogWriter* instance;
	
	LogWriter();

	string getTimesys() {
		time_t now = time(0);
		char* dt = ctime(&now);
		return string(dt).substr(0, string(dt).length() - 1);
	}


	void Creat();

public:
	

	static LogWriter* getInstance() {
		if (instance == nullptr) {
			instance = new LogWriter();
		}
		return instance;
	}

	 void write(string str);
	 void write(float a, float b);
	 void write(string s, float a, float b);

};
