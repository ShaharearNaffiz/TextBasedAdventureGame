#include <stdio.h>

char playerName[50];

void secretEnding() {
    printf("\n==============================================\n");
    printf("      SECRET ENDING - LEGENDARY HERO!\n");
    printf("==============================================\n");
    printf("Congratulations %s! You discovered the hidden treasure!\n", playerName);
    printf("The ancient spirits bless you with immortality.\n");
    printf("You become the guardian of the cursed forest!\n");
    printf("\n--- SECRET ENDING UNLOCKED ---\n");
}

void winEnding() {
    printf("\n==============================================\n");
    printf("   CONGRATULATIONS %s! YOU HAVE WON!\n", playerName);
    printf("==============================================\n");
    printf("You successfully escaped the cursed forest.\n");
    printf("The village celebrates your bravery!\n");
    printf("\n--- GAME OVER ---\n");
}

void alternateEnding() {
    printf("\n==============================================\n");
    printf("        ALTERNATE ENDING - PEACEFUL PATH\n");
    printf("==============================================\n");
    printf("%s, you chose wisdom over violence.\n", playerName);
    printf("The forest spirits grant you safe passage home.\n");
    printf("You leave the forest forever changed.\n");
    printf("\n--- GAME OVER ---\n");
}

void gameOverEnding() {
    printf("\n==============================================\n");
    printf("      GAME OVER %s - YOU LOST!\n", playerName);
    printf("==============================================\n");
    printf("Your journey ends here. Better luck next time!\n");
    printf("\n--- GAME OVER ---\n");
}

void templeScene() {
    int choice;

    printf("\n--- ANCIENT TEMPLE ---\n");
    printf("%s, you enter a magnificent ancient temple.\n", playerName);
    printf("Golden statues line the walls. An altar stands in the center.\n");
    printf("On the altar, there is a glowing orb.\n\n");
    printf("What do you do?\n");
    printf("1. Touch the glowing orb\n");
    printf("2. Leave the temple quietly\n");
    printf("3. Search behind the altar\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou touch the orb. It explodes with blinding light!\n");
        gameOverEnding();
    } else if (choice == 2) {
        printf("\n%s, you respectfully leave the temple.\n", playerName);
        printf("The forest spirits appreciate your wisdom.\n");
        alternateEnding();
    } else if (choice == 3) {
        printf("\nBehind the altar, you find a hidden passage!\n");
        printf("You discover the legendary treasure of the ancients!\n");
        secretEnding();
    } else {
        printf("\nInvalid choice! You accidentally trigger a trap.\n");
        gameOverEnding();
    }
}

void mountainPeakScene() {
    int choice;

    printf("\n--- MOUNTAIN PEAK ---\n");
    printf("%s, you reach the snowy peak of the mountain.\n", playerName);
    printf("The view is breathtaking. You see a temple in the distance.\n");
    printf("A narrow path leads down towards it.\n\n");
    printf("What do you do?\n");
    printf("1. Follow the path to the temple\n");
    printf("2. Try to climb down the other side\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you carefully walk down the path.\n", playerName);
        printf("The ancient temple awaits you.\n");
        templeScene();
    } else if (choice == 2) {
        printf("\nThe rocks are too slippery! You fall down the mountain.\n");
        gameOverEnding();
    } else {
        printf("\nInvalid choice! You slip on the ice and fall.\n");
        gameOverEnding();
    }
}

void mountainScene() {
    int choice;

    printf("\n--- STEEP MOUNTAIN ---\n");
    printf("%s, you stand at the base of a tall mountain.\n", playerName);
    printf("There is a winding path going up and a cave entrance.\n\n");
    printf("What do you do?\n");
    printf("1. Climb up the mountain path\n");
    printf("2. Enter the cave\n");
    printf("3. Rest here for a while\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you begin climbing the mountain.\n", playerName);
        printf("The air gets colder as you ascend.\n");
        mountainPeakScene();
    } else if (choice == 2) {
        printf("\nYou enter the cave but it's a bear's den!\n");
        gameOverEnding();
    } else if (choice == 3) {
        printf("\nWhile resting, a rockslide buries you!\n");
        gameOverEnding();
    } else {
        printf("\nInvalid choice! You wander off and get lost.\n");
        gameOverEnding();
    }
}

void lakeScene() {
    int choice;

    printf("\n--- CRYSTAL LAKE ---\n");
    printf("%s, you arrive at a beautiful crystal clear lake.\n", playerName);
    printf("The water sparkles in the sunlight.\n");
    printf("You see a boat and a path around the lake.\n\n");
    printf("What do you do?\n");
    printf("1. Take the boat across the lake\n");
    printf("2. Walk around the lake\n");
    printf("3. Drink the lake water\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you row the boat safely across.\n", playerName);
        printf("On the other side, you see a mountain.\n");
        mountainScene();
    } else if (choice == 2) {
        printf("\nThe path around the lake leads to a dead end.\n");
        printf("Wild wolves appear and chase you!\n");
        gameOverEnding();
    } else if (choice == 3) {
        printf("\nThe water was cursed! You feel dizzy and collapse.\n");
        gameOverEnding();
    } else {
        printf("\nInvalid choice! You slip into the lake and drown.\n");
        gameOverEnding();
    }
}

