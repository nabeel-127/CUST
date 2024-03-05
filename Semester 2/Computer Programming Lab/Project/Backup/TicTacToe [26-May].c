#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Menu(int match, int check);
Box();
Stats();
SignUp();
SignIn(int *logged_in);

RunGame();
PlayerSelector(int *bot, int *human);
AgainstBot();
offense(int row, int column, int mistake, int *checkmove);
defence(int row, int column, int mistake, int *checkmove);
AgainstHuman();
Move(int row, int column, int mistake);
CheckWin();
WinMessage();



char mark, placement[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int  current_user, user_save = 0, player = 1, winner = 0;
struct Users
{
	char username[20], name[20], password[20];
	int wins, losses, draws, matchesvsbot, matchesvshuman, matches_played, user_check;
}user[25];



main()
{
	int logged_in = 0, option, check = 0, exit;
	
	do
	{
		winner = 0;
		exit = 0;
		if (logged_in == 0)
		{
			Menu(logged_in, check);
			printf("Choose an option: ");
			scanf("%d", &option);
			switch (option)
			{
			case 1:
				SignIn(&logged_in);
				break;
			case 2:
				SignUp();
				break;
			case 3:
				exit = 1;
				break;
			}
		}
		else
		{
			Menu(logged_in, check);
			printf("Choose an option: ");
			scanf("%d", &option);
			switch (option)
			{
			case 1:
				RunGame();
				break;
			case 2:
				Stats();
				break;
			case 3:
				logged_in = 0;
				break;
			case 4:
				exit = 1;
				break;
			}
		}		
	} while (exit == 0);
}


Menu(int match, int check)
{
	system("cls");
	if (match == 0)
	{
		printf("1. Sign in using and existing account\n");
		printf("2. Create a new account\n");
		printf("3. Exit the Game\n");
	}
	else
	{
		printf("1. Start Game\n");
		printf("2. Check Stats\n");
		printf("3. Sign Out\n");
		printf("4. Exit the Game\n");
	}
}


SignIn(int *logged_in)
{
	int i;
	char username[20], password[20], retry;
	do
	{
		system("cls");
		printf("Enter your username: ");
		scanf("%s", username);
		printf("Enter your password: ");
		scanf("%s", password);
		for (i = 0;i < 25;i++)
		{
			if ((strcmp(username, user[i].username) || strcmp(password, user[i].password)) == 0)
			{
				current_user = i;
				*logged_in = 1;
				break;
			}
		}
		if (*logged_in == 0)
		{
			printf("Incorrect Username or Password. Press 'Y' to try again: ");
			scanf(" %c", &retry);
		}
		if (retry != 'y' && retry != 'Y')
		{
			break;
		}
		retry = ' ';
	} while (1);

}


SignUp()
{
	int i, length = 0;
	system("cls");
	for (user_save = 0;user_save < 25;user_save++)
	{
		if (user[user_save].user_check == 1)
		{
			continue;
		}
		printf("Enter your name: ");
		scanf("%s", user[user_save].name);
		do
		{
			printf("Enter the username: ");
			scanf("%s", user[user_save].username);
			for (i = 0;i < 20;i++)
			{
				if (user[user_save].username[i] == '\0')
				{
					break;
				}
				length++;
			}
			if (length >= 3)
			{
				break;
			}
			system("cls");
			printf("Username must me atleast 3 digit long. Try again\n");
		} while (1);
		length = 0;
		do
		{
			printf("Enter the password: ");
			scanf("%s", user[user_save].password);
			for (i = 0;i < 20;i++)
			{
				if (user[user_save].password[i] == '\0')
				{
					break;
				}
				length++;
			}
			if (length >= 5)
			{
				break;
			}
			system("cls");
			printf("Username must me atleast 3 digit long. Try again\n");
		} while (1);
		break;
	}
	user[user_save].wins = 0;
	user[user_save].losses = 0;
	user[user_save].matchesvsbot = 0;
	user[user_save].matchesvshuman = 0;
	user[user_save].matches_played = 0;
	user[user_save].draws = 0;
	user[user_save].user_check = 1;
}



RunGame()
{
	int bot = 0, human = 0;
	do
	{
		if (bot == 0 && human == 0)
		{
			PlayerSelector(&bot, &human);
		}
	
		Box();
	
		if (bot == 1)
		{
			AgainstBot();
		}
		else if (human == 1)
		{
			AgainstHuman();
		}
	
		CheckWin();
	
		player += 3;
	} while (winner == 0);
	
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			placement[i][j] = ' ';
		}
	}
	bot = 0;
	human = 0;
	player = 1;
}

