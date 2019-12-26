#!/bin/bash
rm -f 1.hex
make
arm-none-eabi-objcopy -O ihex bin/*/*.elf 1.hex
st-flash --format ihex write 1.hex
