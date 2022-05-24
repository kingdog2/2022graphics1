#include <stdio.h>
int main(){
    FILE * fout = fopen("file.text", "w+");
    printf("Hello World\n");
    fprintf(fout ,"Hellow World\n");
    fclose(fout); ///關閉檔案
}
