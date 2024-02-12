#include "pohyb.h"

//move top
int position(int column, int row, int Columns){    //int COLUMNS je blbost to COLUMNS je hodnota int columns = COLUMNS; bz bylo good
    int COLUMNS = Columns;
    return (row*COLUMNS + column);
    
    }


void hore(int* matica, int Columns, int Rows) {
    int COLUMNS = Columns;
    int ROWS = Rows;
	for (int i = 1; i < COLUMNS; i++) 
		for (int j = 0; j < ROWS; j++){
			if (matica[position(i,j,COLUMNS)] != 0){
				for (int k = i; k > 0; --k){
					if (matica[position(k-1,j,COLUMNS)] == 0) {
						matica[position(k-1,j,COLUMNS)] = matica[position(k,j,COLUMNS)];
						matica[position(k,j,COLUMNS)] = 0;
                    }
                }
            }
}
}

//move top, count same nums, move top
void hore_sucet(int* matica, int Columns, int Rows, int* SCORE){   //tz rows a columns jsou zbytečný makra se nedávaj jako argumenty jsou globálni
    int COLUMNS = Columns;
    int ROWS = Rows;
    hore(matica,COLUMNS,ROWS);
    for (int i = 1; i < COLUMNS; i++) 
		for (int j = 0; j < ROWS; j++) 
			if (matica[position(i,j,COLUMNS)] != 0) 
				if (matica[position(i-1,j,COLUMNS)] == matica[position(i,j,COLUMNS)]) {
                    *SCORE+=(2*matica[position(i-1,j,COLUMNS)]);
					matica[position(i-1,j,COLUMNS)]+=  matica[position(i,j,COLUMNS)];
					 matica[position(i,j,COLUMNS)] = 0;
				}	 
    hore(matica,COLUMNS,ROWS);
}
//move down
void dole(int* matica, int Columns, int Rows) {
    int COLUMNS = Columns;
    int ROWS = Rows;
	for (int i = 0; i < COLUMNS; i++) 
		for (int j = ROWS-2; j >=0; j--) 
			if (matica[position(j,i,COLUMNS)] != 0) 
				for (int k = j; k < ROWS -1; ++k) 
					if (matica[position(k+1,i,COLUMNS)] == 0) {
						matica[position(k+1,i,COLUMNS)] = matica[position(k,i,COLUMNS)];
						matica[position(k,i,COLUMNS)] = 0;
					}
}
//move down, count same nums,move down
void dole_sucet(int* matica, int Columns, int Rows, int* SCORE) {
    int COLUMNS = Columns;
    int ROWS = Rows;
    dole(matica,COLUMNS,ROWS);
    for(int i=0;i<COLUMNS;i++)
        for (int j = ROWS-2; j >=0; j--)
            if (matica[position(j,i,COLUMNS)] != 0)
                if(matica[position(j,i,COLUMNS)]==matica[position(j+1,i,COLUMNS)]){
                    *SCORE+=(2*matica[position(j+1,i,COLUMNS)]);
                    matica[position(j+1,i,COLUMNS)]+=  matica[position(j,i,COLUMNS)];
                    matica[position(j,i,COLUMNS)] = 0;
                }

    dole(matica,COLUMNS,ROWS);

}
//move right
void vpravo(int* matica, int Columns, int Rows) {
    int COLUMNS = Columns;
    int ROWS = Rows;
	for (int i = 0; i < COLUMNS; i++) 
		for (int j = ROWS - 2; j >= 0; j--) 
			if (matica[position(i,j,COLUMNS)] != 0) 
				for (int k = j; k < ROWS - 1; ++k) 
					if (matica[position(i,k+1,COLUMNS)] == 0) {
						matica[position(i,k+1,COLUMNS)] = matica[position(i,k,COLUMNS)];
						matica[position(i,k,COLUMNS)] = 0;
					}
}
//move right,count,move right
void vpravo_sucet(int* matica, int Columns, int Rows, int* SCORE) {
    int COLUMNS = Columns;
    int ROWS = Rows;
     vpravo(matica,COLUMNS,ROWS);
    for(int i=0;i<COLUMNS;i++)
        for (int j = ROWS-2;j>=0; j--)
            if (matica[position(i,j,COLUMNS)] != 0)
                if(matica[position(i,j,COLUMNS)]==matica[position(i,j+1,COLUMNS)]){
                    *SCORE+=(2*matica[position(i,j+1,COLUMNS)]);
                    matica[position(i,j+1,COLUMNS)]+=  matica[position(i,j,COLUMNS)];
                    matica[position(i,j,COLUMNS)] = 0;
                }
    vpravo(matica,COLUMNS,ROWS);
}
//move left
void vlavo(int* matica, int Columns, int Rows) {
    int COLUMNS = Columns;
    int ROWS = Rows;
	for (int i = 0; i < COLUMNS; i++) 
		for (int j = 1; j < ROWS; j++) 
			if (matica[position(i,j,COLUMNS)] != 0) 
				for (int k = j; k > 0; --k) 
					if (matica[position(i,k-1,COLUMNS)] == 0) {
						matica[position(i,k-1,COLUMNS)] = matica[position(i,k,COLUMNS)];
						matica[position(i,k,COLUMNS)] = 0;
					}
}
void vlavo_sucet(int* matica, int Columns, int Rows, int* SCORE){
    int COLUMNS = Columns;
    int ROWS = Rows;
     vlavo(matica,COLUMNS,ROWS);
    for(int i=0;i<COLUMNS;i++)
        for (int j = 1; j < ROWS; j++)
            if (matica[position(i,j,COLUMNS)] != 0)
                if(matica[position(i,j,COLUMNS)]==matica[position(i,j-1,COLUMNS)]){
                    *SCORE+=(2*matica[position(i,j-1,COLUMNS)]);
                    matica[position(i,j-1,COLUMNS)]+=  matica[position(i,j,COLUMNS)];
                    matica[position(i,j,COLUMNS)] = 0;
                }
    vlavo(matica,COLUMNS,ROWS);
    
}
