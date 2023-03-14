#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

// ----------------------------------------------------------------
// Function Prototypes
void returnToMenu();
void custInfo();
void washcar();
void displayCustomers();
void mainmenu();
void report();
int exitprog();
// Customer Information
// Date Functions
void date(int index);
int dayp(int monthPast, int leap);
int monthp();
int yearp();
// Other Customer Info Functions
void license(int index);
void custName(int index);
void payType(int index);
void service(int index);
// ----------------------------------------------------------------

struct info 
{
  char date[1][7];
  char name[1][20];
  char licenseNum[1][6];
  char service[1][20];
  char payType[1][1];
};

int main() 
{
  system("cls");

  printf("\t\t\t\tWelcome to Trish and Shaun's Auto Wash Services System!\t\t\t\t\n");

  printf("\nPress any key to continue...");
  // Wait for user input

  getch();

  system("cls");
  
  // Call to Main Menu
  mainmenu();
}

FILE *infoFile;
// CUSTOMER INFORMATION (Semicomplete)
void custInfo() 
{
  system("cls");

  int i = 0;

  printf("\t\t\t\tCUSTOMER INFORMATION\t\t\t\t\t");

  printf("\n");

  for (i = 0; i < 1; i++) 
  {
    date(i);
    custName(i);
    license(i);
    service(i);
    payType(i);
  }
  returnToMenu();
}

void washcar() {}

void displayCustomers() {}

void report() {}

int exitprog() { exit(0); }

