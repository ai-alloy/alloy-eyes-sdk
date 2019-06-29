#!/bin/bash

if [ ! -d $1 ];then
	mkdir $1
fi
cd $1
cmake ../.. -DPROJ=$1 -DTOOLCHAIN=/opt/my-kendryte-toolchain/bin
make
