#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <ctype.h>


static int A[13][13];
static int V = 0;
static int X = 0;
static int Y = 0;
static char str[4];
static int temp;
char* temp2;
static bool isNum = false;
static int P = 0;
static int D = 0;
static int E = 0;

static inline bool isint(double d) {
    return d == (int64_t)d;
}


// (1 - 13) Приветствие
int main() {
    printf("                     CONDOT");
    printf("\n               CREATIVE COMPUTING");
    printf("\n             MORRISTOWN, NEW JERSEY");
    printf("\n\n");
    printf("\nTHIS PROGRAM WILL PLAY CONNECT THE DOTS UNH YOU.");
    printf("\nTHE GAME IS PLAYED ON A 4 X 4 ARRAY. WHEN");
    printf("\nYOU WANT TO MAKE A MOVE YOU MUST TYPE IN");
    printf("\nTHE COORDINATES OF THE SPACE BETUEEN THE TWO DOTS YOU");
    printf("\nWANT TO CONNECT. ENTER EACH OF YOUR MOVES BY TYPING");
    printf("\nTHE ROW NUMBER, A COMMA AND THE COLUMN NUMBER.");
    printf("\nTHE UPPER LEFT HAND CORNER OF THE ARRAY IS 1,1.");
    printf("\nHERE WE GO.\n");

    start_game();
}


// (40 - 200) Инициализация игры и игрового поня
void start_game() {
    for (int R = 1; R <= 12; R++)
    {
        for (int C = 1; C <= 12; C++)
        {
            if (R % 2 == 0) A[R][C] = 0;
            else if (C % 2 == 0) A[R][C] = 0;
            else A[R][C] = -50;
        }
    }
    
    print_play_area();
    printf("\nWrite h or H for help");
    input_x_y();
}


// (210 - 300) Получение координат, например: "1,2"
void input_x_y() {
    isNum = false;
    while (!isNum) {
        printf("\nYOUR MOVE:");
        scanf("%s", str);
        temp2 = str[0];
        if (temp2 == 'h' || temp2 == 'H') {
            printf("\n----------- HELP ------------");
            printf("\n     1,2     1,4     1,6     ");
            printf("\n 2,1     2,3     2,5     2,7");
            printf("\n     3,2     3,4     3,6     ");
            printf("\n 4,2     4,3     4,5     4,7");
            printf("\n     5,2     5,4     5,6     ");
            printf("\n 6,2     6,3     6,5     6,7");
            printf("\n     7,2     7,4     7,6     ");
            printf("\n-----------------------------");
            continue;
        }
        temp = atoi(&temp2);
        X = temp;
        temp2 = str[2];
        temp = atoi(&temp2);
        Y = temp;

        if (isint(X)) isNum = true;
        if ((X - 1) * (X - 7) > 0) isNum = false;
        X = X + 2;
        if ((Y - 1) * (Y - 7) > 0) isNum = false;
        Y = Y + 2;
        if ((X + Y + 1) % 2 == 1) isNum = false;
        if (A[X][Y] != 0) isNum = false;
        A[X][Y] = 50;

        if (isNum != true)
            printf("\nYOU REALLY DON'T WANT TO PUT A LINE THERE!!!!");
    }
    print_play_area();
    check_is_compite_area(); 
}


// (310 - 450) Проверка на полную территорию
void check_is_compite_area() {
    if (X % 2 == 0) {
        if (A[X][Y - 2] + A[X + 1][Y - 1] + A[X - 1][Y - 1] != 150) {
            if (A[X][Y + 2] + A[X + 1][Y + 1] + A[X - 1][Y + 1] != 150) {
                if (P == 1) {
                    input_x_y();
                }
            }
            else
            {
                A[X][Y + 1] = 1;
                input_x_y();
            }
        }
        else
        {
            P = 1;
            A[X][Y-1] = 1;
            if (A[X][Y+2] + A[X+1][Y+1] + A[X+1][Y-1] != 150) {
                if (P == 1) {
                    input_x_y();
                }
            }
            else
            {
                A[X][Y+1] = 1;
                input_x_y();
            }
        }
    }
    else {
        if (A[X-2][Y] + A[X-1][Y+1] + A[X-1][Y-1] != 150) {
            if (A[X+2][Y] + A[X+1][Y+1] + A[X+1][Y-1] != 150) {
                 if (P == 1) {
                     input_x_y();
                }
            }
            else
            {
                A[X + 1][Y] = 1;
                input_x_y();
            }
        }
        else
        {
            A[X-1][Y] = 1;
            P = 1;
            if (A[X+2][Y] + A[X+1][Y+1] + A[X+1][Y-1] != 150) {
                if (P == 1) {
                    input_x_y();
                }
            }
            else
            {
                A[X+1][Y] = 1;
                input_x_y();
            }
        }
    }
    choice_of_pc();
}


