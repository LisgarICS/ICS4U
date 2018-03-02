/*
Name: AS
Course: ICS4U
Date: February 26, 2018

Modified by Mr. Creelman March 2nd, 2018 deleted Nifty Mountain Code, to
highlight how events can be used to close allegro window.
*/

#include <iostream>
#include <ctime>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;

using namespace std;
void initAllegro(int rows, int cols);
void waitForClose();
void drawShapes(int rows, int cols);

int main(int argc, char *argv[]){
    int nRows = 580;
    int nCols = 740;

    //initialize allegro
    initAllegro(nRows, nCols);

    // draw something to screen
    drawShapes(nRows, nCols);
    al_flip_display();

    //waits for user to close allegro window
    waitForClose();
    al_destroy_display(display);

    return 0;
}

// display circles just show something is on screen
void drawShapes(int rows, int cols) {
    srand(time(0));
    for (int i =0; i<500; i++) {
        int r = rand() % 50;
        al_draw_circle(rand() % (rows-2*r) +r , rand() % (cols-2*r) + r, r, al_map_rgb(255, 0, 0), 4);
        if (r == 40)
            al_draw_rectangle(rand() % (rows-2*r)  , rand() % (cols-2*r), 100, 50, al_map_rgb(0, 255, 0), 4);
    }
}

//waits until the close button or Escape Key is pressed
void waitForClose() {
    ALLEGRO_EVENT event;

    while (1) {
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            return;
        if (event.type == ALLEGRO_EVENT_KEY_DOWN  &&  event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            return;
    }

}

//Initialize allegro
void initAllegro(int rows, int cols) {

    al_init();
	display = al_create_display(rows, cols);

	//check if allegro routines work successfully
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	}

	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	}

	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "Failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
   	}

   	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

	//set the title of the window
	al_set_window_title(display, "Close Windows with X or Escape");
}
