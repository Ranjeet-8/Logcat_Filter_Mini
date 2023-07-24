#include <bits/stdc++.h>
//#include "LogLine.h"

using namespace std;

class Display
{
    private:
        vector<LogLine> dataset;
        int hour,minute,second,millisecond;
    public:
        Display(vector<LogLine>& set) : dataset(set) {}

        void printPV(string pid, string vid)
        {
            for(auto index : dataset)
            {
                if(index.getPId() == pid && index.getVId() == vid)
                {
                    //write print final print function
                }
            }
        }
        void printTimeRange(string start, string end)
        {
            for(auto index : dataset)
            {
                doParsing(start);
                map<string,int> uTimemap;
                uTimemap = index.getTimemap();
                if(uTimemap.count("Hour") && uTimemap.count("Minute") && uTimemap.count("Second") && uTimemap.count("Millisecond"))
                {
                    if(uTimemap["Hour"]>=hour && uTimemap["Minute"]>=minute && uTimemap["Second"]>=second && uTimemap["Millisecond"]>=millisecond)
                    {
                        doParsing(end);
                    }
                    if(uTimemap["Hour"]<=hour && uTimemap["Minute"]<=minute && uTimemap["Second"]<=second && uTimemap["Millisecond"]<=millisecond)
                    {
                        //write print final print function
                    }
                }
            }
        }
        void doParsing(string input)
        {
            int set_count =0, startIndex =0;
            string word;
            for(int i=0;i<input.length();i++)
            {
                if(input[i] ==':'){
                  word = input.substr(startIndex,i-1);
                  startIndex=i+1;
                  set_count++;  
                }
                setMemberVariableValues(word,set_count);
            }
        }
        void setMemberVariableValues(string input, int sc){
            switch (sc)
            {
                case 1 : 
                    hour = stringToInt(input);
                    break;
                case 2 : 
                    minute = stringToInt(input);
                    break;
                case 3 : 
                    second = stringToInt(input);
                    break;
                case 4 : 
                    millisecond = stringToInt(input);
                    break;
                default:
                    cout<<"Class Display : Function setMemberVariableValues : Getting into default section of switch case : check sc variable value "<<endl;
                    break;
            }
        }
        int stringToInt(string input)
        {
            int output = 0;
            for(int i=0;i<input.length();i++)
            {
                output = output * 10 + input[i];
            }
            return output;
        }
};