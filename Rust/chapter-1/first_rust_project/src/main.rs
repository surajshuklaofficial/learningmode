fn main() {
    println!("Hello, world!");

    let x = 5;
    let y = 10;

    // println!("x = {x} and y + 2 = {y}"); // ok
    // println!("x = {x} and y + 2 = {y + 2}"); // not ok, can't write expressions in braces
    println!("x = {x} and y + 2 = {}", y + 2);
}
