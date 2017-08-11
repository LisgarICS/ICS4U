/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 6 - Use a timer, set a frame rate                       *
 *	                                                                         *
 *	Usage:   Use arrows keys to change direction of sprite                   *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/
/*
* How to use a timer
 1. Declare a frame rate
 2. Declare timer and event queue
 3. Create a timer based on that frame rate
 4. Create event queue
 5. Register timer events
 6. Wait for event
 7. If timer event do what you want to do each frame.

*/

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

#define PINK        al_map_rgb(255, 0, 255)
#define BLACK       al_map_rgb(0, 0, 0)
#define SLATEGREY   al_map_rgb(112,128,144)

const float FPS = 60;			// set frame rate per second
const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

int main(int argc, char *argv[]) {
	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;		// add event queue object
	ALLEGRO_TIMER *timer = nullptr;				    // 1. add timer object

	// Initialize Allegro
	al_init();

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
	al_set_window_title(display, "Allegro Example 6 - Timers");

  	// Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	return -1;
   	}

	// need to add image processor
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// 2. create timer
	timer = al_create_timer(1.0 / FPS);
   	if (!timer) {
   		al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return -1;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
 	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));			// 3. register timer events

	// Create a bitmap and load the picture
	ALLEGRO_BITMAP *ball = nullptr;
	ball = al_load_bitmap("picture.bmp");

	// remove pink part of image
	al_convert_mask_to_alpha(ball, PINK);		// pink mask, but we can pick any colour

	// move ball across screen using keyboard.
	int dx = 0;
	int dy = 0;
	int posx = 100;
	int posy = 100;
	al_draw_bitmap(ball, posx, posy, 0);
	al_flip_display();
	bool doexit = false;

	al_start_timer(timer);		// 4.   Start the timer.

	while (!doexit) {

    	ALLEGRO_EVENT ev;
      	al_wait_for_event(event_queue, &ev);

      	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        	doexit = true;
      	}
      	// set direction if key pressed
      	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         	switch(ev.keyboard.keycode) {
            	case ALLEGRO_KEY_UP:
               		dy = -2;
               		dx = 0;
               		break;
	            case ALLEGRO_KEY_DOWN:
    		        dy = 2;
    		        dx = 0;
            		break;
            	case ALLEGRO_KEY_LEFT:
               		dx = -2;
               		dy = 0;
               		break;
	            case ALLEGRO_KEY_RIGHT:
               		dx = 2;
               		dy = 0;
               		break;
         	}
		}
		// move ball and display for each frame.
        else if (ev.type == ALLEGRO_EVENT_TIMER) {
        	posx += dx;
        	posy += dy;

        	al_clear_to_color(SLATEGREY);
			al_draw_bitmap(ball, posx, posy, 0);
			al_flip_display();
		}
	}

	//Release the bitmap data and exit with no erros
   	al_destroy_bitmap(ball);
	al_destroy_display(display);
	return 0;
}
