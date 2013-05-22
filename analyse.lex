%{
  //#include <iostream>
#define BALISE 320
#define ATTRIBUT 327
#define DOCTYPE 321
#define PHP 322
#define KEY 323
#define FUNCTION 324
#define BALISEFERMANTE 325
#define STRING 326
#define TAB 328
#define ENDL 329
#define SPACE 330
#define BALISEOUVERTE 331
#define BALISEFERMEE 332
#define TEXT 333
#define COMMENTAIRE 334
  //using namespace std
%}

%option noyywrap

%%

[\t]+ { return TAB;}

[\n]+ {return ENDL;}

[ ]+ {return SPACE;}

\<!--[ -~]+--> {return COMMENTAIRE;}

![dD][oO][cC][tT][yY][pP][eE] {return DOCTYPE;}

\?[pP][hH][pP] {return PHP;}

\<[ ]*[a-zA-Z]+[ ]*\> {return BALISE;}

\<\/[ ]*[a-zA-Z]+[ ]*\> {return BALISEFERMANTE;}

\<[ ]*[a-zA-Z]+[ ]+ { return BALISEOUVERTE;}

[a-zA-Z]+=[\"\'][!-~]*[\"\'] { return ATTRIBUT;}

\> { return BALISEFERMEE;}

if|else|for|while|return {return KEY;}

[a-zA-Z]+\( {return FUNCTION;}

[\"\'][!-~]*[\"\'] {return STRING;}

. {return TEXT;}

%%
