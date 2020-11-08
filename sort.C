#include <iostream> 
#include <string> 

#include "sort.h" 

using namespace std; 


void Sort (string Palindromes[], int  size) 
 
{ 

size_t i, j; 

i = 1; 

while(i <size_t(size) ) {

j = i; 

while ((j > 0) and (Palindromes[j-1] > Palindromes[j])) 

{ Swap (Palindromes[j], Palindromes [j-1]); 
  j--; } 
    
  i++; } 
  
return; }


void Swap(string &a, string &b) 

{ string temporary; 
  temporary = a; 
  a = b; 
  b = temporary; 

return; 

}    