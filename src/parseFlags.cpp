#include "parseFlags.hpp"

string outputFilepath = "a.out";
vector<string> files;

bool isQuartzFile(string str){

    int strSize = str.size();

    if(strSize < 4){
        return false;
    }

    int start = strSize - 3;

    string substr = str.substr(start);

    if(substr.compare(".qz") != 0){
        return false;
    }

    return true;

}

int parseFlags(vector<string> args){

    for(int i = 1; i < args.size(); i++){

        if(args.at(i).compare("-o") == 0){

            if((i + 1) == args.size()){
                return MISSING_OUTPUT_FILEPATH;
            }

            outputFilepath = string(args.at(i));
            continue;
        }

        if(isQuartzFile(args.at(i))){
            files.push_back(args.at(i));
        }

    }

    return 0;

}