#!/usr/bin/env python3

import hid

import PySimpleGUI as sg

import keycircle as keyCircle

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
  "\\t",
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
  "sum", #jump
  "woman",
  "money",
  "",
  "some"
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

uppercase_punctuation = {
  "!": "@",
  "'": "\"",
  ";": ":",
  ",": "<",
  ".": ">",
  "?": "/",
  "(": "[",
  ")": "]",
  "-": "_",
}

def getKeyboardByte(keyboard):
    while True:
        result = keyboard.read(9)[3]
        if result != 0:
            return result

def getKeys(keyboard):
    while getKeyboardByte(keyboard) != 232:
        pass

    result = set()

    while True:
        key = getKeyboardByte(keyboard)
        if (key == 243):
            break
        result.add(key - 232)

    return result

def mapKeys(keys, uppercase):
    index = 0
    for v in keys:
        index += 2**(v - 1)

    if (index < len(strings)):
        s = strings[index - 1]
        if (uppercase):
            if (s in uppercase_punctuation):
                return uppercase_punctuation[s]
            else:
                return s.title()
        else:
            return s
    else:
        return ''


def getIfPressed(keys, uppercase):
    return [mapKeys(keys | set([i]), uppercase) for i in list(range(1, 9)) ]

def getLabels(current, keys, uppercase):
    if (current in keys):
        return []
    else:
        first = mapKeys(keys | set([current]), uppercase)
        options = getIfPressed(keys | set([current]), uppercase)
        options = list(filter(lambda k: k != first, options))
        options.insert(0, first)
        return options

sg.theme('DarkAmber')

elements = [keyCircle.keycircle(getLabels(i, set([]), False), i == 5) for i in range(1, 9)]

window = sg.Window('Tutor', [[sg.Column([[circle.get()]]) for circle in elements]], keep_on_top=True)

with hid.Device(9025, 32823) as keyboard:
    lastKeys = set()
    while True:
        event, values = window.Read(timeout = 100)
        if event in (None, 'Cancel'):
            break
        keys = getKeys(keyboard)
        if (keys != lastKeys):
            lastKeys = keys
            for current in range(1, 9):
                tempKeys = keys - set([9, 10])
                uppercase = 9 in keys
                options = getLabels(current, tempKeys, uppercase)
                elements[current-1].update(options)

window.close()