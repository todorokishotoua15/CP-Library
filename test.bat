@echo off

g++ --std=c++17 -o solution %1

set basename=input
set extension=.in

echo %extension%

for /l %%x in (1,1,%2) do (
	solution < %basename%%%x%extension% > output%%x.out
)