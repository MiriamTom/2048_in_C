#include "operacie.h"

int position2(int column, int row,int columns){
    int COLUMNS = columns;
    return (row*COLUMNS + column);
    
    }
int random_num(int min, int max){
    
    return min + rand() % (max+1 - min);
    }
int nahodne_2_4(){
    
    return (random_num(0,3) % 2 == 0) ? 2 : 4;
    
    }

int check_zeros(int* matica, int COLUMNS, int ROWS){
    bool zero = 0;
	for (int i = 0; i < COLUMNS; i++) 
		for (int j = 0; j < ROWS; j++) 
			if (matica[position2(i,j,COLUMNS)] == 0)
                zero = 1;
	return zero;
}

int bez_pohybu(int* matica, int COLUMNS, int ROWS){
    bool moves=0;
    for (int i = 0; i < COLUMNS-1; i++) 
		for (int j = 0; j < ROWS; j++) 
			if (matica[position2(i,j,COLUMNS)] == matica[position2(i+1,j,COLUMNS)])
                moves = 1;
    for (int i = 0; i < COLUMNS; i++) 
		for (int j = 0; j < ROWS-1; j++) 
			if (matica[position2(i,j,COLUMNS)] == matica[position2(i,j+1,COLUMNS)])
                moves = 1;
	
    return moves;
}

int prehra(int* matica, int COLUMNS, int ROWS){
    bool lose=0;
    if(check_zeros(matica, COLUMNS, ROWS)==0)
        if (!bez_pohybu(matica, COLUMNS, ROWS))
            lose=1;
    return lose;   
}

int vyhra(int* matica, int COLUMNS, int ROWS) {
	bool win = 0;
	for (int i = 0; i < COLUMNS; i++) 
		for (int j = 0; j < ROWS; j++) 
			if (matica[position2(i,j,COLUMNS)] == 2048) win = 1;
	return win;
}


void nahodne_cislo(int* matica, int COLUMNS, int ROWS) {
    int x;
    int y;
    bool ok=false;
    if(check_zeros(matica, COLUMNS, ROWS)){
        do{
            x=random_num(0,COLUMNS-1);
            y=random_num(0,ROWS-1);
            if(matica[position2(x,y,COLUMNS)]==0){
                matica[position2(x,y,COLUMNS)]=nahodne_2_4();
                ok=true;
            }
        }while(!ok);
           
    }
}
int* vytvor_maticu(int COLUMNS, int ROWS) {
    int* matica = calloc(ROWS*COLUMNS, sizeof(int));
    nahodne_cislo(matica, COLUMNS, ROWS);
    nahodne_cislo(matica, COLUMNS, ROWS);
    return matica;
}