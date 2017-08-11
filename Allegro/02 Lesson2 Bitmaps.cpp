/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 2 - Display an image on the screen                      *
 *	                                                                         *
 *	Usage:   displaysa single bitmap, then waits for a few seconds.          *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/

// You must include the allegro header files
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

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
 	al_set_window_title(display, "Allegro Example 2 - Bitmaps");

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare a BITMAP called image, setting it's initial value to nullptr
	ALLEGRO_BITMAP *image = nullptr;

	// Load the bitmap into the Bitmap structure
	// image file must be in same directory.
	// Particularly check return code of this type of function that will fail if file not found.
	image = al_load_bitmap("rainbow.bmp");
  	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	al_destroy_display(display);
     	return -1;
	 }

	// Display picture started at top left corner
	al_draw_bitmap(image, 0,  0, 0);

	// write display to screen
	al_flip_display();

    // Wait 5 seconds
	al_rest(5);

	// Free memory and return with successful return code..
	al_destroy_display(display);
   	al_destroy_bitmap(image);
	return 0;
}
