/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 5 - Keyboard Input
 			 																 *
 *	Usage:   Move sprite using arrow keys
 								                                               *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	*****************************************************************************/

/* Steps for Keyboard Input
 1. install keyboard
 2. Create event queue
 3. Register keyboard events
 4. Wait for event
 5. If keyboard event check which key.
 */

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
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;		// add event queue object

	// Initialize Allegro
	al_init();

	// initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
	al_set_window_title(display, "Allegro Example 5 - Keyboard Input");

   	// Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	return -1;
   	}

	// need to add image processor
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize al_init_image_addon!",nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return 0;
	}

	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return -1;
	}

	// need to register events for our event queue
	al_register_event_source(event_queue, al_get_display_event_source(display));
 	al_register_event_source(event_queue, al_get_keyboard_event_source());

	// Create a bitmap and load the image
	ALLEGRO_BITMAP *ball = nullptr;
	ball = al_load_bitmap("picture.bmp");

	// remove pink part of image
	al_convert_mask_to_alpha(ball, PINK);	// pink mask, but we can pick any colour

	// move ball across screen using keyboard.
	int dx = 100;
	int dy = 100;
	al_clear_to_color(SLATEGREY);
	al_draw_bitmap(ball, dx, dy, 0);
	al_flip_display();
	bool doexit = false;
	while (!doexit) {

    	ALLEGRO_EVENT ev;
      	al_wait_for_event(event_queue, &ev);

      	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        	doexit = true;
      	}
      	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         	switch(ev.keyboard.keycode) {
            	case ALLEGRO_KEY_UP:
               		dy -= 8;
               		break;
	            case ALLEGRO_KEY_DOWN:
    		        dy += 8;
            		break;
            	case ALLEGRO_KEY_LEFT:
               		dx -= 8;
               		break;
	            case ALLEGRO_KEY_RIGHT:
               		dx += 8;
               		break;
               	case ALLEGRO_KEY_ESCAPE:
               		doexit = true;
               		break;
         	}
         	al_clear_to_color(SLATEGREY);
		 	al_draw_bitmap(ball, dx, dy, 0);
		 	al_flip_display();
		}
	}

	//Release the bitmap data and exit with no errors
   	al_destroy_bitmap(ball);
	al_destroy_display(display);
	return 0;
}

