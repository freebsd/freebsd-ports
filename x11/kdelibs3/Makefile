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
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	This is the base set of libraries needed by KDE programs

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		artsc.0:${PORTSDIR}/audio/arts \
		fam.0:${PORTSDIR}/devel/fam \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.1:${PORTSDIR}/textproc/libxslt \
		pcre.0:${PORTSDIR}/devel/pcre \
		intl.4:${PORTSDIR}/devel/gettext \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${FONTSCALE}:${PORTSDIR}/x11-fonts/XFree86-4-fontScalable \
		${FONTENCOD}:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

USE_QT_VER=	3
PREFIX=		${KDE_PREFIX}
USE_OPENSSL=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-ltdl-install	\
		--enable-mt		\
		--enable-cups
KDE_BUILD_PLIST=	yes

FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/tcvn-0.enc

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

# fam provides a measurable performance increase for file watching
# operations within KDE
.if exists(${LOCALBASE}/bin/fam)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif # exists(${LOCALBASE}/bin/fam)

# bzip2 is required as a libdepend for the help: kioslave
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif # !exists(/usr/bin/bzip2)

# kabc (the addressbook backend) can use ldap if it's available
.if defined(WITH_LDAP) || exists($(LOCALBASE)/lib/libldap.so)
LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap21-client
PLIST_APPEND+=	plist.ldap
.endif

pre-configure:
	${REINPLACE_CMD} "s, kspell,,g" ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} "s,-pedantic ,," ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/etc/rc.d
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/kdelibs.sh \
		> ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/etc/rc.d/kdelibs.sh

.include <bsd.port.post.mk>
