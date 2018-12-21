#include<stdio.h>

typedef enum{sunday,monday,tuesday,wednesday,thursday,friday,saturday}/*I assign the days*/
day_list;

int leap_year(int year){/*I calculate the leap year*/
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


void convert_days(int dayS,int monthS,int yearS){/*this function provides converting days*/
	FILE *days;
	days=fopen("new_date.txt","a");
	int i,ct,j;
	int start_year=1970,total_day,monthS_day=0;/*I choose the 1970 becase time c timer starting 1 jan 1970*/
	day_list start_years_date=thursday,day;
	
	for(i=1970;i<yearS;i++){/*leap year calculation for calculate the days*/
		ct=leap_year(i)+ct;
	}
	
	if(monthS==1){/*at the last year's days calculation*/
		monthS_day=(dayS-1);
	}
	else if(monthS==2){
		monthS_day=31+(dayS-1);
	}
	else if(monthS==3){
		if(leap_year(yearS)==1){
			monthS_day=60+(dayS-1);	
		}
		else{
			monthS_day=59+(dayS-1);
		}
		
	}
	else if(monthS==4){
		if(leap_year(yearS)==1){
			monthS_day=91+(dayS-1);	
		}
		else{
			monthS_day=90+(dayS-1);
		}
	}
	else if(monthS==5){
		if(leap_year(yearS)==1){
			monthS_day=121+(dayS-1);	
		}
		else{
			monthS_day=120+(dayS-1);
		}
	}
	else if(monthS==6){
		if(leap_year(yearS)==1){
			monthS_day=152+(dayS-1);	
		}
		else{
			monthS_day=151+(dayS-1);
		}
	}
	else if(monthS==7){
		if(leap_year(yearS)==1){
			monthS_day=182+(dayS-1);	
		}
		else{
			monthS_day=181+(dayS-1);
		}
	}
	else if(monthS==8){
		if(leap_year(yearS)==1){
			monthS_day=213+(dayS-1);	
		}
		else{
			monthS_day=212+(dayS-1);
		}
	}
	else if(monthS==9){
		if(leap_year(yearS)==1){
			monthS_day=244+(dayS-1);	
		}
		else{
			monthS_day=243+(dayS-1);
		}
	}
	else if(monthS==10){
		if(leap_year(yearS)==1){
			monthS_day=274+(dayS-1);	
		}
		else{
			monthS_day=273+(dayS-1);
		}
	}
	else if(monthS==11){
		if(leap_year(yearS)==1){
			monthS_day=305+(dayS-1);	
		}
		else{
			monthS_day=304+(dayS-1);
		}
	}
	else if(monthS==12){
		if(leap_year(yearS)==1){
			monthS_day=335+(dayS-1);	
		}
		else{
			monthS_day=334+(dayS-1);
		}
	}
	total_day=(366*ct)+(((yearS-1970)-ct)*365)+monthS_day;/*and the total day*/
	day=(start_years_date+total_day%7)%7;/*I get the mod and add the first thursday*/
	
	
	if(day==sunday){/*and the last print the statements*/
		if(monthS==1){
			printf("Sunday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Sunday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Sunday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Sunday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Sunday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Sunday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Sunday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Sunday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Sunday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Sunday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Sunday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Sunday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Sunday,December %d,%d\n",dayS,yearS);
		}
	}
	else if(day==monday){
		if(monthS==1){
			printf("Monday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Monday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Monday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Monday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Monday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Monday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Monday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Monday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Monday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Monday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Monday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Monday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Monday,December %d,%d\n",dayS,yearS);
		}
	}
	else if(day==tuesday){
		if(monthS==1){
			printf("Tuesday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Tuesday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Tuesday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Tuesday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Tuesday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Tuesday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Tuesday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Tuesday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Tuesday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Tuesday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Tuesday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Tuesday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Tuesday,December %d,%d\n",dayS,yearS);
		}
	}
	else if(day==wednesday){
		if(monthS==1){
			printf("Wednesday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Wednesday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Wednesday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Wednesday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Wednesday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Wednesday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Wednesday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Wednesday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Wednesday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Wednesday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Wednesday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Wednesday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Wednesday,December %d,%d\n",dayS,yearS);
		}
	}
	else if(day==thursday){
		if(monthS==1){
			printf("Thursday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Thursday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Thursday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Thursday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Thursday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Thursday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Thursday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Thursday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Thursday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Thursday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Thursday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Thursday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Thursday,December %d,%d\n",dayS,yearS);
		}
	}
	else if(day==friday){
		if(monthS==1){
			printf("Friday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Friday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Friday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Friday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Friday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Friday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Friday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Friday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Friday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Friday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Friday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Friday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Friday,December %d,%d\n",dayS,yearS);
		}
	}
	else if(day==saturday){
		if(monthS==1){
			printf("Saturday,January %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,January %d,%d\n",dayS,yearS);
		}
		else if(monthS==2){
			printf("Saturday,February %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,February %d,%d\n",dayS,yearS);
		}
		else if(monthS==3){
			printf("Saturday,March %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,March %d,%d\n",dayS,yearS);
		}
		else if(monthS==4){
			printf("Saturday,April %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,April %d,%d\n",dayS,yearS);
		}
		else if(monthS==5){
			printf("Saturday,May %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,May %d,%d\n",dayS,yearS);
		}
		else if(monthS==6){
			printf("Saturday,June %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,June %d,%d\n",dayS,yearS);
		}
		else if(monthS==7){
			printf("Saturday,July %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,July %d,%d\n",dayS,yearS);
		}
		else if(monthS==8){
			printf("Saturday,August %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,August %d,%d\n",dayS,yearS);
		}
		else if(monthS==9){
			printf("Saturday,September %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,September %d,%d\n",dayS,yearS);
		}
		else if(monthS==10){
			printf("Saturday,October %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,October %d,%d\n",dayS,yearS);
		}
		else if(monthS==11){
			printf("Saturday,November %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,November %d,%d\n",dayS,yearS);
		}
		else if(monthS==12){
			printf("Saturday,December %d,%d\n",dayS,yearS);
			fprintf(days,"Saturday,December %d,%d\n",dayS,yearS);
		}
	}
	fclose(days);
	
}

void print_convert_dates(){/*I read the txt and fprint the new_date.txt*/
	FILE *input;
	input=fopen("input_date.txt","rt");
	char str[20];
	int arr[20],i,in_day,in_month,in_year;
	while(!feof(input)){
		fgets(str,100,input);
		for(i=0;str[i]!='\n';i++){
			if(str[i]!='/'){	
				arr[i]=str[i]-48;
			}
		}
		in_day=arr[0]*10+arr[1]*1;
		in_month=arr[3]*10+arr[4]*1;
		in_year=arr[6]*1000+arr[7]*100+arr[8]*10+arr[9]*1;

		convert_days(in_day,in_month,in_year);
		
	}
	fclose(input);
	
	
	
			
}

int main(){
	print_convert_dates();
}