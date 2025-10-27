#include <bits/stdc++.h>
using namespace std;

int main(){
    // FILE *fp = NULL;
    // cout << sizeof(fp) << "\n";
    // 实际上还需要有很多的检查，比如文件是否存在，是否可读写等等。
    char in[110] , out[110];
    scanf("%s%s", in, out);
    FIlE * fin = fopen(in, "r");
    FIlE * fout = fopen(out, "w");
    fseek(fin , 0 , SEEK_END);
    int size = ftell(fin);
    fseek(fin , 0 , SEEK_SET); // rewind(fin)
    char * buffer = (char*) malloc(size);
    fread(buffer, 1, size, fin);
    fwrite(buffer, 1, size, fout);
    fclose(fin);
    fclose(fout);
    free(buffer);
    return 0;
}