SUMMARY = "python3 library for parsing dates and time"
DESCRIPTION = "Library for parsing the following: \
  - Parse a time, get a datetime.time \
  - Parse a date, get a datetime.date \
  - Parse a datetime, get a datetime.datetime \
  - Parse a duration, get a datetime.timedelta \
  - Parse an interval, get a tuple of dates or datetimes \
  - Parse a repeating interval, get a date or datetime generator."
HOMEPAGE = "https://bitbucket.org/nielsenb/aniso8601"

DPN = "python-aniso8601"
INC_PR = "r0"
inherit debian-package
PV = "0.83"

LICENSE = "GPLv3+"
LIC_FILES_CHKSUM = "file://COPYING;md5=8f0e2cd40e05189ec81232da84bd6e1a"
inherit setuptools python3native
DEPENDS += "python3-setuptools-native"

# Empty DEBIAN_QUILT_PATCHES to avoid error "debian/patches not found"
DEBIAN_QUILT_PATCHES = ""

do_install_append() {
	# remove unwanted files
	rm -rf `find ${D}${libdir} -type d -name "__pycache__"`
}
