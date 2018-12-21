#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer{/*I declare the struct "customer" for the customer's linked list*/
	int c_r_no;
	char name[20];
	char surname[20];
	char age[5];
	char gen[10];
	struct customer *next;
}customer;

typedef struct rooms{/*I declare the struct "rooms" for the room's linked list*/
	int r_no;
	int floor;
	int cap;
	struct rooms *next;
	struct customer *next_c;
	
}rooms;

rooms *cons_room_list(){/*I read the rooms.txt and then I generate the room's linked list*/
	FILE *ROOM;
	ROOM=fopen("rooms.txt","rt");
	rooms *head;
	head=(rooms*)malloc(sizeof(rooms));/*I allocate memory for the room's head*/
	rooms *temp;/*I generate the temp for the processes*/
	temp=head;
	while(!feof(ROOM)){/*generating linked list*/
		temp->next=malloc(sizeof(rooms));
		temp=temp->next;
		fscanf(ROOM,"%d,%d,%d",&temp->r_no,&temp->cap,&temp->floor);/*I read and save*/
		temp->next=NULL;
		temp->next_c=NULL;
		
	}
	fclose(ROOM);
	return head;
}

customer *cons_cust_list(){/*I read the customers.txt and then I generate the customer's linked list*/
	FILE *cust;
	customer *temp,*head;
	head=(customer*)malloc(sizeof(customer));
	temp=head;
	char infoLine[100];/*for the 1 row's read need this array*/
	cust=fopen("customers.txt","rt");
	int i = 0;/*it is counter*/
	while (!feof(cust)) {
		temp->next=(customer*)malloc(sizeof(customer));/*I allocate memory with malloc for each loop's customers*/
		temp=temp->next;
		fgets(infoLine, 100, cust);/*I get the 1 row*/
		char *p;
		for (p = strtok(infoLine, ","); p != NULL; p = strtok(NULL, ","), ++i) {/*I seperate the file's readings for the saving*/
			if(i%4==0){/*if mod is 0 it is the customer's room number*/
				temp->c_r_no=((p[0]-48)*100)+((p[1]-48)*10)+(p[2]-48);/*for the convert string to integer*/
			}
			if(i%4==1){/*if mod is 1 it is the customer's name*/
				sprintf(temp->name,"%s",p);
			}
			if(i%4==2){/*if mod is 2 it is the customer's age*/
				sprintf(temp->age,"%s",p);
			}
			if(i%4==3){/*if mod is 3 it is the customer's gen*/
				if(p[0]=='F'){/* for the it dont get the \n(last character)*/
					strncpy(temp->gen,p,6);/*if first letter is F the gen is Female so the program should get six letter */
				}
				else if(p[0]=='M'){
					strncpy(temp->gen,p,4);/*if first letter is M the gen is male so the program should get for letter */
				}
			}
		}	
		p = NULL;
		temp->next=NULL;
	}
	fclose(cust);
	
	return head;
	
}

rooms *link_to_room(rooms *head1,customer *head2){/*in this function I put together room and customer's linked list*/
	rooms *temp1;
	customer *temp2;
	customer *cust_temp;
	temp1=head1;
	temp2=head2;
	while(temp1->next!=NULL){/*For the walk around the room list*/
		temp1=temp1->next;
		temp2=head2;
		while(temp2->next!=NULL){/*For the walk around the customer list*/
			temp2=temp2->next;
			if(temp1->r_no==temp2->c_r_no&&temp1->next_c==NULL){/*If the room is empty*/
				temp1->next_c=(customer*)malloc(sizeof(customer));
				cust_temp=temp1->next_c;
				sprintf(cust_temp->name,"%s",temp2->name);
				sprintf(cust_temp->age,"%s",temp2->age);
				sprintf(cust_temp->gen,"%s",temp2->gen);
				cust_temp->c_r_no=temp2->c_r_no;
				cust_temp->next=NULL;
			}
			else if(temp1->r_no==temp2->c_r_no&&temp1->next_c!=NULL){/*If the room isnt empty*/
				cust_temp=temp1->next_c;
				while(cust_temp->next!=NULL){
					cust_temp=cust_temp->next;
				}
				cust_temp->next=(customer*)malloc(sizeof(customer));
				cust_temp=cust_temp->next;
				sprintf(cust_temp->name,"%s",temp2->name);
				sprintf(cust_temp->age,"%s",temp2->age);
				sprintf(cust_temp->gen,"%s",temp2->gen);
				cust_temp->c_r_no=temp2->c_r_no;
				cust_temp->next=NULL;
			}
		}
	}
	
	return head1;
}

void add_room_to_end(rooms *head,int r_no,int cap,int floor){/*in this function I add the room in room list */
	rooms *temp;
	temp=head;
	while(temp->next!=NULL){/*I come to last element of list*/
		temp=temp->next;
	}
	
	temp->next=(rooms *)malloc(sizeof(rooms));/*I allocate and I add*/
	temp=temp->next;
	temp->r_no=r_no;
	temp->floor=floor;
	temp->cap=cap;
	temp->next=NULL;
	
}

void add_room_after_room_number(rooms *head,int input_r_no,int r_no,int cap,int floor){/*in this function I add the number from after the input number*/
	rooms *temp,*temp2,*temp3;
	int ct=0;
	temp3=head;
	while(temp3->next!=NULL){/*I have found the number of same number*/
		temp3=temp3->next;
		if(temp3->r_no==input_r_no){
			ct++;
		}
	}
	if(ct==0){/*If there is no match, I added it to the end.*/
		add_room_to_end(head,r_no,floor,cap);
	}
	else{/*If there is match, I added it to the after input room number.*/
		temp=head;
		while(temp->next->r_no!=input_r_no){
			temp=temp->next;
		}
		temp2=temp->next->next;
		temp->next->next=(rooms *)malloc(sizeof(rooms));
		temp=temp->next->next;

		temp->r_no=r_no;
		temp->floor=floor;
		temp->cap=cap;

		temp->next=temp2;
	}
}

