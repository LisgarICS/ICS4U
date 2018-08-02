/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017
 *  some code and frames from https:
 //gamedevelopment.tutsplus.com/tutorials/an-introduction-to-spritesheet-animation--gamedev-13099                                                   *
 *                                                                           *
 *	Purpose: Example 10 - Animation from sprite sheet                     *
 *	                                                                         *
 *	Usage:   Show animated sprite				                   *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#define BLACK       al_map_rgb(0, 0, 0)
#define WHITE       al_map_rgb(255, 255, 255)
#define SLATEGREY   al_map_rgb(112,128,144)

const float FPS = 16;			// set frame rate
const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

int main(int argc, char *argv[]) {
	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;		// add event queue object
	ALLEGRO_TIMER *timer = nullptr;				    // 1. add timer object

	// Initialize Allegro
	al_init();

	// initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
	al_set_window_title(display, "Allegro Example 10 - Sprite Sheet Animation");

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

	// 2. setup timer
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

	// declare and then load frames into memory
	ALLEGRO_BITMAP *spriteSheet;
	ALLEGRO_BITMAP *frame[16];

	spriteSheet = al_load_bitmap("runningMotion.png"); // Load frames
	// get frames
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			frame[i*4+j] = al_create_sub_bitmap(spriteSheet, j*125 , i*125, 125, 125);
		}
	}

	// remove pink part of image NOT NEEDED IN THIS CASE
	// for (int i=0; i<16; i++)
	//	al_convert_mask_to_alpha(frame[i], WHITE);		// pink mask, but we can pick any colour

	// set current frame and position.
	int curr = 0;
	int posx = 100;
	int posy = 100;

	al_clear_to_color(WHITE);

	al_flip_display();

	bool doexit = false;

	al_start_timer(timer);		// 4.   Start the timer.
	bool directionRight = true;
	int flags = 0;
	while (!doexit) {

    	ALLEGRO_EVENT ev;
      	al_wait_for_event(event_queue, &ev);

      	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        	doexit = true;
      	}
        else if(ev.type == ALLEGRO_EVENT_TIMER) {
        	curr++;
        	curr %= 16;
	      	al_clear_to_color(WHITE);
	      	if (!directionRight)
	      		flags = 0;
			else
				flags = ALLEGRO_FLIP_HORIZONTAL;
			al_draw_bitmap(frame[curr], posx, posy, flags);
			al_flip_display();
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
            	case ALLEGRO_KEY_RIGHT:
               		directionRight = true;
               		break;
	            case ALLEGRO_KEY_LEFT:
    		        directionRight = false;
            		break;
            	case ALLEGRO_KEY_ESCAPE:
    		        doexit = true;
            		break;
			}
		}
	}
	// Release the bitmap data and then exit

   	al_destroy_bitmap(spriteSheet);
	al_destroy_display(display);
	return 0;
}

