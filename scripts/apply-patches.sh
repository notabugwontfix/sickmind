#!/bin/sh

git submodule foreach 'if [ -f ../patches/`basename $sm_path`.patch ]; then git apply ../patches/`basename $sm_path`.patch; fi'
