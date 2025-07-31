use std::io;
use std::io::Read;

fn main(){
    struct Circle{
        x: i32,
        y: i32,
        r: i32,
    };
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t:i32 = input.trim().parse().unwrap();

    struct Axis{
        x: i32,
        y: i32,
    };
    for _ in 0..t{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();

        let vector:Vec<i32> = input
            .trim()
            .split_whitespace()
            .map(|x|x.parse().unwrap())
            .collect();

        let start = Axis{
            x: vector[0],
            y: vector[1],
        };
        let end= Axis{
            x: vector[2],
            y: vector[3],
        };

        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let circle_num:i32= input
            .trim()
            .parse()
            .unwrap();
        let mut circle_v:Vec<Circle> = Vec::new();

        for _ in 0..circle_num{
            input.clear();
            io::stdin().read_line(&mut input).unwrap();
            let temp: Vec<i32> = input
                .trim()
                .split_whitespace()
                .map(|x| x.trim().parse().unwrap())
                .collect();

            circle_v.push(Circle{
                x: temp[0],
                y: temp[1],
                r: temp[2],
            });
        }
        let mut result = 0;
        for c in circle_v{
            let dist_s = (c.x-start.x).pow(2)+(c.y-start.y).pow(2);
            let dist_e = (c.x - end.x).pow(2)+(c.y-end.y).pow(2);

            if (dist_s<c.r.pow(2) && dist_e>c.r.pow(2)){result+=1;}
            else if (dist_s>c.r.pow(2)&& dist_e<c.r.pow(2)){result+=1};
        }
        println!("{}",result);

    }
}
