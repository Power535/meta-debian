SUMMARY = "Python3 version of the Olson timezone database"
DESCRIPTION = "python-tz brings the Olson tz database into Python. This library allows \
 accurate and cross platform timezone calculations using Python 2.3 or higher. \
 It also solves the issue of ambiguous times at the end of daylight savings, \
 which you can read more about in the Python Library Reference \ 
 (datetime.tzinfo)."
HOMEPAGE = "http://pypi.python.org/pypi/pytz/"

DPN = "python-tz"
INC_PR = "r0"
inherit debian-package
PV = "2012c+dfsg"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=22b38951eb857cf285a4560a914b7cd6"
inherit setuptools python3native
DEPENDS += "python3-setuptools-native"

do_debian_patch_prepend() {
	# ${S}/.pc is existed by default, so we need to remove it to
	# avoid error "unknown quilt patches already applied"
	rm -rf ${S}/.pc
}
do_install_append() {
	# remove unwanted files
	rm -rf `find ${D}${libdir} -type d -name "__pycache__"`
}
RDEPENDS_${PN} += "tzdata"
