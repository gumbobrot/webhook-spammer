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
git clone https://github.com/gumbobr0t/hi-spammer.git
cd hi-spammer
mkdir -p C:/libs
cp -r path/to/cLibs/* C:/libs
cmake .
make
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
