/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 8 - Display various shapes                      *
 *	                                                                         *
 *	Usage:   Run and see shapes                                    *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/

// Here is your first line. You must include the allegro header file or else nothing will work!
#include <allegro5/allegro.h>// You must include the Allegro Header file
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

// lots of colours to choose from
#define RED		 al_map_rgb(230, 25, 75)
#define GREEN	 al_map_rgb(60, 180, 75)
#define YELLOW	 al_map_rgb(255, 225, 25)
#define BLUE	 al_map_rgb(0, 130, 200)
#define ORANGE   al_map_rgb(245, 130, 48)
#define PURPLE	 al_map_rgb(145, 30, 180)
#define CYAN	 al_map_rgb(70, 240, 240)
#define MAGENTA	 al_map_rgb(240, 50, 230)
#define LIME	 al_map_rgb(210, 245, 60)
#define PINK	 al_map_rgb(250, 190, 190)
#define TEAL	 al_map_rgb(0, 128, 128)
#define LAVENDER al_map_rgb(230, 190, 255)
#define BROWN	 al_map_rgb(170, 110, 40)
#define BEIGE	 al_map_rgb(255, 250, 200)
#define MAROON	 al_map_rgb(128, 0, 0)
#define MINT	 al_map_rgb(170, 255, 195)
#define OLIVE	 al_map_rgb(128, 128, 0)
#define CORAL	 al_map_rgb(255, 215, 180)
#define NAVY	 al_map_rgb(0, 0, 128)
#define GREY	 al_map_rgb(128, 128, 128)
#define WHITE	 al_map_rgb(255, 255, 255)
#define BLACK	 al_map_rgb(0, 0, 0)

const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

int main(int argc, char *argv[]) {
	ALLEGRO_DISPLAY *display = nullptr;

	// Initialize Allegro
	al_init();

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
    al_set_window_title(display, "Allegro Example 8 - Shapes");

	// Initialize primative add on
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// paint rectangle  (x1, y1, x2, y2, colour) - Upper left and lower right points of the rectangle
	al_draw_filled_rectangle(100, 100, 200, 150, MAROON);
	al_draw_filled_circle(100, 100, 50, LAVENDER);
	al_draw_circle(400, 400, 80, TEAL, 10);		// last parameter is thickness of line
	al_draw_line(10, 240, 310, 250, NAVY, 25);

	// display what has been drawn
  	al_flip_display();

  	// Wait for a 5 seconds before destroy the dispaly and exit the program.
	al_rest(5);
	al_destroy_display(display);
	return 0;
}
