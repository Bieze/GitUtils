# GitUtils

GitUtils is a program written for making managing your git server easier

## Installation

Use the package manager on your system to install 
Mingw-w64. (BASICALLY A COPY OF THE GITOLITE CREATE REPO THING.)

```bash
# Ubuntu
apt-get install libboost-all-dev
apt-get install g++

make compile
```

## Usage

```bash
# Create a repository
ssh git@host create [repository]

# Delete a repository
ssh git@host delete [repository]

# Help command
ssh git@host help
```

## Contributing
[Pull requests](https://github.com/abdulh4ni/GitUtils/pulls) are welcome. For major changes, please open an [issue](https://github.com/abdulh4ni/GitUtils/issues) first to discuss what you would like to change.

## License
[GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html)