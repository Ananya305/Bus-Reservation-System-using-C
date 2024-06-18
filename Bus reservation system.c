#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
typedef struct BinarySearchTree BST;
// if bst is empty then we have to handle the error
struct BinarySearchTree
{
  int PassnNo; // busNo0SeatNo.
  char name[10];
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
};
BST *root = NULL;
int cost(BST *r);              // calculates costs
void status();                 // shows bus and seats status
void busLists();               // shows buslist and do booking seat and return customer ID
void DisplaySeat(int bus[33]); // Display the seats of buses
void cancel(int x);
void cancel(int x);            //cancel the booking 
BST *reservationInfo(BST *, int, int *); // Display Reservation Info
BST *insert(BST **r, int custID);
BST *insert(BST **r, int custID); // inserting a node 

int busSeat[32][9] = {0};
void redColor() /// Print the message in redcolor
@@ -235,7 +235,7 @@ void cancel(int randomNum)
      printf("   ENTER THE BUS NUMBER: ");
      scanf("%d", &choice);

      printf("\nHOW MANY SEATS DO WANT TO CANCEL : ");
      printf("\n HOW MANY SEATS DO WANT TO CANCEL : ");
      scanf("%d", &seatCancel);
      for (int i = 0; i < seatCancel; i++)
      {
@@ -245,7 +245,7 @@ void cancel(int randomNum)
        busSeat[choice][seatNumber] = 0;
      }
      printf("\n\nYOUR RESERVATION HAS BEEN CANCEL !!\n\n");
      printf("PRESS 'ENTER' KEY TO CONTINUE ");
      printf("\n  PRESS 'ENTER' KEY TO CONTINUE \n");
      getch();
      DisplaySeat(busSeat[choice]);
    }
    else if (c == 'n' || c == 'N')
    {
      printf("\nYOUR RESERVATION CANCELATION HAS BEEN DENIED\n");
    }
  }
  else
  {
    printf("\nNOT FOUND!! ENTER THE CORRECT RESERVATION NUMBER\n");
    goto aa;
  }
}
}
int main()
{
  srand(time(0));
  int randomNum = rand();
  int num, i, custID, reservationNo;
  BST *root1;
  login();
main:
{
  do
  {
    printf("\n\n====================================================================\n\n");
    printf("\t\t\t\033[1;31mBUS RESERVATION\033[0m\t\t");
    printf("\n\n=====================================================================\n");
    printf("\n====================");
    redColor();
    printf("  MAIN MENU ");
    resetColor();
    printf("=====================\n\n");
    printf("   \033[1;31m[1]\033[0m VIEW BUS LIST \n\n");
    printf("   \033[1;31m[2]\033[0m BOOK TICKETS\n\n");
    printf("   \033[1;31m[3]\033[0m CANCEL BOOKING\n\n");
    printf("   \033[1;31m[4]\033[0m BUSES SEATS INFO\n\n");
    printf("   \033[1;31m[5]\033[0m RESERVATION INFO\n\n");
    printf("   \033[1;31m[6]\033[0m EXIT\n");
    printf("\n=====================================================\n");
    printf("\n   ENTER YOUR CHOICE: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
      busLists(); // for list of bus
      break;
    case 2:
      busLists(); // for booking the tickets
      int CustId, choice, seats;
    busChoice:
      printf("\n\nCHOOSE YOUR BUS  : ");
      scanf("%d", &choice);
      if (choice <= 0 || choice > 9)
      {
        redColor();
        printf("\nENTER VALID BUS NUMBER !! \n");
        resetColor();
        getch();
        goto busChoice;
      }
      printf("\n");
      DisplaySeat(busSeat[choice]);
    busSeatChoice:
      printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
      scanf("%d", &seats);
      if (seats <= 0)
      {
        redColor();
        printf("\nENTER VALID SEAT NUMBER!!\n");
        resetColor();
        goto busSeatChoice;
      }
      else if (seats > 32)
      {
        redColor();
        printf("\nENTER VALID SEAT NUMBER WE HAVE ONLY 32 SEATS IN A BUS !!\n");
        resetColor();
        goto busSeatChoice;
      }
      int seatNumber;
      for (int i = 1; i <= seats; i++)
      {
        printf("\n\n==================================================================================\n\n");
      seat:
        printf("   ENTER THE SEAT NUMBER: ");
        scanf("%d", &seatNumber);
        if (seatNumber <= 0)
        {
          redColor();
          printf("\n   ENTER VALID SEAT NUMBER!!\n\n");
          resetColor();
          goto seat;
        }
        else if (seatNumber > 32)
        {
          redColor();
          printf("\n   ENTER VALID SEAT NUMBER WE HAVE ONLY 32 SEATS IN A BUS !!\n\n");
          resetColor();
          goto seat;
        }
        CustId = choice * 1000 + seatNumber; // CustumerId
        busSeat[choice][seatNumber] = 1;
        root = insert(&root, CustId);
        redColor();
        printf("\n   YOUR CUSTOMER ID IS : %d", CustId);
        resetColor();
        printf("\n\n==================================================================================\n\n");
      }
      printf("\nYOUR RESERVATION NUMBER IS : ");
      redColor();
      printf("%d\n", randomNum);
      printf("\nPLEASE NOTE DOWN YOUR RESERVATION NUMBER FOR CANCEL BOOKING TICKETS!!\n");
      resetColor();
      printf("PRESS 'ENTER' KEY TO CONTINUE ");
      getch();
      break;
    case 3:
      cancel(randomNum);
      break;
    case 4:
      status(randomNum);
      break;
    case 5:
    takingReservationNo:
      printf("\n   ENTER YOUR RESERVATION NUMBER :");
      scanf("%d", &reservationNo);
      if (randomNum == reservationNo)
      {
      cust:
        printf("\n   ENTER YOUR CUSTOMER ID :");
        scanf("%d", &custID);
        int custIDmatched = 0;
        root1 = reservationInfo(root, custID, &custIDmatched);
        if (custIDmatched == 0)
        {
          redColor();
          printf("\n   ENTER CORRECT CUSTOMER ID!!\n");
          resetColor();
          goto cust;
        }
      }
      else
      {
        redColor();
        printf("\n INVALID RESERVATION NUMBER PLEASE ENTER CORRECT RESERVATION NUMBER !!\n");
        resetColor();
        goto takingReservationNo;
      }
      break;
    default:
      redColor();
      printf("\n\n   INVALID INPUT CHOOSE CORRECT OPTION\n");
      resetColor();
      break; 
    }
  } while (num != 6);
  printf("\n\n=====================================================================\n\n");
  printf("THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
  printf("\n\nPRESS ANY KEY TO EXIT THE END PROGRAM !! \n");
  printf("\n\n");
  getch();
  return 0;
}
}