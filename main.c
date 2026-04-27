/*
 * ============================================================
 *  Project Title : Text Based Adventure Game
 *  Course        : CSE 115 - Programming Language I (Theory)
 *  Institution   : North South University
 *  Semester      : 1st Semester, Spring 2026
 *  Section       : 5
 *
 *  Group Members :
 *      1. Md. Shaharear Hossain Naffiz  - 2611327042
 *      2. Chowdhury Rounak Jahan Bushra - 2612545042
 *      3. Sumaiya Karim Ilma            - 2532746042
 *      4. Smita Elizabeth Biswas        - 2611961042
 *
 *  Submitted To  : M. Shifat-E-Rabbi
 *                  Department of Electrical and Computer Engineering
 *
 *  Description   : A text-based adventure game where the player
 *                  experiences their very first day at North South
 *                  University. Choices made throughout the game
 *                  affect three stats - Knowledge, Confidence,
 *                  and Mistakes - which together determine the
 *                  player's final outcome.
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 *  GLOBAL VARIABLES
 *  These three stats are updated throughout the game based on
 *  the player's choices and determine the final ending.
 * ============================================================ */
char playerName[50];
int  knowledge;       /* Points earned through academic decisions  */
int  confidence;      /* Points earned through social interactions */
int  mistakes;        /* Penalty counter for wrong choices         */

/* ============================================================
 *  FUNCTION DECLARATIONS (PROTOTYPES)
 * ============================================================ */
void mainMenu();
void startGame();
void gate();
void academicBlock();
void libraryPuzzle();
void clubFair();
void plaza();
void showEnding();
int  getValidChoice(int min, int max);

/* ============================================================
 *  UTILITY - getValidChoice()
 *  Keeps asking for input until the user enters a number
 *  within the accepted range [min, max].
 * ============================================================ */
int getValidChoice(int min, int max)
{
    int choice;
    while (1) {
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            return choice;
        }
        /* Flush invalid input from the buffer */
        while (getchar() != '\n');
        printf("  [!] Invalid input. Please enter a number between %d and %d: ", min, max);
    }
}

/* ============================================================
 *  SCENE 1 - NSU MAIN GATE
 *  The player arrives at NSU and must convince security to
 *  let them through. Different approaches yield different
 *  stat bonuses.
 * ============================================================ */
void gate()
{
    printf("\n");
    printf("  ============================================================\n");
    printf("                     SCENE 1 : NSU MAIN GATE                  \n");
    printf("  ============================================================\n");
    printf("\n");
    printf("  You arrive at the main entrance of North South University.\n");
    printf("  A security guard stops you at the gate.\n");
    printf("\n");
    printf("  Guard: \"This is a restricted campus. Where is your\n");
    printf("          admission proof?\"\n");
    printf("\n");
    printf("  What do you do?\n");
    printf("    1. Be honest and explain you are a new student.\n");
    printf("    2. Confidently state that you belong here.\n");
    printf("    3. Show your admission confirmation email.\n");
    printf("\n");
    printf("  Your choice: ");

    int choice = getValidChoice(1, 3);
    printf("\n");

    switch (choice) {
        case 1:
            printf("  You honestly explain your situation. The guard\n");
            printf("  appreciates your transparency and lets you through.\n");
            printf("  [+1 Confidence]\n");
            confidence += 1;
            break;
        case 2:
            printf("  Your calm confidence impresses the guard.\n");
            printf("  He nods and waves you in without further questions.\n");
            printf("  [+2 Confidence]\n");
            confidence += 2;
            break;
        case 3:
            printf("  You show your email on your phone. The guard\n");
            printf("  verifies it and compliments your preparedness.\n");
            printf("  [+1 Knowledge, +1 Confidence]\n");
            knowledge   += 1;
            confidence  += 1;
            break;
    }

    academicBlock();
}

/* ============================================================
 *  SCENE 2 - ACADEMIC BUILDING
 *  The player navigates to their first class. Taking the
 *  stairs leads to a bonus academic quiz with the professor.
 * ============================================================ */
void academicBlock()
{
    printf("\n");
    printf("  ============================================================\n");
    printf("               SCENE 2 : SAC ACADEMIC BUILDING                \n");
    printf("  ============================================================\n");
    printf("\n");
    printf("  You have located the SAC building where your CSE115\n");
    printf("  class is held. You need to reach the 4th floor.\n");
    printf("\n");
    printf("  How do you get there?\n");
    printf("    1. Take the lift.\n");
    printf("    2. Take the stairs.\n");
    printf("\n");
    printf("  Your choice: ");

    int choice = getValidChoice(1, 2);
    printf("\n");

    if (choice == 1) {
        printf("  Inside the lift you meet a friendly senior who\n");
        printf("  shares useful tips about surviving CSE115.\n");
        printf("  [+2 Confidence]\n");
        confidence += 2;
    } else {
        printf("  On the stairwell you bump into your professor!\n");
        printf("  She smiles and asks you a quick warm-up question.\n");
        printf("\n");
        printf("  Professor: \"Where do programmers primarily study\n");
        printf("              and practice their code at NSU?\"\n");
        printf("\n");
        printf("    1. The Computer Lab\n");
        printf("    2. The Central Library\n");
        printf("    3. The Cafeteria\n");
        printf("\n");
        printf("  Your answer: ");

        int answer = getValidChoice(1, 3);
        printf("\n");

        if (answer == 2) {
            printf("  Professor: \"Excellent! The library has dedicated\n");
            printf("  programming resources. I will see you in class.\"\n");
            printf("  [+2 Knowledge]\n");
            knowledge += 2;
        } else {
            printf("  Professor: \"Not quite, but do visit the library\n");
            printf("  - it has great programming resources.\"\n");
            printf("  [+1 Mistake]\n");
            mistakes++;
        }
    }

    libraryPuzzle();
}