// MAIN MENU
void mainmenu() 
{
  system("cls");

  char choice[1];

  int option = 0;

  int repeated = 0;

  printf("\t\t\t\tSYSTEM FUNCTIONALITIES\t\t\t\t\n");

  printf("\n1.Accept Customer's Information\n2.Wash Car\n3.Display Returning "
         "Customers\n4.Display Sales Report\n5.Exit Program\n");
  // Seletion of Customer Options Validation
  do 
  {
    printf("\nSelect an option: ");

    scanf(" %[^\n]s", choice);

    fflush(stdin);

    option = atoi(choice); // the function "atoi" converts a string to an integer

    switch (option) 
    {
        case 1:
            custInfo();
            break;
        case 2:
            washcar();
            break;
        case 3:
            displayCustomers();
            break;
        case 4:
            report();
            break;
        case 5:
            exitprog();
            break;
        default:
            printf("\nInvalid Entry! Valid options are 1-5.\nPlease try again.");
            repeated += 1;
            break;
    }
    // Clears the screen after 3 invalid entries
    if (repeated % 3 == 0) 
    {
      mainmenu();
    }
  } while (option < 1 || option > 5);
  // End of Customer Options Validation
}
// RETURN TO MAIN MENU
void returnToMenu() 
{
  char response;
  // Get response from user to exit the program
  do 
  {
    printf("\nWould you like to return to the main menu?(y/n): ");

    scanf(" %s", &response);

    fflush(stdin);

    // Checks if the response is valid
    if (response == 'y' || response == 'Y') 
    {
      system("cls");

      mainmenu();
    } 

    else if (response == 'n' || response == 'N') 
    {
      break;
    } 

    else 
    {
      printf("Invalid response. Please try again.\n");
    }
  } while (response != 'N' && response != 'n' && response != 'y' &&
           response != 'Y');
  // End of response validation
  exitprog();
}
// Year function
int yearp() 
{
  // Called by date function
  printf("\t\t\t\tDATE\t\t\t\t\t");
  
  int year = 0;
  // Accept and validate year
  while (1) 
  {
    printf("\nTransaction Year [yyyy]: ");

    scanf("%d", &year);

    fflush(stdin);

    if (year < 1800 || year > 9999) 
    {
      printf("\nNo records kept for this year!");
    } 

    else
    {
      break;
    }
  }
  // End of year validation then return
  return year;
}
// Month function
int monthp() 
{
  // Called by date function
  int month;
  // Accept and validate month
  while (1) 
  {
    printf("\nTransaction Month [mm]: ");

    scanf("\n%d", &month);

    fflush(stdin);

    if (month < 1 || month > 12) 
    {
      printf("\nInvalid entry try again! Months are from 1-12");
    } 

    else 
    {
      break;
    }
  }
  // End of month validation then return
  return month;
}
// Day function
int dayp(int monthPast, int leap) 
{
  int day = 0;

  int limit = 0;
  // Limiting the days of the month based on the monthPast and leap for leap
  // years
  switch (monthPast) 
  {
    // January
  case 1:
    limit = 31;

    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);
      
      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nJanuary has %d days\n ", limit);
      }

      else 
      {
        break;
      }
    }
    break;

    // February
  case 2:
    limit = 28;

    if (leap == 'y') 
    {
      limit = 29;
    }

    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nFebruary has %d days\n ", limit);
      } 

      else 
      {
        break;
      }
    }
    break;

    // March
  case 3:
    limit = 31;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);
      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nMarch has %d days\n ", limit);
      }

      else 
      {
        break;
      }
    }
    break;

    // April
  case 4:
    limit = 31;
    if (day < 1 || day > limit) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      printf("\nInvalid entry try again");

      printf("\nApril has %d days\n ", limit);
    }

    else 
    {
      break;
    }
    break;

    // May
  case 5:
    limit = 31;

    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nMay has %d days\n ", limit);
      } 

      else 
      {
        break;
      }
    }

    break;

    // June
  case 6:
    limit = 30;
    while (1)
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nJune has %d days\n ", limit);
      } 

      else 
      {
        break;
      }
    }
    break;

    // July
  case 7:
    limit = 31;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nJuly has %d days\n ", limit);

      } 

      else 
      {
        break;
      }
    }
    break;

    // August
  case 8:
    limit = 31;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nAugust has %d days\n ", limit);
      }

      else 
      {
        break;
      }
    }
    break;

    // September
  case 9:
    limit = 30;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nSeptember has %d days\n ", limit);

      } 
      else 
      {
        break;
      }
    }
    break;

    // October
  case 10:
    limit = 31;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nOctober has %d days\n ", limit);

      } 

      else 
      {
        break;
      }
    }
    break;

    // November
  case 11:
    limit = 30;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nNovember has %d days\n ", limit);
      } 

      else 
      {
        break;
      }
    }
    break;
    // December

  case 12:
    limit = 31;
    while (1) 
    {
      printf("\nTransaction Day [dd]: ");

      scanf("\n%d", &day);

      fflush(stdin);

      if (day < 1 || day > limit) 
      {
        printf("\nInvalid entry try again");

        printf("\nDecember has %d days\n ", limit);

      } 
      
      else 
      {
        break;
      }
    }
    break;
  }
  // End of switch statement
  return day;
}
// FULL DATE FUNCTION
void date(int index) 
{
  // Clears the screen
  system("cls");

  struct info cust;
  // Controlling values

  int monthPast = 0, i = index;

  char leap = 'n';
  // Function return values declaration

  int day, month, year;
  // Conversion variables

  int dateStore;

  char dateFormat[8];

  // CALLING FOR FULL DATE
  // Year
  year = yearp();
  // Leap year
  if (year % 4 == 0) 
  {
    leap = 'y';
  }
  // Month
  month = monthp();

  monthPast = month;
  // Day
  day = dayp(monthPast, leap);
  // Full Date Formating
  // Math for ordering the date

  dateStore = (day) + (month * 100) + (year * 10000);
  // Formatting the date; chaning the int to a string and putting it in order

  sprintf(dateFormat, "%.2d/%.2d/%4d", (dateStore % 100),
          (dateStore % 10000) / 100, (dateStore / 10000));
  // Opening the file

  infoFile = fopen("Customer Records.txt", "a+");
  // If the file fails to open, the program will exit

  if (infoFile == NULL)
  {
    printf("Error!");

    exit(1);
  }
  // Printing the date to the file
  fprintf(infoFile, "%s", dateFormat);

  // Copy the date to the struct array for later use
  sprintf(cust.date[i], "%s", dateFormat);

  // Close the file
  fclose(infoFile);
}
// LISCENSE INFORMATION
void license(int index) 
{
  system("cls");

  struct info cust;

  printf("\t\t\t\tCUSTOMER LICENSE\t\t\t\t\t");
  // Controlling values

  int i = index, repeated = 0;
  // License plate number

  char licenseNum[6];
  // License Validation
  do 
  {
    printf("\nEnter customer license plate number(4 digits and 2 uppercase "
           "letters): ");

    scanf(" %[^\n]s", licenseNum);

    fflush(stdin);
    
    if (strlen(licenseNum) != 6 || islower(licenseNum[4]) || islower(licenseNum[5]) || isalpha(licenseNum[0]) || isalpha(licenseNum[1]) || isalpha(licenseNum[2]) || isalpha(licenseNum[3]) || isdigit(licenseNum[4]) || isdigit(licenseNum[5])) 
    {
      printf("Invalid entry.\nLicense plate numbers must be 4 digits and 2 "
             "uppercase letters\n");
             
      repeated++;
    }

    else 
    {
      break;
    }
    // Clears the screen after 3 invalid entries
    if (repeated % 3 == 0) 
    {
      license(i);
    };
  } while (strlen(licenseNum) != 6 || islower(licenseNum[4]) || islower(licenseNum[5]) || isalpha(licenseNum[0]) || isalpha(licenseNum[1]) || isalpha(licenseNum[2]) || isalpha(licenseNum[3]) || isdigit(licenseNum[4]) || isdigit(licenseNum[5]));
  // End of License Validation
  // Open the file

  infoFile = fopen("Customer Records.txt", "a+");
  // If the file fails to open, exit the program

  if (infoFile == NULL) 
  {
    printf("Error!");

    exit(1);
  }
  // Add Record
  fprintf(infoFile, "\t%s", licenseNum);
  // Copy the license number to the struct array for later use

  sprintf(cust.licenseNum[i], "%s", licenseNum);
  // Close the file
  fclose(infoFile);
}
// CUSTOMER NAME
void custName(int index) 
{
  system("cls");

  printf("\t\t\t\tCUSTOMER NAME\t\t\t\t\t");

  struct info cust;
  // Controlling values

  int i = index, repeated = 0;
  // Others

  char namecpy1[i][50], namecpy2[i][50], nameRepeated[1][50], name[50];

  char *start1, *end1, *start2, *end2;
  // Name and Validation

  while (1) 
  {
    printf("\nEnter customer #%d's name: ", i + 1);

    scanf(" %[^\n]s", name);

    fflush(stdin);
    // adds a null character to the end of the string

    strncpy(namecpy1[i], name, 20);

    // Confirmation
    printf("Re-enter customer #%d name: ", i + 1);

    scanf(" %[^\n]", nameRepeated[i]);

    fflush(stdin);
    // adds a null character to the end of the string

    strncpy(namecpy2[i], nameRepeated[i], 50);
    // tokenizes the string

    strtok(namecpy1[i], " ");

    strtok(namecpy2[i], " ");
    // checks if the string has whitespace characters

    start1 = namecpy1[i];

    end1 = namecpy1[i] + strlen(namecpy1[i]) - 1;

    start2 = namecpy1[i];

    end2 = namecpy1[i] + strlen(namecpy2[i]) - 1;
    // Remove whitespaces at the end and at the beginning

    while (isspace(*start2)) 
    {
      start1++;
    }

    while (isspace(*end1)) 
    {
      end1--;
    }

    while (isspace(*start2)) 
    {
      start2++;
    }

    while (isspace(*end2)) 
    {
      end2--;
    }
    // Compares the strings
    if (strcmp(namecpy1[i], namecpy2[i]) != 0) 
    {
      printf("\nNames do not match.");
      repeated++;
    } 
    
    else 
    {
      break;
    }

    // Clears the screen after 3 invalid entries
    if (repeated % 3 == 0) 
    {
      custName(i);
    };
  }
  // Open the file
  infoFile = fopen("Customer Records.txt", "a+");
  // If the file fails to open, the program will terminate

  if (infoFile == NULL) 
  {
    printf("Error!");

    exit(1);
  }

  // Add Record
  fprintf(infoFile, "\t%s", name);

  // Copy the name to the struct array for later use
  sprintf(cust.name[i], "%s", name);

  // Close the file
  fclose(infoFile);
  // End of Name and Validation
}

