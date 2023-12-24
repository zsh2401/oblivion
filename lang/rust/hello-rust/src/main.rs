// mod math;
// fn main() {
//     println!("Hello, world! {}", times3(2));
//     let mut s = Student { age: 10 };
//     s.add_age();
//     println!("New age is {}", s.age);
//     println!("Sin is {}", math::sin(0.3));
// }

// fn pow(x: i64) -> i64 {
//     return x * x;
// }
// fn times3(x: i64) -> i64 {
//     const T: i64 = 3;
//     return x * T;
// }

// struct Point {}
// struct Student {
//     age: i32,
// }
// impl Student {
//     fn add_age(&mut self) {
//         self.age += 1;
//     }
// }

use fltk::{app, prelude::*, window::Window};

fn main() {
    let app = app::App::default();
    let mut wind = Window::new(100, 100, 400, 300, "Hello from rust");
    // wind.
    wind.end();
    wind.show();
    app.run().unwrap();
}
