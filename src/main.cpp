#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow() {
        set_title("Gtkmm Demo");
        set_default_size(400, 300);

        button.set_label("Hello, Gtkmm!");
        button.set_margin(20);
        button.signal_clicked().connect([this]() {
            button.set_label("Clicked!");
        });

        set_child(button);
    }

private:
    Gtk::Button button;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.example.gtkmmdemo");
    return app->make_window_and_run<MainWindow>(argc, argv);
}
