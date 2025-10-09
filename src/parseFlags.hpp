#ifndef PARSEFLAGS_HPP
#define PARSEFLAGS_HPP

#include <vector>
#include <string>

#define MISSING_OUTPUT_FILEPATH -1

using std::vector;
using std::string;

extern string outputFilepath;
extern vector<string> files;

int parseFlags(vector<string> args);

#endif