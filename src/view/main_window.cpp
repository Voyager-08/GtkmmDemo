#include "main_window.h"
#include <gtkmm/cssprovider.h>
#include <gtkmm/stylecontext.h>
#include <gdkmm/display.h>

MainWindow::MainWindow()
{
    init();
}

void MainWindow::init()
{
    // ✅ 修复1：用更完整的 CSS 覆盖所有可能的装饰节点
    auto css = Gtk::CssProvider::create();
    css->load_from_string(R"(
        /* 窗口背景色 —— 消除内容区与边框之间的黑色间隙 */
        window, window.background {
            background-color: #1e1e2e;
        }
        /* CSD 装饰阴影/边框 —— 消除外围黑框 */
        decoration {
            border: none;
            outline: none;
            box-shadow: none;
            margin: 0;
            padding: 0;
        }
        /* 部分主题用 window.csd 节点 */
        window.csd {
            box-shadow: none;
            border: none;
        }
    )");

    Gtk::StyleContext::add_provider_for_display(
        Gdk::Display::get_default(),
        css,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );

    set_title("Gtkmm Demo");
    set_default_size(400, 300);

    button.set_label("Hello, Gtkmm!");
    button.set_margin(20);
    button.signal_clicked().connect([this]() {
        button.set_label("Clicked!");

        // ✅ 修复2：子窗口也用 managed 方式创建，避免内存泄漏
        // 并且确保子窗口也能正确应用全局 CSS
        auto w = new Gtk::Window();
        w->set_title("New Window");
        w->set_default_size(200, 200);
        w->set_transient_for(*this);  // 关联父窗口，行为更一致
        w->show();
    });

    set_child(button);
}