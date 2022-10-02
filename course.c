#include <stdlib.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>



GtkWidget *window_introduse;
GtkWidget *fixed_introduse;
GtkWidget *label_introduse;

GtkWidget *button_create_file_introduse;
GtkWidget *window_create_file;
GtkWidget *fixed_create_file;
GtkWidget *button_create_file;
GtkWidget *entry_for_create;
GtkWidget *label_for_create;

GtkWidget *choose_file;
GtkWidget *label_for_choose;

GtkWidget *window_choose_op;
GtkWidget *fixed_choose_op;
GtkWidget *button_for_print;
GtkWidget *button_for_add;
GtkWidget *button_for_change;
GtkWidget *button_for_del_choose;
GtkWidget *button_main_menu;


GtkWidget *window_add;
GtkWidget *fixed_add;
GtkWidget *window_change;
GtkWidget *fixed_change;
GtkWidget *window_del;
GtkWidget *fixed_del;

GtkWidget *button_for_snack;
GtkWidget *button_for_soup;
GtkWidget *button_for_main_dish;
GtkWidget *button_for_dessert;
GtkWidget *button_for_drink;
GtkWidget *label_for_window_add;

GtkWidget *window_for_snack;
GtkWidget *fixed_for_snack;
GtkWidget *window_for_soup;
GtkWidget *fixed_for_soup;
GtkWidget *window_for_main_dish;
GtkWidget *fixed_for_main_dish;
GtkWidget *window_for_dessert;
GtkWidget *fixed_for_dessert;
GtkWidget *window_for_drink;
GtkWidget *fixed_for_drink;


GtkWidget *label_name_soup;
GtkWidget *label_prod_soup;
GtkWidget *label_weight_soup;
GtkWidget *label_price_soup;
GtkWidget *entry_name_soup;
GtkWidget *entry_prod_soup;
GtkWidget *entry_weight_soup;
GtkWidget *entry_price_soup;
GtkWidget *button_save_soup;


GtkWidget *label_name_snack;
GtkWidget *label_prod_snack;
GtkWidget *label_weight_snack;
GtkWidget *label_price_snack;
GtkWidget *entry_name_snack;
GtkWidget *entry_prod_snack;
GtkWidget *entry_weight_snack;
GtkWidget *entry_price_snack;
GtkWidget *button_save_snack;


GtkWidget *label_name_main_dish;
GtkWidget *label_prod_main_dish;
GtkWidget *label_weight_main_dish;
GtkWidget *label_price_main_dish;
GtkWidget *entry_name_main_dish;
GtkWidget *entry_prod_main_dish;
GtkWidget *entry_weight_main_dish;
GtkWidget *entry_price_main_dish;
GtkWidget *button_save_main_dish;



GtkWidget *label_name_drink;
GtkWidget *label_prod_drink;
GtkWidget *label_weight_drink;
GtkWidget *label_price_drink;
GtkWidget *entry_name_drink;
GtkWidget *entry_prod_drink;
GtkWidget *entry_weight_drink;
GtkWidget *entry_price_drink;
GtkWidget *button_save_drink;



GtkWidget *label_name_dessert;
GtkWidget *label_prod_dessert;
GtkWidget *label_weight_dessert;
GtkWidget *label_price_dessert;
GtkWidget *entry_name_dessert;
GtkWidget *entry_prod_dessert;
GtkWidget *entry_weight_dessert;
GtkWidget *entry_price_dessert;
GtkWidget *button_save_dessert;

GtkWidget *button_for_delete;
GtkWidget *entry_for_delete;
GtkWidget *label_for_delete;

GtkWidget *label_for_change;
GtkWidget *entry_for_change;
GtkWidget *button_for_change2;



