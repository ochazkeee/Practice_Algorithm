use std::io;
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t:i32 = input.trim().parse().unwrap();

    for _ in 0..t{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let temp: Vec<i32> = input.trim()
            .split_whitespace()
            .map(|x|x.trim().parse().unwrap())
            .collect();
        let (n,m) = (temp[0],temp[1]);
        let mut small = 0;
        let mut big = 0;

        if n==m{
            println!("1");
            continue;
        }
        else if n<m{
            small = n;
            big = m;
        }
        else if n>m{
            small = m;
            big = n;
        }

        let mut result : u64= 1;

        for i in 0..small{
            result *= (big-i) as u64;
            result /= (i+1) as u64;
        }
        println!("{result}");
    }
}
