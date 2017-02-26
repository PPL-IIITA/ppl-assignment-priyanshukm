#ifndef LOG_H
#define LOG_H

#include <bits/stdc++.h>
using namespace std;

/* Class for Logging Instances of Code Execution */
class Log
{
	private:
	    time_t total_time; /* Total CPU time */
	    fstream file; /* File stream link to currently opened file */
	    string str; /* String to store time */
	public:

		/* Contructor to Initialise Log File name */
	    Log (string fname);
	    
	    /* Function to write message in file */
	    void logger(string eventtype, string message);
	    
	    /* Destructor */
	    ~Log();
};

#endif
