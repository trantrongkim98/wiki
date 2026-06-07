# Setup Multiple SSH Keys

## Usage

### Setup a single SSH key

1. Generate a ssh key

```shell
    ssh-keygen -t ed25519 -C "your_email@example.com"
```

**Note** If you are using a legacy system that doesn't support the Ed25519 algorithm, use:

```shell
     ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

2. custom ssh file name

```shell
Enter file in which to save the key (/Users/kimtt/.ssh/id_ed25519):
```
**eg:** id_rsa_your_company

The result of this command will generate two files named are *id_rsa_your_company* and *id_rsa_your_company.pub*


### Setup Multiple SSH Keys

1. Generate an another ssh key

```shell
    ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

2. Create config file

    a. If config file is not existed
    
    ```shell
        touch ~/.ssh/config
    ```

3. setup the config file

- insert the string below to ~/.ssh/config

```shell
    Host personalAccount.github.com
    HostName github.com
    IdentitiesOnly yes
    IdentityFile ~/.ssh/id_rsa

    Host companyAccount.github.com
    HostName github.com
    IdentitiesOnly yes
    IdentityFile ~/.ssh/id_rsa_company
```