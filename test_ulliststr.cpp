#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;


  dat.push_front("1536");
  dat.push_front("1024");
  dat.push_front("768");

  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
}
