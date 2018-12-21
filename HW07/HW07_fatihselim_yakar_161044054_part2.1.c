#include<stdio.h>

int leap_year(int year){/*for the terminate leap year*/
	if(year%100==0){
		if(year%400==0){
			return 1;
		}
	}
	else if(year%4==0){
		return 1;
	}
	return 0;
	
}


void print31(int day1,int month,int year){/*for the printf of 31 days*/
	FILE *days;
	days=fopen("input_date.txt","a");
	int day;
	for(day=day1;day<=31;day++){
		if(day<10&&month<10){
			fprintf(days,"0%d/0%d/%d\n",day,month,year);
			printf("0%d/0%d/%d\n",day,month,year);
		}
		else if(day<10&&month>=10){
			fprintf(days,"0%d/%d/%d\n",day,month,year);
			printf("0%d/%d/%d\n",day,month,year);
		}
		else if(day>=10&&month<10){
			fprintf(days,"%d/0%d/%d\n",day,month,year);
			printf("%d/0%d/%d\n",day,month,year);
		}
		else{
			fprintf(days,"%d/%d/%d\n",day,month,year);
			printf("%d/%d/%d\n",day,month,year);
		}
	}
	fclose(days);
}

void print30(int day1,int month,int year){/*for the printf of 30 days*/
	FILE *days;
	days=fopen("input_date.txt","a");
	int day;
	for(day=day1;day<=30;day++){
		if(day<10&&month<10){
			fprintf(days,"0%d/0%d/%d\n",day,month,year);
			printf("0%d/0%d/%d\n",day,month,year);
		}
		else if(day<10&&month>=10){
			fprintf(days,"0%d/%d/%d\n",day,month,year);
			printf("0%d/%d/%d\n",day,month,year);
		}
		else if(day>=10&&month<10){
			fprintf(days,"%d/0%d/%d\n",day,month,year);
			printf("%d/0%d/%d\n",day,month,year);
		}
		else{
			fprintf(days,"%d/%d/%d\n",day,month,year);
			printf("%d/%d/%d\n",day,month,year);
		}
	}
	fclose(days);
}

void print29(int day1,int month,int year){/*for the printf of 29 days*/
	FILE *days;
	days=fopen("input_date.txt","a");
	int day;
	for(day=day1;day<=29;day++){
		if(day<10&&month<10){
			fprintf(days,"0%d/0%d/%d\n",day,month,year);
			printf("0%d/0%d/%d\n",day,month,year);
		}
		else if(day<10&&month>=10){
			fprintf(days,"0%d/%d/%d\n",day,month,year);
			printf("0%d/%d/%d\n",day,month,year);
		}
		else if(day>=10&&month<10){
			fprintf(days,"%d/0%d/%d\n",day,month,year);
			printf("%d/0%d/%d\n",day,month,year);
		}
		else{
			fprintf(days,"%d/%d/%d\n",day,month,year);
			printf("%d/%d/%d\n",day,month,year);
		}
	}
	fclose(days);
}

void print28(int day1,int month,int year){/*for the printf of 28 days*/
	FILE *days;
	days=fopen("input_date.txt","a");
	int day;
	for(day=day1;day<=28;day++){
		if(day<10&&month<10){
			fprintf(days,"0%d/0%d/%d\n",day,month,year);
			printf("0%d/0%d/%d\n",day,month,year);
		}
		else if(day<10&&month>=10){
			fprintf(days,"0%d/%d/%d\n",day,month,year);
			printf("0%d/%d/%d\n",day,month,year);
		}
		else if(day>=10&&month<10){
			fprintf(days,"%d/0%d/%d\n",day,month,year);
			printf("%d/0%d/%d\n",day,month,year);
		}
		else{
			fprintf(days,"%d/%d/%d\n",day,month,year);
			printf("%d/%d/%d\n",day,month,year);
		}
	}
	fclose(days);
}

