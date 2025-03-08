@echo off

g++ -std=c++17 -o solution b.cpp

g++ -std=c++17 -o brute temp.cpp

g++ -std=c++17 -o TestGenerator test.cpp

for /l %%x in (1, 1, 1000) do (

TestGenerator > input.in
    
    set a = solution
    set b = brute

    python croupier.py solution brute > output.out

    cat output.out

)


echo done