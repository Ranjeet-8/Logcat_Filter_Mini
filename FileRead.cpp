#include <iostream>
#include <fstream>
#include <vector>
// #include "LogLine.h"

class FileRead
{
    private:
        std::string file_Name;
        std::vector<LogLine> dataset;
    public:
        FileRead(std::string input) : file_Name(input) {}

        void readFile()
        {
            std::ifstream infile(file_Name);
            if(!infile)
            {
                std::cout<<"Error in opening the file"<<std::endl;
            } 
            else
            {
                std::string line;
                while(getline(infile,line))
                {
                    LogLine lobj(line);
                    dataset.push_back(lobj);
                }
            }
        }

        std::vector<LogLine> getDataset(){
            return dataset;
        }
};