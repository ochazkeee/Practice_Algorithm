use std::io::{self, BufRead, BufReader, BufWriter,Write};

fn main(){
    let stdin = io::stdin();
    let stdout = io::stdout();

    let mut lines = BufReader::new(stdin.lock()).lines();
    let mut writer = BufWriter::new(stdout.lock());

    let temp:Vec<usize> = lines.next().unwrap().unwrap()
        .trim()
        .split_whitespace()
        .map(|x| x.trim().parse().unwrap())
        .collect();

    let mut seq:Vec<usize> = Vec::with_capacity(temp[1]);
    back(temp[0],temp[1],1,&mut seq,&mut writer);

}

fn back(
    n:usize,
    m:usize,
    start:usize,
    seq:&mut Vec<usize>,
    writer:&mut BufWriter<io::StdoutLock>
){
    if seq.len() == m {
        let line = seq.iter()
            .map(|x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ");
        writeln!(writer,"{}",line).unwrap();
        return;
    }

    for i in start..=n{
        seq.push(i);
        back(n,m,i,seq,writer);
        seq.pop();
    }
}
