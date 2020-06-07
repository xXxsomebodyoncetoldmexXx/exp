@echo off
::A MUST HAVE TO EVALUATE VARIABLE AT RUN TIME RATHER PARSE TIME
setlocal EnableDelayedExpansion

:: GLOBAL VARIABLE
set n=1
for %%c in (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) do (
	set prob[!n!]=%%c
	set /A n+=1
)

::SETUP CONTEST FOLDER
set /P in=Code Forces Round: 
if "%in%"=="" (set /P folderName=Custom folder name: ) else (set folderName=round%in%)
mkdir D:\Repo\exp\codeforces\%folderName%
if !ERRORLEVEL!==1 (
	pause
	exit /B 1
)
pushd D:\Repo\exp\codeforces\%folderName%

::CREATE CONTEST FILES
set /P in="Number of problems (Default is 4): "
set /A numOfFile=%in%
if !numOfFile!==0 (
	set /A numOfFile = 4
)
for /L %%i in (1, 1, %numOfFile%) do (
  type nul > !prob[%%i]!.cpp
)
subl A.cpp
cmd
exit /B 0
