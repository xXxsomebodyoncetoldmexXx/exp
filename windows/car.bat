@echo off
Rem This program compile and run cpp file
if not [%1]==[] (
  START /B /WAIT g++ -std=c++17 -Wall -Wextra -Ofast -DLOCAL_PROJECT %1
  if %ERRORLEVEL% == 0 (
		echo [RUN]
		a.exe
	)
) else (
	echo "[USAGE]: car <file.cpp>"
	pause
)
