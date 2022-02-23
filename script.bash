#!/bin/bash

sudo apt update && sudo apt full-upgrade
sudo apt install unzip python-dev binutils-common software-properties-common libssl-dev libffi-dev build-essential gdb libmpfr-dev libmpc-dev binwalk pngcheck


# Install pwntools, gmpy2
pip3 install --upgrade pip pwntools gmpy2

# Make repo folder
mkdir repo
cd repo

# install pwndbg peda gef all in one
git clone https://github.com/apogiatzis/gdb-peda-pwndbg-gef
cd gdb-peda-pwndbg-gef
./install.sh

# install   radare2 and it plugin
git clone https://github.com/radareorg/radare2
radare2/sys/install.sh

# install z3 solver
git clone https://github.com/Z3Prover/z3
cd z3
python3 scripts/mk_make.py --python
cd build
make
make install
cd ../../

cd ..
