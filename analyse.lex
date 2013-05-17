%{
  //#include <iostream>
#define BALISE 320
#define ATTRIBUT 327
#define DOCTYPE 321
#define PHP 322
#define KEY 323
#define FUNCTION 324
#define CLASS 325
#define STRING 326
  //using namespace std
%}

%option noyywrap

%%

[\t\n ] {}

![dD][oO][cC][tT][yY][pP][eE] {/*yylval = "DOCTYPE";*/ return DOCTYPE; }

\?[pP][hH][pP] {/*yylval = "php";*/ return PHP;}

\<[a-zA-Z]+ {/*yylval = yytext[1];*/ return BALISE; }

\<\/[a-zA-Z]+ {/*yylval = yytext[1];*/ return BALISE; }

if|else|for|while|return {/*yylval = yytext;*/ return KEY;}

[a-zA-Z]+\( {/*yylval = yytext ;*/ return FUNCTION;}

[\"\'][!-~]*[\"\'] {/*yylval = yytext ;*/ return STRING;}

%%

int main(){
  int i;
  // char* s = "<head>";
  yyin="<head>";
  while((i=yylex())!=0){
    // cout << "Nous traitons le lexème : " << yytext << "\nle jeton correspondant est : " << i << endl;
    printf("Nous traitons le lexème : %s\nle jeton correspondant est : %d\n", yytext, i);
  }
  return 0;
}