// PAY TYPE SELECTION
void payType(int index) 
{
  system("cls");

  struct info cust;

  printf("\t\t\t\tPAY TYPE SELECTION\t\t\t\t\t");

  // Controlling values
  int choice = 0, i = index, repeated = 0;

  // Pay Type and text
  char paidType[1], paidTxt[20];

  do 
  {
    printf("\n1-Card Payment \n2-Cash Payment\nSelect customer #%d's payment method: ",i + 1);

    scanf(" %[^\n]s", paidType);

    fflush(stdin);

    // The keyword "atoi" converts a string to an integer
    // Note that if it is an array of numbers then choice =
    // atoi(&cust.payType[i]); the & is needed
    choice = atoi(paidType);

    // Checks if the input is valid
    if (choice < 1 || choice > 2) 
    {
      printf("Invalid Entry. Please enter 1 or 2.\n");

      repeated++;
    } 

    else 
    {
      break;
    }

    // Clears the screen after 3 invalid entries
    if (repeated % 3 == 0) 
    {
      payType(i);
    };
  } while (choice < 1 || choice > 2);
  // End of pay type validation
  // Switch statement to select the pay type
  switch (choice) 
  {
  case 1:
    strcpy(paidTxt, "Card Payment");
    break;
  case 2:
    strcpy(paidTxt, "Cash payment");
    break;
  default:
    // Should be unreachable
    printf("Invalid Entry. Please enter 1 or 2.\n");
    break;
  }

  // End of pay type selection
  // Open the file
  infoFile = fopen("Customer Records.txt", "a+");

  // If the file fails to open, the program will terminate
  if (infoFile == NULL) 
  {
    printf("Error!");

    exit(1);
  }

  // Add Record
  fprintf(infoFile, "\t%s\n", paidTxt);
  // Copy the pay type to the struct array for later use

  sprintf(cust.payType[i], "%s", paidTxt);

  // Close the file
  fclose(infoFile);
}
// SERVICE SELECTION
void service(int index) 
{
  system("cls");

  printf("\t\t\t\tSERVICE SELECTION\t\t\t\t\t");

  struct info cust;

  // Controlling values
  int option, i = index, repeated = 0;

  // Service and text
  char selectServ[1], serviceTxt[21];
  // Service selection

  printf("\n1. Wash and Vacuum \t\t\t\t $2,500.00\n2. Engine Wash \t\t\t\t\t "
         "$2,000.00\n3. Polishing \t\t\t\t\t $3,500.00\n4. Buffing \t\t\t\t\t "
         "$5,500.00\n5. Roof Cleaning \t\t\t\t $3,200.00\n6. "
         "Detailing/Interior Shampooing \t\t $7,500.00\n");

  // Service validation
  do 
  {
    printf("\nPlease enter your desired service between 1 and 6: ");

    scanf(" %[^\n]s", selectServ);

    option = atoi(selectServ);

    if (option < 1 || option > 6) 
    {
      printf("\nInvalid entry. Please enter a value between 1 and 6.\n");

      repeated++;

    } 

    else 
    {
      break;
    }
    // Clears the screen after 3 invalid entries
    if (repeated % 3 == 0) 
    {
      service(i);
    };
  } while (option < 1 || option > 6);
  // End of Service Validation
  // Convert to string
  switch (option) 
  {
    // Service selection
  case 1:
    strcpy(serviceTxt, "Wash and Vaccum");
    break;
  case 2:
    strcpy(serviceTxt, "Engine Wash");
    break;
  case 3:
    strcpy(serviceTxt, "Polishing");
    break;
  case 4:
    strcpy(serviceTxt, "Buffing");
    break;
  case 5:
    strcpy(serviceTxt, "Roof Cleaning");
    break;
  case 6:
    strcpy(serviceTxt, "Interior Shampooing");
    break;
    // Should be unreachable
  default:
    printf("Invalid Entry. Please enter a value between 1 and 6.\n");
    break;
  }
  // End of Service Selection
  infoFile = fopen("Customer Records.txt", "a+");
  // Check if the file is open, if not, terminate the program

  if (infoFile == NULL) 
  {
    printf("Error!");
    exit(1);
  }
  // Save the service to the file
  fprintf(infoFile, "\t%s", serviceTxt);

  // Copy the service to the struct array for later use
  sprintf(cust.service[i], "%s", serviceTxt);

  // Close the file
  fclose(infoFile);
}
