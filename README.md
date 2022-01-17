# Introduction to VIM for intermediate level usage


This text document (which is a navidVIM.c file format only for fancy markup by default) is a quick intro to [VIM editor](https://www.vim.org/) that could be very useful both as a mini cheat sheet and a guide to start using it at an intermediate level without any previous knowledge.

Also a very quick intro for TMUX is available in the "miniTMUX.txt" file.

Here are the contents in the readme!



## Intro to VIM contents
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Hello! this is Navid :D 			
		  		
My blog: "navidmalek.blog.ir"	
				
THIS IS BASED ON "jadi.ir/"	
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  
 Basic modes =>
 
  	i -> insert mode
  	ESC -> normal mode
  	: -> command mode
  
  Basic commands =>
  
  	o -> new line down
  	O -> new line up
  	J -> join one line to the next
  	x,X -> delete char
  	:wq -> write and quit
  	r -> replace one char
  	a -> append
  	A -> append at the end of line
  	u -> undo
       ctrl + r -> redo
  	d -> delete (dw == delete word, dd == del line)
  	G -> go (1G -> first line, G -> end, 33G -> line 33)
  	y -> copy/yank (yy -> entire line, yw, ...)
  	p, P -> paste [P -> up, p -> down]
  	/navid -> search for "navid" (after search: n, N -> next match)
  	$ -> go to end of line
  	^ -> go to start of line
  	. -> repeat last insert/command
 	m + a => set a marker name "a"
	' + a => jump to the line where mark "a" is

  Visual mode =>
  
  	v -> visual mode (you can select with keyboard and then use your desired command on the selected part, like dd for deleting)
  		or like using > or < to shift the selected part
  		or after selecting, use : for entering command, e.g. use :sort to sort the selected lines
  		or select the part, and use ":normal A;" which will use the "A;" command on the selected part
  
  Set and color =>	
  
  	:set number/nonumber -> numbering of lines appear or not 
  	:colorschema -> for colors
  	:set autoindent -> auto indenting for inner loops/commands in coding
  	:set paste -> paste exactly (don't use autoindent or ...)
 	:set mouse +=a -> for using mouse in visual mode (-= for disabling it)

  You cand combine commands like:
  
  	NumberCommand -> 3x, 2o, ...
  	4dw -> delete 4 words from the curser point
  	1G -> go to line one
  	D$ -> delete from here to end of line
  	% -> go to next opening bracet/parantesize / if at the opening(closing) bracet -> go to the end(beginin) of it
  
  Some fancy commands =>
  
	:browse oldfiles -> to see and open recent edited files
  	:Explore -> for exploring file system (use :q to go back to file) 
  	:Vexplore -> devide the screen vertically (one for Explore, one for file)
  	:split or :vsplit -> for spliting or vertically spliting screen (and cloning the file currently opened)
  		// you can use splitting recursively and with "ctrl+W+ARROW" switch between them HOWEVER using TMux is recommended for this purposes
	ctrl + w | z (| means a pause) -> for closing the preview pane
  
  What is ! and system commands =>
  
  	! at the end of the command  -> to ovveride (e.g. :q! to force quit without saving)
  	:! -> for system command (e.g. :!ls, :!top)
  	!! or :.! -> for printing the output of system command in the code at the curser point (e.g. !! ls)
  
  Buffers =>
  
  	You can open multiple files at the same time in VIM that will be in opened in different buffers
  	:ls -> see the buffers
  	:b2 -> go to the buffer number two
  	:bn or :bp -> next or previous buffer
  	:b navid  -> partially searches for "navid" in the buffer names and switches to it
  	:bd -> deletes the buffer (closes the buffer)
  
  
  Replacing => 
  
  	you can replace strings using regex
  	:s/world/the_world -> replace first "world" with "the_world" in the current line
  	:s/world/the_world/g -> replace it globally in the entire line
  	:18,31s/world/the_world/g -> from number 18 to 31
  	:%s/world/the_world/g -> in the entire document
  	:18,24s/^/\// -> comment (in C) all the 18 to 24 lines (\ is the escape character before //)
	ctrl + v -> block select 
	=followed by=>
		Shift + I + # -> python code multiline comment
		OR
		x -> deletes first character (uncoments)
  
  For help =>
  
	:help COMMAND (e.g. :help smartcase, :help set, ...)

  How to install plugins =>
  
	1)	git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
	2) use:
		touch ~/.vimrc
	3) write the Vundle configuration into "vimrc" file
		{
			set nocompatible              " required
			filetype off                  " required

			" set the runtime path to include Vundle and initialize
			set rtp+=~/.vim/bundle/Vundle.vim
			call vundle#begin()

			" alternatively, pass a path where Vundle should install plugins
			"call vundle#begin('~/some/path/here')

			" let Vundle manage Vundle, required
			Plugin 'gmarik/Vundle.vim'

			" add all your plugins here (note older versions of Vundle
			" used Bundle instead of Plugin)

			" ...

			" All of your Plugins must be added before the following line
			call vundle#end()            " required
			filetype plugin indent on    " required

			set encoding=utf-8
		}
	4) use this command in VIM to install each plugin and configuration you add in "vimrc" file:
		:PluginInstall
	
	5) Adding and configuring some plugins for python:
       		There are many manyyyyy available plugins	
		you can find some of them in here which comments are in persian language:
		https://jadi.net/2020/05/vim-prat-3/

		Also for example if you want enable very basic folding based on indention you can add these lines into "vimrc" and install (using SimplyFold is more advanced for python) 
		the plugin:
		{
			" Enable folding
			set foldmethod=indent
			set foldlevel=99
		}

		Nice autoindent for python:
		{
			Plugin 'vim-scripts/indentpython.vim'
		}
	*) for removing a plugin, delete the entry from "vimrc" and then run the following command in VIM:
		:PluginClean

