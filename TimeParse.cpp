#include <bits/stdc++.h>

using namespace std;

class TimeParse{
    private:
        int hour,minute,second,millisecond;
    public:
        TimeParse(string line)
        {
            doParsing(line);
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
                    cout<<"Class TimeParse : Function setMemberVariableValues : Getting into default section of switch case : check sc variable value "<<endl;
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
        
        int getHour()
        {
            return hour;
        }
        int getMinute()
        {
            return minute;
        }
        int getSecond()
        {
            return second;
        }
        int getMillisecond()
        {
            return millisecond;
        }
};