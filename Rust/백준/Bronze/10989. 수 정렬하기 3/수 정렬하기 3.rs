use std::io::{self, BufReader, BufWriter, Write};
use std::io::prelude::*; // read_line, write_all 등을 위한 prelude 임포트

fn main() {
    let stdin = io::stdin();
    let mut reader = BufReader::new(stdin.lock());

    let stdout = io::stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let mut line = String::new();
    reader.read_line(&mut line).unwrap();
    let mut counts: Vec<usize> = vec![0; 10001];
    let n: usize = line.trim().parse().unwrap();
    for _ in 0..n {
        line.clear();
        reader.read_line(&mut line).unwrap();
        let num: usize = line.trim().parse().unwrap();
        counts[num] += 1; 
    }
    for i in 1..=10000 {
        if counts[i] > 0 {
            for _ in 0..counts[i] {
                writeln!(writer, "{}", i).unwrap();
            }
        }
    }

    writer.flush().unwrap();
}
