#Hanafuda
=====================

An exercise of using AI algorithm / c++.
I'm learning to play hanafuda now...
Just simple Koi-Koi (2-player version).
*NOT FINISHED*

##Rules
See the [official wiki](http://ja.wikipedia.org/wiki/%E8%8A%B1%E6%9C%AD) for rules.

##Battle Platform

###Compile & Run

* Compile: "cmake CMakeLists.txt" and then "make" 
 
* Run: "./hanafuda" 

* You should compile the AI first, then put **header files** and **lib files** into the "/ai", as shown in demo.

##AI

###Compile

* Compile: "cmake CMakeLists.txt" and then "make" 

* It will generate a **.dylib** file by compiling, put this file (and all header files you use) into the certain path in battle platform.

The MIT License (MIT)
------------------

Copyright (c) 2014 Xingdi (Eric) Yuan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.