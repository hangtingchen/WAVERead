# WAVERead : What is it ?
It is **C code to read WAVE files**.

# What kind of Wave file do we want to read?
1. It should be a WAVE file.
2. The Format Code in the Wave file should be 0x001, which means WAVE\_FORMAT_PCM. That is, the file is non-compressed PCM.
3. There is no information chunks that precede or follow the sound data(data chunk).That is, we presume that the preamble in the file header is exactly 44 bytes long. The assumption is strong and not safe, however, it fits most of the WAVE records.

# Install
Add following codes and compile with your own program. It is known that the code can be successfully installed under vs2008 and vs2015.
+ hmath.h & hmath.c basic math codes
+ WAVE.h & WAVE.c WAVE struct and methods to load WAVE file
+ main.c is a test file, no need to be included. Basic use of WAVE_t is shown in this file.
