# Sierpinski

[![Build](https://github.com/nwagyu/sierpinski/actions/workflows/build.yml/badge.svg)](https://github.com/nwagyu/sierpinski/actions/workflows/build.yml)

This is an app that will draw the Sierpinski triangle on your NumWorks calculator.

## Install the app

Installing is rather easy:
1. Download the latest `sierpinski.nwa` file from the [Releases](https://github.com/nwagyu/sierpinski/releases) page
2. Head to [my.numworks.com/apps](https://my.numworks.com/apps) to send the `nwa` file on your calculator

## How to use the app

Well, there isn't much to do. Just launch it and watch. You can press the "Home" button to exit.

## Build and run the app

To build this sample app, you will need to install the [embedded ARM toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) and [nwlink](https://www.npmjs.com/package/nwlink).

```shell
brew install numworks/tap/arm-none-eabi-gcc node # Or equivalent on your OS
npm install -g nwlink
make run
```
