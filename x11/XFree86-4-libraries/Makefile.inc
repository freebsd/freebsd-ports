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
USE_REINPLACE=	yes
XFREE86_HTML_MAN=	yes
PATCHDIR?=	${.CURDIR}/../../x11/XFree86-4-libraries/files
SCRIPTS_ENV+=	CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS}"
MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}"

XINSTALL_DIRS?=	${XBUILD_DIRS}
_XINCLUDE_DIRS=	include ${XBUILD_DIRS} ${XINCLUDE_DIRS}

pre-everything::
	@if [ "x${XFREE86_VERSION}" != "x4" ]; then \
		${ECHO_MSG} "If you use the XFree86-4 ports you must have XFREE86_VERSION=4"; \
		${ECHO_MSG} "set in your /etc/make.conf."; \
		${FALSE}; \
	fi;

.if !target(pre-configure)
pre-configure:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/config/cf/FreeBSD.cf
.endif

.if !target(do-configure)
do-configure:
	@cp ${X11BASE}/lib/X11/config/version.def ${WRKSRC}/config/cf
	@cp ${X11BASE}/lib/X11/config/date.def ${WRKSRC}/config/cf
	@cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefile.boot
	@for dir in ${_XINCLUDE_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${WRKSRC}/config/imake/imake \
			-DTOPDIR=${WRKSRC} -DCURDIR=$${dir} -I${WRKSRC}/config/cf; \
	done
	@for dir in ${_XINCLUDE_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefiles; \
	done
	@for dir in ${_XINCLUDE_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} includes; \
	done
	@for dir in include ${XBUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} depend; \
	done
.endif

.if !target(do-build)
do-build:
	@for dir in ${XBUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} all; \
	done
.endif

.if !target(do-install)
do-install:
	@for dir in ${XINSTALL_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} install; \
	done
	@for dir in ${XINSTALL_MAN_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} install.man; \
	done
	@${MKHTMLINDEX} ${PREFIX}/lib/X11/doc/html
.endif

