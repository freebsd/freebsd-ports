# $FreeBSD$

PORTNAME=	cde
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/cdesktopenv/src/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Common Desktop Environment

LICENSE=	LGPL21

BROKEN_mips64=		fails to build: ./config/imake/imake: No such file or directory
BROKEN_powerpc64=	fails to build: ./config/imake/imake: No such file or directory

BUILD_DEPENDS=	ksh93:shells/ksh93			\
		bdftopcf:x11-fonts/bdftopcf		\
		mkfontscale>=0:x11-fonts/mkfontscale	\
		biconv:converters/iconv			\
		${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/bin/fc-cache:x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:print/freetype2 \
		ksh93:shells/ksh93 \
		xrdb:x11/xrdb \
		xset:x11/xset

USES=		iconv motif perl5 shebangfix tcl:85
SHEBANG_FILES=	programs/dtdocbook/sgmls/sgmls.pl \
		programs/dtinfo/tools/bin/ccdate
USE_LDCONFIG=	${PREFIX}/dt/lib
USE_RC_SUBR=	dtcms dtspc
USE_XORG=	xinerama xp xt xscrnsaver

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
ALL_TARGET=	World
MAKE_ARGS+=	PERL=${PERL}
MAKE_JOBS_UNSAFE=yes
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${OSVERSION} > 1200000
BROKEN=		Does not build on head
.endif

post-patch:
	@if [ -f /usr/include/iconv.h ]; then \
	    ${REINPLACE_CMD} -e 's!^[[:space:]]*const char .ip = (const char .) .bp!char *ip = *bp!' \
	    ${WRKSRC}/programs/dtmail/libDtMail/Common/Session.C \
	    ${WRKSRC}/programs/dtmail/libDtMail/RFC/RFCBodyPart.C; \
	fi

# From shells/ksh93
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/include/sfio*.h  \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/sfio/*.c \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/sfio/*.h

# Speed up poudriere + qemu + native-xtools
	@${REINPLACE_CMD} \
	    -e 's|CcCmd			cc|CcCmd ${CC}|g' \
	    -e 's|CplusplusCmd		c++|CplusplusCmd ${CXX}|g' \
	    -e 's|CppCmd			/usr/bin/cpp|CppCmd ${CPP}|g' \
		${WRKSRC}/config/cf/FreeBSD.cf

# Needed for armv6
	@${REINPLACE_CMD} -e 's|__va_copy|va_copy|g' \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/hash/*.c \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/sfio/*.c \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/string/*.c

# Fix all hardcoded path
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/config/cf/Imake.tmpl \
		${WRKSRC}/programs/dtdocbook/sgmls/sgmls.pl \
		${WRKSRC}/programs/dtinfo/tools/bin/ccdate
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/dt|${LOCALBASE}/dt|g ; \
		s|/etc/dt|${LOCALBASE}/etc/dt|g'

	@${REINPLACE_CMD} -e 's|STAGEDIR|${STAGEDIR}|g' -e \
		's|LOCALBASE|${LOCALBASE}|g' \
		${WRKSRC}/admin/IntegTools/dbTools/installCDE.src \
		${WRKSRC}/admin/IntegTools/post_install/freebsd/configRun.src \
		${WRKSRC}/admin/IntegTools/post_install/freebsd/configShlibs.src \
		${WRKSRC}/admin/IntegTools/post_install/freebsd/configMin.src

# we need to remove a few LOCALBASE
	@${REINPLACE_CMD} -e 's|${LOCALBASE}/etc/dtinfogen|/etc/dtinfogen|g' \
		${WRKSRC}/databases/CDE-RUN.udb \
		${WRKSRC}/config/cf/cde.tmpl
	@${REINPLACE_CMD} -e 's|${LOCALBASE}/etc/dtsr|/etc/dtsr|g' -e \
		's|${LOCALBASE}/etc/dtinfo_start|/etc/dtinfo_start|g' \
		${WRKSRC}/databases/CDE-RUN.udb \
		${WRKSRC}/programs/tttypes/dtinfo_start.ptype \
		${WRKSRC}/programs/tttypes/dtinfo.ptype
	@${REINPLACE_CMD} -e 's|${LOCALBASE}||g' \
		${WRKSRC}/programs/dtinfo/dtinfogen/infolib/etc/dtinfogen_worker.c

# why redefine exit??
	@${REINPLACE_CMD} -e '/void exit/d' \
		${WRKSRC}/lib/tt/bin/tt_type_comp/frozen.mp_types_lex.C
# (time_t*) NULL is apparently too C-ish
	@${REINPLACE_CMD} -e 's,(time_t) *NULL,nullptr,' \
		${WRKSRC}/programs/dtmail/libDtMail/Common/FileShare.C \
		${WRKSRC}/programs/dtmail/libDtMail/RFC/RFCMailBox.C

# The docs say not necessary, but unreliable without
#	@${MKDIR} ${WRKSRC}/imports/x11/include
#	@${LN} -s ${LOCALBASE}/include/X11 ${WRKSRC}/imports/x11/include
#	@${LN} -s ${LOCALBASE}/include/Xm ${WRKSRC}/imports/x11/include
#	@${LN} -s ${LOCALBASE}/include/fontconfig ${WRKSRC}/imports/x11/include
#	@${LN} -s ${LOCALBASE}/include/freetype2 ${WRKSRC}/imports/x11/include


do-install:
	cd ${WRKSRC}/admin/IntegTools/dbTools && \
		./installCDE -s ${WRKSRC} -destdir ${STAGEDIR}
	(cd ${STAGEDIR}${PREFIX}/dt/share/man && \
		for m in 1 1m 3 4 5 6; do \
		    ${GZIP_CMD} man$$m/*.$$m; \
		done)
	${INSTALL_DATA} ${WRKSRC}/lib/pam/libpam/pam.conf \
		${STAGEDIR}${PREFIX}/etc/pam.d/cde.conf

post-install:
	${FIND} ${STAGEDIR}/${PREFIX}/dt -type f -exec ${SH} -c '${STRIP_CMD} {} > /dev/null 2>&1' \;

#	Documented switches don't actually produce desired effect!
#	./installCDE -s ${WRKSRC} -pI ${STAGEDIR}${PREFIX}/dt \
#		   -pV ${STAGEDIR}/var -pC ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
