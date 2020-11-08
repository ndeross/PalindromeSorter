#include <iostream> 
#include <string>
#include <fstream> 
 
#include "PalRoutines.h"
#include "sort.h"  
int const MAX_SIZE = 1000;

void OpenFile (ifstream & inFile); 
void GetData(string Palindromes[MAX_SIZE], int & count);
void PrintMatching (string Palindromes[MAX_SIZE], string phrase, int count);  
void Initialize (string Palindromes[MAX_SIZE]); 
void CheckType (string Palindromes[MAX_SIZE], string phrase, int count, PalindromeT TypeCheck);   
int main () 

{ 
 
   string InFileName; 
   ifstream inFile; 
   string phrase;  
   string classString; 
   string Palindromes[MAX_SIZE];  
   int count; 
     
    
  GetData (Palindromes, count); 
  Sort(Palindromes, count); 
  PrintMatching (Palindromes, phrase, count);   
 
   return 0; 
   
} 




void GetData (string Palindromes[MAX_SIZE], int & count) 

{ int i; 
  string phrase;
  ifstream inFile; 
    

  OpenFile (inFile);        

  getline (inFile, phrase); 

 i=0;
 
 while ((inFile) and (i < MAX_SIZE)) 
 
{ Palindromes[i] = phrase; 
  getline (inFile, phrase); 
  i++;
  count++;      
}   
 
        
return; 


}
	  
	  
	        
void OpenFile (ifstream & inFile) 


{ 
string inFileName; 

  cout << "Enter a file name =>"; 
  cin >> inFileName; 
  
  inFile.open(inFileName.c_str());

  if (!inFile) 
  
  { cout << inFileName  << " does not exist";
    cout << endl;  } 
 
  
  return; 
  
  }  
  
  
 

void PrintMatching (string Palindromes[MAX_SIZE], string phrase, int count) 

{ 
  
   

cout << endl; 
cout << endl; 

  cout << "The perfect palindromes in the list are:" << endl; 
  
  CheckType (Palindromes, phrase, count,PalindromeT :: PERFECT );

cout << endl; 
 cout << endl; 

  cout << "The natural palindromes in the list are:" << endl;

   CheckType (Palindromes, phrase, count, PalindromeT :: NATURAL );
   
cout << endl; 
cout << endl; 


 cout << "The palindromes in the list are:" << endl;
  
 CheckType (Palindromes, phrase, count,PalindromeT ::  REGULAR );

cout << endl;
cout << endl; 

  cout << "The non-palindromes in the list are:" << endl;

 CheckType (Palindromes, phrase, count,PalindromeT ::  NON);  


return; 

} 
 

void CheckType (string Palindromes[MAX_SIZE], string phrase, int count, PalindromeT TypeCheck) 

{ 
   PalindromeT classification; 
   int i; 

   for (i=0; i <= (count-1); i++)

  {
    phrase = Palindromes[i];
   
    classification = ClassifyPhrase(phrase);
    if (classification == TypeCheck)
   
    { cout << "	" << "\"" << phrase << "\"" << endl;}
} 
   return; 
}













