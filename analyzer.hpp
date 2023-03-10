#include <iostream>
#include <list>

/*
    made by NightCaio
    
    free license for personal or commercial use
    a simple lexical analyzer
*/

using namespace std;

// utility methods for identifying character types

    //checks if the character 'c' is a number
		int isNum(char c){
		    return c >= 48 && c <= 57;
		}
		
    //checks if the character 'c' is a letter
		int isChar(char c){
		    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
		}
		
	// returns the type of the token found in numeral form
	// is only used when the token does not match other types
		int analyzer(char c){
		    switch(c){
		        case '(':
		            return 3;
		        case ')':
		            return 4;
		        case '[':
		            return 5;
		        case ']':
		            return 6;
		        case '{':
		            return 7;
		        case '}':
		            return 8;
		        case '<':
		            return 9;
		        case '>':
		            return 10;
		        case '=':
		            return 11;
		        case '+':
		            return 12;
		        case '-':
		            return 13;
		        case '*':
		            return 14;
		        case '/':
		            return 15;
		        case '.':
		            return 16;
		        case ':':
		            return 17;
		        case ';':
		            return 18;
		        case '?':
		            return 19;
		        case '&':
		            return 20;
		        case '|':
		            return 21;
		        case '$':
		            return 22;
		        case '%':
		            return 23;
		        case '`':
		            return 24;
		        case '~':
		            return 25;
		        case '@':
		            return 26;
		        case '!':
		            return 27;
		        case '^':
		            return 28;
		        default:
		            return -1;
		    }
		}
		

	
	
