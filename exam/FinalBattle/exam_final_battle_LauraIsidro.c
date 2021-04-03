/****************************************************************************
*
*						FINAL BATTLE EXAM
*
*					Student name: Laura Isidro
* 
*		WARNING! REMEMBER:
*			- Program must compile. No compiling program is a 0 in the mark.
*			- Program must be perfectly tabulated and spaced.
*			- Program must follow required naming conventions.
*			- Program must show screen results organized and styled.
*
*****************************************************************************/

// TODO 0: Indicate the functions required for every library (0.5p)

#include <stdio.h>		// Required for function(s): printf(), scanf_s()
#include <stdlib.h>		// Required for function(s): srand(), rand(); cls()
#include <time.h>		// Required for function(s): time()

void DrawTitle(void);
void DrawGargole(void);
void DrawCrazyRat(void);
void DrawSkeleton(void);
void DrawPlayerEnemyLife(int pLife, int eLife);

int main()
{
	// Game variables declaration
	//-----------------------------
	int playerLife = 50;
	int playerAttack = 0;
	int playerAction = 0;
	int playerEscape = 0;
	int enemyLife = 0;
	int enemyType = -1;
	int enemyAttack = 0;
	int totalGold = 0;
	int enemyGold = 0;
	char startKey = ' ';
    char playerName[32] = { 0 };

	// Basic game logic
	//-------------------
	// TODO 1a: Init random seed based on current time (0.5p)
	srand(time(NULL));

	DrawTitle(); 	// Draw main title
    
    // TODO 1b: Ask user for player name and store it in playerName (0.5p)
	printf("\nIntroduce your battle name (better one character, because the game doesn't work if not): ");
	scanf_s("%c", playerName, 32);
	printf("\n");

	printf("You are lost in the woods, the most horrible creatures are chasing you...\n");
	printf("Something is approaching, you can feel it, it's time to do your best!\n");

	printf("\nIntroduce X to exit or any other key to START: ");
	scanf_s(" %c", &startKey, 1);

	// TODO 2: Check if X or any other key has been pressed (1p)
	scanf_s("%c", &startKey, 1);
	if (startKey == 'x' || startKey == 'X') printf("\nIn this situation you can't exit. Sorry not sorry ^^");
	else printf("\nNice, let's continue!");

	system("pause");
	system("cls");  //cleaning the screen

	// NOTE: At this point starts a game LOOP
	playerEscape = 0;		// Initialize playerEscape for the loop
	while (playerEscape == 0)
	{
		// TODO 3: Get a random enemy type (0.5p)
		// Enemy type could a number between 0 and 2
		enemyType = rand() % 3;

		//enemyType = 0;

		// TODO 4: Depending on enemyType, draw the right enemy, 
		// display the right message and set enemyLife (1p)
		switch (enemyType)
		{
		case 1:
			printf("A gargole finds you!!");
			DrawGargole();
			enemyLife = (rand() % 11) + 20;
			break;
		case 2:
			printf("A crazy rat finds you!!");
			DrawCrazyRat();
			enemyLife = (rand() % 21) + 40;
			break;
		case 3:
			printf("An skeleton finds you!!");
			DrawSkeleton();
			enemyLife = (rand() % 41) + 80;
			break;
		}

		// enemyType = 0  -->  enemyLife random between [20..30]
		// enemyType = 1  -->  enemyLife random between [40..60]
		// enemyType = 2  -->  enemyLife random between [80..120];

		// EXTRA: Balance enemies life

		DrawPlayerEnemyLife(playerLife, enemyLife);
		
		printf("\n\nPress ENTER to START BATTLE! \n");
		system("pause");

		// TODO 5: At this point starts a battle LOOP (1p)
		// Loop while player and enemy are not dead and player did not escape
		while (playerEscape == 0 || (enemyLife > 0 && playerLife > 0))
		{
			// TODO 6: Print available actions and read player selection (1p)
			printf("\nWhat are you going to do?\n");
			printf("\n 1 - Attack");
			printf("\n 2 - Defend");
			printf("\n 3 - Escape");

			printf("\nChoose a number: ");
			scanf_s("%i", &playerAction);

			// 1 - Attack
			// 2 - Defend
			// 3 - Escape

			// TODO 7: Define playerAttack, random value between [6..20] (0.5p)
			playerAttack = (rand() % 15) + 6;

			// TODO 8: Define enemy attack power (enemyAttack), it depends on enemyType (1p)
			// enemyType = 0  -->  enemyAttack random between [2..10]
			// enemyType = 1  -->  enemyAttack random between [4..16]
			// enemyType = 2  -->  enemyAttack random between [6..22]
			if (enemyType == 0) enemyAttack = (rand() % 9) + 2;
			if (enemyType == 1) enemyAttack = (rand() % 13) + 4;
			if (enemyType == 2) enemyAttack = (rand() % 17) + 6;
			
			// Depending on choosen action, different things happen
			//------------------------------------------------------
			if (playerAction == 1)			// Attack
			{
				// TODO 9: Implement attack logic (1p)
				// playerAttack and enemyAttack are compared, 
				// if playerAttack is greater (or equal), enemy receives de full hit (all playerAttack damage) and player only receives enemyAttack/2 damage.
				// if enemyAttack is greater, player receives de full hit and enemy only receives playerAttack/2 damage.
				if (playerAttack >= enemyAttack)
				{
					enemyLife -= playerAttack;
					playerLife -= enemyAttack / 2;
				}
				else
				{
					playerLife -= enemyAttack;
					enemyLife -= playerAttack / 2;
				}
			}
			else if (playerAction == 2)		// Defend
			{
				// TODO 10: Implement defend logic (1p)
				// enemy receives no damage, player receives enemyAttack/3 damage but also recovers +6 life points
				playerLife -= enemyAttack / 3;
				playerLife += 6;
			}
			else if (playerAction == 3)		// Escape
			{
				// TODO 11: Implement escape logic (1p)
				// player has a 50% probability to escape:
				playerEscape = rand() % 2;
				if (playerEscape == 0)
				{
					playerLife -= enemyAttack;
					printf("You couldn't escape and the enemy hit you");
				}
				else
				{
					printf("You could escape without reciving damage");
					break;
				}
				// if escape, player receives no damage, if not, player receives full damage (show messages)
			}
			else
			{
				// EXTRA: Any idea?
				playerLife -= enemyAttack;
				printf("The monster realizes that you didn't have enough determination and hits you");
			}

			// Print on screen player/enemy attacks (only if player didn't escape)
			if (playerEscape == 0)
			{
				// TODO 12a: Print player/enemy attack (0.5p)
				if (playerAction == 1)
				{
					if (playerAttack >= enemyAttack)
					{
						printf("\nYou hit with %i damage points", playerAttack);
						printf("\nThe monster hit you with %i damage points\n", enemyAttack / 2);
					}
					else
					{
						printf("\nYou hit with %i damage points", playerAttack / 2);
						printf("\nThe monster hit you with %i damage points\n", enemyAttack);
					}
				}
				if (playerAction == 2)printf("The monster hit you with %i damage points, but you heal 6\n", enemyAttack/3);
				// TODO 12b: Draw player/enemy life bars (1p)
				// You need to implement following function, check the function definition!
				DrawPlayerEnemyLife(playerLife, enemyLife);
				printf("\n\n");
			}

			// Check player/enemy life to see if player died or enemy died
			if (playerLife <= 0)
			{
				printf("\nOuch! You died... YOU DIED!!!\n");

				printf("\nGAME OVER...\n");
			}
			else if (enemyLife <= 0)
			{
				printf("GREAT! You beat the monster... YOU BEAT THE MONSTER!!!\n");

				printf("\nCONGRATULATIONS...\n");

				// Enemy dropped gold logic
				enemyGold = 100 + enemyType * 200 + rand() % 100;
				printf("\nMonster drop a bag with money... You get +%i of Gold!\n", enemyGold);

				// Random life potion
				int lifePotion = rand() % 30 + 10;

				printf("Monster also drop a life potion... You get +%i of Life\n", lifePotion);

				totalGold += enemyGold;
				playerLife += lifePotion;

				printf("\nTOTAL GOLD: %i\n", totalGold);
			}

			system("pause");

			// At this point, if player or enemy are not dead and player didn't escape, 
			// return to battle LOOP...
		}
		printf("\nPress X to exit or any other key to fight another ENEMY: ");
		scanf_s(" %c", &startKey, 1);

		// Reset player life for next game
		if (playerLife <= 0) playerLife = 50;

		// NOTE: At this point, if X is pressed finish, if not, get a new FIGHT!
	}

	printf("\nPLAYER TOTAL GOLD: %i\n", totalGold);

	printf("\nGAME OVER\n");

	// EXTRA: Clear-screen

	return 0;
}

