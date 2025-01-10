pub struct Word {
    pub replacement_num: u16,
    pub count: u16,
    pub string: String,
}

impl Word {
    pub fn new(word_string: String) -> Self {
	Self {
	    replacement_num: 0,
	    count: 0,
	    string: word_string,
	}
    }
    pub fn print_name(&self){
	println!("{}", self.string);
    }
    pub fn increment_count(&mut self){
	self.count += 1;
    }
    pub fn set_replacement_num(&mut self, word_count: u16){
	self.replacement_num = word_count;
    }
}
