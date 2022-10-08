# GitUtils

GitUtils is a program written for making managing your git server easier

## Installation

Use the package manager on your system to install g++.

```bash
# Debian and derivatives
apt-get update
apt-get install g++

# Arch Linux and derivatives
pacman -Syu
pacman -S g++

# Fedora and derivatives
dnf update
dnf install gcc-c++

# To install
make compile 
make install

# To update configuration file
cd ~/.gitutils/bin
make update-config

# To update the code
git pull

# See below on how to add to path.
```

## How to add to path.

```bash
# Fish
fish_add_path ~/.gitutils/bin

# Bash
echo export PATH="$HOME/.gitutils/bin:$PATH" >> ~/.bashrc
source ~/.bashrc
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