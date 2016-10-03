/////////////////////////////////////////////////////////////////////////
// Sample Allegro program to help with game of life
/////////////////////////////////////////////////////////////////////////

#include <allegro.h>

#include <iostream>
using namespace std;
#include <apmatrix.h>

#define COLUMNS 64
#define ROWS 48
#define SQUARE_SIZE 10

apmatrix<bool> grid(ROWS, COLUMNS);  // 20 pixel squares

int main(void) {
	int count = 0;
	int colour;
    int x,y;
   	BITMAP *buffer = NULL;
  
    //initialize some stuff
    allegro_init(); 
    install_keyboard(); 
    install_timer();
   
   	buffer = create_bitmap(640, 480);
	if (!buffer)
		return 1;
 
    srand(time(NULL));

    //initialize video mode to 640x480
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, COLUMNS*SQUARE_SIZE, ROWS*SQUARE_SIZE, 0, 0)) {
        allegro_message(allegro_error);
        return 1;
    }
   	const int COLOUR_ALIVE = makecol(0, 255, 0);	// Green
	const int COLOUR_DEAD =  makecol(255, 0, 0);	// Red	
	
   // set_color_depth(32);
    while(!key[KEY_ESC]) {
     	for (int i=0; i<ROWS; i++) {
			for (int j=0; j<COLUMNS; j++) {
				// make vertical bars
				grid[i][j] = ((((j+count) % 4)) == 3); 
			}	
		}	
	   	clear(buffer);
       	for (int i=0; i<ROWS; i++) {
			for (int j=0; j<COLUMNS; j++) {
				x = i * SQUARE_SIZE;
    			y = j * SQUARE_SIZE;
    			if (grid[i][j]) 
    				colour = COLOUR_ALIVE;
    			else
    				colour = COLOUR_DEAD;
    			cout << COLOUR_ALIVE << endl;
    		    rectfill(buffer, y, x, y+SQUARE_SIZE, x+SQUARE_SIZE, colour);
 			} 		
     	}
     	textprintf_ex(buffer, font, 0, 0, 15, -1,
  			     "Generation- %d - Press ESC to quit",   count++);
  		blit(buffer, screen, 0, 0, 0, 0, COLUMNS*SQUARE_SIZE, ROWS*SQUARE_SIZE);	     
        rest(500);  // wait half a sec
    
    }   
	//end program
    allegro_exit();
    return 0;
}
END_OF_MAIN();


