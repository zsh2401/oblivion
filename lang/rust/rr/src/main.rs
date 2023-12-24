use fltk::{app, prelude::*, button::Button, window::Window};

mod math;

fn main() {
    let v = math::vector::Vector::new(&[1, 2]);
    let app = app::App::default();
    let mut wind = Window::new(100, 100, 400, 300, "Hello from rust");
    // wind.
    //
    let mut str = "as";
    let split = str.split("asd");
    let mut btn = Button::new(0, 0, 100, 10, "abc");
    // btn.handle_event(());
    btn.set_label("qqqq");
    wind.add(&btn);
    wind.end();
    wind.show();
    app.run().unwrap();
}