PlayerSelector(int *bot, int *human)
{
	int check, option;
	do
	{
		system("cls");
		check = 0;
		printf("Who would you like to play against?\n");
		printf("1. Human VS Computer\n");
		printf("2. Human VS Human\n");
		printf("Choose and option: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			*bot = 1;
			break;
		case 2:
			*human = 1;
			break;
		default:
			printf("You have entered the wrong value. Try again.\n");
			check = 1;
		}

		

	} while (check == 1);
}




Box()
{
	system("cls");
	printf(" %c | %c | %c \n", placement[0][0], placement[0][1], placement[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", placement[1][0], placement[1][1], placement[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", placement[2][0], placement[2][1], placement[2][2]);
}



Stats()
{
	system("cls");
	printf("Name: %s\n", user[current_user].name);
	printf("Username: %s\n", user[current_user].username);
	printf("Wins: %d\n", user[current_user].wins);
	printf("Losses: %d\n", user[current_user].losses);
	printf("Draws: %d\n", user[current_user].draws);
	printf("Matches played: %d\n", user[current_user].matches_played);
	system("pause");
}



AgainstBot()
{
	int row = 3, column = 3, mistake, checkmove = 0;
	
	if (player % 2 == 1)
	{
		do
		{
			mistake = 0;
			do
			{
				printf("Enter the row: ");
				scanf("%d", &row);
				if (row > 0 && row < 4)
					break;
				else
					printf("Incorrect value, try again.\n");
			} while (1);
			do
			{
				printf("Enter the column: ");
				scanf("%d", &column);
				if (column > 0 && column < 4)
					break;
				else
					printf("Incorrect value, try again.\n");
			} while (1);

			row--;
			column--;

			mark = 'X';

			mistake = Move(row, column, mistake);
		} while (mistake == 1);
	}
	else
	{
		mistake = 0;
		offense(row, column, mistake, &checkmove);
		if (checkmove == 0)
		{
			defence(row, column, mistake, &checkmove);
		}
		
	}
}

offense(int row, int column, int mistake, int *checkmove)
{
	int i;
	mark = 'O';
	mistake = 0;
	*checkmove = 0;
	for (i = 0; i < 3; i++)
	{
		if ((placement[i][0] == mark) && (placement[i][1] == mark) && (placement[i][2] != 'X') && (placement[i][2] != 'O'))
		{
			row = i;
			column = 2;
			*checkmove = 1;
			break;
		}
	}
	if (*checkmove == 0)
	{
		for (i = 0; i < 3; i++)
		{
			if ((placement[i][1] == mark) && (placement[i][2] == mark) && (placement[i][0] != 'X') && (placement[i][0] != 'O'))
			{
				row = i;
				column = 0;
				*checkmove = 1;
				break;
			}
		}
	}
	if (*checkmove == 0)
	{
		for (i = 0; i < 3; i++)
		{
			if ((placement[i][2] == mark) && (placement[i][0] == mark) && (placement[i][1] != 'X') && (placement[i][1] != 'O'))
			{
				row = i;
				column = 1;
				*checkmove = 1;
				break;
			}
		}
		}
	if (*checkmove == 0)
	{
		for (i = 0; i < 3; i++)
		{
			if ((placement[0][i] == mark) && (placement[1][i] == mark) && (placement[2][i] != 'X') && (placement[2][i] != 'O'))
			{
				row = 2;
				column = i;
				*checkmove = 1;
				break;
			}
		}
	}
	if (*checkmove == 0)
	{
		for (i = 0; i < 3; i++)
		{
			if ((placement[1][i] == mark) && (placement[2][i] == mark) && (placement[0][i] != 'X') && (placement[0][i] != 'O'))
			{
				row = 0;
				column = i;
				*checkmove = 1;
				break;
			}
		}
	}
	if (*checkmove == 0)
	{
		for (i = 0; i < 3; i++)
		{
			if ((placement[2][i] == mark) && (placement[0][i] == mark) && (placement[1][i] != 'X') && (placement[1][i] != 'O'))
			{
				row = 1;
				column = i;
				*checkmove = 1;
				break;
			}
		}
	}
	if (*checkmove == 0)
	{
		if ((placement[0][0] == mark) && (placement[1][1] == mark) && (placement[2][2] != 'X'))
		{
			row = 2;
			column = 2;
			*checkmove = 1;
		}
		else if ((placement[1][1] == mark) && (placement[2][2] == mark) && (placement[0][0] != 'X'))
		{
			row = 0;
			column = 0;
			*checkmove = 1;
		}
		else if ((placement[0][0] == mark) && (placement[2][2] == mark) && (placement[1][1] != 'X'))
		{
			row = 1;
			column = 1;
			*checkmove = 1;
		}
		else if ((placement[0][2] == mark) && (placement[1][1] == mark) && (placement[2][0] != 'X'))
		{
			row = 2;
			column = 0;
			*checkmove = 1;
		}
		else if ((placement[1][1] == mark) && (placement[2][0] == mark) && (placement[0][2] != 'X'))
		{
			row = 0;
			column = 2;
			*checkmove = 1;
		}
		else if ((placement[0][2] == mark) && (placement[2][0] == mark) && (placement[1][1] != 'X'))
		{
			row = 1;
			column = 1;
			*checkmove = 1;
		}
	}
	if (*checkmove == 1)
	{
		Move(row, column, mistake);
	}
}

defence(int row, int column, int mistake, int *checkmove)
{
	int i;
	mark = 'X';
	do
	{
		mistake = 0;
		*checkmove = 0;
		for (i = 0; i < 3; i++)
		{
			if ((placement[i][0] == mark) && (placement[i][1] == mark) && (placement[i][2] != 'X') && (placement[i][2] != 'O')) 
			{
				row = i;
				column = 2;
				*checkmove = 1;
				break;
			}
		}
		if (*checkmove == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if ((placement[i][1] == mark) && (placement[i][2] == mark) && (placement[i][0] != 'X') && (placement[i][0] != 'O'))
				{
					row = i;
					column = 0;
					*checkmove = 1;
					break;
				}
			}

		}
		if (*checkmove == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if ((placement[i][2] == mark) && (placement[i][0] == mark) && (placement[i][1] != 'X') && (placement[i][1] != 'O'))
				{
					row = i;
					column = 1;
					*checkmove = 1;
					break;
				}
			}

		}
		if (*checkmove == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if ((placement[0][i] == mark) && (placement[1][i] == mark) && (placement[2][i] != 'X') && (placement[2][i] != 'O'))
				{
					row = 2;
					column = i;
					*checkmove = 1;
					break;
				}
			}

		}
		if (*checkmove == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if ((placement[1][i] == mark) && (placement[2][i] == mark) && (placement[0][i] != 'X') && (placement[0][i] != 'O'))
				{
					row = 0;
					column = i;
					*checkmove = 1;
					break;
				}
			}
		}
		if (*checkmove == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if ((placement[2][i] == mark) && (placement[0][i] == mark) && (placement[1][i] != 'X') && (placement[1][i] != 'O'))
				{
					row = 1;
					column = i;
					*checkmove = 1;
					break;
				}
			}

		}
		if (*checkmove == 0)
		{
			if ((placement[0][0] == mark) && (placement[1][1] == mark) && (placement[2][2] != 'O'))
			{
				row = 2;
				column = 2;
				*checkmove = 1;
			}
			else if ((placement[1][1] == mark) && (placement[2][2] == mark) && (placement[0][0] != 'O'))
			{
				row = 0;
				column = 0;
				*checkmove = 1;
			}
			else if ((placement[0][0] == mark) && (placement[2][2] == mark) && (placement[1][1] != 'O'))
			{
				row = 1;
				column = 1;
				*checkmove = 1;
			}
			else if ((placement[0][2] == mark) && (placement[1][1] == mark) && (placement[2][0] != 'O'))
			{
				row = 2;
				column = 0;
				*checkmove = 1;
			}
			else if ((placement[1][1] == mark) && (placement[2][0] == mark) && (placement[0][2] != 'O'))
			{
				row = 0;
				column = 2;
				*checkmove = 1;
			}
			else if ((placement[0][2] == mark) && (placement[2][0] == mark) && (placement[1][1] != 'O'))
			{
				row = 1;
				column = 1;
				*checkmove = 1;
			}
		}

		if (*checkmove == 0)
		{
			row = rand() % 3;
			column = rand() % 3;
		}
		mark = 'O';
		mistake = Move(row, column, mistake);
	} while (mistake == 1);
}

