#!/usr/bin/env python
# Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
# Copyright (C) 2009-2018 German Aerospace Center (DLR) and others.
# This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v2.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v20.html
# SPDX-License-Identifier: EPL-2.0

# @file    test.py
# @author  Pablo Alvarez Lopez
# @date    2016-11-25
# @version $Id$

# import common functions for netedit tests
import os
import sys

testRoot = os.path.join(os.environ.get('SUMO_HOME', '.'), 'tests')
neteditTestRoot = os.path.join(
    os.environ.get('TEXTTEST_HOME', testRoot), 'netedit')
sys.path.append(neteditTestRoot)
import neteditTestFunctions as netedit  # noqa

# Open netedit
neteditProcess, match = netedit.setupAndStart(neteditTestRoot)

# go to additional mode
netedit.additionalMode()

# select routeProbe
netedit.changeAdditional("routeProbe")

# create routeProbe (camera will be moved)
netedit.leftClick(match, 250, 220)

# create another routeProbe with the same default attributes (camera will be moved)
netedit.leftClick(match, 250, 220)

# set invalid frequency
netedit.modifyAdditionalDefaultValue(2, "-20")

# try to create routeProbe
netedit.leftClick(match, 250, 220)

# set valid default frequency
netedit.modifyAdditionalDefaultValue(2, "120")

# create routeProbe (camera will be moved)
netedit.leftClick(match, 250, 220)

# set invalid name
netedit.modifyAdditionalDefaultValue(3, "\"\"\"")

# try to create RouteProbe with invalid name
netedit.leftClick(match, 250, 220)

# set valid name
netedit.modifyAdditionalDefaultValue(3, "customName")

# create RouteProbe with valid name
netedit.leftClick(match, 250, 220)

# set invalid filename
netedit.modifyAdditionalDefaultValue(4, "&&&&&&&&")

# try to create RouteProbe with invalid filename
netedit.leftClick(match, 250, 220)

# set valid filename
netedit.modifyAdditionalDefaultValue(4, "myOwnFilename.txt")

# set invalid default begin
netedit.modifyAdditionalDefaultValue(5, "-11")

# try to create routeProbe
netedit.leftClick(match, 250, 220)

# set valid default begin
netedit.modifyAdditionalDefaultValue(5, "10")

# create routeProbe (camera will be moved)
netedit.leftClick(match, 250, 220)

# Check undo redo
netedit.undo(match, 6)
netedit.redo(match, 6)

# save additionals
netedit.saveAdditionals()

# save network
netedit.saveNetwork()

# quit netedit
netedit.quit(neteditProcess)
