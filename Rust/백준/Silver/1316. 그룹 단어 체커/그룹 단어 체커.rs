use std::io::{self,BufRead,BufReader,BufWriter,Write};

fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num:i32 =  input.trim()
        .parse()
        .unwrap();
    let mut result = 0;
    for _ in 0..num {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut trashcan:Vec<char> = Vec::new();
        let mut pre = ' ';
        let mut is_groupword= 1;
        for ch in input.chars(){
            if pre != ch {
                if trashcan.contains(&ch){
                    is_groupword = 0;
                    continue;
                }else{
                    trashcan.push(pre);
                    pre = ch;
                }
            }
        }
        if is_groupword == 1 {
            result += 1;
        }
    }
    println!("{result}");
}