void add_customer_to_end(customer *head,int c_r_no,char name[],char age[],char gen[]){/*in this function I add the customer in general customer list */
	customer *temp;
	temp=head;
	while(temp->next!=NULL){/*I come to last element of list*/
		temp=temp->next;
	}
	
	temp->next=(customer *)malloc(sizeof(customer));/*I allocate and I add*/
	temp=temp->next;
	temp->c_r_no=c_r_no;
	sprintf(temp->name,"%s",name);
	sprintf(temp->age,"%s",age);
	sprintf(temp->gen,"%s",gen);
	temp->next=NULL;
	
}

rooms *link_customers_to_room(rooms *head,int r_no,char name[],char age[],char gen[]){/*In this function I add the customer in partial customer list*/
	rooms *temp;
	temp=head;
	customer *temp_add;
	int counter=2;
	while(temp->next!=NULL){/*this loop for the rooms*/
		temp=temp->next;
		if(temp->r_no==r_no&&temp->next_c!=NULL){/*If there are many elements in list*/
			temp_add=temp->next_c;
			while(temp_add->next!=NULL){/*It come last element of the list*/
				counter++;
				temp_add=temp_add->next;
			}
			if(counter>temp->cap){/*If abort the capacity*/
				printf("\n***You dont do this***\n");
			}
			else{/*allocate and add*/
				temp_add->next=(customer*)malloc(sizeof(customer));
				temp_add=temp_add->next;
				sprintf(temp_add->name,"%s",name);
				sprintf(temp_add->age,"%s",age);
				sprintf(temp_add->gen,"%s",gen);
				temp_add->c_r_no=r_no;
				temp_add->next=NULL;
			}	
		}
		else if(temp->r_no==r_no&&temp->next_c==NULL){/*If there isnt elements in list*/
			temp->next_c=(customer*)malloc(sizeof(customer));/*allocate and add*/
			temp_add=temp->next_c;
			sprintf(temp_add->name,"%s",name);
			sprintf(temp_add->age,"%s",age);
			sprintf(temp_add->gen,"%s",gen);
			temp_add->c_r_no=r_no;
			temp_add->next=NULL;
		}
		
	}
	return head;
}

void remove_room(rooms *head,int r_no){/*In this function I remove the same room number's room*/
	rooms *temp;
	temp=head;
	while(temp->next->r_no!=r_no){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=temp->next->next;
}

void show_vacancy(rooms *head){/*This function provides us prints empty room*/
	rooms *temp;
	temp=head;
	printf("Epty rooms:\n");
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->next_c==NULL){/*If there isnt customer in the room I print it*/
			printf("%d\n",temp->r_no);
		}
	}
	
}

void get_by_floor(rooms *head,int floor){/*In this function I print the same floor's room numbers*/
	rooms *temp;
	temp=head;
	printf("Floor %d's rooms:\n",floor);
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->floor==floor){/*If floors are same then I print it*/
			printf("%d\n",temp->r_no);
		}
	}
}

void print_list(rooms*head){/*This function prints the all list*/
	rooms *temp;
	temp=head;
	customer *temp_custom;
	while(temp->next!=NULL){/*walkaround the rooms list*/
		temp=temp->next;
		printf("Room %d(Floor %d-capacity %dx):\n",temp->r_no,temp->floor,temp->cap);
		temp_custom=temp->next_c;
		if(temp->next_c!=NULL){/*If the room isnt empty*/
			while(temp_custom!=NULL){/*walkaround the partial customer list*/
				
				printf("->%s(%s-%s)\n",temp_custom->name,temp_custom->age,temp_custom->gen);
				temp_custom=temp_custom->next;

			}
		}
		else{/*If the room is empty*/
			printf("->Empy\n");
		}
		printf("\n");
	}
	
}

//ADDITIONAL FUNCTION
void print_room(rooms *head){/*In this function I print the room list*/
	rooms *temp;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		printf("%d %d %d\n",temp->r_no,temp->cap,temp->floor);
	}
}

//ADDITIONAL FUNCTION
void print_customer(customer *head){/*In this function I print the customer list*/
	customer *temp;
	temp=head;
	while(temp->next !=NULL){
		temp=temp->next;
		printf("%d %s %s %s\n",temp->c_r_no,temp->name,temp->age,temp->gen);
	}
	printf("\n");
}

int main(){
	rooms *head;
	customer *head2;
	
	head=cons_room_list();
	head2=cons_cust_list();
	head=link_to_room(head,head2);
	
	/*add_room_after_room_number(head,404,999,2,5);
	add_room_to_end(head,888,3,2);
	remove_room(head,888);
	//print_room(head); THIS IS THE ADDITIONAL FUNCTION THAT PRINTS ROOM LIST
	add_customer_to_end(head2,999,"George Orwell","60","Male");
	//print_customer(head2); THIS IS THE ADDITIONAL FUNCTION THAT PRINTS CUSTOMER LIST
	printf("\n");
	get_by_floor(head,4);
	head=link_customers_to_room(head,999,"Fatih Selim Yakar","19","Male");
	printf("\n");
	show_vacancy(head);
	printf("\n");*/
	
	print_list(head);
	
	/*FREEİNG*/
	customer *free_head;
	while(head->next!=NULL){/*I free the room's list*/
		free(head);
		head=head->next;
	}
	
	while(head2->next!=NULL){/*I free the customer's list*/
		free(head2);
		head2=head2->next;
	}
	
	return 0;
}