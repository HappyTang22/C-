#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc,char* argv[])
{
	if(argc<2){
		printf("filedir filename");
		return -1;
	}
	
	DIR *pDir = opendir(argv[1]);
	if(pDir == NULL){
		perror("opendir err");
		return -1;
	}
	
	//循环读取
	struct dirent *pDent = NULL;
	while((pDent = readdir(pDir))){
		printf("%s-%d\n",pDent->d_name,pDent->d_type);
	}
	
	//关闭目录
	closedir(pDir);
	return 0;
}