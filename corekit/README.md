# Usage

``` makefile
COREKIT_PATH = ./Corekit #path of corekit folder

INCLUDES = -I$(COREKIT_PATH)/includes #path of includes folder in corekit

%.o: %.c
	cc $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C $(COREKIT_PATH) #execute make in corekit folder
	cc $(INCLUDES) $(OBJ) -L$(COREKIT_PATH) -lcorekit -o $(NAME) #-lcorekit: includes library name (libcorekit)
```
<br>

_In this example the project structure is:_

``` bash
.
├── main.c
├── makefile
├── corekit ↓
│   ├── Makefile
│   ├── README.md
│   ├── includes ↓
│   └── src ↓

```

<br>

# Makefile explanation

The library (.a file) is called libcorekit.a beacause all the library during compilation must start with 'lib' prefix

<br>

<span style='color:green'>\t</span> &emsp; is just a tab for indentatin level

<br>

<span style='color:green'>$@</span>&ensp; rename with target file name and in the directory of c  original file

<span style='color:green'>$<</span>&emsp;takes the firts prerequisite, so the c file


<span style='color:green'>-c</span> &emsp;flag is used to generate .o file

```makefile
%.o: %.c
	@$(COMPILE) -c $< -Iincludes -o $@
```

<span style='color:green'>-c $<</span>&emsp;means that the compiler should compile the source file specified by the first prerequisite without linking it, resulting in the generation of an object file

<span style='color:green'>-Iincludes</span>&emsp;includes the 'includes' folder that contain all the headers that are to be included

<br>

<span style='color:green'>R=\033[0m</span>&ensp;isn't a color but 's a control code to reset the text attributes to the default, including color.

<br>

# TABLE OF CONTENT

- [Usage](#usage)
- [Makefile explanation](#makefile-explanation)
- [TABLE OF CONTENT](#table-of-content)

