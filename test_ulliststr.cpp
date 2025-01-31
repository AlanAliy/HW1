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


    //Popping back with no items
    cout << endl << "Testing pop_back, pop_front with no items:" << endl;
    try {testerList.pop_back();}
    catch(const std::exception& e)  {std::cerr << e.what() << " POPBACK FAILED" << endl;}

    try {testerList.pop_front();}
    catch(const std::exception& e)  {std::cerr << e.what() << " POPFRONT FAILED" <<  endl;}



    //tests for push front
    cout << endl << "Testing pushfront and popfront: " << endl;
    for (int i=0; i <= 20; i++) {
         testerList.push_front(to_string(i));
    }
    for (size_t i=0; i < testerList.size(); i++) {
         cout << i << "th: " << testerList.get(i) << "  ";
    }
    
    cout << endl << "Size after 21 pushed front: " << testerList.size() << endl;

    size_t size_cur = testerList.size();
    for (size_t i=0; i < size_cur ; i++) {
         testerList.pop_front();
     }
    cout << "Size after all popped front: " << testerList.size() << endl;



    
    cout << endl << "Testing pushback and popback: " << endl;
    
    //pushback
    for (int i=0; i <= 20; i++) {
       testerList.push_back(to_string(i));
    }
    for (size_t i=0; i < testerList.size(); i++) {
         cout << i << "th: " << testerList.get(i) << "  ";
    }
    cout << endl << "Size after 21 pushed back " << testerList.size() << endl;

    //popback
    size_cur = testerList.size();
    for (size_t i=0; i < size_cur ; i++) {
    testerList.pop_front();
    }
    cout << "Size after all popped back: " << testerList.size() << endl;


    //front and back test with size 0
    cout << endl << "Testing front() and back() with zero items: " << endl; 
    try {testerList.front();}
    catch(const std::exception& e)  {std::cerr << e.what()<< endl;}
    
    try {testerList.back();}
    catch(const std::exception& e)  {std::cerr << e.what()<< endl;}
    
    
    for (int i=0; i <= 20; i++) {
       testerList.push_back(to_string(i));
    }
    
    cout << endl << "testing for front and back with items: " << endl;
    cout << "Size(21): " << testerList.size() << endl;
    cout << "Front(0): " << testerList.front() << endl;
    cout << "back: " << testerList.back() << endl;



    //bad get on borders
    cout << endl << "Testing for bad get on last item + 1: " << endl;;
    try { cout << testerList.get(testerList.size());}
    catch(const std::exception& e)  {std::cerr << e.what() << endl;}

    //get

    cout << endl << endl;








     ULListStr list;
	list.push_back("oldfront");
	list.push_back("oldback");

	//EXPECT_TRUE(checkListContent(&list, {"oldfront", "oldback"}));
     for (size_t i=0; i < list.size(); i++) {
         cout << i << "th: " << list.get(i) << "  ";
     }
     cout << endl << endl;



	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
     for (size_t i=0; i < list.size(); i++) {
         cout << i << "th: " << list.get(i) << "  ";
     }
     cout << endl << endl;



	list.push_front("newfront");

     for (size_t i=0; i < list.size(); i++) {
         cout << i << "th: " << list.get(i) << "  ";
     }
     cout << endl << endl;

	// now, a new element struct should get created at the front
	
     
     list.pop_back();
	list.push_front("cloudfront");

     for (size_t i=0; i < list.size(); i++) {
         cout << i << "th: " << list.get(i) << "  ";
    }
	// now, the original head should get deleted
	list.pop_back();
     for (size_t i=0; i < list.size(); i++) {
         cout << i << "th: " << list.get(i) << "  ";
    }



 	list.pop_front();
      for (size_t i=0; i < list.size(); i++) {
         cout << i << "th: " << list.get(i) << "  ";
     }


     ULListStr list2;
     list2.push_back("1");
     list2.push_back("2");
     list2.push_back("3");
     list2.push_back("4");

     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }

     list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }
          list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }
          list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }
          list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }

     cout << endl << "size: " << list2.size() << endl;


     list2.push_front("4");
     list2.push_front("3");
     list2.push_front("2");
     list2.push_front("1");

     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }

     list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }
          list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }
          list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }
          list2.pop_front();
     for (size_t i=0; i < list2.size(); i++) {
         cout << i << "th: " << list2.get(i) << "  ";
     }

     cout << endl << "size: " << list2.size() << endl;


}  

