/*******************
Allegro Newbie Tutorial

by
LoomSoft

http://loomsoft.net
email: jay@loomsoft.net

Updated to Allegro 5 by Mr. Creelman May 2017
*******************/
/* Allegro Newbie Tutorial : Lesson 8 - Bounding Box Collision Detection
 *
 * This tutorial will show you how to do a very simple implementation of
 * collision detection using bounding boxes. The user can move both images.
 *
 * Controls:
 * Up/Down/Left/Right : move image 1
 * A/W/S/D : move image 2
 * SPACE: toggle drawing bounding boxes.
 * ESC: exit
 *
 * This lesson also covers error checking when creating/loading bitmaps,
 * drawing primitive lines, and displaying text. This is something new that
 * was skipped in all the previous tutorials for simplicity. It is extremely
 * good practice to do error checking for any function that allows you to do so.
 *
 * We also learn about using the function: allegro_message.
 */

/* The include and timer setup, and allegro initialization. This is routine stuff! */
#include <iostream>
#include <allegro5/allegro.h> // Include the allegro header file.
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_FONT *arial;
ALLEGRO_EVENT_QUEUE *event_queue;

const float FPS = 16;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define RED         al_map_rgb(255, 0, 0)
#define BACKGROUND  al_map_rgb(0xD6, 0xDC,0xF0)
#define PINK        al_map_rgb(255, 0, 255)
#define BLACK       al_map_rgb(0, 0, 0)

struct Image {
    ALLEGRO_BITMAP *bitmap;               // picture
    int x, y;                             // position on screen
    int bbRight, bbLeft, bbTop, bbBottom; // boundary box
};

// prototypes
int initializeAllegro(int width, int height, const char title[]);
bool loadBitmap(Image &image, const char *filename);
void setPosition(Image &image, int xPos, int yPos);
void calcBounds(Image &a);
void drawBoundingBox(Image &image);
bool isCollision(Image &a, Image &b);

int main(int argc, char *argv[]) {
    Image image1, image2;       // create two images

	initializeAllegro(SCREEN_HEIGHT, SCREEN_WIDTH, "Collision Detection");

	if (!loadBitmap(image1, "11Person.bmp"))
        return 1;
	if (!loadBitmap(image2, "11SpaceShip.bmp"))
        return 1;
    setPosition(image1, 70, 50);
    setPosition(image2, 100, 85);

    int show_bbox = false;
	bool doexit = false;

	while (!doexit) { // Keep going until we hit escape.
        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            doexit = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    image1.y--;
                    break;
                case ALLEGRO_KEY_DOWN:
                    image1.y++; //Move image 1 down.
                    break;
                case ALLEGRO_KEY_LEFT:
                    image1.x--; //Move image 1 left.
                    break;
                case ALLEGRO_KEY_RIGHT:
                     image1.x++;
                     break;
                case ALLEGRO_KEY_A:
                     image2.x--;
                     break;
                case ALLEGRO_KEY_D:
                     image2.x++; //Move image 1 down.
                     break;
                case ALLEGRO_KEY_S:
                     image2.y++; //Move image 1 left.
                     break;
                case ALLEGRO_KEY_W:
                     image2.y--;
                     break;
                case ALLEGRO_KEY_ESCAPE:
                     doexit = true;
                     break;
                case ALLEGRO_KEY_SPACE:
                     show_bbox = !show_bbox;
                     break;
                default:
                    ;

         	}
        }
		/* Time for the drawing stuff! */
        al_clear_to_color(BACKGROUND);
		al_draw_bitmap(image1.bitmap, image1.x, image1.y, 0); //Draw image1
		al_draw_bitmap(image2.bitmap, image2.x, image2.y, 0); //Draw image2

		/* Here we do the drawing of the bounding box if the player is hitting space.
           it turns off if a character hits a key not in use*/
		if (show_bbox) {
			/* Draw images bounding box. */
			drawBoundingBox(image1);
			drawBoundingBox(image2);


		}	/* Just the closing bracket... */

		/* Now, if there's a collision, we want to state it! */
		if (isCollision(image1, image2)) {
			 al_draw_text(arial, PINK, 0, 0, 0, "Collision!");
		}

		/* Do the normal writing to the screen. */
		al_flip_display();

	}

	/* Destroy bitmaps and quit. */
	al_destroy_bitmap(image1.bitmap);
	al_destroy_bitmap(image2.bitmap);
	return 0;
}

/*
    loadBitmap. Load bitmap. Check if load correctly. Return false on error.
    Mask out pink part of picture/
*/
bool loadBitmap(Image &image, const char *filename) {
    image.bitmap = al_load_bitmap(filename);
    if (image.bitmap == nullptr) {
		al_show_native_message_box(display, "Error", filename, "Could not load ",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		return false;
	}
	al_convert_mask_to_alpha(image.bitmap, PINK);
	return true;
}

/*
    setPosition  - Locate image at given location
*/
void setPosition(Image &image, int xPos, int yPos) {
    image.x = xPos; //Set the x position of image 1 to 0.
	image.y = yPos; //Set the y position of image 1 to 0.
}

/*
    calcBounds, calculate border locations of boundary box
*/
void calcBounds(Image &a) {
    a.bbLeft = a.x;
	a.bbTop  = a.y;
	a.bbRight = a.bbLeft + al_get_bitmap_width(a.bitmap);
	a.bbBottom = a.bbTop + al_get_bitmap_height(a.bitmap);
}

/*
*/
void drawBoundingBox(Image &image) {
    calcBounds(image);
	al_draw_line(image.bbLeft, image.bbTop, image.bbRight, image.bbTop, RED, 1);
    al_draw_line(image.bbLeft, image.bbBottom, image.bbRight, image.bbBottom, RED, 1);
	al_draw_line(image.bbLeft, image.bbTop, image.bbLeft, image.bbBottom, RED, 1);
	al_draw_line(image.bbRight, image.bbTop, image.bbRight, image.bbBottom, RED,1);
}

bool isCollision(Image &a, Image &b) {
    calcBounds(a);
    calcBounds(b);
    if (a.bbBottom < b.bbTop) {
        return false;
    }
    else if (a.bbTop > b.bbBottom) {
        return false;
    }
    else if (a.bbRight < b.bbLeft) {
        return false;
    }
    else if (a.bbLeft > b.bbRight) {
        return false;
    }
    return true;
}

int initializeAllegro(int width, int height, const char title[]) {

    ALLEGRO_COLOR background = al_map_rgb(255, 255, 255);       // make background white.

    // Initialize Allegro
	al_init();

	// initialize display
	display = al_create_display(width, height);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
	al_set_window_title(display, title);

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
    // Add fonts


   al_init_font_addon(); // initialize the font addon
   al_init_ttf_addon();// initialize the ttf (True Type Font) addon

   arial = al_load_ttf_font("C:/Windows/Fonts/arial.ttf", 16, 0);
   if (!arial){
      al_show_native_message_box(display, "Error", "Error", "Could not load arial.ttf",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }

    // Initialize primative add on
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
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
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
 	al_register_event_source(event_queue, al_get_keyboard_event_source());

//l_register_event_source(event_queue, al_get_timer_event_source(timer));	*/		// 3. register timer events

	al_clear_to_color(background);

	al_flip_display();
	al_start_timer(timer);
//	std::cout << "Init return zero " << std::endl;
	return 0;
}



