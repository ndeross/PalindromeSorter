#include <iostream>
#include <fstream>
#include <string>

#include "PalRoutines.h"

using namespace std;

void OpenFile(ifstream& inFile);

void PrintResults(string classString, string phrase);

int main()

{
  string InFileName;
  ifstream inFile;
  string phrase;
  PalindromeT classification;
  string classString;

  OpenFile(inFile);

  getline(inFile, phrase);

  cout << endl;

  while (inFile)

  {
    classification = ClassifyPhrase(phrase);

    classString = PalindromeTToString(classification);

    PrintResults(classString, phrase);

    getline(inFile, phrase);
  }

  return 0;
}

void OpenFile(ifstream& inFile)

{
  string inFileName;

  cout << "Enter a file name =>";
  cin >> inFileName;

  inFile.open(inFileName.c_str());

  if (!inFile)

  {
    cout << inFileName << " does not exist";
    cout << endl;
  }

  return;
}

void PrintResults(string classString, string phrase)

{
  cout << "\"" << phrase << "\""
       << " "
       << "is a " << classString <<"." <<  endl;

  return;
}