VIM PLUGINS TO CHECK OUT LATER:
	
	AutoComplete (NEW) https://github.com/neoclide/coc.nvim
	Python Mode https://github.com/python-mode/python-mode
	Tag Bar (overview list of the code): https://github.com/preservim/tagbar -> (installation) https://jdhao.github.io/2018/09/28/nvim_tagbar_install_use/
	Different Colors for Blocks: https://github.com/frazrepo/vim-rainbow 
	Gigutter shows git diff summary: https://www.vim.org/scripts/script.php?script_id=4827

	A list of good plugins -> https://github.com/akrawchyk/awesome-vim




## Intro to TMUX contencts

So here is an intro for TMUX too!


Many TMUX shortcuts are like:

	ctrl + B | or +  ....
	| means to pause after the previous combination
	
Some combinations:

	ctrl + b | ? => some keyboard shortcuts
	ctrl + b | % => split vertically
	ctrl + b | " => split horizontally
	ctrl + b | ArrowKeys => for switching panes
	ctrl + b + ArrowKeys => for resizing panes
	ctrl + b | z => for focusing/unfocusing on the current pane
	ctrl + b | t => for showing time in the pane
	ctrl + b | 0,1,...,n => switch between windows
	ctrl + b | c => create new tmux window
	ctrl + b | d => detach from session
	ctrl + b | PageUP => for going up in the output (for long outputs of a command)	
		q => to quit this browsing mode	
		ctrl + s => to search in this mode		
		

TMUX for session attachment:

	tmux ls => show active sessions
	tmux attach -t 0,1,...,n => attach to a session (you can use name of a session instead of number)
	tmux new -s NAVID => create new session named NAVID		 


For synchronizing the input of all panes:

	ctrl + b | :
		setw synchronize-panes on => all panes have the synchronized input
		setw synchronize-panes off => non-synchronize


To enabile 256 color mode in TMUX (useful in VIM):

	tmux -2 .... 



For a pretty good cheatsheet, visit here:	

	https://gist.github.com/andreyvit/2921703




