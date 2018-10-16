***RESUME***

On all computer systems memory is a scarce resource. No matter how much memory is available, it never seems to be enough. It doesn’t seem so long ago that 256MB of RAM was considered sufficient, but now 2GB of RAM is commonplace as a sensible minimum requirement even for desktop systems, with servers usefully having significantly more.

Linux provides applications with a clean view of a huge directly addressable memory space. Additionally, it provides protection so that different applications are protected from each other, and it allows applications to apparently access more memory than is physically present in the machine, provided the machine is at least well configured and has sufficient swap space.

**Simple Memory Allocation**

You can allocate a great deal of memory on most Linux systems. Let’s start with a very simple program, but one that would defeat old MS-DOS-based programs, because they cannot access memory outside the base 640K memory map of PCs.

*Program memory1.c*

This program asks the malloc library to give it a pointer to a megabyte of memory. You check to ensure that malloc was successful and then use some of the memory to show that it exists. When you run the program, you should see Hello World printed out, showing that malloc did indeed return the megabyte of usable memory. We don’t check that all of the megabyte is present; we have to put some trust in the malloc code.

**Allocating Lots of Memory**

The next program asks to allocate somewhat more memory than is physically present in the machine, so you might expect malloc to start failing somewhere a little short of the actual amount of memory present, because the kernel and all the other running processes are using some memory.

*Program memory2.c*

You should adjust the define PHY_MEM_MEGS depending on your physical machine.

The program is very similar to the previous example. It simply loops, asking for more and more memory, until it has allocated twice the amount of memory you said your machine had when you adjusted the define PHY_MEM_MEGS. The surprise is that it works at all, because we appear to have created a program that uses every single byte of physical memory on the author’s machine. Notice that we use the size_t type for our call to malloc.

Let’s investigate further and see just how much memory we can allocate on this machine with memory3.c. Since it’s now clear that Linux can do some very clever things with requests for memory, we’ll allocate memory just 1K at a time and write to each block that we obtain.

*Program memory3.c*

The application’s allocated memory is managed by the Linux kernel. Each time the program asks for memory or tries to read or write to memory that it has allocated, the Linux kernel takes charge and decides how to handle the request.

Linux is very good at managing memory and will allow applications to use very large amounts of memory and even very large single blocks of memory. However, you must remember that allocating two blocks of memory won’t result in a single continuously addressable block of memory. What you get is what you ask for: two separate blocks of memory.

Usually, the result is that future calls to malloc may fail, not because there’s no memory to allocate, but because the memory structures have been corrupted. These problems can be quite difficult to track down, and in programs the sooner the error is detected, the better the chances of tracking down the cause.

**Abusing Memory**

Suppose you try to do “bad” things with memory.

*Program memory4.c*

The Linux memory management system has protected the rest of the system from this abuse of memory. To ensure that one badly behaved program (this one) can’t damage any other programs, Linux has terminated it.

Each running program on a Linux system sees its own memory map, which is different from every other program’s. Only the operating system knows how physical memory is arranged, and not only manages it for user programs, but also protects user programs from each other.

**The Null Pointer**

Unlike MS-DOS, but more like newer flavors of Windows, modern Linux systems are very protective about writing or reading from the address referred to by a null pointer, although the actual behavior is implementation-specific.

*Program memory5a.c*

In this case, Linux (in the guise of the GNU “C” library) has been forgiving about the read and has simply provided a “magic” string containing the characters ( n u l l ) \0. It hasn’t been so forgiving about the write and has terminated the program. This can sometimes be helpful in tracking down program bugs.

*Program memory5b.c*

This time you attempt to read directly from location zero. There is no GNU libc library between you and the kernel now, and the program is terminated. Note that some versions of UNIX do permit reading from location zero, but Linux doesn’t.

**Freeing Memory**

Fortunately, the Linux memory management system is quite capable of reliably ensuring that memory is returned to the system when a program ends. However, most programs don’t simply want to allocate some memory, use it for a short period, and then exit. A much more common use is dynamically using memory as required.

Programs that use memory on a dynamic basis should always release unused memory back to the malloc memory manager using the free call. This enables separate blocks to be remerged and enables the malloc library to look after memory, rather than have the application manage it.

*Program memory6.c*

This program simply shows how to call free with a pointer to some previously allocated memory.
