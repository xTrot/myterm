#ifndef COMMAND_H

#define COMMAND_H

#include <string>

class command{

	public:

	command();

	const bool exit_requested() const { return this->exit_requested_; }

	bool readline();

	void print_usage() const;

	void execute();

private:

	bool exit_requested_;

};

#endif // COMMAND_H
