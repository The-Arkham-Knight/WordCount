#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void Count(char * file); 
int ccount=0;
int wcount=0;

int main(int argc, char* argv[])               //argv[1]����ָ�argv[2]�����ļ�·��
{
    FILE *fp;
    Count(argv[2]);
        if(strcmp(argv[1],"-c")==0)                   //ͳ���ļ��ַ���
            printf("�ļ�%s�ַ���Ϊ:%d\n",argv[2],ccount);
        else if(strcmp(argv[1],"-w")==0)                   //ͳ���ļ�������
            printf("�ļ�%s������Ϊ:%d\n",argv[2],wcount);
    
    return 0;
}


void Count(char * file)
{
    FILE * fp;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("�ļ������� \n");
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
	wcount++;  //���һ�����ʲ����������+1
    ccount--;  //�ļ���β�ַ���+1
    fclose(fp);
}