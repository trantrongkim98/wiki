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
## asfd

### 1. Find the file wuth name in current directory

Suppose we need to find the file has name tieudan.txt in current directory:

```shell
find . -name tieudan.txt
```

### 2. Find the file in home directory

Find the file in directory /home has name tieudan.txt:

```shell
find /home -name tieudan.txt
```

### 3. Find the file by name, do not case insensitive

```shell
find /home -iname tieudan.txt
```


### 4. Find the directory by name

Find directoies has name Tieudan in the directory:

```shell
find / -type d -name Tieudan
```

### 5. Find the file PHP by name

Find PHP file has name tieudan.php in current directory:

```shell
find . -type f -name tieudan.php
```

### 6. Find all files PHP inside the this directory

```shell
find . -type f -name "*.php"
```

#### Output:

./tieudan.php
./login.php
./index.php

### 7. Find the file has permission 777

```shell
find .type f -perm 0777 -print
```

### 8. Find the file do not have permission 777

```shell
find / -type f ! -perm 777
```

### 9. Find the file SGID has permission 644

```shell
find / -perm 2644
```

### 10. Find the file Sticky Bit has permission 551

```shell
find / -perm 1551
```

### 11. Find the file SUID

```shell
find / -perm /u=s
```

### 12. Find the file SGID

```shell
find / -perm /g=s
```

### 13. Find the file Read-Only

```shell
find / -perm /u=r
```

### 14. Find the file is executable

```shell
find /-perm /a=x
```

### 15. Find the file has permission 777 and change to 644

We can also combine finding files with permissions of 777, then use chmod to change permissions to 644:

```shell
find / -type f -perm 0777 -print -exec chmod 664 {} \;
```

### 16. Find the file has permission 77 and then change to 755

As same as above, we can finding file has permission 777 and then use chmod to change the permission to 755:

```shell
find / -type d -perm 777 -print -exec chmod 755 {} \;
```

### 17. Find and delete individual files

Suppose we need to delete a file called tieudan.txt then we can find and delete:

```shell
find .type f -name "tieudan.txt" -exec rm -f {} \;
```

### 18. Find and delete many files

Example we need to delete file .mp3 and .txt:

```shell
find . -type f -name "*.txt" -exec rm -f {} \;
```
#### HOẶC

```shell
find . -type f -name "*.mp3" -exec rm -f {} \;
```

### 19. Find empty files 

```shell
find /tmp -type f -empty
```

### 20. Find emmpty directories

```shell
find /tmp -type d -empty
```

### 21. Find hidden files

```shell
find /tmp -type f -name ".*"
```

### 22. Find a user file

To find the file has name tieudan.txt, in the root directory and owned by the root user:

```shell
find / -user root -name tieudan.txt
```

### 23. Find file owned by the user


To find all of files owned by Tieudan in /home directory:

```shell
find /home -user tecmint
```

### 24. FInd file owned by the group

To find all of files owned by `developer` Group in /home directory:

```shell
find /home -group developer 
```

### 25. Find all of files owned by the user

To Find all of files /txt owned by `Tieudan` in /home directory:

```shell
find /home -user tieudan -iname ".txt"
```

### 26. Find files modified in the last 50 days

```shell
find /-mtime 50
```

in there you can change 50 to any number do you want

### 27. Find files accessed in the last 50 days

```shell
find / -atime 50
```

Similar, you can change 50 to any number do you want.

### 28. Find files modified between 50 to 100 days ago

To find the file modified at least 50 days ago, but don't larger then 100 days

```shell
find / -mtime +50 -mtime -100
```

You can also change 50 and 100 to any number do you want.

### 29. Find file changed in last hour

```shell
find / -cmin -60
```

### 30. Find file modified in last hour

```shell
find / -mmin -60
```

### 31. Find file accessed last hour

```shell
find / -amin 60
```

### 32. Find file has size equal 50M

```shell
find / -size 50M
```

### 33. Find file has size between 50M and 100M

```shell
find / -size +50M -size -100M
```
The command above going to find the file has size larger than 50MB and lesser than 100MB

### 34. Find and remove file size is 50M

You can combine command rm and find in linux to remove the files of a certain size as follows:

```shell
find / -type f -size +100M -exec rm -f {} \;
```

### 35. Find and remove specify file

To find the mp3 files has size larger than 10MB:

```shell
find / -type f -name *.mp3 -size +10M -exec rm {} \;
```

