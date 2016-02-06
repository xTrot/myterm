#include <iostream>
#include "command.h"
using namespace std;

int main(){

	command cmd; // Our command class

	do{

		if (!cmd.readline()){ // Read command from user

			cmd.print_usage(); // Show usage

		}else{

			cmd.execute(); // Execute command

		}

	} while (!cmd.exit_requested()); // Check for termination

	return 0;

}
