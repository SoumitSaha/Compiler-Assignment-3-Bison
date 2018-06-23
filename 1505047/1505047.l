%{

FILE *logout;
FILE *tokenout;
#include<vector>
#include "SymTab.h"
#include "y.tab.h"

using namespace std;

extern YYSTYPE yylval;
extern SymbolTable *table;
void yyerror(char *);
//vector<string> codesegment[23];

int line_count=1;
int err_count = 0;
//int elsepos;
//int logicoppos;
//int reloppos;

%}

WHITESPACE [ \t\f\r\v]+
NEWLINE \n
LETTER [a-zA-Z]
LETTERORUNDERSCORE [a-zA-Z_]
DIGIT [0-9]
DIGITS {DIGIT}+
INTEGER {DIGITS}
FLOAT {DIGITS}*(\.{DIGITS})(E[+-]?{DIGITS})?
IDENTIFIER {LETTERORUNDERSCORE}({LETTERORUNDERSCORE}|{DIGIT})*
CHAR [ -\[]]|[\]-~]
CHARS {CHAR}+
CHARACTER ('({CHAR})')
SPECIAL_CHAR '\\[vtrabf"n0]'|'\\\\'
STRING \"([\\](\n|.)|[^\\\"\n])*\"
UNFINISHED_STRING \"([\\](\n|.)|[^\\\"\n])*

SINGLE_LINE_COMMENT "//"{CHAR}*$ 

MULTILINE_COMMENT_form1_START [\/][\*]
MULTILINE_COMMENT_form1_END [\*][\/]
ANYTHING_WITHOUT_STAR [^\*]
STAR_NOT_SLASH \*[^\/]

MULTILINE_COMMENT_form2 [\/][\/]([^\"\n]|(\\{NEWLINE}))*

MULTILINE_COMMENT_form1 ({MULTILINE_COMMENT_form1_START}({ANYTHING_WITHOUT_STAR}|{STAR_NOT_SLASH})*{MULTILINE_COMMENT_form1_END})
UNFINISHED_COMMENT ({MULTILINE_COMMENT_form1_START}({ANYTHING_WITHOUT_STAR}|{STAR_NOT_SLASH})*)

INVALIDSUFFPREF {DIGITS}{IDENTIFIER}
EMPTYCHAR "''"

UNFINISHED_CHAR "'"([^\n\'])*|(\'\\\')
MULTI_CHAR "'"[^\n\']([^\n\'])*"'"

TOO_MANY_DEC_POINT ((([0-9])*)*(\.)+)+((([0-9])*)*(\.)+)+([0-9])*
ILL_FORMED_NUMBER ({INTEGER}|{FLOAT})([E]*{FLOAT}*{INTEGER}*)*

UNRECOGNIZED_CHAR .

%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

"if"							{	
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"IF");
                                    yylval.value = s;
                                    return IF;
                                }

"else"							{ 	
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"ELSE");
                                    yylval.value = s;
                                    return ELSE;  
                                }
"for"							{ 	
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"FOR");
                                    yylval.value = s;
                                    return FOR;
                                }
"while"							{ 	
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"WHILE");
                                    yylval.value = s;
                                    return WHILE;
                                }
"do"							{ 	
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"DO");
                                    yylval.value = s;
                                    return DO;}
"int"							{ 	
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"INT");
                                    yylval.value = s;
                                    return INT;
                                }
"char"							{  
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"CHAR");
                                    yylval.value = s;
                                    return CHAR;
                                }
"float"							{     
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"FLOAT");
                                    yylval.value = s;
                                    return FLOAT;
                                }
"double"						{     
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"DOUBLE");
                                    yylval.value = s;
                                    return DOUBLE;
                                }
"void"							{  
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"VOID");
                                    yylval.value = s;
                                    return VOID;
                                }
"return"						{     
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"RETURN");
                                    yylval.value = s;
                                    return RETURN;
                                }
"println"						{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"PRINTLN");
                                    yylval.value = s;
                                    return PRINTLN;
                                }
"++"							{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"INCOP");
                                    yylval.value = s;
                                    return INCOP;
                                }
"--"							{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"DECOP");
                                    yylval.value = s;
                                    return DECOP;
                                }

"+"|"-"							{	
									SymbolInfo* s = new SymbolInfo(string(yytext),"ADDOP");
									yylval.value = s;
									return ADDOP;
								}

"*"|"/"|"%" 					{	
									SymbolInfo* s = new SymbolInfo(string(yytext),"MULOP");
									yylval.value = s;
									return MULOP;
								}

"<"|"<="|">"|">="|"=="|"!=" 	{	
									SymbolInfo* s = new SymbolInfo(string(yytext),"RELOP");
									yylval.value = s;
                                    //reloppos = codesegment[16].size();
									return RELOP; 
								}

"="		 						{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"ASSIGNOP");
                                    yylval.value = s;
                                    return ASSIGNOP;
                                }

"&&"|"||"						{	
									SymbolInfo* s = new SymbolInfo(string(yytext),"LOGICOP");
									yylval.value = s;
                                    //logicoppos = codesegment[15].size();
									return LOGICOP;
								}

"!"								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"NOT");
                                    yylval.value = s;
                                    return NOT;
                                }
"("								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"LPAREN");
                                    yylval.value = s;
                                    return LPAREN;
                                }
