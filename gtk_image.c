#include <config.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gi18n.h>

#define IMAGE_1 "/home/slash/Pictures/Selection_315.png"
#define IMAGE_2 "/home/slash/Pictures/459911.jpg"
GtkWidget *image;
GtkWidget *image2;

GtkWidget *window;
GtkWidget *window2;

gchar *image_file[] = {IMAGE_1, IMAGE_2};

gpointer worker (gpointer data)
{
	int i = 0;

	/* hard work here */
	while (1) {
		g_usleep (1000000);
		if (i >= 2)
			i = 0;

		if (i == 0)
			gtk_widget_hide(image);
		else
			gtk_widget_show(image);
		i++;
	}

	return NULL;
}

GtkWidget* create_window (void)
{
	GThread *pthread;

	/* Set up the UI */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "image-viewer-c");

	image = gtk_image_new ();
	gtk_image_set_from_file (GTK_IMAGE (image), image_file[0]);
	gtk_container_add(GTK_CONTAINER(window), image);

	gtk_widget_show(image);
	pthread = g_thread_new ("worker", worker, window);
	if (!pthread)
		g_print("pthread fail\r\n");

	return window;
}

int main (int argc, char *argv[])
{
	GtkWidget *window;

	gtk_init (&argc, &argv);
	window = create_window ();
	gtk_widget_show_all (window);
	gtk_main ();
	return 0;
}
