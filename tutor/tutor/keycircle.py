import PySimpleGUI as sg

class keycircle:
  def __init__(self, options, padLeft):
    self.options = options
    if padLeft:
      self.padLeft = 200
    else:
      self.padLeft = 0

  def createTextGrid(options):
    def getEntry(entry):
      if len(options) > entry:
        return options[entry]
      else:
        return ''

    return [
        [getEntry(1), getEntry(2), getEntry(3)],
        [getEntry(4), getEntry(0), getEntry(5)],
        [getEntry(6), getEntry(7)]
    ]

  def get(self):

    def createElement(text):
      if (text == self.options[0]):
        textSize = 20
        color = 'orange'
      else:
        textSize = 10
        color = 'gray'

      return sg.Text(text, size=(4, 1), text_color=color, font=('Monospace', textSize))

    self.layout = [
      [createElement(v) for v in row]
        for row in keycircle.createTextGrid(self.options)]

    return sg.Column(self.layout, justification='center', pad=((self.padLeft, 0), (0, 0)), element_justification='center')

  def update(self, options):
    self.options = options
    textGrid = keycircle.createTextGrid(self.options)
    for y, row in enumerate(textGrid):
      for x, v in enumerate(row):
        self.layout[y][x].Update(v)
