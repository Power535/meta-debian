inherit debian-package
require recipes-debian/sources/gdb.inc
BPN = "gdb"

LICENSE = "GPLv3+ & LGPLv3 & GPLv2+ & LGPLv2+ & GPL-3.0-with-GCC-exception & BSD-3-Clause & LGPLv2.1+"
LIC_FILES_CHKSUM = " \
    file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
    file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
    file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
    file://COPYING.LIB;md5=9f604d8a4f8e74f4f5140845a21b6674 \
    file://libdecnumber/dconfig.h;endline=23;md5=5f846eb921cb68667d3b67a3642aa02d \
    file://libiberty/bsearch.c;endline=29;md5=d61ed055b57f318f2809fb19e2e45e02 \
    file://libiberty/strverscmp.c;endline=19;md5=753161881764c9bee1aefe5411224b1c \
"

FILESPATH_append = ":${COREBASE}/meta/recipes-devtools/gdb/gdb"
SRC_URI += " \
    file://gdb-Fix-ia64-defining-TRAP_HWBKPT-before-including-g.patch \
"