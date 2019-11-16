import threading

class name(threading.Thread):
  def __init__(self):
    threading.Thread.__init__(self)

  def run(self):
    print("Code here")
