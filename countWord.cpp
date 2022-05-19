#include<stdio.h>
#include<string.h>

void countCharOrWord(char *op,char *filename){
	char line[1024] = {0};
	
	FILE *file = fopen(filename,"r");
	if(!file){
		printf("文件不存在或找不到该文件!");
		return;
	}
	int wordnum=0;
	int charnum=0;
	while(1){
		if(EOF == fscanf(file,"%s",line))
		break;
	    wordnum++;
	    charnum+=strlen(line);
	}
	fclose(file);
	if(strcmp(op,"-c")){
		printf("单词数为:%d",wordnum);
	}else if(strcmp(op,"-w")){
	printf("字符数为:%d",charnum);
    }else{
    	printf("输入有错误!");
	}
	
}

int main(int argc,char *argv[]){
	
	if(argc==3){
		char *op = argv[1];
		char *file= argv[2];
		countCharOrWord(op,file);
	}else{
		printf("输入有错误!");
	}
	return 0;
}