#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	FILE *fp;
	int getw;
	int scount=0, icount=0;
	if((fp=fopen("C:/Users/THINKPAD/Desktop/�ִ��������/����/test.txt","r"))==NULL){   //ֻ�ò�����
        printf("Open the file failure...\n");
        exit(0);
    }
	getw=fgetc(fp);
	while(getw!=EOF){
		while(getw!=' ' && getw!='\t' && getw!='\n' && getw!=',' && getw!='.' && getw!=EOF){
			getw=fgetc(fp);
		}
		scount++;
		while(getw==' '||getw=='\t'||getw=='\n' || getw==',' || getw=='.'){
			getw=fgetc(fp);
			icount++;
			if(getw==EOF){
				break;
			}
		}
	}
	fclose(fp);
	if(strcmp(argv[1],"-w")==0){
		printf("�ܹ��� %d ������\n",scount);
	}
	if(strcmp(argv[1],"-c")==0){
		printf("�ܹ��� %d ���ַ�\n",icount);
	}
	return 0;
}
