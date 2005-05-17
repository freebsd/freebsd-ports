# -*-mode: makefile-*-
# New ports collection makefile for:	KDE libraries 3
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	4
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMESUFFIX?=	# empty
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

DEPENDS=	${PORTSDIR}/misc/kdehier
BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		artsc.0:${PORTSDIR}/audio/arts \
		aspell:${PORTSDIR}/textproc/aspell \
		fam.0:${PORTSDIR}/devel/fam \
		dns_sd:${PORTSDIR}/net/mDNSResponder \
		idn:${PORTSDIR}/devel/libidn \
		jasper:${PORTSDIR}/graphics/jasper \
		pcre:${PORTSDIR}/devel/pcre \
		tiff.4:${PORTSDIR}/graphics/tiff \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	iceauth:${X_CLIENTS_PORT} \
		${FONTSCALE}:${X_FONTS_TTF_PORT} \
		${FONTENCOD}:${X_FONTS_ENCODINGS_PORT}

.if ${PKGNAMESUFFIX} == -nocups
CONFLICTS+=	kdeartwork-3.[2-3]* kdebase-3.[0-3]* kdepim-3.2*
.else
CONFLICTS+=	kdeartwork-3.[2-3]* kdebase-3.[0-3]* kdelibs-nocups-[0-9]* kdepim-3.2*
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
.endif

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
CONFIGURE_TARGET=# empty
CONFIGURE_ARGS+=--disable-ltdl-install	\
		--enable-mt \
		--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
CONFIGURE_ENV+=	libltdl_cv_shlibext=".so"

FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/tcvn-0.enc

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

# bzip2 is required as a libdepend for the help: kioslave
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif # !exists(/usr/bin/bzip2)

pre-configure:
	${REINPLACE_CMD} "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/kdeprint/cups/kmcupsmanager.cpp

post-configure:
	${TOUCH} ${WRKSRC}/dcop/dcop-path.h.in
	${TOUCH} ${WRKSRC}/kdecore/kdemacros.h.in
	${TOUCH} ${WRKSRC}/kio/kssl/ksslconfig.h.in

post-install:
	${MKDIR} ${PREFIX}/etc/rc.d
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/kdelibs.sh \
		> ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/etc/rc.d/kdelibs.sh

.include <bsd.port.post.mk>
