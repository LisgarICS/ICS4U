/*****************************************************************************
 *	Source:https://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial/Addons/Fonts                                                     *
 *	                                                *
 *                                                                           *
 *	Purpose: Example 9 - Display Text                      *
 *	                                                                         *
 *	Usage:   Run and see text                                     *
 *	                                                                         *
 *	Revision History: changed and added text and font - Mr. Creelman                                                      *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#define BACKGROUND al_map_rgb(0x09, 0x31, 0x45)
#define FOREGROUND al_map_rgb(0x3C, 0x64, 0x78)

const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

int main(int argc, char **argv){

   // Initialize allegor
   al_init();

   // Initialize display
   ALLEGRO_DISPLAY *display = nullptr;
   display = al_create_display(SCREEN_W, SCREEN_H);
   if (!display){
       al_show_native_message_box(display, "Error", "Error", "Failed to initialize Display.!",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       return -1;
   }
   al_set_window_title(display, "Allegro Example 9 - Text");

   al_init_font_addon(); // initialize the font addon
   al_init_ttf_addon();// initialize the ttf (True Type Font) addon

   // load the specific font you want
   ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 36, 0);
   if (!font){
      al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }

   al_clear_to_color(BACKGROUND);
   al_draw_text(font, FOREGROUND, 640/2, (480/4), ALLEGRO_ALIGN_CENTRE, "Everything is Awesome!");
   al_flip_display();
   al_rest(1);
   al_draw_text(font, FOREGROUND, 640/2, (480/2), ALLEGRO_ALIGN_CENTRE, "When your part of a team");
   al_flip_display();

   al_rest(5.0);

   // free memory and return success.
   al_destroy_display(display);
   return 0;
}


