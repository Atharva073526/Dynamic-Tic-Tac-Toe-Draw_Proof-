# include<stdio.h>

void displayboard();
char pos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int temp1[100], temp2[100];

int status(char );

int main(){
    int player = 1, stat, i, p=0, g=0, val1, val2, x, y;
    char mark, b, c;

    displayboard();
    
    while(stat!=1){
        run:
        player = ((player%2==0)?2:1);

        mark = ((player==1)?'X':'O');

        printf ("Enter position player %d: ", player);
        scanf ("%d", &i);

        if (i<1 || i>9){
            printf ("Cheating!!");
            if (player==1)
                printf ("Player 2 wins");
            else
                printf ("Player 1 wins");
        }

        if (pos[i]=='X' || pos[i]=='O'){
            printf ("Occupied!\n");
            goto run;
        }

        if (player==1){
            temp1[p] = i;
        }
        if (player==2){
            temp2[g] = i;
        }

        pos[i] = mark;

        stat = status(mark);

        if (p<3 || g<3)
            displayboard();

        if (stat==1){
            displayboard();
            printf ("Player %d wins", player);
        }

        else{
            if (p>3){
                x = p-4;
                val1 = temp1[x];
                b = val1 +'0';
                pos[val1] = b;
                displayboard();
            }

            if (g>3){
                y = g-4;
                val2 = temp2[y];
                c = val2 + '0';
                pos[val2] = c;
                displayboard();
            }
        }

        player++;
        p += 1;
        g += 1;
    }

    return 0;
}

void displayboard(){
    
    printf ("---Tic-Tac-Toe---\n\n");

    printf("      |      |      \n");
    printf("    %c |   %c  |    %c   \n", pos[1], pos[2], pos[3]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("    %c |   %c  |   %c   \n", pos[4], pos[5], pos[6]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("    %c |   %c  |   %c  \n", pos[7], pos[8], pos[9]);
    printf("      |      |      \n");
}

int status(char mark){
    int i = 1, done=0;

    if ((pos[1]==mark && pos[2]==mark && pos[3]==mark)||(pos[4]==mark && pos[5]==mark && pos[6]==mark)||(pos[7]==mark && pos[8]==mark && pos[9]==mark)||(pos[1]==mark && pos[4]==mark & pos[7]==mark)||(pos[2]==mark && pos[5]==mark && pos[8] == mark)||(pos[3]==mark && pos[6]==mark && pos[9]==mark)||(pos[1]==mark && pos[5]==mark && pos[9]==mark)||(pos[3]==mark && pos[5]==mark && pos[7]==mark))
        return 1;

    return 0;
}