GtkWidget *window_change_dish;
GtkWidget *fixed_change_dish;
GtkWidget *label_change_dish_name;
GtkWidget *label_change_dish_prod;
GtkWidget *label_change_dish_weight;
GtkWidget *label_change_dish_price;
GtkWidget *entry_change_dish_name;
GtkWidget *entry_change_dish_prod;
GtkWidget *entry_change_dish_weight;
GtkWidget *entry_change_dish_price;
GtkWidget *button_change_dish_price_save;




GtkBuilder *builder;
int type_int(GtkWidget* entry)
{    
    int var,flag=1;
    char str[100];
    strncpy(str,gtk_entry_get_text(GTK_ENTRY(entry)),99);
    int count = 0;
        for (int i = 0; i < strlen(str); i++)
       {
            if (isdigit(str[i]))
                count++;
        }
        if (count == strlen(str)){
            var = atoi(str);
        }
        if ((count != strlen(str))||var<=0){
            flag=0;
        }

            return flag;
}

int  type_float(GtkWidget* entry)
{
     int var,flag=1;
    char str[100];
    strncpy(str,gtk_entry_get_text(GTK_ENTRY(entry)),99);
        int count = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (isdigit(str[i]) || str[i] == '.')
                count++;
        }
        if (count == strlen(str)){
            var = atof(str);
        }
        if ((count != strlen(str))||var<=0){
             flag=0;
        }

            return flag;
}


 


