#include <gtk/gtk.h>
#include <stdlib.h> // Include the standard library for the system() function

void on_window_closed(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}
////////////////////CHANGE INTERFACE NAME IN THE COMMAND///////////////////////////
void on_kill_button_clicked(GtkWidget *button, gpointer data) {
    // Define the command to be executed
    const char *command = "ifconfig enp4s0 down";//change interface name in this line
    
    // Execute the command
    system(command);
}

////////////////////ALSO HERE///////////////////////////
void on_start_button_clicked(GtkWidget *button, gpointer data) {
    // Define the command to be executed
    const char *command = "ifconfig enp4s0 up";//change interface name in this line
    
    // Execute the command
    system(command);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);
    
    // Create a label
    GtkWidget *label = gtk_label_new("Ethernet interface");
    
    // Create the "Kill" button with a label
    GtkWidget *kill_button = gtk_button_new_with_label("Kill");
    // Connect the "clicked" signal of the "Kill" button to the callback function
    g_signal_connect(kill_button, "clicked", G_CALLBACK(on_kill_button_clicked), NULL);
    
    // Create the "Start" button with a label
    GtkWidget *start_button = gtk_button_new_with_label("Start");
    // Connect the "clicked" signal of the "Start" button to the callback function
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_button_clicked), NULL);
    
    // Create a horizontal box container to hold the buttons
    GtkWidget *hbox = gtk_hbox_new(FALSE, 5);
    // Add the "Kill" button and the "Start" button to the horizontal box container
    gtk_box_pack_start(GTK_BOX(hbox), kill_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), start_button, TRUE, TRUE, 0);
    
    // Create a vertical box container to hold the label and the horizontal box container with buttons
    GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    // Add the label and the horizontal box container with buttons to the vertical box container
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    
    // Add the vertical box container to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    // Show all widgets
    gtk_widget_show_all(window);
    
    // Start the GTK main loop
    gtk_main();
    
    return 0;
}
