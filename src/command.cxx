#include "command.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

string lastcommand;
string line;

command::command()

: exit_requested_(false)

{

}

bool command::is_valid_command_line(const string &line) const{
	
	// TODO: Compare line to valid command structure using regex
	
	// Hint: check boost::expressive::sregex
	
	return false;

}

bool command::readline(){

// TODO: Print prompt for the user.
	cout<<"command:";
// Read line from user.
	
	getline(cin,line);
	stringstream input_stringstream(line);
	
	char* args[2];
	args[0] = (char*) line.c_str();
	args[1] = NULL;
	
	getline(input_stringstream,lastcommand,' ');
	
	if(execvp(args[0],args)<0)
		return false;
	else
		return true;
}

void command::print_usage() const

{

// TODO: Display usage format to user.
	cout<<"Correct Usage for "<<lastcommand<<":"<<endl;
	string cmd = lastcommand+" --help";
	string data;
	FILE * stream;
	const int max_buffer = 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");
	
	stream = popen(cmd.c_str(), "r");
	if (stream) {
		while (!feof(stream))
			if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
			pclose(stream);
		}
	cout<<data;
	

}

void command::execute()

{

// TODO: Execute the command.

}
