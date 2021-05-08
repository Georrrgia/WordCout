#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	FILE *fp;
	int getw;
	int scount=0, icount=0;
	if((fp=fopen("C:/Users/THINKPAD/Desktop/现代软件工程/代码/test.txt","r"))==NULL){   //只用参数？
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
		printf("总共有 %d 个单词\n",scount);
	}
	if(strcmp(argv[1],"-c")==0){
		printf("总共有 %d 个字符\n",icount);
	}
	return 0;
}
