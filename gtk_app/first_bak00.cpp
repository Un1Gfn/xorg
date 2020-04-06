#include <gtk/gtk.h>

int main(int argc, char* argv[]){

  gtk_init(&argc,&argv);
  GtkWidget* window;
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Connect signal to function
  // "g_" from "G" library, not "GTK" library
  // Listen to the window
  // Listen to the "delete-event" (user press [X] button)
  // macro G_CALLBACK
  // call the gtk_main_quit() which requires no parameter (NULL)
  // if(argc>=2)
  g_signal_connect(
    window,
    "delete-event", // "delete_event" ok
    G_CALLBACK(gtk_main_quit),NULL
  );

  // Make then "window" visible on normal circumstances
  // if(argc>=2)
  gtk_widget_show(window);

  // Endless loop
  gtk_main();

  return 0;
}