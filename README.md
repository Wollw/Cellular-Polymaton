Cellular Polymaton
=============

About
-----

This implements a generalized cellular automaton framework for creating
automaton using unique geometry.  I created this to allow me to make sculptures using light to represent cell state using shapes other than a
simple square grid.  This required being able to explicitly say which
cells are neighbors to each other.

Configuration
-------------

The file "src/config.h" can be changed to configure the rules and cells
of the automaton as well as some other options.

Configuration Options
---------------------
The following is an explanation of the configurable options available
in the file "config.h"

    #define	CFG_CELL_COUNT	<size_t>
The number of cells in the automaton. Required.

    #define CFG_MOST_NEIGHBORS	<size_t>
The number of neighbor cells the cell with the most neighbors has.

    #define CFG_ENABLE_USART
If this is defined the automaton will output cell data over serial.

    struct rules cfg_rules
The members 'live' and 'dead' define the rules for cells that are
alive and dead.  For example, the rule set:
    `{ 0b00001100, 0b00001000 }`
defines rules for Conway's Game of Life.  The first bit field
has bits 2 and 3 set, meaning cells with 2 or 3 living neighbors
will stay alive (as the first rule set is for currently living
cells).  The second bit field has only bit 3 set, meaning cells
with three living neighbors will be born (as the second rule set is
for cells that are currently dead).

    struct cells cfg_cells
This has two members, 'neighbors' and 'initial\_state'.  'neighbors'
defines the cells that are considered neighbors to each cell and
'initial\_state' defines the initial state of the cell.  Cell's are
identified by the position in the cfg\_cells[] array and neighbor
relationships are defined in a bit field such that a bit field of 
0b1100 means a cell is neighbors with the cells at index 2 and 3 (as bits
2 and 3 are set).  'initial\_state' is either 'DEAD' or 'LIVE' but these
are truly just macros for false and true respectively so boolean values
can be used as well.  As an example here is a simple cfg\_cells array
defining a two cell automaton where the first cell starts out alive
the second starts dead and they are both neighbors to eachother:
    `cfg_cells[] = {
        { 0b10, LIVE },
        { 0b01, DEAD }
    }`

Compilation
------------

After creating a valid 'src/config.h' file you build by using the included
Makefile.  The Makefile doesn't define a MCU type so you either have to
define it in the Makefile yourself or just run make as follows:

    $ MCU=mymcu make

After compilation you can program with the following if the Makefile's
programmer settings match your setup:

    $ MCU=mymcu make program
