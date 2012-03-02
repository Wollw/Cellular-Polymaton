Automaton AVR
=============

About
-----

This is a cellular automaton simulator based around the Atmel AVR MCU.
All that is needed to use this simulation is an AVR (ATmega328P and 
ATtiny85 have been tested) and three 74HC595 shift registers.  Optional 
parts that can be added are an ADC input for dynamic setting of the delay
between cell state changes, a serial connection for reading the petridish's
state, and 4021 parallel to serial shift registers for reading the initial
state and rules from some external source (such as dip switches).

Configuration
-------------
Before compiling there must be a valid 'config.h' file in 'src' directory.
See 'cfg/example.h' for an example.

Pins used for the various inputs and outputs can be defined in the header
file for that purpose (ie: the shift registers used to control the LEDs can
be configured in leds.h).

Configuration Options
---------------------

	#define CONFIG_USE_SERIAL					<bool>
	"true" to output current cell states on rx, "false" to disable serial
	output.

	#define	CONFIG_USE_SWITCHES_FOR_SETTINGS	<bool>
	"true" to use rules read in from a parallel -> serial shift register
	"false" to use predefined values from CONFIG_RULES_SURV,
	CONFIG_RULES_BITH, and CONFIG_INITIAL_STATE.

	#define	CONFIG_RULES_SURV					<uint32_t>
	#define	CONFIG_RULES_BIRTH					<uint32_t>
	uint32_t where each bit represents the rule for a neighbor count.
	For example, the rules for Conway's Game of Life would be written like
	this:
		#define	CONFIG_RULES_SURV	0b1100
		#define CONFIG_RULES_BIRTH	0b1000
	bits 2 and 3 are set in the survival rules and only bit 3 is set
	for the birth rules.  Conway's Game of Life defines cells as
	surviving if they have 2 or 3 living neighbors and a dead cell comes to
	life if it has three living neighbors. This is only used if
	CONFIG_USE_SWITCHES_FOR_SETTINGS is false.

	#define	CONFIG_INITIAL_STATE				<uint64_t>
	uint64_t where each bit represents a cell's initial state.
	if CONFIG_INITIAL_STATE is set to 0b111000 then the cells with the ids
	of 3, 4, and 5 will be alive at the start of the start of the
	simulation.  This would result in a blinker with Conway's Game of Life
	rules. This is only used if CONFIG_USE_SWITCHES_FOR_SETTINGS is false.

	#define	CONFIG_USE_ADC_FOR_DELAY_TIME		<bool>
	If this is "true" the delay time will be determined by value read on
	the ADC pin defined in "adc.h". The delay will be the value read
	by on the ADC pin unless CONFIG_DELAY_MIN and CONFIG_DELAY_MAX are
	defined.

	#define CONFIG_DELAY_MIN					<uint16_t>
	#define	CONFIG_DELAY_MAX					<uint16_t>
	If CONFIG_USE_ADC_FOR_DELAY_TIME is "true" these values are used to
	set a minimum and maximum delay time for the ADC to scale it's reading
	by.  If CONFIG_DELAY_MIN is 1000 and CONFIG_DELAY_MAX is 2500 then
	if the ADC reading is 0 the delay will be 1 second and if it is 
	1023 it will be 2.5 seconds.

	#define CONFIG_DELAY_MS 					<uint16_t>
	Number of milliseconds to delay between update.  This is only used
	if CONFIG_USE_ADC_FOR_DELAY_TIME is set to false.

	#define CONFIG_NEIGHBORS					<uint64_t[]>
	An array of uint64_t values that represent the cells considered 
	neighbors to each cell.  Each bit of a neighbor value is represents
	a cell so that a neighbor value of 0b111 would mean that cells 0, 1, and
	2 are neighbors to that cell.  If that value is at index 4 then cell 4
	will be the cell with neighbors of 0, 1, and 2.

Installation
------------
Pick a configuration:
    $ cp cfg/myconfig.h src/config.h

To build for (replace "mymcu" with the mcu you are building for):
	$ MCU=mymcu make

To upload:
    $ make program
