SUMMARY = "collection of utilities for WSGI applications"
DESCRIPTION = "The Web Server Gateway Interface (WSGI) is a standard interface between web\n\
 server software and web applications written in Python.\n\
 .\n\
 Werkzeug is a lightweight library for interfacing with WSGI. It features\n\
 request and response objects, an interactive debugging system and a powerful\n\
 URI dispatcher. Combine with your choice of third party libraries and\n\
 middleware to easily create a custom application framework."
HOMEPAGE = "http://werkzeug.pocoo.org/"

DPN = "python-werkzeug"
INC_PR = "r0"
inherit debian-package

LICENSE = "BSD-3-Clause & (MIT | GPLv2)"
LIC_FILES_CHKSUM = "\
	file://LICENSE;md5=ad2e600a437b1b03d25b02df8c23ad1c \
	file://werkzeug/debug/shared/jquery.js;beginline=5;endline=7;md5=473704caa6d04787eee46e7afdcb7edc"
inherit setuptools
do_install_append() {
	# remove unwanted files
	find ${D}${libdir} -type f -name "*.pyc" -exec rm -f {} \;
	rm -rf `find ${D}${libdir} -type d -name "__pycache__"`
}