# -*-mode: makefile-*-
# New ports collection makefile for:	KDE libraries 3
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	This is the base set of libraries needed by KDE programs

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		artsc.0:${PORTSDIR}/audio/arts \
		cups.2:${PORTSDIR}/print/cups-base \
		fam.0:${PORTSDIR}/devel/fam \
		jasper:${PORTSDIR}/graphics/jasper \
		tiff.4:${PORTSDIR}/graphics/tiff \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${FONTSCALE}:${PORTSDIR}/x11-fonts/XFree86-4-fontScalable \
		${FONTENCOD}:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

USE_GETTEXT=	yes
USE_QT_VER=	3
PREFIX=		${KDE_PREFIX}
USE_OPENSSL=	yes

USE_OPENLDAP=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-ltdl-install	\
		--enable-mt

KDE_BUILD_PLIST=	yes

FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/tcvn-0.enc

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

# bzip2 is required as a libdepend for the help: kioslave
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif # !exists(/usr/bin/bzip2)

pre-configure:
	${REINPLACE_CMD} "s, kspell,,g" ${WRKSRC}/doc/Makefile.in

post-configure:
	${TOUCH} ${WRKSRC}/dcop/dcop-path.h.in
	${TOUCH} ${WRKSRC}/kio/kssl/ksslconfig.h.in

post-install:
	${MKDIR} ${PREFIX}/etc/rc.d
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/kdelibs.sh \
		> ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/etc/rc.d/kdelibs.sh

.include <bsd.port.post.mk>