void puzzleScene() {
    int answer;

    printf("\n--- PUZZLE CHAMBER ---\n");
    printf("%s, you enter a mysterious chamber with an ancient riddle.\n", playerName);
    printf("The door ahead is locked. Solve the riddle to proceed.\n\n");
    printf("RIDDLE: What is 7 x 2?\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 14) {
        printf("\nCorrect %s! The door unlocks with a loud click.\n", playerName);
        printf("You step through and find yourself back at the village.\n");
        winEnding();
    } else {
        printf("\nWrong answer! The chamber begins to collapse!\n");
        gameOverEnding();
    }
}

void villageScene() {
    int choice;

    printf("\n--- VILLAGE SQUARE ---\n");
    printf("%s, you arrive at a small village. The villagers look worried.\n", playerName);
    printf("An old man approaches you.\n\n");
    printf("Old Man: 'Brave traveler, a monster guards the exit.\n");
    printf("Only those who solve the ancient puzzle can pass safely.'\n\n");
    printf("What do you do?\n");
    printf("1. Go to the puzzle chamber\n");
    printf("2. Try to fight the monster alone\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        puzzleScene();
    } else if (choice == 2) {
        printf("\n%s, you attempt to fight but you're not strong enough.\n", playerName);
        gameOverEnding();
    } else {
        printf("\nInvalid choice! You wander aimlessly and get lost.\n");
        gameOverEnding();
    }
}

void bridgeScene() {
    int choice;

    printf("\n--- ROPE BRIDGE ---\n");
    printf("%s, you find an old rope bridge crossing a deep canyon.\n", playerName);
    printf("The bridge looks unstable. Below, you see sharp rocks.\n\n");
    printf("What do you do?\n");
    printf("1. Cross the bridge carefully\n");
    printf("2. Look for another way around\n");
    printf("3. Jump across the narrow part\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you carefully cross the bridge step by step.\n", playerName);
        printf("On the other side, you see a village!\n");
        villageScene();
    } else if (choice == 2) {
        printf("\nYou search for hours but there's no other way.\n");
        printf("Exhausted, you collapse from hunger.\n");
        gameOverEnding();
    } else if (choice == 3) {
        printf("\nYou attempt to jump but miss! You fall into the canyon.\n");
        gameOverEnding();
    } else {
        printf("\nInvalid choice! The bridge breaks under your weight.\n");
        gameOverEnding();
    }
}

void riverScene() {
    int choice;

    printf("\n--- RAPID RIVER ---\n");
    printf("%s, you reach a wide river with fast-flowing water.\n", playerName);
    printf("There is a broken bridge and a small raft nearby.\n\n");
    printf("What do you do?\n");
    printf("1. Use the raft to cross\n");
    printf("2. Try to swim across\n");
    printf("3. Follow the river downstream\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you safely paddle across using the raft.\n", playerName);
        printf("Ahead, you see another bridge over a canyon.\n");
        bridgeScene();
    } else if (choice == 2) {
        printf("\nThe current is too strong! You are swept away.\n");
        gameOverEnding();
    } else if (choice == 3) {
        printf("\nYou follow the river and discover a peaceful lake.\n");
        lakeScene();
    } else {
        printf("\nInvalid choice! You slip and fall into the river.\n");
        gameOverEnding();
    }
}

void caveScene() {
    int choice;

    printf("\n--- DARK CAVE ---\n");
    printf("%s, you enter a dark and damp cave.\n", playerName);
    printf("You hear water dripping and see two tunnels ahead.\n\n");
    printf("Which tunnel do you take?\n");
    printf("1. Left tunnel (you hear wind)\n");
    printf("2. Right tunnel (you see a faint light)\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you follow the left tunnel and feel fresh air.\n", playerName);
        printf("The tunnel leads you to a river.\n");
        riverScene();
    } else if (choice == 2) {
        printf("\nYou follow the light but it was a trap!\n");
        printf("You fall into a deep pit filled with spikes.\n");
        gameOverEnding();
    } else {
        printf("\nInvalid choice! You stumble in the darkness and hit your head.\n");
        gameOverEnding();
    }
}

void forestScene() {
    int choice;

    printf("\n--- MYSTERIOUS FOREST ---\n");
    printf("%s, you find yourself in a dense, dark forest.\n", playerName);
    printf("The trees are tall and the path ahead splits into two directions.\n\n");
    printf("Where do you want to go?\n");
    printf("1. Go left towards the dark cave\n");
    printf("2. Go right towards the open field\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n%s, you walk towards the dark cave...\n", playerName);
        caveScene();
    } else if (choice == 2) {
        printf("\nYou walk into the open field.\n");
        printf("Suddenly, wild wolves surround you!\n");
        gameOverEnding();
    } else {
        printf("\nInvalid choice! You get lost in the forest forever.\n");
        gameOverEnding();
    }
}

void startGame() {
    printf("==============================================\n");
    printf("   WELCOME TO THE CURSED FOREST ADVENTURE\n");
    printf("==============================================\n");

    // Ask for player's name
    printf("\nBefore we begin, what is your name?\n");
    printf("Enter your name: ");
    scanf("%s", playerName);

    printf("\n==============================================\n");
    printf("Hello %s! Your adventure begins now...\n", playerName);
    printf("==============================================\n");
    printf("\nYou wake up in a mysterious forest with no memory.\n");
    printf("Your goal is to find your way out and return home.\n");
    printf("Make wise choices to survive!\n");
    printf("\nPress Enter to begin your adventure...");
    getchar();  // Clear the input buffer
    getchar();  // Wait for Enter key

    forestScene();
}

int main() {
    startGame();
    return 0;
}
