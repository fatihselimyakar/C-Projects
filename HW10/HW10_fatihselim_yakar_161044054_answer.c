#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{/*I declare the struct for the linked list*/
	int data;
	struct node *next;
}node;

int read_line(FILE *read){/*this function provides us read the one line file to variable*/
	int res;
	fscanf(read,"%d,00",&res);
	return res;
}

int find_prime(int n){/*this function finds the prime number between 0 and n*/
	int c = 2;
    for (c=2;c<=n-1;c++)
    {
       if (n%c==0)
       {
		   return 0;
       }
    }
	if(n==1){
		return 0;
	}
    return 1;
    
}

double fpn_dyn(FILE *write_da){/*this function read the whole file and saves the dynamic array and print/fprint the prime numbers and measure time */  
	clock_t t1,t2;
	t1=clock();
	FILE *read;
	int i=0,*p,size=1;
	p=(int *)calloc(size,sizeof(int));/*In the beginning I allocate the 1 memory(dynamic 1d array)*/
	read=fopen("data.txt","r");
	while(!feof(read)){
		p[i]=read_line(read);/*I read and save the my array*/
		if(find_prime(p[i])==1&&p[i]!=0){
			printf("\nprime number(dynamic arr):%d,00",p[i]);/*it prints*/
			fprintf(write_da,"\nprime number(dynamic arr):%d,00",p[i]);/*it prints the file*/
		}
		p=(int*)realloc(p,(i+2)*sizeof(int));/*All loop I set the +1 allocate the memory*/
		i++;
		
	}
	t2=clock();
	double diff = (((double)t2 - (double)t1)/1000);/*I divided by 1000 because it finds kind of nanosecond*/
	return diff;/*It returns the Time*/
	free(p);
}

double fpn_dyn_between_space(int max){/*this function read the until max value and while saves the dynamic array it print the prime numbers and measure time*/
	clock_t t1,t2;
	t1=clock();
	FILE *read;
	int i=0,*p,size=1;
	p=(int *)calloc(size,sizeof(int));/*In the beginning I allocate the 1 memory(dynamic 1d array)*/
	read=fopen("data.txt","r");
	while(i<=max){
		p[i]=read_line(read);/*I read and save the my array*/
		if(find_prime(p[i])==1&&p[i]!=0){
			printf("\nprime number(dynamic arr):%d,00",p[i]);/*it prints*/
		}
		p=(int*)realloc(p,(i+2)*sizeof(int));/*All loop I set the +1 allocate the memory*/
		i++;
	}
	t2=clock();
	double diff = (((double)t2 - (double)t1)/1000);/*I divided by 1000 because it finds kind of nanosecond*/
	return diff;/*It returns the Time*/
	free(p);
}

double fpn_ll(FILE *write_ll){/*this function read the whole file and saves the linked list and print/fprint the prime numbers and measure time */
	clock_t t1,t2;
	t1=clock();
	FILE *read;
	read=fopen("data.txt","r");
	node * root;/*I declare the root pointer*/
	node * iter;/*I declare the iterator for the find other linked list's values*/
	root=(node *)calloc(1,sizeof(node));/*I allocate the 1 memory for the root pointer*/
	iter=root;
	while(!feof(read)){/*this while loop is generate the memory location and fill this memory and go to the next like chain*/
		iter->next=(node *)calloc(1,sizeof(node));
		iter=iter->next;
		iter->data=read_line(read);
		if(find_prime(iter->data)==1&&iter->data!=0){
			printf("\nprime number(l.list):%d,00",iter->data);/*it prints*/
			fprintf(write_ll,"\nprime number(l.list):%d,00",iter->data);/*it prints the folder*/
		}
		iter->next=NULL;
	}
	t2=clock();
	fclose(read);
	double diff = (((double)t2 - (double)t1)/1000);/*I divided by 1000 because it finds kind of nanosecond*/
	return diff;/*It returns the Time*/
	free(root);
	
}

