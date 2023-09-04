# Little Hell Engine

**Little Hell Engine** (or just "little hell") is a project that aims to re-imagine the idTech 1 for the modern day. 

## Motivation

## Goals

Starting with a true to the original source port of DOOM (Chocolate DOOM) as its foundation, the little hell engine aims to: 

- Foundationally shift from being a source port to being a standalone game engine
- Renovate the idTech1 codebase and bring it into the 21st century using modern C best practices, with a cozy, high-level API
- Maintain the 'soul' of idTech1, without the baggage of legacy code and support for hardware that is older than I am.
- Facilitate the creation of new [boomer shooters](https://en.wiktionary.org/wiki/boomer_shooter) and other retro-style games built on the same roots of DOOM.

### Progress
- [ ] Remove support for backing screens which draw the HUD before blitting it to the real screen (`V_CopyRect()`)
- [ ] Create a new API called `Drawable` for easy management of all 2D elements such as status bars, HUDs, etc.
- [ ] Create a working demo game showcasing the engine.
- [x] Use the Meson build system, and a Nix shell for frictionless dependency management.
- [x] Removal of CMake and GNU Autotools
- [x] Removal of code that provides platform support for Windows (to be re-added at a later date)
- [x] Removal all packaging code for Win32, macOS, and Linux
- [x] Remove emulation for GUS, PAS, PC Speaker, MIDI via Fluidsynth/Timidity/Windows, and music packs.
- [x] Retain OPL emulation in software only. Nice and simple.
- [x] Remove DOOM II, Plutonia/TNT, Ultimate Doom, Final Doom, Strife, Heretic, and Hexen support
- [x] Remove deliberate emulation of bugs and quirks of Doom v1.2, v1.666, etc. Doom v1.9 is the basis of the little hell engine. 
- [x] No DeHackEd, no wad-merging like DeuTex.
- [x] Remove the `setup` application. Edit the `.cfg` by hand. Minimalism, baby.


| Chocolate Doom [(203f5da)](https://github.com/chocolate-doom/chocolate-doom/commit/203f5da3f9bfd38b5db7d9e2b501748ac550b602)    | files | blank | comment | code   | Little Hell Engine[(4d2877f)](https://github.com/ranguli/mindoom/commit/4d2877face48a5caad45ee60d20e69e13ef01f67) | files | blank | comment | code  |
|--------------------|-------|-------|---------|--------|--------------------|-------|-------|---------|-------|
| C                  | 329   | 37986 | 40769   | 198641 | C                  | 131   | 14199 | 11417   | 54595 |
| C/C++ Header       | 223   | 5647  | 7973    | 24521  | C/C++ Header       | 131   | 2691  | 4518    | 8719  |
| Meson              | 0     | 0     | 0       | 0      | Meson              | 1     | 13    | 7       | 227   |
| make               | 19    | 258   | 14      | 1072   | make               | 0     | 0     | 0       | 0     |
| CMake              | 16    | 98    | 258     | 858    | CMake              | 0     | 0     | 0       | 0     |
| Objective-C        | 5     | 303   | 196     | 789    | Objective-C        | 0     | 0     | 0       | 0     |
| Python             | 5     | 276   | 228     | 709    | Python             | 1     | 15    | 32      | 57    |
| Nix                | 0     | 0     | 0       | 0      | Nix                | 1     | 2     | 0       | 27    |
| XML                | 2     | 3     | 2       | 614    | XML                | 0     | 0     | 0       | 0     |
| YAML               | 4     | 28    | 3       | 296    | YAML               | 0     | 0     | 0       | 0     |
| m4                 | 1     | 40    | 4       | 246    | m4                 | 0     | 0     | 0       | 0     |
| Bourne Again Shell | 4     | 3     | 3       | 32     | Bourne Again Shell | 1     | 0     | 0       | 6     |
| Dockerfile         | 1     | 11    | 8       | 20     | Dockerfile         | 0     | 0     | 0       | 0     |
| TNSDL              | 1     | 1     | 0       | 11     | TNSDL              | 0     | 0     | 0       | 0     |
| Sum                | 626   | 45186 | 49487   | 230396 | Sum                | 307   | 18527 | 16914   | 70267 |


## Features

None yet really :(

## Examples

Soon!

The little hell engine uses the game code for DOOM 1 as its test bed. Development of the engine is done in tandem with the development of our own version of DOOM I (v1.9 Registered Version) running on the little hell engine. When we begin to add new functionality to the engine (as opposed to just rewriting large quantities of it), attention will switch to creating a demo game designed to showcase and utilize all of the engine functionality.

## Building

```bash
git clone https://github.com/ranguli/mindoom
cd doom
nix-shell shell.nix
meson build
ninja -C build
```


## Credits

