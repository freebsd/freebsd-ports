# include for XFree86-4 ports which share XFree86-4-libraries's patches.
#
# XBUILD_DIRS is the group of directories under ${WRKSRC} that will 
#   be built in.
# XINCLUDE_DIRS is the group of directories under ${WRKSRC} that need
#   to be Makefilesed or included in besides XBUILD_DIRS
# XINSTALL_DIRS is the group of directories which will have 
#   their install targets run.
# XINSTALL_MAN_DIRS is the group of directories which will have 
#   their install.man targets run.

MAKE_ENV+=	FBSDCC="${CC}" FBSDCXX="${CXX}"
_XBUILD_DIRS=	include ${XBUILD_DIRS}
XINSTALL_DIRS?=	${XBUILD_DIRS}
_XINCLUDE_DIRS=	${_XBUILD_DIRS} ${XINCLUDE_DIRS}

.if !target(do-configure)
do-configure:
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
