use std::io;

#[derive(Clone, Copy)]
struct Coords {
    x: usize,
    y: usize,
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num: usize = input.trim().parse().unwrap();

    let mut arr: Vec<Vec<char>> = vec![vec![' '; 2 * num - 1]; num];
    let top = Coords { x: num - 1, y: 0 };

    draw(num, top, &mut arr);

    for row in arr {
        println!("{}", row.iter().collect::<String>());
    }
}

fn draw(size: usize, top: Coords, arr: &mut Vec<Vec<char>>) {
    if size == 3 {
        let x = top.x;
        let y = top.y;
        arr[y][x] = '*';
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        for i in 0..5 {
            arr[y + 2][x - 2 + i] = '*';
        }
        return;
    }

    let half = size / 2;

    draw(half, Coords { x: top.x, y: top.y }, arr);
    draw(half, Coords { x: top.x - half, y: top.y + half }, arr);
    draw(half, Coords { x: top.x + half, y: top.y + half }, arr);
}
