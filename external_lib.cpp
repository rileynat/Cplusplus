#include "external_lib.h"
#include <cassert>
#include <cmath>

using namespace std;


bool is_prime( long long int n ) {
	if ( n <= 0 ) { return false; }
	if ( n == 2 ) { return true; }
	if ( n % 2 == 0 ) { return false; }
	long long int m = sqrt(n);
	
	for (long long int i=3; i<=m; i+=2) {
      if (n%i==0) {
         return false;
      }
   }
   return true;
}

int GCD( long long int a, long long int b ) {

   if (b==0) return a;
   return GCD(b,a%b);
}

int LCM ( long long int a, long long int b ) {
	return b*a / GCD(a,b);
}


string num_to_string_ten( int n ) {
	assert ( n < 10 );
	assert ( n >= 0 );
	switch ( n ) {
	
		case 0: return "zero";
				break;
		
		case 1: return "one";
				break;
				
		case 2: return "two";
				break;
				
		case 3: return "three";
				break;
				
		case 4: return "four";
				break;
				
		case 5: return "five";
				break;	
				
		case 6: return "six";
				break;
				
		case 7: return "seven";
				break;
				
		case 8: return "eight";
				break;
				
		case 9: return "nine";
				break;
				
		default: assert(false); //string was not set
				break;
	}
}

string num_to_string_thou( int n ) {
	string return_string = "";
	assert ( n < 1000 && n >= 0);
	
	int hundreds = n / 100;
	int tens = (n / 10) % 10;
	int ones = n % 10;
	
	if ( hundreds != 0 ) {
		return_string += num_to_string_ten(hundreds);
		return_string += " hundred ";
		if (tens != 0 || ones != 0 ) {
			return_string += "and ";
		}
	}
	
	
	
	assert( tens >= 0 && tens < 10 );
	if ( tens > 1 ) { 
		
		switch( tens ) {
		
			case 2: return_string += "twenty";
					break;
					
			case 3: return_string += "thirty";
					break;
					
			case 4: return_string += "forty";
					break;
					
			case 5: return_string += "fifty";
					break;
					
			case 6: return_string += "sixty";
					break;
					
			case 7: return_string += "seventy";
					break;
					
			case 8: return_string += "eighty";
					break;
					
			case 9: return_string += "ninety";
					break;
					
			default: assert(false); // this should never be reached
					break;
		}
		
		if ( ones != 0 ) {
			return_string += "-";
			return_string += num_to_string_ten(ones);
			
		}
		
	} else if ( tens == 1 ) {
		
		switch(ones) {
		
		case 0: return_string += "ten";
				break;
		
		case 1: return_string += "eleven";
				break;
				
		case 2: return_string += "twelve";
				break;
				
		case 3: return_string += "thirteen";
				break;
				
		case 4: return_string += "fourteen";
				break;
				
		case 5: return_string += "fifteen";
				break;	
				
		case 6: return_string += "sixteen";
				break;
				
		case 7: return_string += "seventeen";
				break;
				
		case 8: return_string += "eighteen";
				break;
				
		case 9: return_string += "nineteen";
				break;
				
		default: assert(false); //string was not set
				break;
		}
	} else if ( tens == 0 ) {
	
		if ( ones > 0 ) {
			return_string += num_to_string_ten(ones);
		}
		
		if ( hundreds == 0 && tens == 0 && ones == 0 ) {
			return_string = "zero";
		}
	}
	
	return return_string;
}	