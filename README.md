# I'm Learning C++!

I'm following `C++ Crash Course` by Josh Lospinoso [here](https://nostarch.com/cppcrashcourse). I'm writing all the chapter code and exercises for each chapter. Each chapter has their own directory as I go. 

Initially I was buildling each file with the command `g++ -g -o build/chapter_code chapter_code.pp && cd build && chapter_code.exe`. 

But recently, I just started using SCons to make my build command more universal. Now I can just use `Scons .` and it'll build. This started in Chapter 5.  
