use std::io;

mod word_stuff;

fn main() -> io::Result<()> {
    let mut new_word = word_stuff::Word::new("Black".to_string());
    let num: u16 = 5;
    new_word.increment_count();
    new_word.set_replacement_num(num);
    println!("{}, {}, {}", new_word.string, new_word.replacement_num, new_word.count);
    Ok(())
}