AgainstHuman()
{
	int user, row, column, mistake;

	user = (player % 2 == 0) ? 2 : 1;

	do
	{
		mistake = 0;
		do
		{
			printf("Player %d, enter the row: ", user);
			scanf("%d", &row);
			if (row > 0 && row < 4)
				break;
			else
				printf("Incorrect value, try again.\n");
		} while (1);
		do
		{
			printf("Player %d, enter the column: ", user);
			scanf("%d", &column);
			if (column > 0 && column < 4)
				break;
			else
				printf("Incorrect value, try again.\n");
		} while (1);
		
		row--;
		column--;

		if (player % 2 == 0)
		{
			mark = 'O';
		}
		else
		{
			mark = 'X';
		}
		mistake = Move(row, column, mistake);
	} while (mistake == 1);

}



Move(int row, int column, int mistake)
{
	if (row < 0 || row >= 3 || column < 0 || column >= 3)
	{
		system("cls");
		Box();
		printf("You have made the wrong move. Try again\n");
		mistake = 1;
	}
	else if (placement[row][column] == 'X' || placement[row][column] == 'O')
	{
		system("cls");
		Box();
		printf("Invalid Move. Try again\n");
		mistake = 1;
	}
	else if (placement[row][column] == ' ')
	{
		placement[row][column] = mark;
	}
	return mistake;
}