int print_between_dates(int dayS,int monthS,int yearS,int dayE,int monthE,int yearE){/*for the print all of between dates*/
	FILE *days;
	days=fopen("input_date.txt","a");
	int year,month,day,mem=0;
	year=yearS;
	while(year<=yearE){
		if(yearS==yearE){
			month=monthS;
			while(month<=12){
				if(month!=monthE&&mem!=1){
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){/*for the 31 days printing*/
						if(month==monthS){
							print31(dayS,month,year);
						}
						else{	
							print31(1,month,year);
						}
					}
					else if(month==2){/*for the february printing*/
						if(leap_year(year)==1){
							if(month==monthS){
								print29(dayS,month,year);
							}
							else{
								print29(1,month,year);
							}
						}
						else{
							if(month==monthS){
								print28(dayS,month,year);
							}
							else{
								print28(1,month,year);
							}
						}	
					}
					else if(month==4||month==6||month==9||month==11){/*for the 30 days printing*/
						if(month==monthS){
							print30(dayS,month,year);
						}
						else{	
							print30(1,month,year);
						}
					}
				}
				else if(month==monthE&&monthS!=monthE){/*for the break the loop*/
					for(day=1;day<=dayE;day++){
						if(day<10&&month<10){
							fprintf(days,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(days,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(days,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(days,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
						mem=1;
					}
				}
				else if(month==monthE&&monthS==monthE){/*for the break the loop*/
					for(day=dayS;day<=dayE;day++){
						if(day<10&&month<10){
							fprintf(days,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(days,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(days,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(days,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
						mem=1;
					}
				}
				month++;
			}
		}
		else if(year==yearE&&yearS!=yearE){/*for the start year not equal to end year*/
			month=1;
			while(month<=12){
				if(month!=monthE && mem!=1){/*month isnt the end month issue*/
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
						print31(1,month,year);
					}
					else if(month==2){
						if(leap_year(year)==1){
							print29(1,month,year);
						}
						else{
							print28(1,month,year);
						}
					}
					else if(month==4||month==6||month==9||month==11){
						print30(1,month,year);
					}
				}
				else if(month==monthE){/*if the month is end mounth*/
					for(day=1;day<=dayE;day++){
						if(day<10&&month<10){
							fprintf(days,"0%d/0%d/%d\n",day,month,year);
							printf("0%d/0%d/%d\n",day,month,year);
						}
						else if(day<10&&month>=10){
							fprintf(days,"0%d/%d/%d\n",day,month,year);
							printf("0%d/%d/%d\n",day,month,year);
						}
						else if(day>=10&&month<10){
							fprintf(days,"%d/0%d/%d\n",day,month,year);
							printf("%d/0%d/%d\n",day,month,year);
						}
						else{
							fprintf(days,"%d/%d/%d\n",day,month,year);
							printf("%d/%d/%d\n",day,month,year);
						}
						mem=1;
					}
				}
				month++;
			}
		}
		else if(year<yearE&&year!=yearS&&year!=yearE){/*year isnt start year,lower and isnt equal to end year */
			month=1;
			while(month<=12){
				if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
					print31(1,month,year);
				}
				else if(month==2){
					if(leap_year(year)==1){
						print29(1,month,year);
					}
					else{
						print28(1,month,year);
					}
				}
				else if(month==4||month==6||month==9||month==11){	
					print30(1,month,year);
				}
				month++;
			}
		}
		else if(year<yearE&&year==yearS){/*year is lower to end year and equal to start year*/
			month=monthS;
			while(month<=12){
				if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
					if(month==monthS){
						print31(dayS,month,year);
					}
					else{	
						print31(1,month,year);
					}
				}
				else if(month==2){
					if(leap_year(year)==1){
						if(month==monthS){
							print29(dayS,month,year);
						}
						else{
							print29(1,month,year);
						}
					}
					else{
						if(month==monthS){
							print28(dayS,month,year);
						}
						else{
							print28(1,month,year);
						}
					}	
				}
				else if(month==4||month==6||month==9||month==11){
					if(month==monthS){
						print30(dayS,month,year);
					}
					else{	
						print30(1,month,year);
					}
				}
				month++;
			}
		}
		year++;
	}
	return 0;
}


int main(){/*for the user taking values*/
	int i;
	int dayS,dayE,monthS,monthE,yearS,yearE;
	char trash_hold;
	printf("Please enter the start day formatted by dd/MM/yyyy:");
	scanf("%d%c%d%c%d",&dayS,&trash_hold,&monthS,&trash_hold,&yearS);
	printf("Please enter the end day formatted by dd/MM/yyyy:");
	scanf("%d%c%d%c%d",&dayE,&trash_hold,&monthE,&trash_hold,&yearE);
	print_between_dates(dayS,monthS,yearS,dayE,monthE,yearE);
	
}