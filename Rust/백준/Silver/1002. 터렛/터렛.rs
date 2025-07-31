use std::io;
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num: i32 =  input.trim().parse().unwrap();

    for _ in 0..num{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let nums: Vec<i32> = input.trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        let (x1,y1,r1,x2,y2,r2) = (nums[0],nums[1],nums[2],nums[3],nums[4],nums[5]);

        let dx = x1 - x2;
        let dy = y1 - y2;
        let distance_power = (dx*dx)+(dy*dy);

        let rsum_power = (r1+r2)*(r1+r2);
        let rdiff_power = (r1-r2)*(r1-r2);

        let result =
        if dx == 0 && dy == 0 && r1==r2{-1}
        else if distance_power > rsum_power{0}
        else if distance_power < rdiff_power{0}
        else if distance_power == rsum_power || distance_power == rdiff_power {1}
        else{2};

        println!("{}",result);
    }
}
