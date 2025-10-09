#ifndef PARSEFLAGS_HPP
#define PARSEFLAGS_HPP

#include <vector>
#include <string>

#define PRINT_HELP_EXIT -1
#define MISSING_OUTPUT_FILEPATH -2

using std::vector;
using std::string;

extern string outputFilepath;
extern vector<string> files;

int parseFlags(vector<string> args);
void printHelp(string arg0);

#endif