#include <gtk/gtk.h>
#include <glib.h>
#include "readproc.c"
GdkPixbuf *create_pixbuf(const gchar * filename) {

   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);

   if (!pixbuf) {

      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }
   return pixbuf;
}

static gboolean on_timeout (gpointer user_data)
{
  static unsigned f_times = 0;

  GtkLabel *label = GTK_LABEL (user_data);

  ++f_times;
  gchar *text = g_strdup_printf ("I have been updated %u times", f_times);
  gtk_label_set_label (label, text);
  g_free (text);

  return G_SOURCE_CONTINUE; /* or G_SOURCE_REMOVE when you want to stop */
}

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *separator1;
  GtkWidget *separator2;
  GtkWidget *separator3;
  GtkWidget *separator4;
  GtkWidget *separator5;
  GtkWidget *box;
  GdkPixbuf *icon;

  int taille = 1000;
  char* pcpu = calloc(taille , sizeof(char));
  memset(pcpu, 0, taille);

  char* etat = calloc(taille , sizeof(char));
  memset(etat, 0, taille);

  char* pid = calloc(taille , sizeof(char));
  memset(pid, 0, taille);

  char* ppid = calloc(taille , sizeof(char));
  memset(ppid, 0, taille);

  char* pmem = calloc(taille , sizeof(char));
  memset(pmem, 0, taille);

  char* cmd = calloc(taille , sizeof(char));
  memset(cmd, 0, taille);

  GtkWidget *ptext_gen1;
  char *text_gen1;
  GtkWidget *ptext_gen2;
  char *text_gen2;
  GtkWidget *ptext_gen3;
  char *text_gen3;
  GtkWidget *ptext_gen4;
  char *text_gen4;
  GtkWidget *ptext_gen5;
  char *text_gen5;
  GtkWidget *ptext_gen6;
  char *text_gen6;



  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  int hauteur = 800;
  int largeur = 400;
  gtk_window_set_default_size (GTK_WINDOW(window), hauteur, largeur);
  gtk_window_set_title(GTK_WINDOW(window), "Yatengaki");
  icon = create_pixbuf("index.png");
  gtk_window_set_icon(GTK_WINDOW(window), icon);
  //gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  //gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_object_unref(icon);
  box = gtk_box_new(FALSE, 10);

  pcpu,etat,pid,ppid,pmem,cmd = readGTK(&pcpu, &etat, &pid, &ppid, &pmem, &cmd);
  box = gtk_box_new(FALSE, 10);
  gtk_container_add(GTK_CONTAINER(window), box);

  separator1 = gtk_separator_new(0);
  separator2 = gtk_separator_new(0);
  separator3 = gtk_separator_new(0);
  separator4 = gtk_separator_new(0);
  separator5 = gtk_separator_new(0);


  text_gen1 = g_strdup_printf("%%cpu\n\n%s",pcpu);
  ptext_gen1 = gtk_label_new(text_gen1);
  gtk_label_set_line_wrap(GTK_LABEL(ptext_gen1), TRUE);
  g_timeout_add (1000 /* milliseconds */,on_timeout,ptext_gen1);
  //gtk_box_pack_start(GTK_BOX(box), ptext_gen1, FALSE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(box), separator1, FALSE, TRUE, 10);

  text_gen2 = g_strdup_printf("etat\n\n%s",etat);
  ptext_gen2 = gtk_label_new(text_gen2);
  gtk_label_set_line_wrap(GTK_LABEL(ptext_gen2), TRUE);
  g_timeout_add (1000 /* milliseconds */,on_timeout,ptext_gen2);
  //gtk_box_pack_start(GTK_BOX(box), ptext_gen2, FALSE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(box), separator2, FALSE, TRUE, 10);

  text_gen3 = g_strdup_printf("pid\n\n%s",pid);
  ptext_gen3 = gtk_label_new(text_gen3);
  gtk_label_set_line_wrap(GTK_LABEL(ptext_gen2), TRUE);
  g_timeout_add (1000 /* milliseconds */,on_timeout,ptext_gen3);
  //gtk_box_pack_start(GTK_BOX(box), ptext_gen3, FALSE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(box), separator3, FALSE, TRUE, 10);

  text_gen4 = g_strdup_printf("ppid\n\n%s",ppid);
  ptext_gen4 = gtk_label_new(text_gen4);
  gtk_label_set_line_wrap(GTK_LABEL(ptext_gen4), TRUE);
  g_timeout_add (1000 /* milliseconds */, on_timeout,ptext_gen4);
  //gtk_box_pack_start(GTK_BOX(box), ptext_gen4, FALSE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(box), separator4, FALSE, TRUE, 10);

  text_gen5 = g_strdup_printf("%%mem\n\n%s",pmem);
  ptext_gen5 = gtk_label_new(text_gen5);
  gtk_label_set_line_wrap(GTK_LABEL(ptext_gen5), TRUE);
  g_timeout_add (1000 /* milliseconds */, on_timeout, gtk_box_pack_start(GTK_BOX(box), ptext_gen5, FALSE, TRUE, 0))
  //gtk_box_pack_start(GTK_BOX(box), ptext_gen5, FALSE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(box), separator5, FALSE, TRUE, 10);

  text_gen6 = g_strdup_printf("cmd\n\n%s",cmd);
  ptext_gen6 = gtk_label_new(text_gen6);
  gtk_label_set_line_wrap(GTK_LABEL(ptext_gen6), TRUE);
  g_timeout_add (1000 /* milliseconds */, on_timeout,gtk_box_pack_start(GTK_BOX(box), ptext_gen6, FALSE, TRUE, 0));
  //gtk_box_pack_start(GTK_BOX(box), ptext_gen6, FALSE, TRUE, 0);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
  G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  //sleep(1);

  g_free(text_gen1);
  g_free(text_gen2);
  g_free(text_gen3);
  g_free(text_gen4);
  g_free(text_gen5);

  free(pcpu);
  free(etat);
  free(pid);
  free(ppid);
  free(pmem);
  free(cmd);
  //gtk_grab_remove(box);
  //gtk_widget_destroy(box);
  //gtk_container_remove(window, box);

  gtk_main();
  return 0;
}