//--------------------------------------------------------------------
// Functions definition
//--------------------------------------------------------------------

void DrawTitle(void)
{
	printf("\n");
	printf("            787288778   42    87     87     882      20               \n");
	printf("          78887 78887 7885  2887    887   7228887  7888               \n");
	printf("           280         882   8807   887  88   788   480               \n");
	printf("           788722      482   88  97 887  88   588   784               \n");
	printf("           788  7      487   887  75887  88 77788   289               \n");
	printf("           788         082   887    887  882   88   784               \n");
	printf("           7884        8887  8887   888  881  7885  488  797          \n");
	printf("            77         77    77     77   77    77   727227            \n");
	printf("     784887      484     752820770   774078 97   8        477888 82   \n");
	printf("   7888 78887  7228887 707 28 7888 25  80 7887 488      2888  4888    \n");
	printf("    288   12  88    88     88      7  289      788       88           \n");
	printf("    788 780   88   288     88         784       88       884727       \n");
	printf("    788  4887 88777788     88         284       88       887          \n");
	printf("    788   784 885   88     88   72    284   77  88       88           \n");
	printf("   7888   45  880   888    888729     7888742   887 725  0884 7787    \n");
	printf("     77215    72    27      722         712     222557    722155      \n");
	printf("\n");
}

