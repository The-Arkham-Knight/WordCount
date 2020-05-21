#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void Count(char * file); 
int ccount=0;
int wcount=0;

int main(int argc, char* argv[])               //argv[1]保存指令，argv[2]保存文件路径
{
    FILE *fp;
    Count(argv[2]);
        if(strcmp(argv[1],"-c")==0)                   //统计文件字符数
            printf("文件%s字符数为:%d\n",argv[2],ccount);
        else if(strcmp(argv[1],"-w")==0)                   //统计文件单词数
            printf("文件%s单词数为:%d\n",argv[2],wcount);
    
    return 0;
}


void Count(char * file)
{
    FILE * fp;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("文件不存在 \n");
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);
            ccount++;
        if(a==' '||a=='\n'||a==',')
        {
            wcount++;
        }
    }
	wcount++;  //最后一个单词不会计数，需+1
    ccount--;  //文件结尾字符会+1
    fclose(fp);
}