struct MENU
{
    int type_dish;
    char name[100];
    char prod[100] ;
    char   weight[100];
    char price[100];
}dish;


 int main(int argc,char *argv[]) 
{
    gtk_init(&argc, &argv);
    builder=gtk_builder_new_from_file("Part1.glade");
    window_introduse=GTK_WIDGET(gtk_builder_get_object(builder, "window_introduse"));
    window_create_file=GTK_WIDGET(gtk_builder_get_object(builder, "window_create_file"));

    window_choose_op=GTK_WIDGET(gtk_builder_get_object(builder, "window_choose_op"));

    window_add=GTK_WIDGET(gtk_builder_get_object(builder, "window_add"));
    window_change=GTK_WIDGET(gtk_builder_get_object(builder, "window_change"));
    window_del=GTK_WIDGET(gtk_builder_get_object(builder, "window_del"));
        window_change_dish=GTK_WIDGET(gtk_builder_get_object(builder, "window_change_dish"));

    window_for_snack=GTK_WIDGET(gtk_builder_get_object(builder, "window_for_snack"));
    window_for_soup=GTK_WIDGET(gtk_builder_get_object(builder, "window_for_soup"));
    window_for_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "window_for_main_dish"));
    window_for_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "window_for_dessert"));
    window_for_drink=GTK_WIDGET(gtk_builder_get_object(builder, "window_for_drink"));


    g_signal_connect(window_introduse,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_create_file,"destroy", G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(window_choose_op,"destroy", G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(window_add,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_change,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_del,"destroy", G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(window_for_snack,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_for_soup,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_for_main_dish,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_for_dessert,"destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window_for_drink,"destroy", G_CALLBACK(gtk_main_quit),NULL);
        g_signal_connect(window_change_dish,"destroy", G_CALLBACK(gtk_main_quit),NULL);


    gtk_builder_connect_signals(builder,NULL);
   
    fixed_introduse=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_introduse"));
    label_introduse=GTK_WIDGET(gtk_builder_get_object(builder, "label_introduse"));

    button_create_file_introduse=GTK_WIDGET(gtk_builder_get_object(builder, "button_create_file_introduse"));
    fixed_create_file=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_create_file"));
    button_create_file=GTK_WIDGET(gtk_builder_get_object(builder, "button_create_file"));
    entry_for_create=GTK_WIDGET(gtk_builder_get_object(builder, "entry_for_create"));
    label_for_create=GTK_WIDGET(gtk_builder_get_object(builder, "label_for_create"));

    choose_file=GTK_WIDGET(gtk_builder_get_object(builder, "choose_file"));
    label_for_choose=GTK_WIDGET(gtk_builder_get_object(builder, "label_for_choose"));

    fixed_choose_op=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_choose_op"));
    button_for_print=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_print"));
    button_for_add=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_add"));
    button_for_change=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_change"));
    button_for_del_choose=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_del_choose"));
    button_main_menu=GTK_WIDGET(gtk_builder_get_object(builder, "button_main_menu"));
    label_for_choose=GTK_WIDGET(gtk_builder_get_object(builder, "label_for_choose"));


            fixed_add=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_add"));
                fixed_change=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_change"));
                    fixed_del=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_del"));
    button_for_snack=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_snack"));
    button_for_soup=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_soup"));
    button_for_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_main_dish"));
    button_for_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_dessert"));
    button_for_drink=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_drink"));
    label_for_window_add=GTK_WIDGET(gtk_builder_get_object(builder, "label_for_window_add"));

    fixed_for_snack=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_for_snack"));
    fixed_for_soup=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_for_soup"));
    fixed_for_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_for_main_dish"));
    fixed_for_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_for_dessert"));
    fixed_for_drink=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_for_drink"));

    label_name_snack=GTK_WIDGET(gtk_builder_get_object(builder, "label_name_snack"));
    label_prod_snack=GTK_WIDGET(gtk_builder_get_object(builder, "label_prod_snack"));
    label_weight_snack=GTK_WIDGET(gtk_builder_get_object(builder, "label_weight_snack"));
    label_price_snack=GTK_WIDGET(gtk_builder_get_object(builder, "label_price_snack"));
    entry_name_snack=GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_snack"));
    entry_prod_snack=GTK_WIDGET(gtk_builder_get_object(builder, "entry_prod_snack"));
    entry_weight_snack=GTK_WIDGET(gtk_builder_get_object(builder, "entry_weight_snack"));
    entry_price_snack=GTK_WIDGET(gtk_builder_get_object(builder, "entry_price_snack"));
    button_save_snack=GTK_WIDGET(gtk_builder_get_object(builder, "button_save_snack"));
    
    
    label_name_soup=GTK_WIDGET(gtk_builder_get_object(builder, "label_name_soup"));
    label_prod_soup=GTK_WIDGET(gtk_builder_get_object(builder, "label_prod_soup"));
    label_weight_soup=GTK_WIDGET(gtk_builder_get_object(builder, "label_weight_soup"));
    label_price_soup=GTK_WIDGET(gtk_builder_get_object(builder, "label_price_soup"));
    entry_name_soup=GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_soup"));
    entry_prod_soup=GTK_WIDGET(gtk_builder_get_object(builder, "entry_prod_soup"));
    entry_weight_soup=GTK_WIDGET(gtk_builder_get_object(builder, "entry_weight_soup"));
    entry_price_soup=GTK_WIDGET(gtk_builder_get_object(builder, "entry_price_soup"));
    button_save_soup=GTK_WIDGET(gtk_builder_get_object(builder, "button_save_soup"));
    
    label_name_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "label_name_main_dish"));
    label_prod_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "label_prod_main_dish"));
    label_weight_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "label_weight_main_dish"));
    label_price_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "label_price_main_dish"));
    entry_name_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_main_dish"));
    entry_prod_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "entry_prod_main_dish"));
    entry_weight_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "entry_weight_main_dish"));
    entry_price_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "entry_price_main_dish"));
    button_save_main_dish=GTK_WIDGET(gtk_builder_get_object(builder, "button_save_main_dish"));
    

    label_name_drink=GTK_WIDGET(gtk_builder_get_object(builder, "label_name_drink"));
    label_prod_drink=GTK_WIDGET(gtk_builder_get_object(builder, "label_prod_drink"));
    label_weight_drink=GTK_WIDGET(gtk_builder_get_object(builder, "label_weight_drink"));
    label_price_drink=GTK_WIDGET(gtk_builder_get_object(builder, "label_price_drink"));
    entry_name_drink=GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_drink"));
    entry_prod_drink=GTK_WIDGET(gtk_builder_get_object(builder, "entry_prod_drink"));
    entry_weight_drink=GTK_WIDGET(gtk_builder_get_object(builder, "entry_weight_drink"));
    entry_price_drink=GTK_WIDGET(gtk_builder_get_object(builder, "entry_price_drink"));
    button_save_drink=GTK_WIDGET(gtk_builder_get_object(builder, "button_save_drink"));

    label_name_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "label_name_dessert"));
    label_prod_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "label_prod_dessert"));
    label_weight_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "label_weight_dessert"));
    label_price_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "label_price_dessert"));
    entry_name_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_dessert"));
    entry_prod_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "entry_prod_dessert"));
    entry_weight_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "entry_weight_dessert"));
    entry_price_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "entry_price_dessert"));
    button_save_dessert=GTK_WIDGET(gtk_builder_get_object(builder, "button_save_dessert"));

    button_for_delete=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_delete"));
    entry_for_delete=GTK_WIDGET(gtk_builder_get_object(builder, "entry_for_delete"));
    label_for_delete=GTK_WIDGET(gtk_builder_get_object(builder, "label_for_delete"));

    label_for_change=GTK_WIDGET(gtk_builder_get_object(builder, "label_for_change"));
    entry_for_change=GTK_WIDGET(gtk_builder_get_object(builder, "entry_for_change"));
    button_for_change2=GTK_WIDGET(gtk_builder_get_object(builder, "button_for_change2"));


    fixed_change_dish=GTK_WIDGET(gtk_builder_get_object(builder, "fixed_change_dish"));
    label_change_dish_name=GTK_WIDGET(gtk_builder_get_object(builder, "label_change_dish_name"));
    label_change_dish_prod=GTK_WIDGET(gtk_builder_get_object(builder, "label_change_dish_prod"));
    label_change_dish_weight=GTK_WIDGET(gtk_builder_get_object(builder, "label_change_dish_weight"));
    label_change_dish_price=GTK_WIDGET(gtk_builder_get_object(builder, "label_change_dish_price"));
    entry_change_dish_name=GTK_WIDGET(gtk_builder_get_object(builder, "entry_change_dish_name"));
    entry_change_dish_prod=GTK_WIDGET(gtk_builder_get_object(builder, "entry_change_dish_prod"));
    entry_change_dish_weight=GTK_WIDGET(gtk_builder_get_object(builder, "entry_change_dish_weight"));
    entry_change_dish_price=GTK_WIDGET(gtk_builder_get_object(builder, "entry_change_dish_price"));
    button_change_dish_price_save=GTK_WIDGET(gtk_builder_get_object(builder, "button_change_dish_price_save"));
    


   
    gtk_widget_show(window_introduse);
    gtk_main();
    return EXIT_SUCCESS;
}



