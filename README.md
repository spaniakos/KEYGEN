ArduinoDES
==========

Keygeneration algorythm for arduino and Raspberry pi


Usage
=====

### Raspberry  pi
install
```
sudo make install
cd examples_Rpi
make
```

What to do after changes to the library
```
sudo make clean
sudo make install
cd examples_Rpi
make clean
make
```

What to do after changes to a sketch
```
cd examples_Rpi
make <sketch>

or 
make clean
make
```

How to start a sketch
```
cd examples_Rpi
sudo ./<sketch>
```



License
=======

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
