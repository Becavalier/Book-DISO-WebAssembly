fn main() {
  println!("Hello, WebAssembly!");
  println!("{}", add(10, 20));
}

fn add(x: i32, y: i32) -> i32 {
 x + y
}
