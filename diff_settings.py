#!/usr/bin/env python3

def apply(config, args):
    config["baseimg"] = "baserom.us.z64"
    config["myimg"] = "./build/quest64"
    config["mapfile"] = "./build/quest64.map"
    config['source_directories'] = ['.']
    config['makeflags'] = ['COMPARE=0']
    config["make_command"] = ["ninja"]