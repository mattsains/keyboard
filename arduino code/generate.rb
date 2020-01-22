strings = [
    "a",
    "s",
    "w",
    "e",
    "x",
    "d",
    "we",
    "t",
    "f",
    "c",
    "fact",
    "r",
    "are",
    "set",
    "were",
    "n",
    "q",
    "j",
    "san",
    "y",
    "any",
    "eyes", # or need
    "and",
    "b",
    "fan",
    "", # weird
    "can",
    "be",
    "ran", # or next
    "best",
    "went", # or years
    "i",
    "z",
    "k",
    "ask",
    ",",
    "",
    "did",
    "said",
    "v",
    "if",
    "its",
    "wait",
    "ever",
    "five",
    "tried",
    "first",
    "h",
    "ah", # or han
    "his",
    "has",
    "he",
    "yeah",
    "she",
    "when", #had
    "bit", #hit
    "that",
    "this",
    "with",
    "the",
    "have",
    "these",
    "where", # heard
    "o",
    "(",
    ".",
    "",
    "-",
    "",
    "do",
    "wood",
    "g",
    "of",
    "cost",
    "two",
    "get", #or
    "for",
    "good", #order
    "words", #offered
    "u",
    "",
    "soon", #us
    "now",
    "you",
    "anyone",
    "done", #use
    "down",
    "but", #not
    "about",
    "just",
    "town",
    "your",
    "before", #often
    "course", #once
    "because",
    "l",
    "all",
    "lock",
    "will",
    "lie",
    "",
    "like",
    "well",
    "till", #lot
    "fall",
    "still", #lost
    "call", #lost
    "tell", #over
    "felt", #life
    "told", #lives
    "work", #least
    "oh",
    "hell",
    "soul", #john
    "who", #how
    "only",
    "alone", #lay
    "should", #house
    "would",
    "thought", #into
    "again", #having
    "such", #looking
    "without",
    "through", #other
    "another",
    "could",
    "already", #however
    "p",
    "?",
    ")",
    "pass",
    "'",
    "",
    "deep",
    "we'd", #passed
    "\\b",
    "pat",
    "",
    "past",
    "per",
    "part",
    "step", #press
    "we're", #perfect
    "m",
    "am", #man
    "ms",
    "mass",
    "my",
    "many",
    "seemed",
    "same", #made
    "",
    "",
    "",
    "camp", #pants
    "remember", #mr
    "army", #matter
    "spent", #mrs
    "came", #parent
    "!",
    "",
    "",
    "",
    "i",
    "",
    "keep",
    "speak", #paid
    "tip",
    "",
    "pick",
    "pack",
    "trip", #I've
    "private",
    "it's",
    "we've", #paris
    "him",
    "pain",
    "ship", #miss
    "spanish",
    "I'm",
    "happy",
    "she'd", #mind
    "make",
    "",
    "path",
    "smith", 
    "captain", #match",
    "them",
    "remain", #haven't
    "didn't",
    "that's", #perhaps
    ";",
    "",
    "",
    "",
    "pope",
    "",
    "possessed",
    "top",
    "gap",
    "stop", #post
    "",
    "report", #poor
    "page",
    "stopped", #process
    "power",
    "up",
    "",
    "sum", #jumped
    "woman",
    "monkey",
    "",
    "women",
    "put",
    "among",
    "most",
    "famous", #moscow
    "more",
    "from",
    "don't", #person
    "company", #major
    "pool",
    "lap",
    "slip", #lips
    "",
    "people",
    "apple", #pale
    "spoke", #people's
    "we'll", #please
    "pilot",
    "",
    "split", #politics
    "capital", #political
    "prove",
    "april", #plate
    "replied", #police
    "place",
    "million",
    "human",
    "\\n", #mission
    "small",
    "home",
    "example", #play
    "simply", #pulled
    "explained", #played
    "might",
    "film", #imagination
    "much",
    "almost", #making
    "government", #mother
    "family", #important
    "something", #possible
    "especially", #himself
]

strings.each_with_index do |s, index|
    puts "const char string_#{index}[] PROGMEM = \"#{s}\";"
end

print "const char * const keymap[] PROGMEM = { "

print strings.map.with_index {|s, index| "string_#{index}"} .join(", ")

puts "};"