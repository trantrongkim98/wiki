# FIND commandline in Linux

## Notes

1. -size [b|c|w|k|M|G]

2. -type [b|c|d|p|f|l|s|D]

3. 

## Usage

1. Find file bigger than 1M and replace it with empty content

    ```bash
    find . -type f -size +1M -exec sh -c 'echo "" > "$1"' _ {} \;
    ```
        -type f: find file
        -size +1M: find file have to be bigger than 1M
        -exec sh -c 'echo "" > "$1"' _ {}: each file found going to echo "" to it, _ {} make sure file path is correct
    ``


