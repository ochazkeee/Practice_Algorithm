use std::io::{self,BufRead,BufReader,BufWriter,Write,StdoutLock};

fn main(){
    let stdin = io::stdin();
    let stdout = io::stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let mut input = String::new();
    stdin.read_line(&mut input).unwrap();
    let temp:Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|x| x.trim().parse().unwrap())
        .collect();
    let mut seq:Vec<i32> = vec![];

    back_tracking(temp[0],temp[1],&mut seq,&mut writer);
}
fn back_tracking(n:i32,m:i32,seq:&mut Vec<i32>,writer: &mut BufWriter<StdoutLock>){
    if seq.len() == m as usize {
        let line = seq.iter()
            .map(|x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ");
        writeln!(writer,"{}",line).unwrap();
        return;
    }
    for i in 1..=n{
        if seq.contains(&i){continue;}
        seq.push(i);
        back_tracking(n,m,seq,writer);
        seq.pop();
    }
}