// (460 - 692) Ход ПК
void choice_of_pc() {
    printf("\nMY MOVE");
    for (int R = 4; R <= 10; R = R + 2)
    {
        for (int C = 4; C <= 10; C = C + 2)
        {
            if ((A[R-1][C] + A[R+1][C] + A[R][C-1] + A[R][C+1]) != 150)
            {
                continue;
            }
            else
            {
                A[R][C] = -1;
                if (A[R-1][C] != 0)
                {
                    p61(R, C);
                }
                else
                {
                    A[R-1][C] = 50;
                    if (A[R-3][C] + A[R-2][C-1] + A[R-2][C+1] != 150)
                    {
                        print_play_area();
                    }
                    else
                    {
                        A[R-2][C] = -1;
                        p61(R, C);
                    }
                }
            }
        }
    }
    if (E > 1) {
        p71();
    }
    pc_is_compite_area();
}
void p61(int R, int C) {
    if (A[R+1][C] != 0)
    {
        p62(R, C);
    }
    else
    {
        A[R+1][C] = 50;
        if (A[R+3][C] + A[R+2][C-1] + A[R+2][C+1] != 150)
        {
            print_play_area();
        }
        else
        {
            A[R+2][C] = -1;
            if (A[R][C-1] != 0)
            {
                if (A[R][C + 1] != 0) {
                    print_play_area();
                }
                else
                {
                    A[R][C + 1] = 50;
                    if (A[R][C + 3] + A[R - 1][C + 2] + A[R + 1][C + 2] != 150) {
                        print_play_area();
                    }
                    else
                    {
                        A[R][C + 2] = -1;
                        print_play_area();
                    }
                }
            }
            else
            {
                p62(R, C);
            }
        }
    }
}
void p62(int R, int C) {
    A[R][C-1] = 50;
    if (A[R][C-3] + A[R-1][C-2] + A[R+1][C+2] != 150)
    {
        print_play_area();
    }
    else
    {
        A[R][C-2] = -1;
        if (A[R][C+1] != 0)
        {
            print_play_area();
        }
        else
        {
            A[R][C+1] = 50;
            if (A[R][C+3] + A[R-1][C+2] + A[R+1][C+2] != 150)
            {
                print_play_area();
            }
            else
            {
                A[R][C+2] = -1;
                print_play_area();
            }
        }
    }
}


// (700 - 862) Проверка на полную территорию ПК
void pc_is_compite_area() {
    printf("\nRUN pc_is_compite_area");
    if (A[12 - X][12 - Y] != 0) {
        p71();
    }
    else
    {
        A[12 - X][12 - Y] = 50;
        if (E > 1) {
            ramdom_point();
        }
        else
        {
            print_play_area();
        }
        if (E > 1) {
            pc_is_compite_area();
        }
    }
    // 
    ramdom_point(); //870 - 920
}
void p71() {
    for (int R = 2; R <= 9; R++)
    {
        for (int C = 2; C <= 9; C++)
        {
            if ((R + C) % 2 == 0) {
                continue;
            }
            else
            {
                if (A[R][C] != 0) {
                    continue;
                }
                else
                {
                    if (R % 2 == 0) {
                        if (A[R][C-2] + A[R-1][C-1] + A[R+1][C-1] == 100) {
                            continue;
                        }
                        else if (A[R][C + 2] + A[R - 1][C + 2] + A[R + 1][C + 1] != 100) {
                            A[R][C] = 50;
                            input_x_y();
                        }
                    }
                    else
                    {
                        if (A[R-2][C] + A[R-1][C-1] + A[R-1][C+1] == 100) {
                            continue;
                        }
                        else if (A[R+2][C] + A[R+1][C-1] + A[R+1][C+1] == 100) {
                            continue;
                        }
                        else
                        {
                            A[R][C] = 50;
                            input_x_y();
                        }
                    }
                }
            }
        }
    }
}


// (870 - 920) Случайный ход ПК
void ramdom_point() {
    printf("\nRUN ramdom_point\n");
    int R = (int)(rand() % 8) + 3;
    int C = (int)(rand() % 8) + 3;
    if (R % 2 == 0) {
        if (C % 2 == 0) {
            if (A[R][C] != 0) {
                ramdom_point();
            }
            else
            {
                A[R][C] = 0;
                print_play_area();
            }
        }
        else
        {
            ramdom_point();
        }
    }
    else
    {
        if (C % 2 == 0) {
            A[R][C] = 0;
            print_play_area();
        }
        else
        {
            ramdom_point();
        }
    }
    input_x_y();
}


// (930 - 960) Конец или новая игра
void again() {
    printf("\nDO YOU WANT TO PLAY AGAIN (TYPE 1 FOR YES OR 2 FOR NO)");
    int B = 0;
    scanf("%d", B);
    if (B == 1)
        start_game();
}


// (1000-1320) Отрисовка игрового поля
void print_play_area() {
    printf("\n");
    P = 0;
    D = 0;
    E = 0;
    for (int R = 3; R <= 9; R++)
    {
        for (int C = 3; C <= 9; C++)
        {
            if (A[R][C] == 0) {
                printf("   ");
            }
            else if (A[R][C] == -50) {
                printf(" . ");
            }
            else if (A[R][C] == -1) {
                printf(" C ");
                D = D + A[R][C];
                E = E + 1;
            }
            else if (A[R][C] == 1) {
                printf(" H ");
                D = D + A[R][C];
                E = E + 1;
            }
            else if (R % 2 == 0) {
                printf(" : ");
            }
            else {
                printf(" - ");
            }
        }
        printf("\n");
    }
    printf("E = %d, D = %d\n", E, D);
    if (E >= 9) {
        if (D > 0) printf("\nYOU WON!!!");
        else printf("\nI WON");
        again();
    }
    else {
        return;
    }
}
