#include <stdio.h>                                  //第 1 行
#include <string.h>                                 //第 2 行
void main()                                         //第 3 行
{ 
    char s[1000];                                   //第 4 行
    char words[100][16];                            //第 5 行
    int i, j, len;                                  //第 6 行
    int wcount = 0, wlen, index = 0, inaword = 0;   //第 7 行
    char c;                                         //第 8 行
    scanf("%s", s);                                 //第 9 行

    len = strlen(s);                                //第 10 行
    for (i = 0; i < len; i++)                       //第 11 行
    { 
        if (sentence[i] != " ")                     //第 12 行
        { 
            if (inaword == 0)                       //第 13 行
            { 
                wcount++;                           //第 14 行
                inaword = 1;                        //第 15 行
            } 
            words[wcount - 1][index] = s[i];        //第 16 行
        } 
        else                                        //第 17 行
        { 
            words[wcount - 1][index] = '\0';        //第 18 行
            inaword = 0;                            //第 19 行
        } 
    } 
    words[wcount - 1][index] = '\0';                //第 20 行
    for (i = 0; i < wcount; i++)                    //第 21 行
    { 
        wlen = strlen(words[i]);                    //第 22 行
        if (words[i][0] >= 0 && words[i][0] <= 9)   //第 23 行
        { 
            for (j = 0; j < wlen; j++)              //第 24 行
            { 
                c = words[i][j];                    //第 25 行
                words[i][j] = words[i][wlen - j - 1];//第 26 行
                words[i][wlen - j - 1] = c;         //第 27 行
            } 
        } 
        else                                        //第 28 行
        { 
            for (j = 0; j < wlen; j++)              //第 29 行
                words[i][j] = words[i][j] + (words[i][0] >= 'A' //第 30 行
                                && &words[i][0] <= 'Z' ? 32 : 32);//第 30 行
        } 
    } 
    for (i = 0; i < wcount; i++)                    //第 31 行
    {
        if(i > 0)printf("%s",words[i]);             //第 32 行    
        else printf("%s\n",words[i]);               //第 33 行
    }
}