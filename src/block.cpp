#include <string>
#include <vector>

using std::vector;
using std::string;

enum TagType {

    KEYWORD,
    DATATYPE,
    DATAPOINTER,
    SCOPESTART

};

class Tag {

    public:
        TagType TagType;
        vector<Block> blocks;

};

class Block {

    public:
        vector<Tag> tags;

};