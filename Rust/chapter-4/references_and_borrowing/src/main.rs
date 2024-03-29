fn main() {
    // println!("Hello, world!");

    // let mut x: Box<i32> = Box::new(1);
    // let a: i32 = *x;         
    // *x += 1;                 
                         

    // let r1: &Box<i32> = &x;  
    // let b: i32 = **r1;       

    // let r2: &i32 = &*x;      
    // let c: i32 = *r2;

    // println!("{}", x);


    // let x: Box<i32> = Box::new(-1);
    // let x_abs1 = i32::abs(*x); // explicit dereference
    // let x_abs2 = x.abs();      // implicit dereference
    // assert_eq!(x_abs1, x_abs2);

    // let r: &Box<i32> = &x;
    // let r_abs1 = i32::abs(**r); // explicit dereference (twice)
    // let r_abs2 = r.abs();       // implicit dereference (twice)
    // assert_eq!(r_abs1, r_abs2);

    // let s = String::from("Hello");
    // let s_len1 = str::len(s); // explicit reference
    // let s_len2 = s.len();      // implicit reference
    // assert_eq!(s_len1, s_len2);

    // let mut v: Vec<i32> = vec![1, 2, 3];
    // let num: &mut i32 = &mut v[2];
    // *num += 1;
    // println!("Third element is {}", *num);
    // println!("Vector is now {:?}", v);

    let v = vec![1, 2, 3];
    let v2 = &v;
    give_and_take(&v, 4);
    println!("{}", v2[0]);

    fn give_and_take(v: &Vec<i32>, n: i32) -> i32 {
        v.push(n);
        v.remove(0)
    }
}
