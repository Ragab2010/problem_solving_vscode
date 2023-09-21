#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>// setw , setfill


using namespace std;
string timeConversionCpp(string s) {
    int hour = stoi(s);
    int min =  stoi(s.substr(3, 2)); // Change to extract 2 characters for minutes
    int second =  stoi(s.substr(6, 2)); // Change to extract 2 characters for seconds
    string pm_am = s.substr(8);
    
    if (pm_am == "PM") {
        if (hour < 12) {
            hour += 12;
        }
    } else if (pm_am == "AM") {
        if (hour == 12) {
            hour = 0;
        }
    }

    // Use std::setw to ensure two digits with leading zeros
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << second;
    return ss.str();
}


int main(){

    cout<<"---------------------timeConversionCpp-----------------"<<endl;
    //cout<<timeConversionCpp("12:15:11AM")<<endl;
    cout<<timeConversionCpp("07:05:45PM")<<endl;
    
    return 0;
}