# -*-mode: makefile-*-
# New ports collection makefile for:	KDE libraries 3
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
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
		dns_sd:${PORTSDIR}/net/mDNSResponder \
		idn:${PORTSDIR}/dns/libidn \
		jasper:${PORTSDIR}/graphics/jasper \
		lua.5:${PORTSDIR}/lang/lua50 \
		pcre:${PORTSDIR}/devel/pcre \
		tiff.4:${PORTSDIR}/graphics/tiff \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	iceauth:${X_CLIENTS_PORT} \
		${FONTSCALE}:${X_FONTS_TTF_PORT} \
		${FONTENCOD}:${X_FONTS_ENCODINGS_PORT}

CONFLICTS+=	kdeadmin-3.[0-3].* kdeadmin-3.4.[0-1]* kdeartwork-3.[2-3]* kdebase-3.[0-4]* kdepim-3.2*
.if defined(WITHOUT_CUPS) || defined(KDE_WITHOUT_CUPS)
CONFLICTS+=	kdelibs-[0-9]*
PKGNAMESUFFIX=	-nocups
CONFIGURE_ARGS+=--disable-cups
PLIST=		${.CURDIR}/../kdelibs3-nocups/pkg-plist
.else
CONFLICTS+=	kdelibs-nocups-[0-9]*
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-base
.endif

USE_BZIP2=	yes
USE_FAM=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_QT_VER=	3
PREFIX=		${KDE_PREFIX}

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

USE_AUTOTOOLS=  libtool:15
CONFIGURE_TARGET=# empty
CONFIGURE_ARGS+=--disable-ltdl-install	\
		--disable-as-needed \
		--enable-mt \
		--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include \
		--with-lua-dir=${LOCALBASE} \
		--with-lua-libraries=${LOCALBASE}/libs \
		--with-lua-includes=${LOCALBASE}/include \
		--with-ssl-dir=/
CONFIGURE_ENV+=	libltdl_cv_shlibext=".so"

FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

# bzip2 is required as a libdepend for the help: kioslave
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif # !exists(/usr/bin/bzip2)

pre-configure:
	${REINPLACE_CMD} "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/kdeprint/cups/kmcupsmanager.cpp
	${REINPLACE_CMD} -e "s,ac_cups_share_test=.*,ac_cups_share_test=\`\$$kde_cups_config --datadir\`,g" \
			 -e "s,pcreposix.h,pcre.h,g" ${WRKSRC}/configure

post-configure:
	${TOUCH} ${WRKSRC}/dcop/dcop-path.h.in
	${TOUCH} ${WRKSRC}/kdecore/kdemacros.h.in
	${TOUCH} ${WRKSRC}/kio/kssl/ksslconfig.h.in
	${TOUCH} ${WRKSRC}/kjs/global.h.in

post-install:
	${MKDIR} ${PREFIX}/etc/rc.d
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/kdelibs.sh \
		> ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/etc/rc.d/kdelibs.sh

.include <bsd.port.post.mk>
