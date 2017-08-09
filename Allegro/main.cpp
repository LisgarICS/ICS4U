// sierpinski triangle for 4U using classes and Allegro 5
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <allegro5/allegro.h>
#include "Point.h"

int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//ALLEGRO_EVENT ev;
	ALLEGRO_KEYBOARD_STATE key_state;
	 //std::cout << "here" << std::endl;
	// Allegro initialization
	if (!al_init()) {

      std::cerr << "failed to initialize allegro! "  << std::endl;
      return -1;
   }
   if (!al_install_keyboard()) {
   	  std::cerr << "failed to initialize the keyboard! "  << std::endl;
      return -1;
   }
   display = al_create_display(SCREEN_W, SCREEN_H);
   if (!display) {
      std::cerr << "failed to create display!" << std::endl;

      return -1;
   }
  /* event_queue = al_create_event_queue();
   if (!event_queue) {
   	  std::cerr << "failed to create event_queue!" << std::endl;
      al_destroy_display(display);

      return -1;
   }
	al_register_event_source(event_queue, al_get_keyboard_event_source());*/
	al_clear_to_color(al_map_rgb(10, 10, 200));
	al_flip_display();

	// Declare and initialize coordinates
	POINT vertex[3];

	vertex[0].setPoint(320, 50);
	vertex[1].setPoint(160, 400);
	vertex[2].setPoint(480, 400);

	POINT current(vertex[0]);
//	std::cout << "here" << std::endl;
	//while (ev.keyboard.keycode != ALLEGRO_KEY_ESCAPE) {
	while (true) {
		int j = rand() % 3;
		current.midPoint(vertex[j]);
		current.putPoint();
		al_unlock_bitmap(al_get_backbuffer(display));
		al_flip_display();
		al_rest(0.001);
  	    al_get_keyboard_state(&key_state);
      	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
        	break;
	}
    al_destroy_display(display);
	return 0;
}
