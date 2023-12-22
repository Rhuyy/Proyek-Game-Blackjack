#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <ctype.h>

int score=100;int bet;
int finalCardValue,dealerFinalCardValue;
int iswin,isdouble;

void welcome()
{
	printf("  ____  _            _     _            _     \n");
  	printf(" | __ )| | __ _  ___| | __(_) __ _  ___| | __ \n");
  	printf(" |  _  | |/ _` |/ __| |/ /| |/ _` |/ __| |/ / \n");
  	printf(" | |_) | | (_| | (__|   < | | (_| | (__| _ <  \n");
  	printf(" |____/|_| __,_| ___|_||_|/ | __,_| ___|_||_| \n");
  	printf("                        |__/                  \n\n");
    printf("\nGet ready to play and win!\n\n");
}

void youwin()
{
	printf(" __     __          __          ___       \n");
	printf(" \\ \\   / /          \\ \\        / (_)      \n");
	printf("  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __  \n");
	printf("   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\ \n");
	printf("    | | (_) | |_| |    \\  /\\  /  | | | | |\n");
	printf("    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_|\n\n");
}

void youlose()
{
	printf(" __     __           _               \n");     
	printf(" \\ \\   / /          | |                   \n");
	printf("  \\ \\_/ /__  _   _  | |     ___  ___  ___ \n");
	printf("   \\   / _ \\| | | | | |    / _ \\/ __|/ _ \\ \n");
	printf("    | | (_) | |_| | | |___| (_) \\__ \\  __/\n");
	printf("    |_|\\___/ \\__,_| |______\\___/|___/\\___|\n");
}

void thankyou(int score)
{
	printf("  _______ _                 _                        \n");
	printf(" |__   __| |               | |                       \n");
	printf("    | |  | |__   __ _ _ __ | | __  _   _  ___  _   _ \n");
	printf("    | |  | '_ \\ / _` | '_ \\| |/ / | | | |/ _ \\| | | |\n");
	printf("    | |  | | | | (_| | | | |   <  | |_| | (_) | |_| |\n");
	printf("    |_|  |_| |_|\\__,_|_| |_|_|\\_\\  \\__, |\\___/ \\__,_|\n");
	printf("                                    __/ |            \n");
	printf("                                   |___/             \n");
	printf("Thanks for playing!\n");
	printf("Your final score was: %d\n", score);
}

int calculateTotal(int* sumcardarr, int numCards) 
{
    int total = 0;
    int numAces = 0;
	int i;

    for (i = 0; i < numCards; i++)
	{
        if (sumcardarr[i] == 12) 
		{ 
            total += 11; 
            numAces++;
        } 
		else if (sumcardarr[i] >= 9 && sumcardarr[i]<=11) 
		{
            total += 10;
        } 
		else 
		{
            total += sumcardarr[i] + 2;
        }
    }

    while (total > 21 && numAces > 0) 
	{
        total -= 10; 
        numAces--;
    }

    return total;
}

void drawCard(int *sumcardarr, int *counter, int isplayer) {
    int card = rand() % 52;
    int carddiv = card / 13;
    int cardmod = card % 13;
    
    char drawnValue[2];
	if (cardmod == 0)
	strcpy(drawnValue, "02");
	else if (cardmod == 1)
	strcpy(drawnValue, "03");
	else if (cardmod == 2)
	strcpy(drawnValue, "04");
	else if (cardmod == 3)
	strcpy(drawnValue, "05");
	else if (cardmod == 4)
	strcpy(drawnValue, "06");
	else if (cardmod == 5)
	strcpy(drawnValue, "07");
	else if (cardmod == 6)
	strcpy(drawnValue, "08");
	else if (cardmod == 7)
	strcpy(drawnValue, "09");
	else if (cardmod == 8)
	strcpy(drawnValue, "10");
	else if (cardmod == 9)
	strcpy(drawnValue, "JJ");
	else if (cardmod == 10)
	strcpy(drawnValue, "QQ");
	else if (cardmod == 11)
	strcpy(drawnValue, "KK");
	else if (cardmod == 12)
	strcpy(drawnValue, "AA");

    // Display gambar kartu
//    switch(carddiv)
//		{
	if (isplayer == 1)
	printf("You draw:\n");
	else
	printf("Dealer draws:\n");
	
	if (isplayer > 2)
	{
	printf(" -------------\n");
	printf("| * * * * * * |\n");
	printf("|  * * * * *  |\n");
	printf("| * * * * * * |\n");
	printf("|  * * * * *  |\n");
	printf("| * * * * * * |\n");
	printf("|  * * * * *  |\n");
	printf("| * * * * * * |\n");
	printf("|  * * * * *  |\n");
	printf("| * * * * * * |\n");
	printf(" -------------\n");
	}
	
	
	else if (carddiv == 0)
	{
					//hearts
	printf(" -------------\n");
	printf("|           %s|\n", drawnValue);
	printf("|             |\n");
	printf("|    ** **    |\n");
	printf("|   *******   |\n");
	printf("|   *******   |\n");
	printf("|    *****    |\n");
	printf("|      *      |\n");
	printf("|             |\n");
	printf("|%s           |\n", drawnValue);
	printf(" -------------\n");			
	}
	else if (carddiv == 1)
	{
					//spades
	printf(" -------------\n");
	printf("|           %s|\n", drawnValue);
	printf("|             |\n");
	printf("|      .      |\n");
	printf("|     / \\     |\n");
	printf("|    /   \\    |\n");
	printf("|   (__ __)   |\n");
	printf("|     _|_     |\n");
	printf("|             |\n");
	printf("|%s           |\n", drawnValue);
	printf(" -------------\n");
	}
	else if (carddiv == 2)
	{
					//diamonds
	printf(" -------------\n");
	printf("|           %s|\n", drawnValue);
	printf("|             |\n");
	printf("|     /\\      |\n");
	printf("|    /  \\     |\n");
	printf("|   |    |    |\n");
	printf("|    \\  /     |\n");
	printf("|     \\/      |\n");
	printf("|             |\n");
	printf("|%s           |\n", drawnValue);
	printf(" -------------\n");
	}
	else if (carddiv == 3)
	{
					//clubs
	printf(" -------------\n");
	printf("|           %s|\n", drawnValue);
	printf("|             |\n");
	printf("|      _      |\n");
	printf("|    _( )_    |\n");
	printf("|   (__|__)   |\n");
	printf("|     _|_     |\n");
	printf("|             |\n");
	printf("|             |\n");
	printf("|%s           |\n", drawnValue);
	printf(" -------------\n");
	}
		
//	sleep(1);	
//    printf("card = %d\ncarddiv = %d\ncardmod = %d\n", card, carddiv, cardmod);
    sumcardarr[(*counter)++] = cardmod;
}

