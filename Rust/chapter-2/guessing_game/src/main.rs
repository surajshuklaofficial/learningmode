use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Guess the number!!!");

    let secret_number = rand::thread_rng().gen_range(1..=100); // start..=end


    loop {
        println!("Please input your guess.");

        // In Rust, variables are immutable by default
        // String::new, a function that returns a new instance of a String
        // :: syntax in the ::new line indicates that
        // new is an associated function of the String type.
        let mut guess = String::new(); // created a mutable variable that is currently bound to a new, empty instance of a String

        io::stdin()
            .read_line(&mut guess) // takes whatever the user types into standard input and append that into a string (without overwriting its contents)
            .expect("Failed to read line!");

        
        // due to this rust will infer secret_number as u32 otherwise it would be i32 (by default)
        // because there is a comparision b/w secret_number and guess (below)
        // let guess: u32 = guess.trim().parse().expect("Please type a number!"); // here it will crashes the program if the input is not valid(convertible to number)
        
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        
        println!("You guessed: {guess}");
        
        // match expression is made up of arms
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
