#include <config.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gi18n.h>

#define IMAGE_1 "/home/slash/Pictures/Selection_315.png"
#define IMAGE_2 "/home/slash/Pictures/459911.jpg"

gpointer worker (gpointer data)
{
	GtkWidget *image;
	gchar *image_file[] = {IMAGE_1, IMAGE_2};

	GtkWidget *window = data;
	int i = 0;

	image = gtk_image_new ();

  /* hard work here */
	gtk_image_set_from_file (GTK_IMAGE (image), image_file[0]);

	gtk_container_add(GTK_CONTAINER(window), image);

	while (1) {
		gtk_widget_show(image);
		g_usleep (1000000);
		gtk_image_set_from_file (GTK_IMAGE (image), image_file[i]);
		i++;
		if (i >= 2)
			i = 0;
	}

	return NULL;
}

GtkWidget* create_window (void)
{
	GtkWidget *window;
	GThread *pthread;

	/* Set up the UI */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "image-viewer-c");

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
