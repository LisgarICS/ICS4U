/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 3 - Show how to clip a bitmap (image)                   *
 *	                                                                         *
 *	Usage:   Shows two clipped bitmaps then exits					         *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/

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
	al_set_window_title(display, "Allegro Example 3 - Clipping Bitmaps");

   	// need to add image processor
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return 0;
	}

	// Create a bitmap for the rainbow and load appropriate image
	ALLEGRO_BITMAP *rainbow = nullptr; //Declare a ALLEGRO_BITMAP called rainbow
	rainbow = al_load_bitmap("rainbow.bmp"); // Load our picture

	// Create a bitmap for the clipped image, and clip out from (x1, y1) to (x2, y2)
	ALLEGRO_BITMAP *clippedRainbow = nullptr;
	clippedRainbow  = al_create_sub_bitmap(rainbow, 50 , 50, 150, 150);

	// draw the new sub bitmap to a couple of locations on the display
	al_draw_bitmap(clippedRainbow , 0, 0, 0); //Draw from 0,0 to 50,50 on the screen at (0,0)
	al_draw_bitmap(clippedRainbow , 100, 100, 0); //Draw from 0,0 to 50,50 on the screen at (0,0)
	al_flip_display();	 // show what is on the display

	// Wait for 5 seconds. . .
	al_rest(5);

	//Release the bitmap data and exit with no erros
   	al_destroy_bitmap(rainbow);
	al_destroy_bitmap(clippedRainbow);
	al_destroy_display(display);
	return 0;
}

