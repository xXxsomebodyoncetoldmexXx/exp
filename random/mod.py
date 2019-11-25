#!/usr/bin/env python3

import requests
import urllib.parse
import threading
from random import choice, shuffle, randint
from json import loads, dumps
from getpass import getpass
from bs4 import BeautifulSoup as bs
from time import sleep

base = "https://codeforces.com/"
contestName = input("Name of the contest: ")
contestDuration = max(int('0' + input("Length (Default 1 Hours): ")), 60)
numberOfContest = max(int('0' + input("Number of contest you want to combine (Default 1 contest): ")), 1)
typeOfProblem = input("Type of problem you want to add: ").upper()
contestLevel = int(input("Div 1 or 2: "))
Token = input("Please give me the token: ")

if(contestLevel == 1):
  contestLevel = "(Div. 1)"
else:
  contestLevel = "(Div. 2)"
if Token == "":
  print("")
  print("Seriously, well if that the case i gonna go to to sleep, bye!")
  sleep(3)
  print("...")
  sleep(3)
  print("What a cunt!")
  exit(1)

if contestName == "":
  contestName = "YOU ARE SUPER GAY"
if typeOfProblem == "":
  typeOfProblem = "ABCD"

# FETCHING CODEFORCESE USING THREAD
# class bot(threading.Thread):
#   def __init__(self, start, off, limit):
#     threading.Thread.__init__(self)
#     self.off = off
#     self.cur = start
#     self.limit = limit
#     self.s = requests.Session()

#   def run(self):
#     global Plist
#     while(self.cur <= self.limit):
#       print(f"Fetching {self.cur:05d}")
#       r = bs(self.s.get(base + f"/contest/{self.cur}").text, 'html.parser')
#       Plist.append(f"{self.cur} - {r.title.text}")
#       self.cur += self.off

# GET CONTEST LIST
# Plist = []
# botL = []
# for i in range(600):
#   botL.append(bot(i+1, 500, 1200))
#   botL[i].start()
# for i in range(600):
#   botL[i].join()
# with open("ContestList", "w+") as f:
#   for c in Plist:
#     f.write(c + "\n")


def makeMS(prob_list, userToken):
  global base
  global contestName
  global contestDuration
  with requests.Session() as s:
    s.cookies['X-User'] = userToken

    # GET CRSF TOKEN
    r = s.get(base + "/mashup/new").text
    r = bs(r, 'html.parser')
    csrfTk = r.form.input['value']

    # LOOK UP PROBLEM
    # action=getProblem&problemQuery={}&problemCount={}&csrf_token={}
    form = {}
    form["action"] = "getProblem"
    prob = []
    for idx, name in enumerate(prob_list):
      form["problemQuery"] = name
      form["problemCount"] = idx
      form["csrf_token"] = csrfTk
      r = s.post(base + "/data/mashup", data=form).text
      prob.append(r)

    # REGISTER PROBLEM INTO MASHUP
    # action=saveMashup&isCloneContest=false&parentContestId=&parentContestIdAndName=&contestName={}&contestDuration={}&problemsJson={}&csrf_token={}
    form = {}
    form["action"] = "saveMashup"
    form["isCloneContest"] = "false"
    form["parentContestId"] = ""
    form["parentContestIdAndName"] = ""
    form["contestName"] = contestName
    form["contestDuration"] = contestDuration
    form["problemsJson"] = str(prob).replace("'", "").replace("\\\\", "\\").replace(' {"englishName', '{"englishName')
    form["csrf_token"] = csrfTk
    r = s.post(base + "/data/mashup", data=form).text
    print(r)

probList = []
# MY MINI DATABASE - SAFE TIME TO LOOKUP
with open("ContestList", "r") as f:
  for line in f:
    if contestLevel in line:
      contestID = int(line.split("-")[0])
      if contestID > 400:
        probList.append(contestID)

have_add = False
Tproblem = []
while True:

  # LIST OF CONTEST THAT HAVE BEEN ADD
  ig = list(map(int, open("ignoreCont").read().split("\n")[:-1]))

  # GET CONTEST PROBLEM TYPE
  for _ in range(numberOfContest):
    while True:
      k = choice(probList)
      if k not in ig:
        break
    r = bs(requests.get(base + f"/contest/{k}").text, 'html.parser')
    filt = set()
    for t in r.findAll("option"):
      if t["value"] in typeOfProblem and t["value"] != "":
        filt.add(t["value"])
    for v in filt:
      Tproblem.append(f"{k}{v}")
    if randint(0, 1) == 1 and have_add == False:
      Tproblem.append(f"{k}D")
      have_add = True
      # print(k, r.title.text)
    ig.append(k)
  if have_add == False:
    Tproblem.append(f"{ig[-randint(1, 3)]}D")
  # IDK, JUST TO MAKE IT MORE FUN ¯\_(ツ)_/¯
  for _ in range(numberOfContest):
    shuffle(Tproblem)

  if len(Tproblem) < len(typeOfProblem) * numberOfContest:
    print("Oh i die, what a shame, let's me start over")
  else:
    makeMS(Tproblem, Token)
    break

with open("ignoreCont", "w") as f:
  for i in ig:
    f.write(str(i) + "\n")

