#include <iostream>
#include <cassert> //assert stuff
#include <stdlib.h> //atoi

using namespace std;

void printTime(string time);
bool isValidTime(string time);
bool hasValidTimeFormat(string time);
bool hasValidTimeValues(string time);
string getTime(char timeA_B);

void test();

int main()
{
test();
/*
    string time_A = getTime('A');
    if(time_A =="x"){
        return 0;//exit
    }
    string time_B = getTime('B');
    if(time_B  == "x"){
        return 0;//exit
    }

    printTime(time_A);
    printTime(time_B);*/
}

/*
    This method will get the time and return it as a string. It will also validate the time format
*/
string getTime(char timeA_B){
    bool hasValidTime = false;
    string time = "";
    while(!hasValidTime){
        cout << "Enter Time " << timeA_B << "(hh mm ss), or x to exit: ";
        getline(cin, time);
        if(time == "x" || time == "X"){
            cout << "Goodbye!" << endl;
            return "x";
        }
        hasValidTime = isValidTime(time);
    }
    return time;
}

/**
* Validates Time Orchestrator/Manager
* Try and do upfront validations so we have validate data to work with later.
*/
bool isValidTime(string time){

    if(!hasValidTimeFormat(time)){
        return false;
    }

    if(!hasValidTimeValues(time)){
        return false;
    }

    return true;
}

/**
* Validates Time Format
*/
bool hasValidTimeFormat(string time){

    string currentVal;
    for(int i = 0; i < time.length(); i++){
        currentVal = time[i];

        //1.  We are expecting a number here? it will be expected to exist where i = 0,1,3,4,6,7, if any of these do not have a number, end program with error message
        if(i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7 ){
            //we are reading each index, for indexes where we expect a number, check that it equals a number else error
            if(!(currentVal == "0" || currentVal == "1"  || currentVal == "2"  || currentVal == "3"  || currentVal == "4"  || currentVal == "5"
                || currentVal == "6"  || currentVal == "7"  || currentVal == "8"  || currentVal == "9")){
                cout << "ERROR hasValidTimeFormat 1: Time format must be hh mm ss, you gave the following time which does not conform: " << time << endl;
                return false;
            }
        }

        //2.  Check that in index 2 of ie 11 23 56 doesnt contain 1112356, always expecting a space for index 2 and 5
        if(i == 2 || i == 5){
            if(currentVal != " "){
                cout << "ERROR hasValidTimeFormat 2: Time format must be hh mm ss, you gave the following time which does not conform: " << time << endl;
                return false;
            }
        }
    }
    return true;
}

/**
* Validates Time units values.
* Hour should be 00 -> 23
* Minutes 00 -> 59
* Seconds 00 -> 59
*/
bool hasValidTimeValues(string time){
    string hh = time.substr(0,2);
    string mm = time.substr(3,2);
    string ss = time.substr(6,2);

    int hour = atoi(hh.data());
    int minutes = atoi(mm.data());
    int seconds = atoi(ss.data());

    if(!(hour > -1 && hour < 24)){
        cout << "ERROR hasValidTimeValues 1: Hour value must be 00 - 23, you gave: " << hour << endl;
        return false;
    }
    if(!(minutes > -1 && minutes < 60)){
        cout << "ERROR hasValidTimeValues 2: Minutes value must be 00 - 59, you gave: " << minutes << endl;
        return false;
    }
    if(!(seconds > -1 && seconds < 60)){
        cout << "ERROR hasValidTimeValues 3: Seconds value must be 00 - 59, you gave: " << seconds << endl;
        return false;
    }
    return true;
}

void printTime(string time){
    string hh = time.substr(0,2);
    string mm = time.substr(3,2);
    //cout << "MM: |" << mm << "|";
    string ss = time.substr(6,2);

    cout << hh << ":" <<  mm << ":" << ss << endl;
}




void test(){
    string testTime = "22 59 48";
    bool test = false;

    test = isValidTime(testTime);
    cout << "Tested isValidTime with result: " << test << endl << endl;

    test = hasValidTimeValues(testTime);
    cout << "Tested hasValidTimeValues with result: " << test << endl << endl;

    test = hasValidTimeFormat(testTime);
    cout << "Tested hasValidTimeFormat with result: " << test << endl<< endl;

    printTime(testTime);
    cout << "Tested printTime." << endl << endl;

}