/* ============================================================
 *  SCENE 3 - CENTRAL LIBRARY
 *  The player visits the library to print their schedule.
 *  A simple credit-calculation puzzle must be solved first.
 * ============================================================ */
void libraryPuzzle()
{
    printf("\n");
    printf("  ============================================================\n");
    printf("                  SCENE 3 : CENTRAL LIBRARY                   \n");
    printf("  ============================================================\n");
    printf("\n");
    printf("  After class you head to the Central Library to print\n");
    printf("  your course schedule. The self-service kiosk asks you\n");
    printf("  to solve a quick verification puzzle.\n");
    printf("\n");
    printf("  Puzzle: CSE115 carries 3 credits. If you are enrolled\n");
    printf("          in 4 courses this semester, what is your total\n");
    printf("          credit load?  (3 x 4 = ?)\n");
    printf("\n");
    printf("  Your answer: ");

    int answer;
    scanf("%d", &answer);
    printf("\n");

    if (answer == 12) {
        printf("  Correct! The kiosk unlocks and prints your schedule.\n");
        printf("  [+2 Knowledge]\n");
        knowledge += 2;
    } else {
        printf("  That is not right. A librarian steps over to help\n");
        printf("  you complete the process manually.\n");
        printf("  [+1 Mistake]\n");
        mistakes++;
    }

    clubFair();
}

/* ============================================================
 *  SCENE 4 - CLUB FAIR
 *  NSU clubs are recruiting. The player can join a club
 *  to earn stat bonuses before heading to the Plaza.
 * ============================================================ */
void clubFair()
{
    printf("\n");
    printf("  ============================================================\n");
    printf("                    SCENE 4 : CLUB FAIR                       \n");
    printf("  ============================================================\n");
    printf("\n");
    printf("  Outside the library you discover the annual NSU Club\n");
    printf("  Fair in full swing. Dozens of stalls line the walkway.\n");
    printf("\n");
    printf("  Which club catches your interest?\n");
    printf("    1. NSU Programming Club - competitive coding team.\n");
    printf("    2. NSU Cultural Club    - events, arts & heritage.\n");
    printf("    3. Skip the fair and walk toward the Plaza.\n");
    printf("\n");
    printf("  Your choice: ");

    int choice = getValidChoice(1, 3);
    printf("\n");

    switch (choice) {
        case 1:
            printf("  You sign up for the Programming Club. Senior\n");
            printf("  members immediately share study resources.\n");
            printf("  [+2 Knowledge, +1 Confidence]\n");
            knowledge   += 2;
            confidence  += 1;
            break;
        case 2:
            printf("  You join the Cultural Club. The lively atmosphere\n");
            printf("  and warm welcome boost your social confidence.\n");
            printf("  [+3 Confidence]\n");
            confidence += 3;
            break;
        case 3:
            printf("  You decide to skip the clubs and explore the Plaza.\n");
            break;
    }

    plaza();
}

/* ============================================================
 *  SCENE 5 - NSU PLAZA (FINAL SCENE)
 *  The last stop of the day. The player makes one final
 *  decision before the game calculates their ending.
 * ============================================================ */
void plaza()
{
    printf("\n");
    printf("  ============================================================\n");
    printf("                  SCENE 5 : NSU PLAZA                         \n");
    printf("  ============================================================\n");
    printf("\n");
    printf("  The sun is lower in the sky as you reach the iconic\n");
    printf("  NSU fountain plaza. Students are chatting and relaxing\n");
    printf("  after their classes. It is the perfect end to a long day.\n");
    printf("\n");
    printf("  What do you do for the rest of the afternoon?\n");
    printf("    1. Join a group of students chatting by the fountain.\n");
    printf("    2. Visit the Registrar's Office to learn about\n");
    printf("       add/drop, grading policy, and advising hours.\n");
    printf("    3. Head home - it has been a big enough day.\n");
    printf("\n");
    printf("  Your choice: ");

    int choice = getValidChoice(1, 3);
    printf("\n");

    switch (choice) {
        case 1:
            printf("  You spend an hour laughing and exchanging contacts\n");
            printf("  with CSE students. You already feel at home.\n");
            printf("  [+3 Confidence]\n");
            confidence += 3;
            break;
        case 2:
            printf("  The Registrar's staff walk you through key academic\n");
            printf("  policies. You leave feeling informed and prepared.\n");
            printf("  [+3 Knowledge]\n");
            knowledge += 3;
            break;
        case 3:
            printf("  You take a quiet moment by the fountain, then head\n");
            printf("  for the gate. A calm ending to an eventful first day.\n");
            break;
    }

    showEnding();
}

