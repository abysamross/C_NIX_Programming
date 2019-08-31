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

6. [generic stack](stacks)

	This excercise contains a rudimentary generic stack implementation.

	Generic implies that it can hold data of any type, even derived ones.

	The following are the functions/operations in this data structure:

	- `initStack()` - a function which returns a pointer to a `struct stack`. 

	- `push(struct stack*, type, data)` - a macro which needs

		- `struct stack`, pointer (look into [mstack.h](stacks/mstack.h))
		- `type`, of items to be pushed in the stack. Eg. `int`, `int*`, `struct struct_name`, `float(*)[N]` etc.
		- `data`, to be pushed in the stack 

	`push` macro does type checking of `data` making sure that it of type `type` and then dynamically allocates memory to it 
	and passes this pointer as  `void*` to the actual `push()` of the stack. The stack just keeps this reference and returns it 
	whenever `top()` asks for it and removes this refernce when `pop()` pops it.

	- `pop(struct stack*)` - a macro that takes a `struct stack` pointer and calls `pop()` of that stack.

	- `top(struct stack*)` - a macro that takes a `struct stack` pointer and calls `top()` of that stack.

		- `top()` returns a `void` pointer containing the address of a location having data of type `type` (as passed in `push()`).
		- `top()` returns `NULL` if the stack is empty.

	- `empty(struct stack*)` - a macro that takes a `struct stack` pointer and calls `empty()` of that stack.

		- `empty()` returns 1 if the stack is empty and 0 otherwise.

	- `size(struct stack*)` -  a macro that takes a `struct stack` pointer and calls the `size()` of stack.

		- returns the number of elements of type `type` in the stack.
	
	- `freeStack(struct stack*)` - a function that pops all the elements of the stack and frees up all memory held by the stack.

	All the above mentioned operations except `freeStack(struct stack*)` take **O(1)** time. `freeStack(struct stack*)` takes **O(n)** time.

	All the macros does type checking for the stack pointer passed to it.

	An illustration/example can be found in [stacTrial.c](stacks/stacTrial.c) file.

	**NOTE:** `make` will build the/any example you include in the current directory along with the stack implementation and will leave the 
	stack obj file (`mstack.o`) for reuse in the same machine.

7. [unit testing C code](unit_testing_illustration)

	This is an illustration of unit testing in C.
   
	This uses MinUnit, a minimal unit testing framework for C, found here: http://www.jera.com/techinfo/jtns/jtn002.html

	And was brought to my notice by: https://www.youtube.com/watch?v=vEICc0zygWQ

	Please checkout the site and small video for easily understanding this.

	The core idea behind this frame work is just a couple of macros.

	- `mu_assert(message, test)` 	: which returns `message` if `test` evaluates to 0.
	- `mu_run_test_ret(test)`	 	: which runs `test()`, increments count of tests run and returns `message`, if any, returned by it.
	
	The following are my additions:

	- `mu_assert_name(message, test)`	: which prints `message` and the `__func__` from which it was invoked, if `test` evaluates to 0.
	- `mu_run_test(test)`	 			: which runs `test()`, increments count of tests run and also the count of failed tests if it fails.

	The `makefile` builds the test binary, `test.out`, for you.

	Make sure to name your test files with `main()` as `test_<feature_to_be_tested>.c`.

	Where `<feature_to_be_tested>.c` is the file containing containing the implementation of the feature/functionality that you want test.
