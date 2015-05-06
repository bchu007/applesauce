//Name: Chu, Brian
//Assignment 4: map
//student ID: 861174197
//Date: 5/4/15

#include <iostream>
#include <map>
#include "mymap.H"
int main() {
    mymap<string,int> ml;
    ml["January"] = 31;
    ml["February"] = 30;
    ml["March"] = 31;
    ml["April"] = 30;
    ml["May"] = 31;
    ml["June"] = 30;
    ml["July"] = 31;
    ml["August"] = 31;
    ml["September"] = 30;
    ml["October"] = 31;
    ml["November"] = 30;
    ml["December"] = 31;
    cout << ml.find("April")->second << endl; // 30
    cout << ml.find("Yam")->second << endl; // junk
    cout << ml["May"] << endl; // 31
    cout << (ml.find("Yam") == ml.end()? "miss" : "hit") // miss
        << endl;
    cout << ml["Yam"] << endl; // 0
    cout << (ml.find("Yam") == ml.end()? "miss" : "hit") // hit
        << endl;
}