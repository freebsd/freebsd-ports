# Include before bsd.port.pre.mk for XFree86-4 ports which share 
# XFree86-4-libraries's patches.
# The purpose of this file is to reduce the duplicated code among the XFree86-4
# ports which each do only part of a standard XFree86 build.
#
# XBUILD_DIRS is the group of directories under ${WRKSRC} that will 
#   be built in.
# XINCLUDE_DIRS is the group of directories under ${WRKSRC} that need
#   to be Makefilesed or included in besides XBUILD_DIRS
# XINSTALL_DIRS is the group of directories which will have 
#   their install targets run.
# XINSTALL_MAN_DIRS is the group of directories which will have 
#   their install.man targets run.

DIST_SUBDIR=	xc
WRKSRC?=	${WRKDIR}/xc
USE_IMAKE=	YES
XFREE86_HTML_MAN=	yes
PATCHDIR=	${.CURDIR}/../../x11/XFree86-4-libraries/files
SCRIPTS_ENV+=	CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS}"
MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}"

_XBUILD_DIRS=	include ${XBUILD_DIRS}
XINSTALL_DIRS?=	${XBUILD_DIRS}
_XINCLUDE_DIRS=	${_XBUILD_DIRS} ${XINCLUDE_DIRS}

pre-everything::
	@if [ "x${XFREE86_VERSION}" != "x4" ]; then \
		${ECHO_MSG} "If you use the XFree86-4 ports you must have XFREE86_VERSION=4"; \
		${ECHO_MSG} "set in your /etc/make.conf."; \
		${FALSE}; \
	fi;

.if !target(do-configure)
do-configure:
	@cp ${X11BASE}/lib/X11/config/version.def ${WRKSRC}/config/cf
	@cp ${X11BASE}/lib/X11/config/date.def ${WRKSRC}/config/cf
	@cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefile.boot
	
.for i in ${_XINCLUDE_DIRS}
	@cd ${WRKSRC}/${i} && ${WRKSRC}/config/imake/imake \
		-DTOPDIR=${WRKSRC} -DCURDIR=${i} -I${WRKSRC}/config/cf
.endfor
.for i in ${_XINCLUDE_DIRS}
	@cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefiles
.endfor
.for i in ${_XINCLUDE_DIRS}
	@cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} includes
.endfor
.for i in ${_XBUILD_DIRS}
	@cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} depend
.endfor
.endif

.if !target(do-build)
do-build:
.for i in ${XBUILD_DIRS}
	@cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} all
.endfor
.endif

.if !target(do-install)
do-install:
.for i in ${XINSTALL_DIRS}
	@cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} install
.endfor
.for i in ${XINSTALL_MAN_DIRS}
	@cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} install.man
.endfor
.endif
.if ${XFREE86_HTML_MAN:L} == yes
	@${MKHTMLINDEX} ${PREFIX}/lib/X11/doc/html
.endif

