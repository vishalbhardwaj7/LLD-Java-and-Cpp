#include<bits/stdc++.h>
using namespace std;

// chain of responsibilities
// client -> request -> object 1 -> object 2 -> ............


class LogProcessor{
public:
    const int INFO = 1, DEBUG=2, ERROR=3;
    LogProcessor *nextLogProcessor;
    LogProcessor(LogProcessor *nextLoggerProcess){
        this->nextLogProcessor = nextLoggerProcess; // assignt the next logger process
    }

    virtual void log(int logLevel, string message){ // vritual function..... so that in runtime the derived classes' implementations can be used
        if(nextLogProcessor != NULL){
            nextLogProcessor->log(logLevel,message);
        }
        else 
            throw "EXCEPTION: Can't Handle this type of logging";
    }
};

class InfoLogProcessor : public LogProcessor{
public:
    InfoLogProcessor(LogProcessor *nextLogProcessor):LogProcessor(nextLogProcessor){}
    void log(int logLevel, string message){
        if(logLevel == INFO) // there can be complex logics also like handling of these logs
            cout<< "INFO: " << message<<endl;
        else if(nextLogProcessor != NULL) 
            nextLogProcessor->log(logLevel,message);
        else 
            throw "EXCEPTION: Can't Handle this type of logging";
    }
};
class DebugLogProcessor : public LogProcessor{
public:
    DebugLogProcessor(LogProcessor *nextLogProcessor):LogProcessor(nextLogProcessor){}
    void log(int logLevel, string message){
        if(logLevel == DEBUG) // there can be complex logics also like handling of these logs
            cout<< "DEBUG: " << message<<endl;
        else if(nextLogProcessor != NULL) 
            nextLogProcessor->log(logLevel,message);
        else 
            throw "EXCEPTION: Can't Handle this type of logging";
    }
};
class ErrorLogProcessor : public LogProcessor{
public:
    ErrorLogProcessor(LogProcessor *nextLogProcessor):LogProcessor(nextLogProcessor){}
    void log(int logLevel, string message){
        if(logLevel == ERROR) // there can be complex logics also like handling of these logs
            cout<< "ERROR: " << message<<endl;
        else if(nextLogProcessor != NULL)
            nextLogProcessor->log(logLevel,message);
        else 
            throw "EXCEPTION: Can't Handle this type of logging";
    }
};

int main(){
    try {
        LogProcessor *logger = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(NULL)));
        // this means a hierarchy so that info -> debug -> error
        logger->log(logger->INFO, "Reached this point of code now making a call to DB");
        logger->log(logger->ERROR, "DB error encountered");
        logger->log(logger->DEBUG, "Reached function xyz");


        // exception will come at this point of time
        logger->log(4, "Yo bro i am not supported try printing me");
    } catch (const char* exception) {
        cerr << "Exception caught: " << exception << endl;
    }
}