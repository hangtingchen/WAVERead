# WAVERead : What is it ?
It is **C code to read WAVE files**.

#What kind of Wave file do we want to read?
1. It should be a WAVE file.
2. The Format Code in the Wave file should be 0x001, which means WAVE\_FORMAT_PCM. That is, the file is non-compressed PCM.
3. There is no information chunks that precede or follow the sound data(data chunk).That is, we presume that the preamble in the file header is exactly 44 bytes long. The assumption is strong and not safe, however, it fits most of the WAVE records.

#The 44-byte-long head in the WAVE file

- $N_c$ Number of channels
- $N_s$ Number of samples
- $F$ Sample rate
- $M_s$ Each sample's length in byte
- $M_c$ Each container's length in byte
- Each block consists of $N_c$ samples.
- One container contains one sample. In usual, the container's size is equal or big than sample's size. For example, one sample is 24-bit-long and the container is 32-bit-long, which presented as **32-bit 24.0 float (type 1, 24-bit)** in Cool Edit.
- Endian is kind of important for reading the WAVE properly.


| Field        | Length         | Contents  | Endian |
| ------------- |:-------------:| -----| ---- |
| ckID | 4 | Chunk ID:"RIFF" | big |
| cksize | 4 | $4+24+8+M_c\times N_c \times N_s+(pad\_byte) $ | little |
| WAVEID | 4 | WAVE ID:"WAVE" | big |
| ckID | 4 | Chunk ID:"fmt" | big |
| cksize | 4 |Chunk size:16 | little |
| wFormatTag | 2 |WAVE\_FORMAT\_PCM,that is 0x0001 | little |
| nChannels | 2 | $N_c$ | little |
| nSamplesPerSec | 4 | $F$ | little |
| nAvgBytesPerSec | 4 | $F\times M_c\times N_c$ | little |
| nBlockAlign | 2 | $M_c\times N_c$ | little |
| wBitsPerSample | 2 | $M_s\times 8$ | little |
| ckID | 4 | Chunk ID:"data" | big |
| cksize | 4 | Chunk size:$M_c\times N_c \times N_s$ | little |
| sampled data | $M_c\times N_c\times N_s$ | the audio data | little |
| pad byte | 0 or 1 | padding byte if sampled data size if odd | |

#How to use these c code?