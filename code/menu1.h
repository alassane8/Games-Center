#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu1(unsigned char ** mat2, unsigned char ** mat2_bis, char *pseudo){
    
    //Variables definition 
    int difficulty = 0;
    int menu_options = 0;
    int i;
    char pseudo[100];
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    // Player 1
    gotoligcol(0, 30);
    SetConsoleTextAttribute(hConsole, 6);
    printf("/////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("S U D O K U");
    SetConsoleTextAttribute(hConsole, 6);
    printf(" ///////////////////////////////////////\n");
    gotoligcol(8, 30);
    SetConsoleTextAttribute(hConsole, 6);
    printf("/////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("M A I N   M E N U");
    SetConsoleTextAttribute(hConsole, 6);
    printf(" ////////////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);

    sudokuascii();

    //Copyrights
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);

    gotoligcol(10, 70);
    printf("1. Play");
    gotoligcol(11, 70);
    printf("2. Load game");
    gotoligcol(12, 70);
    printf("3. Rules");
    gotoligcol(13, 70);
    printf("4. Exit ");
    gotoligcol(14, 70);
    fflush(stdin);
    scanf("%d", &menu_options);

    // Inputs mistakes
    while (menu_options != 1 && menu_options != 2 && menu_options != 3 && menu_options != 4)
    {
        gotoligcol(25, 120);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(14, 70);
        printf("  ");
        gotoligcol(14, 70);
        fflush(stdin);
        scanf("%d", &menu_options);
    }

    // Play 
    if (menu_options == 1)
    {
        // Sudoku level
        gotoligcol(15, 70);
        SetConsoleTextAttribute(hConsole, 6);
        printf("Choose Sudoku difficulty:");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(16, 70);
        printf("1. Easy");
        gotoligcol(17, 70);
        printf("2. Medium");
        gotoligcol(18, 70);
        printf("3. Hard");
        gotoligcol(19, 70);
        fflush(stdin);
        scanf("%d", &difficulty);

        while (difficulty != 1 && difficulty != 2 && difficulty != 3)
        {
            gotoligcol(25, 120);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(19, 70);
            printf("  ");
            gotoligcol(19, 70);
            fflush(stdin);
            scanf("%d", &difficulty);
        }

        if(difficulty == 1){

            system("cls");
            initialisation_matrice1(mat2, mat2_bis);
            easy(mat2, mat2_bis, pseudo);
            decors1(mat2);
            play1(mat2, mat2_bis, pseudo);   
        }

        if(difficulty == 2){

            system("cls");
            initialisation_matrice1(mat2, mat2_bis);
            medium(mat2, mat2_bis, pseudo);
            decors1(mat2);
            play1(mat2, mat2_bis, pseudo);   
        }

        if(difficulty == 3){

            system("cls");
            initialisation_matrice1(mat2, mat2_bis);
            hard(mat2, mat2_bis, pseudo);
            decors1(mat2);
            play1(mat2, mat2_bis, pseudo);    
        }
    }
    
    // Load game
    if (menu_options == 2)
    {
        system("cls");
        choice_loading_game1(mat2, maté_bis, pseudo);
    }

    // Rules
    if (menu_options == 3)
    {
        system("cls");
        rules1(mat2, mat2_bis, pseudo);
    }

    // Exit
    else if (menu_options == 4)
    {
        system("cls");
        exitgame1(mat2, mat2_bis, pseudo);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
