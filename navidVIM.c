~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Hello world! :D	  		!!!
This is Navid! 			!!!
		  		!!!
My blog: "navidmalek.blog.ir"	!!!
				!!!
THIS IS BASED ON "jadi.ir/"	!!!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



	---------------------
---------AN INTRO TO "VIM"---------
	---------------------


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+  
+  
+  Basic modes =>
+  	i -> insert mode
+  	ESC -> normal mode
+  	: -> command mode
+  
+  Basic commands =>
+  	o -> new line down
+  	O -> new line up
+  	J -> join one line to the next
+  	x,X -> delete char
+  	:wq -> write and quit
+  	r -> replace one char
+  	a -> append
+  	A -> append at the end of line
+  	u -> undo
	ctrl + r -> redo
+  	d -> delete (dw == delete word, dd == del line)
+  	G -> go (1G -> first line, G -> end, 33G -> line 33)
+  	y -> copy/yank (yy -> entire line, yw, ...)
+  	p, P -> paste [P -> up, p -> down]
+  	/navid -> search for "navid" (after search: n, N -> next match)
+  	$ -> go to end of line
+  	^ -> go to start of line
+  	. -> repeat last insert/command
+  
+  Visual mode =>
+  	v -> visual mode (you can select with keyboard and then use your desired command on the selected part, like dd for deleting)
+  		or like using > or < to shift the selected part
+  		or after selecting, use : for entering command, e.g. use :sort to sort the selected lines
+  		or select the part, and use ":normal A;" which will use the "A;" command on the selected part
+  
+  Set and color =>	
+  	:set number/nonumber -> numbering of lines appear or not 
+  	:colorschema -> for colors
+  	:set autoindent -> auto indenting for inner loops/commands in coding
+  	:set paste -> paste exactly (don't use autoindent or ...)
+  
+  You cand combine commands like:
+  	NumberCommand -> 3x, 2o, ...
+  	4dw -> delete 4 words from the curser point
+  	1G -> go to line one
+  	D$ -> delete from here to end of line
+  	% -> go to next opening bracet/parantesize / if at the opening(closing) bracet -> go to the end(beginin) of it
+  
+  Some fancy commands =>
+  	:Explore -> for exploring file system (use :q to go back to file) 
+  	:Vexplore -> devide the screen vertically (one for Explore, one for file)
+  	:split or :vsplit -> for spliting or vertically spliting screen (and cloning the file currently opened)
+  		// you can use splitting recursively and with "ctrl+W+ARROW" switch between them HOWEVER using TMux is recommended for this purposes
+  
+  What is ! and system commands =>
+  	! at the end of the command  -> to ovveride (e.g. :q! to force quit without saving)
+  	:! -> for system command (e.g. :!ls, :!top)
+  	!! or :.! -> for printing the output of system command in the code at the curser point (e.g. !! ls)
+  
+  Buffers =>
+  	You can open multiple files at the same time in VIM that will be in opened in different buffers
+  	:ls -> see the buffers
+  	:b2 -> go to the buffer number two
+  	:bn or :bp -> next or previous buffer
+  	:b navid  -> partially searches for "navid" in the buffer names and switches to it
+  	:bd -> deletes the buffer (closes the buffer)
+  
+  
+  Replacing => 
+  	you can replace strings using regex
+  	:s/world/the_world -> replace first "world" with "the_world" in the current line
+  	:s/world/the_world/g -> replace it globally in the entire line
+  	:18,31s/world/the_world/g -> from number 18 to 31
+  	:%s/world/the_world/g -> in the entire document
+  	:18,24s/^/\// -> comment (in C) all the 18 to 24 lines (\ is the escape character before //)
+  
+  For help =>
+	:help COMMAND (e.g. :help smartcase, :help set, ...)
+
+  How to install plugins =>
+		git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
+	2) use:
+		touch ~/.vimrc
+	3) write the Vundle configuration into "vimrc" file
+		{
+			set nocompatible              " required
+			filetype off                  " required
+
+			" set the runtime path to include Vundle and initialize
+			set rtp+=~/.vim/bundle/Vundle.vim
+			call vundle#begin()
+
+			" alternatively, pass a path where Vundle should install plugins
+			"call vundle#begin('~/some/path/here')
+
+			" let Vundle manage Vundle, required
+			Plugin 'gmarik/Vundle.vim'
+
+			" add all your plugins here (note older versions of Vundle
+			" used Bundle instead of Plugin)
+
+			" ...
+
+			" All of your Plugins must be added before the following line
+			call vundle#end()            " required
+			filetype plugin indent on    " required
+
+			set encoding=utf-8
+		}
+	4) use this command in VIM to install each plugin and configuration you add in "vimrc" file:
+		:PluginInstall
+	
+	5) Adding and configuring some plugins for python:
+       		There are many manyyyyy available plugins	
+		you can find some of them in here which comments are in persian language:
+		https://jadi.net/2020/05/vim-prat-3/
+
+		Also for example if you want enable very basic folding based on indention you can add these lines into "vimrc" and install (using SimplyFold is more advanced for python) 
+		the plugin:
+		{
+			" Enable folding
+			set foldmethod=indent
+			set foldlevel=99
+		}
+
+		Nice autoindent for python:
+		{
+			Plugin 'vim-scripts/indentpython.vim'
+		}
+	*) for removing a plugin, delete the entry from "vimrc" and then run the following command in VIM:
+		:PluginClean
+
+
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

A playground for training and messing around with code/text:

To my knowledge, many chapters of the book are exactly what Linus ###
told the journalist (David Diamond) during the conversations the two had; #TODO
that may help you with the answer! ###

static int tops_init(void) {
	topsDir = proc_mkdir("elf_det", NULL); //creating the directory: elf_det in proc

	if (!topsDir) {
		return -ENOMEM;
	}	
        //0777 means full premmisions for the file
	topsFile = proc_create("det", 0777, topsDir, &tops_fops); //create proc file det with tops_fops file operations
        printk("det initiated; /proc/elf_det/det created\n");
	topsWrite = proc_create("pid",0777, topsDir, &write_fops);//create proc file pid with write_fops file operations
        printk("pid initiated; /proc/elf_det/pid created\n");

	if (!topsFile) {
		return -ENOMEM;
	}
	

	return 0;
}
