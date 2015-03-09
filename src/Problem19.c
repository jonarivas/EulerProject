/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #19
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct date{
	int day;
	int month;
	int year;
	int dayofweek;
};

enum months{
	january = 0,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december,
	totalmonths
};

enum DAY
{
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    totaldays
};

int isLeapYear(int year){
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
void nextDay(struct date *current){
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	months[february] += isLeapYear(current->year);
	current->day = (current->day+1) % months[current->month];
	if (current->day == 0){
		current->month = (current->month + 1) % totalmonths;
		if (current->month == 0){
			current->year++;
		}
	}
	current->dayofweek = (current->dayofweek + 1 )% totaldays;
}

int compareDays(struct date *date1, struct date *date2){
	if (date1->year == date2->year && date1->month == date2->month && date1->day == date2->day){
		return 1;
	}
	return 0;
}

void printDay(struct date *current){
	printf("current day is %d %d/%d/%d\n", current->dayofweek, current->day +1 , current->month + 1, current->year);
}

struct date * createDate(int dayofweek, int day, int month, int year){
	struct date *date;
	date =  (struct date *)malloc(sizeof(struct date));
	date->dayofweek = dayofweek;
	date->day = day - 1;
	date->month = month;
	date->year = year;
	return date;
}

int isFirstDayofMonth(struct date * day){
	if (day->day == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	struct date *day, *lastday, *startdate;
	int numberofSundays = 0;
	day = createDate(monday, 1, january, 1900);
	startdate = createDate(monday, 1, january, 1901);
	lastday = createDate(monday,31, december, 2000);

	while(!compareDays(day, startdate)){
		nextDay(day);
	}
	nextDay(lastday);
	while(!compareDays(day, lastday)){
		if (day->dayofweek == sunday && isFirstDayofMonth(day)){
			numberofSundays++;

		}
		nextDay(day);
	}
	printf("number of sundays: %d", numberofSundays);

	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