void startGame()
{
	int i,j,card,sumcard,carddiv,cardmod,input,counter;
	int sumcardarr[20];
	isdouble = 0;sumcard=0;counter=0;
	srand((unsigned int)time(NULL));
	sleep(1);
	drawCard(sumcardarr,&counter,1);
	sumcard = calculateTotal(sumcardarr,counter);
	while(1)
	{
//		system("cls");
		sleep(1);
		printf("Your total value : %d\n",sumcard);
		printf("1 to Draw, 2 to Stay, 3 for Double\n");
		scanf("%d",&input);
		if(input == 1)
		{
			//draw
			drawCard(sumcardarr,&counter,1);
			sumcard = calculateTotal(sumcardarr,counter);
			if (sumcard >= 21 || isdouble==1)
                break;
		}
		else if(input==2)
		{
			//stay
			break;
		}
		else if (input==3)
		{
			//double
			isdouble=1;
			drawCard(sumcardarr,&counter,1);
			sumcard = calculateTotal(sumcardarr,counter);
			if (sumcard >= 21 || isdouble==1)
                break;
		}
		else
		{
			printf("input invalid");
			system("pause");
		}
	}
	
	if(sumcard<=21)
	{
		printf("Your final card value = %d",sumcard);
		finalCardValue = sumcard;

	}
	else
	{
		printf("You Bust\n");
		finalCardValue = 0;
	}

	
}

void drawDealer()
{
	int i,j,card,dealersumcard,carddiv,cardmod,input,counter;
	int cardcounter = 2;
	int dealersum;
	int sumcardarr[20];
	int isdouble = 0;dealersumcard=0;counter=0;
	srand((unsigned int)time(NULL));
	while(1){
//		if (dealersumcard>=16)
//		cardcounter++;
		sleep(1);
		if (dealersumcard>=16){
		cardcounter++;
		dealersum = dealersumcard;
		drawCard(sumcardarr,&counter,cardcounter);
		dealersumcard=calculateTotal(sumcardarr,counter);
		break;
		}
		else{
		drawCard(sumcardarr,&counter,cardcounter);
		dealersumcard=calculateTotal(sumcardarr,counter);
		continue;
		}
	}
	printf("Dealer's Total Value: %d + 1 Card\n", dealersum);
	if(dealersumcard<=21) dealerFinalCardValue = dealersumcard;
	else dealerFinalCardValue = 0;
;
}

void winLose()
{
	if(finalCardValue>dealerFinalCardValue)
	{
		iswin=1;
		youwin();
	}
	else if(finalCardValue<dealerFinalCardValue)
	{
		iswin=0;
		youlose();
	}
	else
	{
		iswin=-1;
		printf("Its a Draw!\n");
	}
}

void printScore()
{
	system("cls");
	if(finalCardValue!=0) printf("\nYour final card value = %d\n",finalCardValue);
	else printf("You have busted!\n");
	
	if(dealerFinalCardValue!=0 )printf("\nDealer's final card value = %d\n",dealerFinalCardValue);
	else printf("Dealer have busted!\n");
}

int calculateScore(int bet)
{
	if(iswin==1)
	{
		if(isdouble==1) score+=(bet*2);
		else score+=bet;
	} 
	else if(iswin==0)
	{
		if (isdouble==1)
		score-=(bet*2);
		else
		score-=bet;
	}
	else
	score += 0;
}

int main()
{
	welcome();
	system("pause");
	system("cls");
	int play;
	while(score>0)
	{
		system("cls");
		printf("Your current score: %d\nChoose your bet: ",score);
		scanf("%d",&bet);
		drawDealer();
		startGame();
		printScore();
		winLose();
		score = calculateScore(bet);
		printf("\nYour score is now %d !\n",score);	
		system("pause");
		system("cls");
		printf("Continue Playing?\n1 to Continue\n2 to Exit\n");
		scanf("%d", &play);
		if (play == 2){
		thankyou(score);
		break;
		}
	}

}
