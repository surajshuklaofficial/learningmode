fn main() {
    let mut y = 5;
    println!("The value of y is: {y}");
    y = 6;
    println!("The value of y is: {y}");

    // shadowing
    println!("shadowing concept!!!");

    let x = 5;
    let x = x + 1; // x is shadowed by x

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");

    let mut z: u32 = 1;
    {
        // let mut z = z;
        z += 2;
    }
    println!("{z}"); // 3
}
