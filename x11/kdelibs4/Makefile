# New ports collection makefile for:	KDE libraries 2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	2.1.1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		mimelib.3:${PORTSDIR}/converters/kdesupport2

USE_OPENSSL=	yes
USE_QT_VER=	2
SOMAJOR=	4
SOMINOR=	0
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.if ${MACHINE_ARCH} == "alpha"
CFLAGS=		-O0 ${KDE_CFLAGS}
.endif

USE_GMAKE=	yes
MAKE_ENV=	SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"
PLIST_SUB+=	LIBVER="${SOMAJOR}"

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} <= 410002
	@${ECHO}
	@${ECHO} "			NOTICE"
	@${ECHO}
	@${ECHO} "Your OpenSSL installation could be out of date.  This is"
	@${ECHO} "just a warning, but if your system's world was built on"
	@${ECHO} "sources earlier than August 20 along RELENG_4 or older,"
	@${ECHO} "then KDE2 will not build with SSL support."
	@${ECHO}
.endif

pre-configure:
	${PERL} -pi -e "s@-O2@-O0@g" ${WRKSRC}/configure
	(find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi.orig -e \
		"s@version-info 1:0@version-info ${SOMAJOR}:${SOMINOR}@g; \
		 s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g")

post-install:
.for LIB in DCOP kab kdecore kdesu kdeui kfile kformula kio kjs \
	    kparts kspell ksycoca kjava
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.${SOMAJOR} ${PREFIX}/lib/lib${LIB}.so
.endfor
.for LIB in artsc artsflow artsflow_idl kmid kmedia2_idl qtmcop soundserver_idl
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.0 ${PREFIX}/lib/lib${LIB}.so
.endfor

.include <bsd.port.post.mk>
