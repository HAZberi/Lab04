// lab4ExA.cpp
// ENSF 614 Lab 4 Exercise A
//
// This program demonstrates the use of all the features
// of the MyArray class.


#include <iostream>
using namespace std;

#include "MyArray.h"

int main()
{
  
  int i;

  // Create empty array, then grow it.
  MyArray a;
  a.resize(5);
  for (i = 0; i < a.size(); i++)
    a.set(i, 0.5 + i);
  
  cout << "Elements of a: ";
  for (i = 0; i < a.size(); i++)
    cout << ' ' << a.at(i);
  cout << endl;
  cout << "(Expected:      " << "0.5 1.5 2.5 3.5 4.5)\n\n";

  // Copy array from built-in array, then expand.
  double x[] = { 10.5, 11.5, 12.5, 13.5 };
  MyArray b(x, 4);
  b.resize(7);
  for (i = 4; i < b.size(); i++)
    b.set(i, 10.5 + i);

  cout << "Elements of b after first resize: ";
  for (i = 0; i < b.size(); i++)
    cout << ' ' << b.at(i);
  cout << endl;
  cout << "(Expected:                         " 
       << "10.5 11.5 12.5 13.5 14.5 15.5 16.5)\n\n";

  // Now shrink b.
  b.resize(3);

  cout << "Elements of b after second resize: ";
  for (i = 0; i < b.size(); i++)
    cout << ' ' << b.at(i);
  cout << endl;
  cout << "(Expected:                          " 
       << "10.5 11.5 12.5)\n\n";

  // Quick check of copy ctor.
  MyArray c(b);
  c.set(0,  -1.5);               // should not affect b

  cout << "Elements of b after copy ctor check: ";
  for (i = 0; i < b.size(); i++)
    cout << ' ' << b.at(i);
  cout << endl;
  cout << "(Expected:                            " 
       << "10.5 11.5 12.5)\n\n";

  cout << "Elements of c after copy ctor check: ";
  for (i = 0; i < c.size(); i++)
    cout << ' ' << c.at(i);
  cout << endl;
  cout << "(Expected:                            " 
       << "-1.5 11.5 12.5)\n\n";

  // Quick check of operator =.
  // Note tests of self-assignment and chaining.
  c = b = a;
  a.set(0, -10.5);              // should not affect b or c
  b.set(0, -11.5);              // should not affect a or c
  a = a;

  cout << "Elements of a after operator = check: ";
  for (i = 0; i < a.size(); i++)
    cout << ' ' << a.at(i);
  cout << endl;
  cout << "(Expected:                             " 
       << "-10.5 1.5 2.5 3.5 4.5)\n\n";
  
  cout << "Elements of b after operator = check: ";
  for (i = 0; i < b.size(); i++)
    cout << ' ' << b.at(i);
  cout << endl;
  cout << "(Expected:                             " 
       << "-11.5 1.5 2.5 3.5 4.5)\n\n";
  
  cout << "Elements of c after operator = check: ";
  for (i = 0; i < c.size(); i++)
    cout << ' ' << c.at(i);
  cout << endl;
  cout << "(Expected:                             " 
       << "0.5 1.5 2.5 3.5 4.5)\n\n";

  return 0;
}
