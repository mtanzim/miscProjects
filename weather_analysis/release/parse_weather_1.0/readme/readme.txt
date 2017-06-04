Tanzim Mokammel
3/21/2013


1. Place files ending in ".txt" into the folder of the executable (main folder)
2. Execute "parse_weather.exe"
3. Output files will be placed in "dat" subdirectory of the main folder

Notes:
All files ending in ".txt" will be processed. Avoid placing irrelevant ".txt" files in the main folder as it will cause errors.
This is why "readme.txt" is placed in its own folder.
Output files are named according to the station number specified inside the input files, NOT the input filenames.
There is no clean up algorithm. Manually delete files that are no longer needed. However, the program will NOT work if any of the orginal files are removed, or if 
the "tmp" and "dat" subdirectories are NOT present.

