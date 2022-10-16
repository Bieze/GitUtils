# GitUtils

GitUtils is a program written for making managing your git server easier

## Support

| Support   | Answer    | When will it get support |
| :---      | :----:    |           ---:           |
| Linux     | ✔️        | v0.1.1                   |
| Windows   | ✔️        | v0.1.0                   |
| BSD Family| ✔️        | v0.1.1                   |


## Dependencies

| Name          | Version   | Platforms  | Other versions supported |
| :---          | :----     | ----:      |                  ---:    |
| Boost         | 1.74.0    | All        | Unknown                  |
| MinGW64 or 32 | 10.0.0    | Windows    | Unknown                  |


* Note For Windows users only:
    Please add the directory where Boost is installed to the system environment variables.
    For example on my setup I have boost installed at C:\SDKs\boost, so I added C:\SDKs to
    the system environment variables.


### Debian, Arch and Fedora and their derivatives
```bash
# Arch Linux and derivatives
pacman -S boost

# Debian and derivatives
apt-get install libboost-all-dev

# Fedora and derivatives
yum install boost
yum install boost-devel
```

## How to compile the full program

* For the stable version

```bash
git clone https://github.com/abdulh4ni/GitUtils.git
cd GitUtils

mkdir build && cd build

# Linux
cmake ..

# Windows
cmake .. -G "MinGW Makefiles"

make
```

* For the latest (Might not compile)

```bash
git clone https://github.com/abdulh4ni/GitUtils.git
cd GitUtils
git checkout devel

mkdir build && cd build

# Linux
cmake ..

# Windows
cmake .. -G "MinGW Makefiles"

make
```

## The finisher

```bash
# Installing on Linux
cd build
sudo mv gitutils /usr/bin
```

## Usage

```bash
# Create a repository
ssh git@host gitutils create [repository]

# Delete a repository
ssh git@host gitutils delete [repository]

# Lists all repositories
ssh git@host gitutils list

# Help command
ssh git@host gitutils help
```

## Contributing
[Pull requests](https://github.com/abdulh4ni/GitUtils/pulls) are welcome. For major changes, please open an [issue](https://github.com/abdulh4ni/GitUtils/issues) first to discuss what you would like to change.

## License
[GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html)