void on_button_create_file_introduse_clicked(GtkButton *b){
     gtk_widget_hide(window_introduse);
    gtk_widget_show(window_create_file);

}

void on_button_create_file_clicked(GtkButton *b){
   const gchar *path ;
   FILE* menu;
   path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
    if ((menu = fopen(path, "rb")) == NULL)
    {
        menu = fopen(path, "wb");
    }
   
   gtk_widget_hide(window_create_file);
    gtk_widget_show(window_choose_op);
    fclose(menu);

}


void on_button_for_print_clicked(GtkButton *b){

        const gchar *path ;
       FILE* menu;
        FILE* menu_help2;
        path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
    
        menu = fopen(path, "rb");
        menu_help2=fopen("help.txt", "w");
        fprintf(menu_help2,"                Меню\n");
fread(&dish, sizeof(dish), 1, menu);
        fprintf(menu_help2,"ЗАКУСКИ\n");
        while (!feof(menu))
        {
            if (dish.type_dish == 1)
                fprintf(menu_help2,"%s\n\tСклад: %s\n\tВага: %s гр\n\tЦіна: %s грн\n\n", dish.name, dish.prod, dish.weight, dish.price);           
            fread(&dish, sizeof(dish), 1, menu);
        }
        fseek(menu, 0, 0);
        fread(&dish, sizeof(dish), 1, menu);
        fprintf(menu_help2,"СУПИ\n");
        while (!feof(menu))
        {
            if (dish.type_dish == 2)
                fprintf(menu_help2,"%s\n\tСклад: %s\n\tВага: %s гр\n\tЦіна:%s грн\n\n", dish.name, dish.prod, dish.weight, dish.price);
            fread(&dish, sizeof(dish), 1, menu);
        }
        fseek(menu, 0, 0);
        fread(&dish, sizeof(dish), 1, menu);
        fprintf(menu_help2,"ОСНОВНІ СТРАВИ\n");
        while (!feof(menu))
        {
            if (dish.type_dish == 3)
                fprintf(menu_help2,"%s\n\tСклад: %s\n\tВага: %s гр\n\tЦіна: %s грн\n\n", dish.name, dish.prod, dish.weight, dish.price);
            fread(&dish, sizeof(dish), 1, menu);
        }
        fseek(menu, 0, 0);
        fread(&dish, sizeof(dish), 1, menu);
        fprintf(menu_help2,"ДЕСЕРТИ\n");
        while (!feof(menu))
        {
            if (dish.type_dish == 4)
                fprintf(menu_help2,"%s\n\tСклад: %s\n\tВага: %s гр\n\tЦіна: %s грн\n\n", dish.name, dish.prod, dish.weight, dish.price);
            fread(&dish, sizeof(dish), 1, menu);
        }
        fseek(menu, 0, 0);
        fread(&dish, sizeof(dish), 1, menu);
        fprintf(menu_help2,"НАПОЇ \n");
        while (!feof(menu))
        {
            if (dish.type_dish == 5)
                fprintf(menu_help2,"%s\n\tСклад: %s\n\tВага: %d гр\n\tЦіна: %0.2f грн\n\n", dish.name, dish.prod, dish.weight, dish.price);
            fread(&dish, sizeof(dish), 1, menu);
        }
        fseek(menu, 0, 0);

                fclose( menu_help2);
                system("xdg-open help.txt");

}
void on_button_for_change_clicked(GtkButton *b){
             gtk_widget_hide(window_choose_op);
             gtk_widget_show(window_change);
             gtk_editable_delete_text (GTK_EDITABLE(entry_for_change),0,-1);
             gtk_editable_delete_text (GTK_EDITABLE(entry_change_dish_name),0,-1);
             gtk_editable_delete_text (GTK_EDITABLE(entry_change_dish_prod),0,-1);
             gtk_editable_delete_text (GTK_EDITABLE(entry_change_dish_weight),0,-1);
             gtk_editable_delete_text (GTK_EDITABLE(entry_change_dish_price),0,-1);
}
void on_button_for_add_clicked(GtkButton *b){
             gtk_widget_hide(window_choose_op);
             gtk_widget_show(window_add);
}
void on_button_for_del_choose_clicked(GtkButton *b){
             gtk_widget_hide(window_choose_op);
             gtk_widget_show(window_del);
             gtk_editable_delete_text (GTK_EDITABLE(entry_for_delete),0,-1);
                             gtk_entry_set_placeholder_text(GTK_ENTRY(entry_for_delete),"...");
}
void on_button_main_menu_clicked(GtkButton *b){
             gtk_widget_hide(window_choose_op);
             gtk_widget_show(window_introduse);
            gtk_editable_delete_text (GTK_EDITABLE(entry_for_create),0,-1);
  
}


