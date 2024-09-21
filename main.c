#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

#define ROW 30
#define COLS 30
#define food_symbol "*"
#define snake_body "O"
#define MAX_LENGTH 50
int i,j,score = 0, gameover,x,y,food_X,food_y,move;
int snake_length = 1;

void Rules(){
    printf("Rules:");
    printf("\n1.If you hit the wall game over\n2.Eating the food increases the score by 5");
}



void setup(){
    gameover = 0;
label1:
    food_X = rand() % COLS-1;
    if (food_X == 0)
        goto label1;
    
    
label2: 
    food_y = rand() % ROW-1;
    if (food_y == 0)
        goto label2;

}


void board(){
    
    system("cls");
    
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COLS; j++){
            if (i == 0 || i == COLS-1 || j==0 || j== ROW-1)
            {
                printf("+");
            }
            else{
                if(i == x && j == y) 
                    printf(snake_body); 
                else if (i == food_X && j == food_y)
                    printf(food_symbol);
                
                else printf(" ");       
            }
        }
        printf("\n");

       
    }
    printf("\nSCORE = %d ",score);
    printf("\nTO exit press x ");
    
    
}

void input()
 {
    if(kbhit()){
        sleep(0.1);
        switch(getch())
        {
        case 'w':
            move=1;
            break;
        case 's':
            move=2;
            break;
        case 'a':
            move=3;
            break;
        case 'd':
            move=4;
            break;
        case 'x':
            gameover=1;
        
        }
    }
}

void logic(){
    sleep(0.9);
    switch(move)
        {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
        default: 
        break; 
        }
    

    if (x==food_X && y==food_y)
    {
        score = score+5;
        setup();
    }
    if (x <=0 || x >= ROW ||y<=0|| y >= COLS)
    {
        gameover=1;
        printf("\nGame Over You hit the wall");
    }
    
    

    
}

int main()
{
    
    printf("Welcome TO Snake Game");
    Rules();
    printf("\nPress space to start \nPress x to exit");
    char key = getch();

    if (key == 32)
    {
        setup();
        x = ROW/2;
        y = COLS/2;
    
        while (!gameover)
        {
            //logic for my board
            input();
            board();
            logic();
        }
    }
   
    return 0;
}