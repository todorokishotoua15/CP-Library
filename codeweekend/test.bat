@echo off

if %1%==clear (
	echo deleting all the files
	del *.in
	del *.out
	EXIT /B
)

g++ --std=c++17 -o solution %1

if %2%==show (
	solution < ../inputf.in > ../outputf.out
	EXIT /B	
)

set basename=input
set extension=.in

echo %extension%

for /l %%x in (1,1,%2) do (
	solution < %basename%%%x%extension% > output%%x.out
)