double fpn_ll_between_space(int max){/*this function read the until max and saves the linked list and print the prime numbers and measure time */
	clock_t t1,t2;
	t1=clock();
	FILE *read;
	read=fopen("data.txt","r");
	node * root;/*I declare the root pointer*/
	node * iter;/*I declare the iterator for the find other linked list's values*/
	root=(node *)calloc(1,sizeof(node));/*I allocate the 1 memory for the root pointer*/
	iter=root;
	while(iter->data<=max){/*this while loop is generate the memory location and fill this memory and go to the next like chain*/
		iter->next=(node *)calloc(1,sizeof(node));
		iter=iter->next;
		iter->data=read_line(read);
		if(find_prime(iter->data)==1&&iter->data!=0){/*it prints*/
			printf("\nprime number(l.list):%d,00",iter->data);/*it prints the folder*/
		}
		iter->next=NULL;
	}
	t2=clock();
	fclose(read);
	double diff = (((double)t2 - (double)t1)/1000);/*I divided by 1000 because it finds kind of nanosecond*/
	return diff;/*It returns the Time*/
	free(root);
}

int main(){
	/*I open the file for write for the linked list*/
	FILE *write_ll;
	write_ll=fopen("output_prime_LiknedList.txt","w");
	double llbts=fpn_ll_between_space(500000);/*it reads and print the screen until 500.000 by linked list*/
	double llbts2=fpn_ll_between_space(750000);/*it reads and print the screen until 750.000 by linked list*/
	double llbts3=fpn_ll_between_space(999979);/*it reads and print the screen until 1.000.000 by linked list*/
	double llbts_folder=fpn_ll(write_ll);/*it reads and print the screen and the folder for all these numbers by linked list*/
	/*All of these are prints or fprints the times*/
	printf("\nlinked list 500.000 Time(ms):%.0f\n",llbts);
	fprintf(write_ll,"\nlinked list 500.000 Time(ms):%.0f",llbts);
	printf("\nlinked list 750.000 Time(ms):%.0f\n",llbts2);
	fprintf(write_ll,"\nlinked list 750.000 Time(ms):%.0f",llbts2);
	printf("\nlinked list 1.000.000 Time(ms):%.0f\n",llbts3);
	fprintf(write_ll,"\nlinked list 1.000.000 Time(ms):%.0f",llbts3);
	printf("\nlinked list read and write all these numbers Time(ms):%.0f\n",llbts_folder);
	fprintf(write_ll,"\nlinked list read and write all these numbers Time(ms):%.0f",llbts_folder);
	fclose(write_ll);
	
	/*I open the file for write for the dynamic array*/
	FILE *write_da;
	write_da=fopen("output_prime_dynamic_array.txt","w");
	double dabts=fpn_dyn_between_space(500000);/*it reads and print the screen until 500.000 by dynamic array*/
	double dabts2=fpn_dyn_between_space(750000);/*it reads and print the screen until 750.000 by dynamic array*/
	double dabts3=fpn_dyn_between_space(999979);/*it reads and print the screen until 1.000.000 by dynamic array*/
	double dabts_folder=fpn_dyn(write_da);/*it reads and print the screen and the folder for all these numbers by the dynamic array*/
	/*All of these are prints or fprints the times*/
	printf("\ndynamic array 500.000 Time(ms):%.0f\n",dabts);
	fprintf(write_da,"\ndynamic array 500.000 Time(ms):%.0f",dabts);
	printf("\ndynamic array 750.000 Time(ms):%.0f\n",dabts2);
	fprintf(write_da,"\ndynamic array 750.000 Time(ms):%.0f",dabts2);
	printf("\ndynamic array 1.000.000 Time(ms):%.0f\n",dabts3);
	fprintf(write_da,"\ndynamic array 1.000.000 Time(ms):%.0f",dabts3);
	printf("\ndynamic array read and write all these numbers Time(ms):%.0f\n",dabts_folder);
	fprintf(write_da,"\ndynamic array read and write all these numbers Time(ms):%.0f",dabts_folder);
	fclose(write_da);
}