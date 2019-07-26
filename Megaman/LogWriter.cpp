
#include "LogWriter.h"


LogWriter* LogWriter::instance = nullptr;

LogWriter::LogWriter() 
{
	myfile.open(LogFileName, ios::out);

}

void LogWriter::Creat()
{
	
}



void LogWriter::write(string str) {
	
	myfile << getTimesys()<<"	"<< str.c_str() << endl;
}
void LogWriter::write(float a, float b) {

	myfile << getTimesys()<< "		" << a <<" "<<b<< endl;
}

void LogWriter::write(string s, float a, float b)
{
	myfile << getTimesys() << "	" << s.c_str() << " ";
	myfile  << a << " " << b << endl;

}
