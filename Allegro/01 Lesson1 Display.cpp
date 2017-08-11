/*****************************************************************************
 *	Name:     Mr. Creelman                                                   *
 *	Date:     August 2017                                                    *
 *                                                                           *
 *	Purpose: Example 1 - Bring up the display screen                         *
 *	                                                                         *
 *	Usage:   Run, wait a few seconds then see message box.                   *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/

#include <allegro5/allegro.h>                       // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box

const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

// NOTE: argc, argv parameters are required.
int main(int argc, char *argv[]) {

	// Initialize Allegro
	al_init();

	// Initialize display
	ALLEGRO_DISPLAY *display = nullptr;
	display = al_create_display(SCREEN_W, SCREEN_H);

	// Always check if your allegro routines worked successfully.
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
	al_set_window_title(display, "Allegro Example 1 - Create Display");

	// Wait two seconds
    al_rest(2);

    // Display message box.
    al_show_native_message_box(
        display,                        // screen
        "Allegro Message Box",          // Title Bar Text
        "Allegro",                      // Title
        "Display Loaded Successfully",  // message
        nullptr,
        0);  // gives okay button.

    // Free up memory taken by display.
    al_destroy_display(display);

    // Exit with no errors
	return 0;
}

