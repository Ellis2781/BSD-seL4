#!/bin/sh
git submodule update --remote --merge
cd usr.bin/make && ./bootstrap
