# $FreeBSD$

PORTNAME=	cde
DISTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/cdesktopenv/src/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Common Desktop Environment

BUILD_DEPENDS=	ksh93:shells/ksh93			\
		bdftopcf:x11-fonts/bdftopcf		\
		mkfontdir:x11-fonts/mkfontdir	\
		biconv:converters/iconv

USES=		motif perl5 shebangfix
SHEBANG_FILES=	programs/dtdocbook/sgmls/sgmls.pl \
		programs/dtinfo/tools/bin/ccdate
USE_LDCONFIG=	${PREFIX}/dt/lib
USE_RC_SUBR=	dtcms dtspc
USE_XORG=	xinerama xp xt

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
ALL_TARGET=	World
MAKE_ARGS+=	PERL=${PERL}
MAKE_JOBS_UNSAFE=yes
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${OSVERSION} > 1200000
BROKEN=		Does not build on head
.endif

DTPATHSRE=	's,/usr/dt,${STAGEDIR}${PREFIX}/dt,;s,/etc/dt,${STAGEDIR}${PREFIX}/etc/dt,;\
		s,/var/dt,${STAGEDIR}${PREFIX}/dt/var,'
post-patch:
	if [ -f /usr/include/iconv.h ]; then \
	    ${REINPLACE_CMD} -e 's!^[[:space:]]*const char .ip = (const char .) .bp!char *ip = *bp!' \
	    ${WRKSRC}/programs/dtmail/libDtMail/Common/Session.C \
	    ${WRKSRC}/programs/dtmail/libDtMail/RFC/RFCBodyPart.C; \
	fi
	${REINPLACE_CMD} -e 's,^PREFIX.*,PREFIX=${STAGEDIR}${PREFIX},' \
		${WRKSRC}/admin/IntegTools/post_install/freebsd/configMin.src
	${FIND} ${WRKSRC}/programs/dtksh/ksh93 -type f -exec \
		${REINPLACE_CMD} -e 's,SF_FLAGS,SFIO_FLAGS,g' \{} \+
	cd ${WRKSRC} && \
	    ${MKDIR} imports/x11 && \
	    ${LN} -s ${LOCALBASE}/bin ${LOCALBASE}/include ${LOCALBASE}/lib \
		imports/x11 && \
	    ${MKDIR} imports/motif/include && \
	    ${LN} -s ${LOCALBASE}/include/Xm imports/motif/include
# PREFIX safe- ugh! Ignore doc subdirectoy as it causes build headaches
#	${FIND} ${WRKSRC}/??[^c]* -type f -exec ${REINPLACE_CMD} \
#		-e 's,\([>/]|^\)usr/dt,\2${PREFIX:S,^/,,}/dt,g' \
#		-e 's,\([^a-zA-Z]|^\)/etc/dt,\1${PREFIX}/etc/dt,g' \
#	    \{} +
	${REINPLACE_CMD} ${DTPATHSRE} ${WRKSRC}/databases/*
	${FIND} ${WRKSRC}/programs/ -type f \
		-name Makefile \
		-exec ${REINPLACE_CMD} ${DTPATHSRE} \{} +
#		\( -name '*.[Cch]' -or -name Makefile \) \

do-install:
	cd ${WRKSRC}/admin/IntegTools/dbTools && \
		./installCDE -s ${WRKSRC} -pseudo
	${ECHO_CMD} "MANPATH ${PREFIX}/dt/share/man" > \
		${STAGEDIR}${PREFIX}/etc/man.d/cde.conf
	(cd ${STAGEDIR}${PREFIX}/dt/share/man && \
		for m in 1 1m 3 4 5 6; do \
		    ${GZIP_CMD} man$$m/*.$$m; \
		done)
	${INSTALL_DATA} ${WRKSRC}/lib/pam/libpam/pam.conf \
		${STAGEDIR}${PREFIX}/etc/pam.d

#	Documented switches don't actually produce desired effect!
#	./installCDE -s ${WRKSRC} -pI ${STAGEDIR}${PREFIX}/dt \
#		   -pV ${STAGEDIR}/var -pC ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
