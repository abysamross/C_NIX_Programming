# C_NIX_Programming
## Brushing up programming in the *nix.

### This repo contains the following exercises:

1. [mmap and pthread](mmap_pthreads/mmaptrial.c):

	The objective is to spawn n ```posix``` threads and let each of these n threads
	```mmap()``` _filesize/n_ sized chunks of a file starting from _chunksize*i_
	offset in file (_where i=thread num_).
	The threads write these _mmap-ed_ chunks to files named _filename.txt.thread_num_
	in ```$PWD```.

2. [aligned mem](aligned_malloc/alignedmalloc.c):

	The objective is to allocate a size of memory whose starting address is aligned
	to a specified value using just the std available library functions, like ```malloc()```.

3. [char and line counting](counting):

	This is just a simple illustration of counting [chars](counting/cnt.c) and 
	[lines](couting/locnt.c) in a stream. The stream can be any file or ```STDIN```. 

	```Variadic``` functions (_functions that take variable # of arguments_) and 
	```getopt()```, ```getopt_long()``` for parsing command line options and their
	arguments are also explored.

	In the makefile, `$(filter-out`*`pattern`*`,`*`text`*`)` function was used to 
	filter out _pattern_ from _text_ and get a _substring_ of _text_ free from 
	_pattern_.

	In addition the program is written in a modular way, probably making it easier 
	to convert these modules into libraries later on if needed. Such modules 
	are the **mprint.c** (_the module for printing_), **fops.c** (_the module for buffered file ops_).

	**Usage**:

	```./cnt.out -l|-c [<stream name>]```

	- ```-c``` is for counting chars from <_stream name_> and ```-l``` is for counting lines.  
	- You can specify the optional <_stream name_> anywhere after the executable name.
	- If <_stream name_> is not mentioned, input is expected from ```STDIN```.
	- The ```-l``` and ```-c``` options can be mentioned together as ```-lc``` and they can also 
	  be seperately mentioned at the same time, but both will use the same stream i.e there can be
	  only one stream at all times.

	```./locnt.out --cc[=<streamA>]|--lc[==<streamB>]```

	- longoptions ```--cc``` is for counting chars and ```--lc``` is for counting lines.  
	- The optional streams can be different. Either or both of them can be a file or ```STDIN```,
	  (```STDIN``` when no stream is specified)

4. [keywords and qualifiers](keywords):

	This exercise generates the assembly output of C files in which variables having different 
	storage classes, qualifiers and linkages have been defined. The aim of this ex is to figure 
	out the where these variables are assigned memory in the processes' memory layout.
	
	`make` will output the preprocessor output to `STDOUT` in addition to generating assembly output 
	in `*.s` files.

	The storage classes __*static*__, __*auto*__, __*register*__ and the __*volatalile*__ qualifier is explored. 
	Look into the makefile to understand the `CFLAGS`  used to generate these output.

	Knowing the meanings of __*assembler directives*__ will help you make sense of the assembly output
	and in figuring out the location of these variables.

	**`NOTE:`** those meanings can be found here: https://docs.oracle.com/cd/E26502_01/html/E28388/eoiyg.html

5. [pthreads](pthreads)

	This excercise illustrates the use of pthread condition variables and
	pthread mutexes.

	This excercise is a solution to: https://leetcode.com/problems/print-in-order/

	For better understanding of using pthread related functions lookup **`LINUX MAN PAGES`** https://linux.die.net/man/


