fn main() {
  let t = ([1; 2], [3; 4]); // [1; 2] => array => [1, 1], [3; 4] => array => [3, 3, 3, 3]
  let (a, b) = t;
  println!("{}", a[0] + t.1[0]); 
}
