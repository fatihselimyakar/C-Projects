#include <stdio.h>

int find_size_of_line(char line[]){/*this function provides us find the size of line.*/
	int ct=0;
	while(!(line[ct]=='\0'||line[ct]=='\n')){/*while line[ct] is end point then counter(ct) is decreasing.*/
		ct++;
	}
	return ct;
}

void reverse_line(char line[], int line_lenght){/*this function reverse the string.*/
	int i,j;
	char temp[1024];
	for(i=0;i<line_lenght;i++){
		temp[i]=line[line_lenght-(i+1)];/*I get the reverse string value with temp's memory.*/
	}
	for(j=0;j<line_lenght;j++){/*I assign the temp's values to my input string.*/
		line[j]=temp[j];
	}
		
}

void encrypt_open_msg(){/*this function provides encrypt the open_msg.txt*/
	FILE *input;
	input=fopen("open_msg.txt","rt");
	FILE *output;
	output=fopen("secret_msg.txt","wt");
	char str[1024];/* for the memorize my input file*/
	int i=0,j,key,lenght;
	do{
		printf("\nPlease enter your key value between 26 and 1:\n");/*I get the key value*/
		scanf("%d",&key);
	}
	while(key<1&&key>26);
	
	while(!feof(input)){/*I read the all line one by one until the end of the file with while loop and the fgets function and I encrypted it and wrote it to the other file.*/
		fgets(str,1024,input);
		lenght=find_size_of_line(str);
		reverse_line(str,lenght);
		for(j=0;j<lenght;j++){
				if(str[j]=='.'){
					str[j]='*';
				}
				else if(str[j]==' '){
					str[j]='_';
				}
				else if(str[j]<='z'&&str[j]>='a'){
					if(str[j]-key<'a'){
						str[j]=('z'+1)-('a'-(str[j]-key));
					}
					else{
						str[j]=str[j]-key;
					}
				}
		}
		printf("%s",str);
		fprintf(output,"%s",str);
	}
	fclose(output);
	fclose(input);
}

void decrypt_secret_msg(){/*this function provides decrypt the open_msg.txt*/
	
	FILE *input;
	input=fopen("secret_msg.txt","rt");
	FILE *output;
	output=fopen("open_msg.txt","wt");
	char str[1024];/* for the memorize my input file*/
	int i=0,j,key,lenght;
	
	do{
		printf("\nPlease enter your key value between 26 and 1:\n");/*I get the key value*/
		scanf("%d",&key);
	}
	while(key<1&&key>26);
	
	while(!feof(input)){/*I read the all line one by one until the end of the file with while loop and the fgets function and I decrypted it and wrote it to the other file.*/
		fgets(str,1024,input);
		lenght=find_size_of_line(str);
		reverse_line(str,lenght);
		for(j=0;j<lenght;j++){
			if(str[j]=='*'){
				str[j]='.';
			}
			else if(str[j]=='_'){
				str[j]=' ';
			}
			else if(str[j]<='z'&&str[j]>='a'){
				if(str[j]+key>'z'){
					str[j]=((str[j]+key)-'z')+('a'-1);
				}
				else{
					str[j]=str[j]+key;
				}
			}
		}
		printf("%s",str);
		fprintf(output,"%s",str);
	}
	fclose(output);
	fclose(input);

}

void menu(){/*here I write the menu function and I use all of these functions in this function*/
	int ch;
	do{
		printf("\n\n1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("0. Exit\n");
		printf("Choice:");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				encrypt_open_msg();
				break;
			case 2:
				decrypt_secret_msg();
				break;
			case 0:
				break;
				
		}
	}
	while(ch!=0);
}

int main (){/*I use my wrote functions*/
	menu();
}
		
