#pragma once
#include <fstream>

class logger{
private:
    static inline std::ofstream output;
public:
    static void setOutputFile(std::string const &fileName){
        output.open(fileName);
    }
    static void write(std::string const &text){
        output << text;
    }
    static void newLine() {
        output << std::endl;
    }
};
