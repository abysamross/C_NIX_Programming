# C_NIX_Programming
## Brushing up programming in the *nix.

### This repo contains the following exercises:

1. [mmap and pthread](mmap_pthreads/mmaptrial.c):

	The objective is to spawn n posix threads and let each of these n threads
	```mmap()``` _filesize/n_ sized chunks of a file starting from _chunksize*i_
	offset in file _(where i=thread num)_.
	The threads write these mmap-ed chunks to files named _filename.txt.thread_num_
	in ```$PWD```.

2. [aligned mem](aligned_malloc/alignedmalloc.c):

	The objective is to allocate a size of memory whose starting address is aligned
	to a specified value using just the std available library functions, like ```malloc()```.
