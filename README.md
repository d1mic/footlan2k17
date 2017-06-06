# FootLAN 2k17
FootLAN is a multiplayer game similar to popular [Pocket Soccer](https://en.wikipedia.org/wiki/DX-Ball) written in C++ programming using [SFML](https://www.sfml-dev.org/) library. The game is played using [LAN](https://en.wikipedia.org/wiki/Local_area_network) connection between two devices conneted.

![Ovde ide slika logoa kad je ubacim :) ]()

## Getting Started

These instructions will get you a copy of the game up and running on your local machine. This version is mainly tested on Ubuntu.

### Prerequisites

What things you need to install the software and how to install them

1. **Install g++**

```sh
$ sudo apt-get update
$ sudo apt-get install g++
```

2. **Install SFML library**

There are three ways to install SFML library:

* Using package manager

```sh
$ sudo apt-get install libsfml-dev
```
* Download the SDK

Download the SDK from the [download page](https://www.sfml-dev.org/download.php), unpack it and copy the files to your preferred location: either a separate path in your personal folder (like /home/me/sfml), or a standard path (like /usr/local). 

* Building SFML yourself
If you want to go this way, there's a dedicated tutorial on building SFML yourself. 


### Install and run the game

How to install and run the game on both computers.

1. Download the repository
2. Go to server folder and run
```
$ make
$ sudo ./server
```
on one of the computers.

3. Go to src folder and run
```
$ make
$ sudo ./main
```
on both computers.


## Built using
* [SFML](https://www.sfml-dev.org/) - game development library

## Authors

* **Ivan Šeša** - [ivke080](https://github.com/ivke080)

* **Strahinja Stanojević** - [filozof50](https://github.com/filozof50)

* **Nikola Dimić** -  [dimaria95](https://github.com/dimaria95/)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

 
