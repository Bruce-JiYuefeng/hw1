#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  //test push_back and push_front
    dat.push_back("one");
    assert(dat.back() == "one" && dat.front() == "one" && dat.size() == 1);

    dat.push_front("zero");
    assert(dat.front() == "zero" && dat.size() == 2);

    dat.push_back("two");
    assert(dat.back() == "two" && dat.size() == 3);


    //test pop_back and pop_front
    dat.pop_back();
    assert(dat.back() == "one" && dat.size() == 2);

    dat.pop_front();
    assert(dat.front() == "one" && dat.size() == 1);

    dat.pop_back();
    assert(dat.empty());

    //test back and front
    try {
        dat.front();  
        assert(false);
    } catch(const std::out_of_range& e) {
        assert(true); 
    }

    dat.push_back("new one");
    assert(dat.front() == "new one" && dat.back() == "new one");

    //test get and set
    assert(dat.get(0) == "new one");
    dat.set(0, "modified");
    assert(dat.get(0) == "modified");

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}



