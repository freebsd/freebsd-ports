# New ports collection makefile for:	KDE libraries 3
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	3.0.5
PORTREVISION=	0
CATEGORIES?=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:${PORTSDIR}/devel/autoconf \
		${LOCALBASE}/bin/automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		qtmcop.1:${PORTSDIR}/audio/arts \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		pcre.0:${PORTSDIR}/devel/pcre \
		cups.2:${PORTSDIR}/print/cups-base \
		xslt.1:${PORTSDIR}/textproc/libxslt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif
RUN_DEPENDS=	${FONTSCALE}:${PORTSDIR}/x11-fonts/XFree86-4-fontScalable \
		${FONTENCOD}:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

USE_OPENSSL=	yes
USE_QT_VER=	3
SOMAJOR=	4
SOMINOR=	0
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
PREFIX?=	${KDE_PREFIX}
CONFIGURE_ARGS+=--enable-cups --disable-ltdl-install
FONTSCALE=	${X11BASE}/lib/X11/fonts/PEX/Roman.phont
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/tcvn-0.enc

.include "${.CURDIR}/../kde3/Makefile.kde"

USE_GMAKE=	yes
MAKE_ENV=	SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"
PLIST_SUB+=	LIBVER="${SOMAJOR}" LDCONFIG="${LDCONFIG}"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/fam)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

pre-fetch: kde-version-check
.if ${OSVERSION} <= 410002
	@${ECHO}
	@${ECHO} "			NOTICE"
	@${ECHO}
	@${ECHO} "Your OpenSSL installation could be out of date.  This is"
	@${ECHO} "just a warning, but if your system's world was built on"
	@${ECHO} "sources earlier than August 20 along RELENG_4 or older,"
	@${ECHO} "then KDE3 will not build with SSL support."
	@${ECHO}
.endif

pre-configure:
	cd ${WRKSRC}; ${GMAKE} -f Makefile.cvs

post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/etc/rc.d
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/kdelibs.sh > \
		${DESTDIR}${PREFIX}/etc/rc.d/kdelibs.sh
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/etc/rc.d/kdelibs.sh

.include <bsd.port.post.mk>
