kbuild-template
===============

This is a project template, that uses the Linux Kernel build system Kbuild.

Kbuild was originially developed to be used with the Linux Kernel.
It implements a powerfull configuration and build infrastructure that
allowes you to build a project with only the sources, that are really
needed to fit your configuration.

But Kbuild can not only be used along with the Linux kernel. Lots of other
projects use the Kbuild system as well. A few famos examples:

- buildroot        -- https://buildroot.org/
- zephyr           -- https://www.zephyrproject.org/
- U-Boot           -- http://www.denx.de/wiki/U-Boot


This project showes you that Kbuild is a makefile framework for writing 
simple makefiles for complex and configurable tasks that you can easily 
use for your own purposes.

How it works
------------

The top Makefile reads the .config file, which comes from the application
configuration process.

The top Makefile is responsible for building building the application
It builds this goal by recursively descending into the subdirectories of
the application source tree.
The list of subdirectories which are visited depends upon the application
configuration. The top Makefile can include several other Makefiles that
supply function specific information to the top Makefile.

Each subdirectory has a kbuild Makefile which carries out the commands
passed down from above. The kbuild Makefile uses information from the
.config file to construct various file lists used by kbuild to build
any built-in targets.

scripts/Makefile.* contains all the definitions/rules etc. that
are used to build the application based on the kbuild makefiles.


Sample project
--------------

This project combines a pretty simple application with the Kbuild environment.
The Kbuild system itself was copied from the Linux Kernel. Next, the Makefiles
and scripts where simplified and most of the kernel specific rules and targets
where removed or replaced by out own application specific targets.

All changes to the Makefiles and scripts are logged in this git repository.


Building
--------

Building the sample application is quite simple. 

First configure it, then just call make to build it.

        make menconfig # Create the ".config" file
        make           # Build the application

These steps generate a small executable `myapp`,
which just print some messages to the console.

You can save default configurations into the `configs/` directory.
There are two sample default configurations one with all options
enabled (`all-y-defconfig`) and one with no option enabled (`all-n-defconfig`)

You can configure the project with a default configuration by calling e.g.

        make all-y-defconfig

        
The full list of configuration and build targets is available by:

        make help


How to use and modify this template for your own applications?
--------------------------------------------------------------

The application sources can easily be replaced and extended by your 
own files.

Currently the sources are located in the following directories:

- main/     -- Main application source
- lib/      -- A sample logging library, that will be compiled into a .a file
- include/  -- This directory holds all include files.

All you need to to is to modify the following files, according to your needs:

- Kconfig       in the top and all sub-directories
- Makefile      in the top and all sub-directories

Eventually also

- Kbuild

To get a starting point, just search for the string `myapp` in all Makefiles 
and Kconfig files. As a first task, replace these strings with your own 
application name.

It should be quite obvious how to extend this example to your needs.

You can add more subdirectories by adding to `objs-y` or `libs-y` variables
of the top-level `Makefile`.

In our sample, these variables are set to:

        objs-y          := main
        libs-y          := lib

You can also add further sub-sub directories, as you like.



Kbuild documentation
--------------------

The original Kbuild documentation is located at

Learn about the kconfig language:
`Documentation/kbuild/kconfig-language.txt`.

Learn how to write makefiles:
`Documentation/kbuild/makefiles.txt`.

This is the original documentation from the Linux Kernel
