# :soccer: FootLAN 2k17 :soccer:
FootLAN is a multiplayer game similar to popular [Pocket Soccer](https://play.google.com/store/apps/details?id=com.rastergrid.game.pocketsoccer&hl=sr) written in C++ programming using [SFML](https://www.sfml-dev.org/) library. The game is played using [LAN](https://en.wikipedia.org/wiki/Local_area_network) connection between two devices conneted.

![logo](https://github.com/dimaria95/footlan2k17/blob/master/screenshots/logo2.jpg)

## :computer: Getting Started

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

## :video_game: Gameplay

When start game is selected both players choose the team that they want to play with.
The player that chooses first , plays first. Both players simutaniously try to kick the ball into opponnents net.
Player kicks the ball by selecting his own player and pulling him in the opposite direction of where he wants to move the player.

* Select:  **space** 
* Exit the game: **Escape**
* Go back:  **Backspace** 
* Movement: **Mouse** 

![logo](https://github.com/dimaria95/footlan2k17/blob/master/screenshots/gameplay.png)

## :wrench: Built using
* [SFML](https://www.sfml-dev.org/) - game development library

## :mortar_board: Authors

* **Ivan Šeša** - [ivke080](https://github.com/ivke080)

* **Strahinja Stanojević** - [filozof50](https://github.com/filozof50)

* **Nikola Dimić** -  [dimaria95](https://github.com/dimaria95/)

## :book: License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

 
