#include <stdio.h>                                  //第 1 行
#include <string.h>                                 //第 2 行
int main()                              //错误1     //第 3 行
{ 
    char s[1000];                                   //第 4 行
    char words[100][16];                            //第 5 行
    int i, j, len;                                  //第 6 行
    int wcount = 0, wlen, index = 0, inaword = 0;   //第 7 行
    char c;                                         //第 8 行
    //scanf("%s", s);           //错误2                      //第 9 行
    gets(s);
    len = strlen(s);                                //第 10 行
    for (i = 0; i < len; i++)                       //第 11 行
    { 
        if (s[i] != ' ')  //错误3   “ ”                //第 12 行
        { 
            if (inaword == 0)                       //第 13 行
            { 
                wcount++;                           //第 14 行
                inaword = 1;                        //第 15 行
            } 
            words[wcount - 1][index ++] = s[i];  //错误4      //第 16 行
        } 
        else                                        //第 17 行
        { 
            words[wcount - 1][index] = '\0';
            index = 0;//index = 0;错误5                   //第 18 行
            inaword = 0;                            //第 19 行
        } 
    } 
    words[wcount - 1][index] = '\0';                //第 20 行
    for (i = 0; i < wcount; i  ++)                    //第 21 行
    { 
        wlen = strlen(words[i]);                    //第 22 行
        if (words[i][0] >= '0' && words[i][0] <= '9')//错误6   //第 23 行
        { 
            for (j = 0; j < wlen / 2; j++) //错误7            //第 24 行
            { 
                c = words[i][j];                    //第 25 行
                words[i][j] = words[i][wlen - j - 1];//第 26 行
                words[i][wlen - j - 1] = c;         //第 27 行
            } 
        } 
        else                                        //第 28 行
        { 
            int f = words[i][0] >= 'A'&& words[i][0]<= 'Z';//改错8
            for (j = 0; j < wlen; j++)              //第 29 行
                words[i][j] = words[i][j] + (f ? -'A' + 'a' : -'a' + 'A');//第 30 行
        } 
    } 
    for (i = wcount - 1; i >= 0; i--)   //错误9                 //第 31 行
    {
        printf("%s ",words[i]);             //第 32 行                 //第 33 行
    }
    return 0;                                      //错误10
}