#include <bits/stdc++.h>
#include "TimeParse.h"
using namespace std;

class LogLine{
    private:
        string mDate;
        map<string,int> mTimeMap;
        string mProcessId;
        string mThreadId;
        string mLogLevel;
        string mLogMessage;
    public:
        LogLine(string line)
        {
            doParsing(line);
        }

        void doParsing(string input)
        {
            int set_count =0, startIndex =0;
            string word;
            for(int i=0;i<input.length();i++)
            {
                if(input[i] ==' '){
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
                    mDate = input;
                    break;
                case 2 : 
                    TimeParse tobj(input);
                    mTimeMap["Hour"] = tobj.getHour();
                    mTimeMap["Minute"] = tobj.getMinute();
                    mTimeMap["Second"] = tboj.getSecond();
                    mTimeMap["Millisecond"] = tobj.getMillisecond();
                    //Time
                    break;
                case 3 : 
                    mProcessId= input;
                    break;
                case 4 : 
                    mThreadId = input;
                    break;
                case 5 : 
                    mLogLevel = input;
                    break;
                case 6 : 
                    mLogMessage = input;
                    break;
                default:
                    cout<<"Class LogLine : Function setMemberVariableValues : Getting into default section of switch case : check sc variable value "<<endl;
                    break;
            }
        }

        //Need to create getter methods for all member variables;
};