/* ============================================================
 *  ENDING - showEnding()
 *  Displays the player's final stats and determines which
 *  of four possible endings they have achieved.
 * ============================================================ */
void showEnding()
{
    printf("\n");
    printf("  ============================================================\n");
    printf("                  END OF YOUR FIRST DAY AT NSU                \n");
    printf("  ============================================================\n");
    printf("\n");
    printf("  FINAL STATS\n");
    printf("  ------------\n");
    printf("  Knowledge  : %d\n", knowledge);
    printf("  Confidence : %d\n", confidence);
    printf("  Mistakes   : %d\n", mistakes);
    printf("\n");
    printf("  RESULT\n");
    printf("  ------\n");

    if (knowledge >= 6 && confidence >= 6) {
        printf("  *** LEGENDARY FRESHMAN ***\n");
        printf("  You mastered academics AND social life on day one.\n");
        printf("  Your classmates are already calling you a legend.\n");
    } else if (knowledge >= 3 || confidence >= 3) {
        printf("  *** PROMISING STUDENT ***\n");
        printf("  You had a solid first day. Keep up the momentum\n");
        printf("  and NSU will treat you very well.\n");
    } else if (mistakes < 2) {
        printf("  *** STEADY STARTER ***\n");
        printf("  A quiet but careful first day. With time and effort\n");
        printf("  you will find your stride at NSU.\n");
    } else {
        printf("  *** CHAOTIC FIRST DAY ***\n");
        printf("  Things did not go perfectly - but every NSU student\n");
        printf("  has a story like this. Tomorrow will be better!\n");
    }

    printf("\n");
    printf("  Thank you for playing, %s!\n", playerName);
    printf("  Good luck with your semester at North South University.\n");
    printf("\n");
    printf("  ============================================================\n");
}

/* ============================================================
 *  startGame()
 *  Initialises stats, collects the player's name, and
 *  launches the first scene.
 * ============================================================ */
void startGame()
{
    /* Reset stats for a fresh run */
    knowledge  = 0;
    confidence = 0;
    mistakes   = 0;

    printf("\n  Enter your name: ");
    scanf("%49s", playerName);

    printf("\n");
    printf("  ============================================================\n");
    printf("   Welcome to North South University, %s!\n", playerName);
    printf("  ============================================================\n");
    printf("\n");
    printf("  Today is your very first day on campus.\n");
    printf("  Every choice you make will shape your experience.\n");
    printf("  Good luck!\n");

    gate();
}

/* ============================================================
 *  mainMenu()
 *  Top-level menu that persists until the player exits.
 * ============================================================ */
void mainMenu()
{
    int choice;

    do {
        printf("\n");
        printf("  ============================================================\n");
        printf("                   NSU CAMPUS ADVENTURE                       \n");
        printf("              A Text-Based Adventure Game                      \n");
        printf("                  CSE115 - Group Project                         \n");
        printf("  ============================================================\n");
        printf("\n");
        printf("    1. Start New Game\n");
        printf("    2. How to Play\n");
        printf("    3. About This Project\n");
        printf("    4. Exit\n");
        printf("\n");
        printf("  Your choice: ");

        choice = getValidChoice(1, 4);
        printf("\n");

        switch (choice) {
            case 1:
                startGame();
                break;

            case 2:
                printf("  HOW TO PLAY\n");
                printf("  -----------\n");
                printf("  - Read each scene description carefully.\n");
                printf("  - Type the number of your chosen option and press Enter.\n");
                printf("  - Your choices affect three stats:\n");
                printf("      Knowledge  - gained through academic decisions.\n");
                printf("      Confidence - gained through social interactions.\n");
                printf("      Mistakes   - increased by wrong answers.\n");
                printf("  - At the end of the game your stats determine\n");
                printf("    which of four possible endings you receive.\n");
                printf("  - Try different choices for a new experience!\n");
                break;

            case 3:
                printf("  ABOUT THIS PROJECT\n");
                printf("  ------------------\n");
                printf("  NSU Campus Adventure is a text-based interactive\n");
                printf("  story game developed as a group project for the\n");
                printf("  CSE115 (Programming Language I - Theory) course\n");
                printf("  at North South University.\n");
                printf("\n");
                printf("  The game simulates a new student's first day on\n");
                printf("  campus through five scenes: the Main Gate, the\n");
                printf("  Academic Building, the Central Library, the Club\n");
                printf("  Fair, and the NSU Plaza.\n");
                printf("\n");
                printf("  Language : C (Standard C99)\n");
                break;

            case 4:
                printf("  Exiting the game. Best of luck at NSU!\n");
                break;
        }

    } while (choice != 4);
}

/* ============================================================
 *  MAIN FUNCTION - Program entry point
 * ============================================================ */
int main()
{
    mainMenu();
    return 0;
}


