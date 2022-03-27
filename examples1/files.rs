use std::env;
use std::fs;
use std::path;

pub fn main() {
    let home_dir = env::home_dir();
    let file_path = path::PathBuf::from([home_dir, ".bashrc"]);
    let file = handle_err(fs::read(file_path));
    let result = handle_err(std::str::from_utf8(file));
    println!("{result}")
}

fn handle_err<T, E>(v: Result<T, E>) -> T {
    match v {
        Ok(t) => t,
        Err(e) => {
            println!("{e}");
            std::process::exit(1)
        }
    }
}
