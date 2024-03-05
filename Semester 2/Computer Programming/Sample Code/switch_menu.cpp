/* Menu Program */
#include <stdio.h>
    
// function main
void main()
{
   int menu_opion;
   printf(" *** Welcome to XYZ Service Centre. ***\n");
   printf(" Entre 4 for New Connection .\n");
   printf(" Entre 3 for Complanints .\n");
   printf(" Entre 2 for Tariff Details .\n");
   printf(" Entre 1 for the operator .\n");
   scanf("%d", &menu_opion); 

   switch ( menu_opion ){
   case 4:
	   printf("Process for new connection has started. Thanks\n");
	   break;
   case 3:
	   printf("Your complaint will be addressed shortly. Thanks\n");
	   break;
   case 2:
	   printf("Tariff Guide will be mailed to your postal address. Thanks\n");
	   break;
   case 1:
	   printf("Your Call will be forwarded to the operator. Thanks\n");
	   break;
   default:
	   printf("You have entered the wrong option.\n");
   }
        
} 
