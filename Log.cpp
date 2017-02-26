#ifndef LOG_H
#include "Log.h"

#include <bits/stdc++.h>
using namespace std;

Log::Log(string fname)
{
    if (file.is_open())
        file.close();
    file.open(fname, ios::out | ios::app);
    if (file.fail()) {
        throw runtime_error ("Log File ain't open.\n");
    }
}

void Log::logger(string eventtype, string logmessage)
{
    time(&total_time);
    str = ctime(&total_time);
    file << str << ' ' << eventtype << ' ' << logmessage << endl;
}

Log::~Log()
{
    if (file.is_open())
        file.close();
}

#endif