void on_button_for_snack_clicked(GtkButton *b){
            gtk_editable_delete_text (GTK_EDITABLE(entry_weight_snack),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_price_snack),0,-1);
                    gtk_editable_delete_text (GTK_EDITABLE(entry_name_snack),0,-1);
                        gtk_editable_delete_text (GTK_EDITABLE(entry_prod_snack),0,-1);
                    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_snack),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_snack),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name_snack),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_prod_snack),"...");
             gtk_widget_hide(window_add);
             gtk_widget_show(window_for_snack);
}
void on_button_for_soup_clicked(GtkButton *b){
                gtk_editable_delete_text (GTK_EDITABLE(entry_weight_soup),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_price_soup),0,-1);
                    gtk_editable_delete_text (GTK_EDITABLE(entry_name_soup),0,-1);
                        gtk_editable_delete_text (GTK_EDITABLE(entry_prod_soup),0,-1);
                                                    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_soup),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_soup),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name_soup),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_prod_soup),"...");
             gtk_widget_hide(window_add);
             gtk_widget_show(window_for_soup);
}
void on_button_for_main_dish_clicked(GtkButton *b){
                    gtk_editable_delete_text (GTK_EDITABLE(entry_weight_main_dish),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_price_main_dish),0,-1);
                    gtk_editable_delete_text (GTK_EDITABLE(entry_name_main_dish),0,-1);
                        gtk_editable_delete_text (GTK_EDITABLE(entry_prod_main_dish),0,-1);
                                                    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_main_dish),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_main_dish),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name_main_dish),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_prod_main_dish),"...");
             gtk_widget_hide(window_add);
             gtk_widget_show(window_for_main_dish);
}
void on_button_for_dessert_clicked(GtkButton *b){
                        gtk_editable_delete_text (GTK_EDITABLE(entry_weight_dessert),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_price_dessert),0,-1);
                    gtk_editable_delete_text (GTK_EDITABLE(entry_name_dessert),0,-1);
                        gtk_editable_delete_text (GTK_EDITABLE(entry_prod_dessert),0,-1);

                            gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_dessert),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_dessert),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name_dessert),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_prod_dessert),"...");
             gtk_widget_hide(window_add);
             gtk_widget_show(window_for_dessert);
}
void on_button_for_drink_clicked(GtkButton *b){
                gtk_editable_delete_text (GTK_EDITABLE(entry_weight_drink),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_price_drink),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_name_drink),0,-1);
                gtk_editable_delete_text (GTK_EDITABLE(entry_prod_drink),0,-1);
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_drink),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_drink),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name_drink),"...");
                gtk_entry_set_placeholder_text(GTK_ENTRY(entry_prod_drink),"...");
             gtk_widget_hide(window_add);
             gtk_widget_show(window_for_drink);
}


