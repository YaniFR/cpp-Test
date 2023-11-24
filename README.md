# cpp-Test

My first c++ project !

### Downloading the source code

You first need to clone the project :

```shell
git clone https://github.com/YaniFR/cpp-Test
cd cpp-Test
``` 
To update the source code you can use git pull inside the project

```shell
git pull
```

### Compiling

You can use g++ to compile the project

```shell
$cppFiles = Get-ChildItem -Path .\Source -Recurse -Filter *.cpp | Select-Object -ExpandProperty FullName
$cppFiles += "main.cpp"
g++ $cppFiles -o test
```
OR you can use [CMake](https://cmake.org/) to compile the project 

```shell
cmake
cd build
cmake --build .
```

### Running the code

You can run the code like this 

```shell
./test.exe number args

number : 
nothing (default) = test my little (very little) game !
1 : Return the args that you have provided
2 : Return the number of args
3 : Enter two args and return the args with the highest value in "poids.json"
4 : Useless, this was used to create a map
5 : Return all Key in "poids.json"
6 : Initialize a player named Potbuy and return basic information about it
```

### Contributing

Don't waste your time on this project it's just a test project for me to learn c++ ! <br />

BUT ! If you see some code that could be improved etc, you can contact me via @chef_yanou on discord to provide me all the information !
