#Cellular Polymaton
##About
This implements a generalized cellular automaton framework for creating
automaton using unique geometry.  I created this to allow me to make sculptures using light to represent cell state using shapes other than a
simple square grid.  This required being able to explicitly say which
cells are neighbors to each other.  The project is available under the MIT
License.

##Configuration
The file 'src/config.h' can be changed to configure the rules and cells
of the automaton as well as some other options.  The following is an
explanation of the configurable options available in that file.

###Required
	#define	CFG_CELL_COUNT	<size_t>
The number of cells in the automaton.

	#define CFG_MOST_NEIGHBORS	<size_t>
The number of neighbor cells the cell with the most neighbors has.

	struct rules cfg_rules
The members 'live' and 'dead' define the rules for cells that are
alive and dead.  For example `{ 0b00001100, 0b00001000 }`
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
	`{
		{ 0b10, LIVE },
		{ 0b01, DEAD }
	}`

###Optional
	#define CFG_ENABLE_USART
If this is defined the automaton will output cell data over serial.

	#define	CFG_USART_BAUDRATE	<uint64_t>
This defines the baudrate of the serial port.

	#define CFG_ENABLE_SHIFT
If defined the state will be shifted out to a shift register (like the
74HC595) using the definitions below.

	#define CFG_SHIFT_REGISTER_PIN_COUNT	<int>
The total number of pins between all the shift registers including unused
pins.  If you have three 74HC595 shift registers then this number will be
24 because 8 * 3 is 24.

	#define	CFG_SHIFT_DDR	<DDRn>
	#define	CFG_SHIFT_PORT	<PORTn>
	#define	CFG_RCLK		<PINn>
	#define	CFG_SER			<PINn>
	#define	CFG_SRCLK		<PINn>
The ports and pins used for controlling the shift registers. If you are
using `PB0`, `PB1`, and `PB2` to respectively control the `RCLK`, `SER`,
and `SRCLK` pins of the shift registers then you would define them as
follows:

	#define	CFG_SHIFT_DDR	DDRB
	#define	CFG_SHIFT_PORT	PORTB
	#define	CFG_RCLK		PIN0
	#define	CFG_SER			PIN1
	#define	CFG_SRCLK		PIN2

##Compilation

After creating a valid 'src/config.h' file you build by using the included
Makefile.  The Makefile doesn't define a MCU type so you either have to
define it in the Makefile yourself or just run make as follows:

	$ MCU=mymcu make

After compilation you can program with the following if the Makefile's
programmer settings match your setup:

	$ MCU=mymcu make program
