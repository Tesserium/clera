# clera
Blows up your terminal if you mistype `clear`, but C++ version plus automatic adjustment according to the terminal size, also with more frames. Credit goes to [this repo](https://github.com/kz6fittycent/clera/tree/master).

## Installing
For most linux distros, use the following command:
```
curl https://raw.githubusercontent.com/Tesserium/clera/master/install.sh | sh
```
The script installs an executable `clera` to `/usr/local/bin` and create links `claer`, `celar`, `lcear`, `cllear`, `cleear`, `clleear` and `cls` (for Linux newcomers who are accustomed to the Windows command line) by default. You can edit the script to make it install to somewhere else, or comment out some lines if you don't need so many.
