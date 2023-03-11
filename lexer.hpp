#include "analyzer.hpp"

/*
    made by NightCaio
    
    free license for personal or commercial use
    a simple lexical analyzer
    
    this header includes "analyzer.hpp" in the hierarchy
*/

// struct that represents the token
// can be a string, number, keyword or symbol
		typedef struct {
		    int type;
		    string value;
		} Token;

// method that performs lexical analysis
		list<Token> lexer(string code){
			//
		    list<Token> result;
		    
		    for(int i=0; i < code.length(); i++){
		         //
		        char begin = code.at(i);
		        Token tok;
		        
		        // ignore enter and spaces
		        if(begin == ' ' || begin == '\n') continue;
		
		        // strings
		        if(begin == '\"' || begin == '\''){
		            tok.type = 2;
		            i++;
		            while(i < code.length() && code.at(i)!='\"' && code.at(i)!='\''){
		                tok.value += code.at(i);
		                i++;
		            }
		        }
		        
		        // numbers
		        else if(isNum(begin)){
		            tok.type = 1;
		            while(i < code.length() && (isNum(code.at(i)) || code.at(i) == '.')){
		                tok.value += code.at(i);
		                i++;
		                
		            }
		            i--;
		        }
		        
		        // keywords & properties
		        else if(isChar(begin) || begin == '_'){
		            tok.type = 0;
		            while(i < code.length() && (isChar(code.at(i)) || isNum(code.at(i)) || code.at(i) == '_')){
		                tok.value += code.at(i);
		                i++;
		            }
		            i--;
		        }
		        
		        // ignore comments with '#'
		        else if(begin == '#'){
		            while(i < code.length() && code.at(i) != '\n')
		                i++;
		            i++;
                continue;
		        }
		        
		        // special characters
		        else {
		            tok.type = analyzer(begin);
		
		            // throws unknown character error 
		            if(tok.type == -1){
		                cout << "LEXER ERROR: unexpected token \'" << begin << "\'";
		                exit(1);
		            }
		            tok.value = begin;
		        }
		
		        // add the current token to the list
		        result.push_back(tok);
		        //
		        }
		        //
		        return result;
		    }

// debug method to print token array
		void printLexer(list<Token> s){
			
		    cout << "lexer result:\n\n| ";
		    for(Token v : s)
		        cout << v.value << " | ";
		
		    cout << "\n\n| ";
		    for(Token v : s)
		
		        if(v.type == 0)
		            cout << "keyword | ";
		
		        else if(v.type == 1)
		            cout << "number | ";
		
		        else if(v.type == 2)
		            cout << "string | ";
		
		        else
		            cout << v.value << " | ";
		
		    cout << "\n\n|  ";
		    for(Token v : s)
		        cout << v.type << "  |  ";
		
		    cout << "\n";
		}

