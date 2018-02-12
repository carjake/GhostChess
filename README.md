![Logo](Docs/g10154.png)
# team11_RTEP5: Mechanised User vs. Computer Chess Board
Computer chess engines have become very advanced and are great for learning how to play or improving your skills. However, playing on a computer is just not the same as seeing the physical pieces move accross the board!

This project aims to design and build a mechanised chess engine, allowing users to play against the StockFish chess engine on a physical board. A mechanical arm will use an electromagnet to move the computer's pieces accross the board, mimicking a real chess expert.

![Layers of the system](Docs/path7416.png)

#Reasons why?
Playing games on a computer screen can be great - but it takes away from the game. Ghost Chess allows users to detach from their everyday computer use to really invest in the game itself, providing a more engaging gaming experience. Variable difficulty levels allow users to improve their chess skills. Not to mention that it is really cool!

## Table of Contents
[Getting Started](#getting_started)
  * [Required Hardware](#required_hardware)
  * [Building Software](#building_software)

# Getting Started <a name="getting_started"></a>

## Required Hardware <a name="required_hardware"></a>
2x Stepper Motors
Electromagnet and set of magnets
Sensor matrix (hall effect sensors or read switch)
Chess board and pieces


## Building Software <a name="building_software"></a>
To build this project's software: first clone the repository then run

```
cmake .
make

./chess

```

## Assessment Criteria

Responsiveness of the system. How long the system will take to move a piece.
Latency permitted for the piece -> dependant on where the piece has to move (
Sampling rate of 2Hz? for board state of 64 elements
Bus Protocol? 
Channels? 1
Kernel or userspace + why
data flow (formats, latencies, processing and conversions)
Buffering and sample size
  -> latency introduced from buffering?
Postprocessing of data and how that introduces latencies / processor load?
  -> Post processing of the data (sample rates sufficiently slow perhaps)
 
Threads/ load distributing ? ensure responsiveness

QT GUI permitted refresh rate and latency introduced (may not be so much of an issue since our sample rates are slow)

Structure software in classes, associated unit tests

### Team Roles
Have we decided on these?

Time allocation? Gantt chart perhaps -> soft-hard-ware and debugging and parallel efforts
Release strategy -> git tagged branches at various points in development

# Progress Success Evaluation
How does the project acheive the goals that are set out above?