void on_button_save_dessert_clicked(GtkButton *b){
   const gchar *path ;
   FILE* menu;
   if(type_int(entry_weight_dessert)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_weight_dessert),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_dessert),"Error");
   }
   else if(type_float(entry_price_dessert)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_price_dessert),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_dessert),"Error");
   }
   else{
    path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));

   menu = fopen(path, "ab+");
   dish.type_dish = 4;
       strncpy(dish.name,gtk_entry_get_text(GTK_ENTRY(entry_name_dessert)),99);
        strncpy(dish.prod,gtk_entry_get_text(GTK_ENTRY(entry_prod_dessert)),99);
        strncpy(dish.weight,gtk_entry_get_text(GTK_ENTRY(entry_weight_dessert)),99);
        strncpy(dish.price,gtk_entry_get_text(GTK_ENTRY(entry_price_dessert)),99);

   fwrite(&dish, sizeof(dish), 1, menu);
   fclose(menu);

   gtk_widget_hide(window_for_dessert);
   gtk_widget_show(window_choose_op);
   }
}


void on_button_save_drink_clicked(GtkButton *b){
   
   const gchar *path ;
   FILE* menu;
      if(type_int(entry_weight_dessert)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_weight_drink),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_drink),"Error");
   }
   else if(type_float(entry_price_dessert)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_price_drink),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_drink),"Error");
   }
   else{
       path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
   menu = fopen(path, "ab+");
   dish.type_dish = 5;

           strncpy(dish.name,gtk_entry_get_text(GTK_ENTRY(entry_name_drink)),99);
        strncpy(dish.prod,gtk_entry_get_text(GTK_ENTRY(entry_prod_drink)),99);
        strncpy(dish.weight,gtk_entry_get_text(GTK_ENTRY(entry_weight_drink)),99);
        strncpy(dish.price,gtk_entry_get_text(GTK_ENTRY(entry_price_drink)),99);

  
   fwrite(&dish, sizeof(dish), 1, menu);
   fclose(menu);
    gtk_widget_show(window_choose_op);
       gtk_widget_hide(window_for_drink);
   }
}