CheckWin()
{
	int i, j, count = 0;

	for (i = 0; i < 3; i++)
	{
		if ((placement[i][0] == mark) && (placement[i][1] == mark) && (placement[i][2] == mark))
		{
			if (player % 2 == 0)
				winner = 2;
			else
				winner = 1;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if ((placement[0][i] == mark) && (placement[1][i] == mark) && (placement[2][i] == mark))
		{
			if (player % 2 == 0)
				winner = 2;
			else
				winner = 1;
		}
	}
	if (winner == 0)
	{
		if (placement[1][1] == mark)
		{
			if ((placement[0][0] == mark) && (placement[2][2] == mark))
			{
				if (player % 2 == 0)
					winner = 2;
				else
					winner = 1;
			}
			else if ((placement[0][2] == mark) && (placement[2][0] == mark))
			{
				if (player % 2 == 0)
					winner = 2;
				else
					winner = 1;
			}
		}
	}
	

	if (winner == 0)
	{
		for (i = 0;i < 3;i++)
		{
			for (j = 0;j < 3;j++)
			{
				if (placement[i][j] == 'X' || placement[i][j] == 'O')
				{
					count++;
				}
			}
		}
		if (count >= 9)
		{
			winner = -1;
		}
	}

	
	if (winner == 1)
	{
		user[current_user].matches_played++;
		user[current_user].wins++;
		Box();
		WinMessage();
	}
	else if (winner == 2)
	{
		user[current_user].matches_played++;
		user[current_user].losses++;
		Box();
		WinMessage();
	}
	else if (winner == -1)
	{
		user[current_user].matches_played++;
		user[current_user].draws++;
		Box();
		WinMessage();
	}
}



WinMessage()
{
	if (winner == -1)
	{
		printf("It's a Draw\n");
		system("pause");
	}
	else
	{
		printf("Player %d has won\n", winner);
		system("pause");
	}
}