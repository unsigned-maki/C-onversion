# C-onversion

Various conversion utilities as single header ANSI C library.

# Running Tests
```
git clone https://github.com/unsigned-maki/C-onversion.git
cd C-onversion
mkdir build
cd build 
CMake ..
make
```

# Usage
```c
// include the header.
#include "c_onversion.h"

int main()
{
	// construct a new Converter instance with the new_converter function.
	Converter *converter = new_converter();
	
	// use its functions.
	converter->character.to_upper("test");

	return 0;
}
```
