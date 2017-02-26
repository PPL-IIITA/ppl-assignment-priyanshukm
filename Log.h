#ifndef LOG_H
#define LOG_H

#include <bits/stdc++.h>
using namespace std;

/*! Class for Logging Instances of Code Execution */
class Log
{
	private:
	    /*! Total CPU time */
	    time_t total_time; 
	    /*! File stream link to currently opened file */
	    fstream file; 
	    /*! String to store time */
		string str; 
	public:

		/*! Contructor to Initialise Log File name */
	    Log (string fname);
	    
	    /*! Function to write message in file */
	    void logger(string eventtype, string message);
	    
	    /*! Destructor */
	    ~Log();
};

#endif
