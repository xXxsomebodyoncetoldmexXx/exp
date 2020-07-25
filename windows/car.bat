@echo off
setlocal EnableDelayedExpansion
Rem This program compile and run cpp file
if not [%1]==[] (
  rem START /B /WAIT g++ -std=c++17 -Wall -Wextra -Ofast -DLOCAL_PROJECT %1
  g++ -std=c++17 -Wall -Wextra -Ofast -march=native -DLOCAL_PROJECT %1
  if !ERRORLEVEL! == 0 (
		echo [RUN]
		a.exe
	)
) else (
	echo "[USAGE]: car <file.cpp>"
	pause
)
