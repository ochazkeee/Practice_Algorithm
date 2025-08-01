use std::io::{self,BufReader};
use std::io::prelude::*;
fn main(){
    let stdin = io::stdin();
    let reader = BufReader::new(stdin.lock());
    let mut lines = reader.lines();
    let mut scores = 0;

    for _ in 0..5{
        let line = lines.next().unwrap().unwrap();
        let num: i32 = line.trim().parse().unwrap();

        match num{
            0..=39 => scores +=40,
            _ => scores += num,
        }

    }
    scores /= 5;
    println!("{scores}");
}
