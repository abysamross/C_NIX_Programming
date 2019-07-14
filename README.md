# C_NIX_Programming
Brushing up programming in the *nix.

This repo contains the following exercises:

1. mmap and pthread:
	The objective is to spawn n posix threads and let each of these n threads
	mmap - filesize/n - sized chunks of a file starting from - chunksize*i -
	offset in file (where i=thread num).
	The threads write these mmap-ed chunks to files named <filename>.txt.<thread_num>
	in $PWD

2. aligned mem:
	The objective is to allocate a size of memory whose starting address is aligned
	to a specified value using just the std available library functions, like malloc.
