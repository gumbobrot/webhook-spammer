<p align="center">
  <img src="https://img.shields.io/badge/C++-17-blue.svg" alt="C++ Version">
  <img src="https://img.shields.io/badge/CMake-3.20-blueviolet.svg" alt="CMake Version">
  <img src="https://img.shields.io/badge/Curl-7.77-green.svg" alt="Curl Version">
</p>

# Discord Webhook Utility

A versatile Discord webhook utility for spamming and deleting messages.

## Overview

This project is a Discord webhook utility primarily written in C++, utilizing the Curl library for HTTP requests. It provides the ability to send spam messages through webhooks and delete messages from Discord channels.

## Dependencies

Before building the project, ensure you have the following dependencies installed:

- [CMake](https://cmake.org/download/)
- [Curl](https://curl.se/download.html)

Additionally, make sure you have all the required files from `cLibs` in the directory `C:/libs`. Create the directory if it doesn't exist.

## Building the Project

```bash
# Step 1: Clone the Repository
git clone https://github.com/gumbobr0t/hi-spammer.git

# Step 2: Navigate to Project Directory
cd hi-spammer

# Step 3: Prepare Dependencies
# Create the necessary directory for dependencies and copy the required files:
mkdir C:\libs
xcopy /s "cLibs\*" "C:\libs\"

# Step 4: Configure with CMake
cmake .

# If you encounter a "compiler not found" error, ensure you have a C++ compiler installed.
# Refer to the CMake documentation for information on how to specify a compiler.

# Step 5: Build the Project
make

# Note: If you're using Windows, you may need to use a different command or IDE to build the project.
# Refer to the documentation for your specific environment.

# Additionally, make sure that you have a C++ compiler installed on your system.
# You can check if a C++ compiler is available by running the command `g++ --version`.

# If you don't have a C++ compiler installed, you'll need to download and install one.
# For Windows, you can use tools like MinGW or Visual Studio.
# For macOS, Xcode Command Line Tools provide the necessary compiler.
# On Linux, you can use packages like `build-essential` on Debian-based systems
# or `gcc-c++` on Red Hat-based systems to install a compiler.

# After installing a C++ compiler, you may need to add it to your system's PATH environment variable
# so that CMake can find it. Consult the documentation for your specific compiler and operating system
# for instructions on how to do this.

# Once you have a C++ compiler installed and properly configured, rerun the `cmake .` command
# and then proceed with the `make` step.

# If you're using an IDE, refer to its documentation for instructions on how to configure the compiler for your project.
```

## Usage

To use the tool, run the executable with the following command:

```bash
./hi
```

The tool will prompt you with the following questions:

- `Hook URL`: Provide the webhook URL.
- `Message`: Enter the message to be sent.
- `Count`: Specify the number of times to send the message.
- `Delete Messages`: Type 'y' to delete messages, 'n' to skip

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the [MIT License](https://opensource.org/license/mit/).
