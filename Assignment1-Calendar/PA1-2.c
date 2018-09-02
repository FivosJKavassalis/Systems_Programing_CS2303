 /*

	PA1.c -- Fivos Kavassalis / fikavassalis

 */

 #include <stdio.h>
 int dayOfWeek; // day of a week is stored here (days of the week as a numeric value: Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday= 6) 
 int year = 2018; // the starting year. Will be used in firstDayOfYear().
 int givenYear; // the input year of the user. 
 

 // Function Prototypes: 
 int isLeap(int yr);
 void userInput(void);
 int firstDayOfYear(void);
 void printCalendar(int yr, int startingDay);
 int printMonth(int yearNum, int monthNum, int firstDayMonth);
 int printMonthName(int yearNum, int monthNum);
 

 /**
   The main() function is the main core of the program. The program begins from the main().
   It prints out a 12-month calendar based on the input year from the user. All functions used will be specified in this file.
   This function does not take in any parameters.
   @return 0 
 */
 int main(void) {

	userInput();
	dayOfWeek = firstDayOfYear();
  	printCalendar(givenYear, dayOfWeek);
	return 0; 
 } // int main(void)


 /**
    Tests whether a year is a leap year.
    @param yr year, should be an integer greater than 0
    @return 1 (true) or 0 (false) , which indicates whether yr is a leap year.
 */
 int isLeap(int yr) {
	if((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0) // tests whether yr is a leap year
		return 1; // true
	else
		return 0; // false
 } // int isLeap(int yr)
  

 /**
    The function userInput() prints out a monthly calendar label, asks the user for the calendar's year, 
    and prints a calendar label with the input year. It does not take in any parameters, nor does it return anything.
 */
 void userInput(void) {
 	printf("MONTHLY CALENDAR\n");
	printf("Please enter the year for this calendar:- "); 
	scanf("%d", &givenYear);
	
	while(givenYear <= 0) { // while loop prints out error message and requests an integer (year) greater than 0.
		printf("Error! Please enter a valid year (year > 0):- "); // LOOP INVARIANT: (givenYear <= 0)
		scanf("%d", &givenYear);	
	}	
	
	printf("*** CALENDAR for %d ***\n", givenYear);
 
 } // void userInput(void)


 /**
    This function finds the first day of the input year. It does not take in any parameters 
    @return dayOfWeek, which in this case is the first day of the year
 */
 int firstDayOfYear(void) {

	int dayOfWeek = 1; // will store first day of the input year. Initial value is reference to a known year in which the day of the week of a particular date is known (Date: 1/1/2018) 
                       
	while (givenYear < year) { // while loop finds the first day of the given year if it is a smaller integer compared to the reference year
		
		dayOfWeek -= 1 + isLeap(--year); 
		dayOfWeek = (dayOfWeek + 7) % 7; // LOOP INVARIANTS: ( 0 <= dayOfWeek <= 6), (givenYear < year)
	}

	while (givenYear > year) { // while loop finds the first day of the given year if it is a greater integer compared to the reference year
		
		dayOfWeek += 1 + isLeap(year++); 
		dayOfWeek = (dayOfWeek + 7) % 7; // LOOP INVARIANTS: ( 0 <= dayOfWeek <= 6), (givenYear > year)
	}

	return dayOfWeek;

 } // int firstDayOfYear(void)


 /**
    Prints the 12 months (and their days) of the year's calendar in a calendar format.
    @param yr, which should be an integer value greaten than 0
    @param startingDay, which should be an integer value between (including) 0 and 6
    It does not return anything.
 */
 void printCalendar(int yr, int startingDay) {
	
	for(int i=1; i<=12; i++) { // in the for loop, a month is printed in calendar format and the first day of the next month is assigned each time
		
		startingDay = printMonth(yr, i, startingDay); // LOOP INVARIANTS: (startingDay = ((printMonthName(yearNum, monthNum) + startingDay) % 7)), (1<= i <= 12)
	}	

 } // void printCalendar(int yr, int startingDay)


 /**
    This function prints out a month of a specified year in a calendar format. 
    @param yearNum, is an integer value that is the calendar's year
    @param monthNum, is an integer value that represents the month number
    @param firstDayMonth, is an integer value of the first day of the month
    @return firstDayMonth, which is the integer value of the first day of the next month
 */	
 int printMonth(int yearNum, int monthNum, int firstDayMonth) {

	int numDays = printMonthName(yearNum, monthNum); // stores number of days of a month
	
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	
	for(int j=0; j<firstDayMonth; j++) { // loop prints 3 blank spaces (firstDayMonth) times. If j is not Sunday (0), it prints one extra blank space
		
                printf("   "); // LOOP INVARIANTS: (0 <= j < firstDayMonth)    
		if(j)          // tests if j is not Sunday 
		  printf(" "); // true
	}
	
	

	for(int k=1; k<=numDays; k++){ // loop puts a number of the month under the corresponding day, each time.
	
		if(firstDayMonth) // tests whether firstDayMonth is not Sunday
		  printf(" ");    // to start from just under first letter -- if true	

		printf("%3d", k);
		
		firstDayMonth++;      // LOOP INVARIANT: (1 <= k <= numDays)

		if(firstDayMonth == 7) { // tests whether firstDayMonth is one day after Saturday
			printf("\n");
			firstDayMonth = 0; // true
		}

	}
	
	printf("\n");
	printf("\n");

	return firstDayMonth;
	
 } // int printMonth(int yearNum, monthNum, firstDayMonth)


 /**
    This function prints out the name of the given month and the given year and stores the number of days of this month
    @param yearNum, which is the integer number of a year
    @param monthNum, which is the integer number of a month
    @return days, which is an integer value indicating number of days of month 
 */
 int printMonthName(int yearNum, int monthNum) {
	int days; // stores number of days of a month

	switch(monthNum) { // executes case corresponding to the number of the month
		
		case 1:
			printf("January %d\n\n", yearNum);
			days = 31;
			break;
		case 2:
			printf("February %d\n\n", yearNum);
			days = isLeap(yearNum) ? 29 : 28;
			break;
		case 3:
			printf("March %d\n\n", yearNum);
			days = 31;
			break;
		case 4:
			printf("April %d\n\n", yearNum);
			days = 30;
			break;
		case 5:
			printf("May %d\n\n", yearNum);
			days = 31;
			break;
		case 6:
			printf("June %d\n\n", yearNum);
			days = 30;
			break;
		case 7:
			printf("July %d\n\n", yearNum);
			days = 31;
			break;
		case 8:
			printf("August %d\n\n", yearNum);
			days = 31;
			break;
		case 9:
			printf("September %d\n\n", yearNum);
			days = 30;
			break;
		case 10:
			printf("October %d\n\n", yearNum);
			days = 31;
			break;
		case 11:
			printf("November %d\n\n", yearNum);
			days = 30;
			break;
		case 12:
			printf("December %d\n\n", yearNum);
			days = 31;
			break;
		
	} 

	return days;
 } // int printMonthName(int yearNum, int monthNum)
 
 

