#include <stdio.h>
int main(){
    FILE * fout = fopen("file.text", "w+");
    fprintf(fout ,"3.1415926\n");
    fclose(fout); ///關閉檔案

    float angle=0;
    FILE * fin = fopen("file.text", "r");
    fscanf(fin ,"%f", &angle);
    printf("讀到了角度:%f", angle);
    fclose(fin);
}
