# Random Password Generator

This program creates x number of random password(s) with user defined length.

## Installation/Prerequisite

```bash
1. You will need header file for random password generator.
```

## Program Description

```bash
- This program will generate k passwords of length n with m possible characters (based on the length of the alphabet). 
  The user has several alphabet options to choose for random password:
	 1. Lowercase English characters + digits.
	 2. Lowercase/Uppercase English characters + digits
	 3. Lowercase/Uppercase English characters, digits + extra characters: !@#$%^&*()[]{}\.:;/~
The password alphabet of possible characters is going to be read from a text file called alphabet.config and generated passwords are going to be shown to user in console and stored in passwords.txt file. 
If such file does not exist, the program will genrate the file and will save the generated passwords in that file.
The program will show the number of possible password combinations of such configuration calculated as: m to the power of n.
```