void on_button_save_main_dish_clicked(GtkButton *b){
   const gchar *path ;
   FILE* menu;
         if(type_int(entry_weight_main_dish)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_weight_main_dish),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_main_dish),"Error");
   }
  else if(type_float(entry_price_main_dish)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_price_main_dish),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_main_dish),"Error");
   }
   else{
       path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
   menu = fopen(path, "ab+");
   dish.type_dish = 3;
      
       strncpy(dish.name,gtk_entry_get_text(GTK_ENTRY(entry_name_main_dish)),99);
        strncpy(dish.prod,gtk_entry_get_text(GTK_ENTRY(entry_prod_main_dish)),99);
        strncpy(dish.weight,gtk_entry_get_text(GTK_ENTRY(entry_weight_main_dish)),99);
        strncpy(dish.price,gtk_entry_get_text(GTK_ENTRY(entry_price_main_dish)),99);
      

  
   fwrite(&dish, sizeof(dish), 1, menu);
   fclose(menu);
      gtk_widget_show(window_choose_op);
         gtk_widget_hide(window_for_main_dish);
   }

}

void on_button_save_snack_clicked(GtkButton *b){
   const gchar *path ;
   FILE* menu;
    if(type_int(entry_weight_snack)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_weight_snack),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_snack),"Error");
   }
   else if(type_float(entry_price_snack)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_price_snack),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_snack),"Error");
   }
   else{
    path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
   menu = fopen(path, "ab+");
   dish.type_dish = 1;



      strncpy(dish.name,gtk_entry_get_text(GTK_ENTRY(entry_name_snack)),99);
        strncpy(dish.prod,gtk_entry_get_text(GTK_ENTRY(entry_prod_snack)),99);
        strncpy(dish.weight,gtk_entry_get_text(GTK_ENTRY(entry_weight_snack)),99);
        strncpy(dish.price,gtk_entry_get_text(GTK_ENTRY(entry_price_snack)),99);



   fwrite(&dish, sizeof(dish), 1, menu);
   fclose(menu);
      gtk_widget_show(window_choose_op);
         gtk_widget_hide(window_for_snack);
   }
}

void on_button_save_soup_clicked(GtkButton *b){
   const gchar *path ;
   FILE* menu;
            if(type_int(entry_weight_soup)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_weight_soup),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_weight_soup),"Error");
   }
   else if(type_float(entry_price_soup)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_price_soup),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price_soup),"Error");
   }
   else{
       path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
   menu = fopen(path, "ab+");
   dish.type_dish = 2;


       strncpy(dish.name,gtk_entry_get_text(GTK_ENTRY(entry_name_soup)),99);
        strncpy(dish.prod,gtk_entry_get_text(GTK_ENTRY(entry_prod_soup)),99);
        strncpy(dish.weight,gtk_entry_get_text(GTK_ENTRY(entry_weight_soup)),99);
        strncpy(dish.price,gtk_entry_get_text(GTK_ENTRY(entry_price_soup)),99);


   fwrite(&dish, sizeof(dish), 1, menu);
   fclose(menu);

      gtk_widget_show(window_choose_op);
         gtk_widget_hide(window_for_soup);
  }
}

