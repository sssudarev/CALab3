# Laboratory work #3

Command line tool for file content comparison.

## Usage:

### --help (-h)

Shows the manual for the program.

#### Example

- ./cmpr --help

### --first (-f)

Inputs first file.

#### Arguments

- **$1** (string): The file name.

#### Example

- ./cmpr --first file.md

### --second (-s)

Inputs second file.

#### Arguments

- **$1** (string): The file name.

#### Example

- ./cmpr --second file.md

### --detailed (-d)

Gives more detailed comparison.

#### Example

- ./cmpr --first file1.md --second file2.md --detailed