")"								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"RPAREN");
                                    yylval.value = s;
                                    return RPAREN;
                                }
"{"								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"LCURL");
                                    yylval.value = s;
                                    return LCURL;
                                }
"}"								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"RCURL");
                                    yylval.value = s;
                                    return RCURL;
                                }
"["								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"LTHIRD");
                                    yylval.value = s;
                                    return LTHIRD;
                                }
"]"								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"RTHIRD");
                                    yylval.value = s;
                                    return RTHIRD;
                                }
","								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"COMMA");
                                    yylval.value = s;
                                    return COMMA;
                                }
";"								{    
                                    SymbolInfo* s = new SymbolInfo(string(yytext),"SEMICOLON");
                                    yylval.value = s;
                                    return SEMICOLON;
                                }

{IDENTIFIER}		{
				SymbolInfo* s = new SymbolInfo(string(yytext),"ID");
				yylval.value = s;
				return ID;
			}

{INTEGER} 	{
				SymbolInfo* s = new SymbolInfo(string(yytext),"CONST_INT");
				yylval.value = s;
				return CONST_INT;
			}
			
{FLOAT} 	{
				SymbolInfo* s = new SymbolInfo(string(yytext),"CONST_FLOAT");
				yylval.value = s;
				return CONST_FLOAT;
			}

{CHARACTER}		{
				string str = string(yytext);
    			string subs;
    			subs = str.substr(1,1);
				SymbolInfo* s = new SymbolInfo(string(yytext),"CONST_CHAR");
				yylval.value = s;
				return CONST_CHAR;
			}

{SPECIAL_CHAR}		{
				string str = string(yytext);
    			string subs;
    			string t2 = "";
    			subs = str.substr(1,2);
    			if(subs == "\t"){
    				char c = '\t';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\n"){
    				char c = '\n';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\\"){
    				char c = '\\';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\""){
    				char c = '\"';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\a"){
    				char c = '\a';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\f"){
    				char c = '\f';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\r"){
    				char c = '\r';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\b"){
    				char c = '\b';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\v"){
    				char c = '\v';
            		string t1(1,c);
            		t2 = t1;
    			}
    			if(subs == "\0"){
    				char c = '\0';
            		string t1(1,c);
            		t2 = t1;
            	}
				SymbolInfo* s = new SymbolInfo(string(yytext),"CONST_CHAR"); // It may need to be corrected
				yylval.value = s;
				return CONST_CHAR;
			}

{UNFINISHED_CHAR}		{
				int p = 0;
				for(int i = 0; i<string(yytext).size(); i++){
        			if(string(yytext).at(i) =='\n'){
        				p++;
        			}
    			}
    			line_count = line_count+p;
    			err_count++;
				}

{INVALIDSUFFPREF}		 {
    			err_count++;
				}	

{EMPTYCHAR}		{
    			err_count++;
				}

{MULTI_CHAR}	{
				int p = 0;
				for(int i = 0; i<string(yytext).size(); i++){
        			if(string(yytext).at(i) =='\n'){
        				p++;
        			}
    			}
    			line_count = line_count+p;
    			err_count++;
				}

{STRING}		{
				int p = 0;
				string str = string(yytext);
    			string subs;
    			subs = str.substr(1,str.size()-2);
    			string strf = "";
    			for(int i = 0; i<subs.size(); i++){
        			if(subs.at(i) =='\\'){
        				if(subs.at(i+1) == '\n'){
            				i = i+1;
            				p++;
            			}
            			else if(subs.at(i+1) == 't'){
            				char c = '\t';
            				string t1(1,c);
            				strf.append(t1);
            				i = i+1;
            			}
            			else if(subs.at(i+1) == '\\'){
            				char c = '\\';
            				string t1(1,c);
            				strf.append(t1);
            				i = i+1;	
            			}
        			}
        			else{
            			char c = subs.at(i);
            			string t1(1,c);
            			strf.append(t1);
        			}
    			}
    			string strff = "";
    			strff.append("\"");
    			strff.append(strf);
    			strff.append("\"");
				line_count = line_count + p;
                SymbolInfo* s = new SymbolInfo(string(yytext),"STRING");
                yylval.value = s;
				return STRING;
			}

{UNFINISHED_STRING} 	{
				int p = 0;
				for(int i = 0; i<string(yytext).size(); i++){
        			if(string(yytext).at(i) =='\n'){
        				p++;
        			}
    			}
    			line_count = line_count+p;
    			err_count++;
			}

{SINGLE_LINE_COMMENT}|{MULTILINE_COMMENT_form1}|{MULTILINE_COMMENT_form2}	 {
				int p = 0;
				for(int i = 0; i<string(yytext).size(); i++){
        			if(string(yytext).at(i) =='\n'){
        				p++;
        			}
    			}
    			line_count = line_count+p;
    			//return COMMENT;
			}

{UNFINISHED_COMMENT} 	{
				int p = 0;
				for(int i = 0; i<string(yytext).size(); i++){
        			if(string(yytext).at(i) =='\n'){
        				p++;
        			}
    			}
    			line_count = line_count+p;
    			err_count++;
			}

{ILL_FORMED_NUMBER} 	{
    			err_count++;
			}

{TOO_MANY_DEC_POINT} 	{
    			err_count++;
			}			

{UNRECOGNIZED_CHAR} 	{
    			err_count++;
			}	

%%

int yywrap(void)
{
	return 1;
}
