#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{


    ULListStr testerList;

    try {testerList.pop_back();}
    catch(const std::exception& e)  {std::cerr << e.what() << endl;}


    for (int i=0; i <= 25; i++) {
        testerList.push_back(to_string(i));
    }
    
    cout << "Size: " << testerList.size() << endl;

    //bad get request
    try { cout << testerList.get(testerList.size());}
    catch(const std::exception& e)  {std::cerr << e.what() << endl;}
    

    cout << "Front(0): " << testerList.front() << endl;
    cout << "back (25): " << testerList.back() << endl;
    
    
    testerList.pop_back();
    cout << "back--popped (24): " << testerList.back() << endl;

    for (size_t i=0; i < testerList.size(); i++) {
        cout << i << "th: " << testerList.get(i) << "   ";
    }
    cout << endl << endl;

    size_t size_cur = testerList.size();
    for (size_t i=0; i < size_cur ; i++) {
        testerList.pop_back();
        cout << "Size: " << testerList.size() << "   ";
    }
    cout << endl << endl;

    cout << "Size after all popped back: " << testerList.size() << endl;
}  
