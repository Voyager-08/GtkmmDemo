#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();

private:
    Gtk::Button button;

    void init();
};

#endif // MAIN_WINDOW_H