void DrawGargole(void)
{
	printf("\n");
	printf("                 .;                    ;,.                  \n");
	printf("               ##-,.xX              =x-.=+#,                \n");
	printf("                  =#X -=           x ,XX  .                 \n");
	printf("         =-===       X- +X-;--;,+x, #       -===-           \n");
	printf("      =X-      ##    #X  .      .  .#    =#=      #X        \n");
	printf("     =  .= -+,   ,; x  +- -X; +x  +- ;= +    += .=   +      \n");
	printf("   #+ ++-=.#x .#;  -  #; * .###  * #-  ,  X+ -#=.=-X. #x    \n");
	printf("   #=X#+  -#  x-##  .xX-   +#+#    #x=  =#+=- +x   ##+x#    \n");
	printf("       #X;X  #x  Xx  .-=++x    =x+x=-   #, .#+ -x;#,        \n");
	printf("        ,#+ xx   ;   ###++=    -=+###-  -    #. ##          \n");
	printf("         Xx++X#x x#  ###+  x###   ###, -#.,X#+++X           \n");
	printf("                ###x =###.####X#--###  ###;                 \n");
	printf("                   #- .X###;+X;+###=  X=                    \n");
	printf("               x+   #+  ;###xxX##+   #.  -+                 \n");
	printf("              #  -= +,+x   -+++   -X;=- x  ##               \n");
	printf("               ##  . #  ##x    -X#+ +- . =#,                \n");
	printf("                 #x  #     #+=#=    ##  #X                  \n");
	printf("                  +##      ;#;+      +##                    \n");
	printf("                             X;-X          ++++xxxXx        \n");
	printf("                              ,# .xx    xX  ##X,    #-      \n");
	printf("                                x#+ +XX= =#+   +X   #=      \n");
	printf("                                   Xxx+xX        ###        \n");
	printf("\n");
}

void DrawCrazyRat(void)
{
	printf("\n");
	printf("                x+++x  ++++  +x==x.                         \n");
	printf("  =#. #X      +#  x+;+x;...+x-=X. ##      x#. ##            \n");
	printf("  X# +X #=    ##  ,#,         #-  x#     # +x x#    -;;;    \n");
	printf("  =#; .=X#=     +-=;          ,=-=,    ,X#+,.-+= =x+.;###,  \n");
	printf(" .++#=-#, ;X-.   # XX=+;  ,==+# #,  .,X=  #=-; .=  ;#x;,=   \n");
	printf("     ###x.  ;+x+## *  =+;;++  * +#+x+-   +##= =#  =#+       \n");
	printf("         #x     -#x ,=,    .=; +#=     =#,   =, =#X         \n");
	printf("          =#;=    =X+,      .+X+    =;#X   ;x   =#          \n");
	printf("           ##-     ,=##x=;x##=-     ,##    #=  +#           \n");
	printf("            #-    +=;=##,###---x.   .#    #   ##            \n");
	printf("            #=  ;X  =+=.+#-;+=  x-  -#   #,  ;#+            \n");
	printf("           #,     =X.         xx      #x,+  ,#x             \n");
	printf("           #,     -            ,     .##   ;#+              \n");
	printf("         ,#,.                          X+ ,##               \n");
	printf("         ,#  .                    .    +#x#.                \n");
	printf("         ;#+.,                    ., ;.x#-                  \n");
	printf("          =#,-;  .    ,     ,   , .=;x#=                    \n");
	printf("          =##X-=+. ;..,. , ,; . .,-X+##+                    \n");
	printf("        ## =-x##x-;x-,===,;x+.=;;+##X;= =#                  \n");
	printf("        =##  #-.##################;.#. x##                  \n");
	printf("          Xx#++x#. .=======-==-  #X++#xX.                   \n");
	printf("\n");
}

