import os
import subprocess

BUILD_DIR = "./build"
SRC_DIR = "./src"
BUILD_OS = "Windows"

for FILE in os.listdir(SRC_DIR):
    if FILE.endswith('.cpp') and BUILD_OS == "Windows":
        NEWNAME=FILE[:-4]
        subprocess.call(["g++", "-static", "-L./src/include/boost_1_80_0", f"{SRC_DIR}/{FILE}", "-o", f"{BUILD_DIR}/{NEWNAME}.exe"])
    elif FILE.endswith('.cpp') and BUILD_OS == "Linux":
        NEWNAME=FILE[:-4]
        subprocess.call(["g++", "-static", f"{SRC_DIR}/{FILE}", "-o", f"{BUILD_DIR}/{NEWNAME}"])
        subprocess.call(["chmod", "+x", f"{BUILD_DIR}/{NEWNAME}"])