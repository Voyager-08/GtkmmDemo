#include <gtkmm/application.h>
#include "view/main_window.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.example.gtkmmdemo");
    return app->make_window_and_run<MainWindow>(argc, argv);
}