void on_button_for_delete_clicked(GtkButton *b){
    const gchar *path ;
    int flag=0;
    path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
    FILE* menu;
    menu = fopen(path, "ab+");
    char name_dish[100];
    strncpy(name_dish,gtk_entry_get_text(GTK_ENTRY(entry_for_delete)),99);
    fseek(menu, 0, 0);                      
    FILE* menu_helper = fopen("helper.bin", "wb");
    fread(&dish, sizeof(dish), 1, menu);
    int i = 0;
    while (!feof(menu))
    {
        if (strcmp(name_dish, dish.name))
        {
            fwrite(&dish, sizeof(dish), 1, menu_helper);
            i++;
            
        }else{
             flag=1; 
        }
        fread(&dish, sizeof(dish), 1, menu);
  
    }
    fclose(menu_helper);
    fclose(menu);
    menu = fopen(path, "wb");
    menu_helper = fopen("helper.bin", "rb");
    while (i)
    {
        fread(&dish, sizeof(dish), 1, menu_helper);
        fwrite(&dish, sizeof(dish), 1, menu);
        i--;
    }
    fclose(menu_helper);
    fclose(menu);
    if(flag==1){
    gtk_widget_show(window_choose_op);
    gtk_widget_hide(window_del);
    }else{
    gtk_editable_delete_text (GTK_EDITABLE(entry_for_delete),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_for_delete),"Такої страви немає в меню");
    }
}

void on_button_for_change2_clicked(GtkButton *b){
            const gchar *path ;
            char name_dish[100] ;
            int flag=0;
              path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
                strcpy(name_dish,gtk_entry_get_text(GTK_ENTRY(entry_for_change)));
            FILE* menu;
            menu = fopen(path, "rb");
            while (!feof(menu)){
        if (!strcmp(name_dish, dish.name))
        {
            gtk_widget_hide(window_change);
            gtk_widget_show(window_change_dish);

             flag=1;
        }
        fread(&dish, sizeof(dish), 1, menu);
        }
    fclose(menu);
    if(flag==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_for_change),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_for_change),"Такої страви немає в меню");
    }

}

void on_button_change_dish_price_save_clicked(GtkButton *b){
             if(type_int(entry_change_dish_weight)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_change_dish_weight),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_change_dish_weight),"Error");
   }
   else if(type_float(entry_change_dish_price)==0){
    gtk_editable_delete_text (GTK_EDITABLE(entry_change_dish_price),0,-1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_change_dish_price),"Error");
   }
   else{
    const gchar *path ;
    const gchar *name_dish ;
    path = gtk_entry_get_text(GTK_ENTRY(entry_for_create));
    name_dish = gtk_entry_get_text(GTK_ENTRY(entry_for_change));
    FILE* menu;
    menu = fopen(path, "rb+");
    fread(&dish, sizeof(dish), 1, menu);
    while (!feof(menu))
    {
        if (!strcmp(name_dish, dish.name))
        {
       strncpy(dish.name,gtk_entry_get_text(GTK_ENTRY(entry_change_dish_name)),99);
        strncpy(dish.prod,gtk_entry_get_text(GTK_ENTRY(entry_change_dish_prod)),99);
        strncpy(dish.weight,gtk_entry_get_text(GTK_ENTRY(entry_change_dish_weight)),99);
        strncpy(dish.price,gtk_entry_get_text(GTK_ENTRY(entry_change_dish_price)),99);

            fseek(menu, -(long)sizeof(dish), 1);
            fwrite(&dish, sizeof(dish), 1, menu);
            break;
        }
        fread(&dish, sizeof(dish), 1, menu);
    }
    fclose(menu);
    gtk_widget_show(window_choose_op);
    gtk_widget_hide(window_change_dish);
   }
}