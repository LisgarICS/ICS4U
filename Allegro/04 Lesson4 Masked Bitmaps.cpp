/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 4 - Show how to mask a bitmap (image). Makes a colour,
 			 usually pink, transparent.
 *	                                                                         *
 *	Usage:   Shows a masked image (sprite), and moves it across and down     *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#define PINK        al_map_rgb(255, 0, 255)
#define BLACK       al_map_rgb(0, 0, 0)
#define SLATEGREY   al_map_rgb(112,128,144)

const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

int main(int argc, char *argv[]) {
	ALLEGRO_DISPLAY *display = nullptr;

	// Initialize Allegro
	al_init();

	// initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize display!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
	al_set_window_title(display, "Allegro Example 4 - Masked Bitmaps");

   	// need to add image processor
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Create a bitmap and load the image.
	ALLEGRO_BITMAP *ball = nullptr; //Declare a ALLEGRO_BITMAP called ball
	ball = al_load_bitmap("picture.bmp"); // Load our picture
	if (!ball) {
       		al_show_native_message_box(display, "Error", "Error",
    			"picture.bmp not found", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    		return -1;;
	}
	// Now we will make the pink portion of the picture transparent
	al_convert_mask_to_alpha(ball, PINK);

	// Some loops to move the ball on the display
	for (int x =100; x<300; x++) {
		al_clear_to_color(SLATEGREY);
		al_draw_bitmap(ball, x, 100, 0);
		al_flip_display();
		al_rest(.01);
	}
	for (int y =100; y<300; y++) {
		al_clear_to_color(SLATEGREY);
		al_draw_bitmap(ball, 300, y, 0);
		al_flip_display();
		al_rest(.01);
	}

	// Wait for 2 seconds. . .
	al_rest(2);

	// free memory and return success
   	al_destroy_bitmap(ball);
	al_destroy_display(display);
	return 0;
}