void DrawSkeleton(void)
{
	printf("\n");
	printf("                      ;;,;;                       \n");
	printf("                    x+  #  +x                     \n");
	printf("                  #-    .=   -#                   \n");
	printf("                 -+      x.   +-                  \n");
	printf("                 #     ;   ,   #                  \n");
	printf("                 # .;       ,. #                  \n");
	printf("                 ## -.      - ##                  \n");
	printf("    ..           + x###   ###x +                  \n");
	printf("   #. ==        # +####   ####+ #                 \n");
	printf("   .+ . ---   -;# .x#X  -  X#x. #--               \n");
	printf("    +x,;.  --+ =#x.   .###.   .x#+ =,.            \n");
	printf("     ##,.-.  - xXXX X       X XXX+  X##XXX        \n");
	printf("    -+x#+.,-   x#x= #,# ###.# -x##  =xxX####=     \n");
	printf("  -#=..=##-.;;  ,#X =#######= X##   #++++xxX##-   \n");
	printf("  ##+-++=x#X,.-.  +# +=#-#-+ x##  +#+=++++xX###   \n");
	printf("    ##x+===X#x.,-   -       =+  ,##+==+++x##X     \n");
	printf("     .#x+=+=+##=.;-  ,#;   -+ ++#x+=++++x##.      \n");
	printf("       ##x====x#X;.-,  -X+--#xx+=+=+=x+###        \n");
	printf("      = .X#++===X#x.,-   X#x+++=+==++x##. =       \n");
	printf("    +;    ###x===+##=.,-   ##+===++x###    -==    \n");
	printf("  .++-  -,  -#X+++=x##-.-,  ;##+x+X#-  ;; .   #   \n");
	printf("  #  +  #     #X+++++##x,,-   +#XX#     #  #,.#   \n");
	printf("   +   =       #x+++++###x,,-   ##      #, X   #  \n");
	printf(" . #;,=# .     ,#xxxX#;  =#=.-,  ;       .-#   #  \n");
	printf(" ##xXX####      #==+X  -.+=+X,.-.  -       #.  #  \n");
	printf("  #+=+x##       #x-=- #x=XX x#+.,-  ;=-+-=-##x #  \n");
	printf("  #x==-+#       ##Xx#X.;.,.x####- -+++==-=,;####  \n");
	printf("  ##+X=+X##    #X====X#;,;#x-+X##X+=x##Xx##- +##  \n");
	printf("  #####xx###   #+-+XX==+++Xx+Xx=#+=#X+x===+#X X   \n");
	printf("    #######.  #XX+-+x+++++x++++XX##.X#X+x==X#;.#  \n");
	printf("      ----   ##+xXxx======+X#xX+=+## ;###=x#X-=-  \n");
	printf("              ##XxxXX#X#X#XX=++x##=    X####  +#  \n");
	printf("             ;#XXX#########X###XX#         +x##.  \n");
	printf("            .#xx+x#,        ##++=x#         --    \n");
	printf("            #=-=X#-          ##+xx##              \n");
	printf("            #-;=##            ##=--#              \n");
	printf("           ,##x+X##X#-        ##+-=#              \n");
	printf("          #;X####x;, #       ##xxx#-              \n");
	printf("          #         -X    XxX###xx#-+             \n");
	printf("          .=     +###     # .  -#+#X #            \n");
	printf("            ###XxxxX##    ;+         #            \n");
	printf("             #x=====x#X    ####X;--==             \n");
	printf("            -##Xx+==x##   ##x++xxX##              \n");
	printf("          .#==xXX+=###-  ##x=X###X##..            \n");
	printf("         ##-;--+x##xx    ##x=++==-,;x##           \n");
	printf("          #######         ###x===;,,  +#x         \n");
	printf("                           .;######xxx###         \n");
	printf("                                 ++++++           \n");
	printf("\n");
}

// TODO 12b: Implement function to draw player and enemy life (1p)
// Use a "for" loop to draw a bar using characters:
//	 Player Life: OOOOOOOOOOOOOOO
//   Enemy Life:  XXXXXXXXXXXXXXXXXXXX
// Make sure to check that player/enemy life is not lower than 0
void DrawPlayerEnemyLife(int pLife, int eLife)
{
	// ...
	printf("\nPlayer Life: ");
	for (int i = 0; i < pLife; i++)
	{
		printf("O");
	}

	printf("\nEnemy Life: ");
	for (int i = 0; i < eLife; i++)
	{
		printf("X");
	}
}