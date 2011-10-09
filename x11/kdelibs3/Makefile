# -*-mode: makefile-*-
# New ports collection makefile for:	KDE libraries 3
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	7
CATEGORIES=	x11 kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMESUFFIX?=	# empty
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl \
		artsc.0:${PORTSDIR}/audio/arts \
		aspell:${PORTSDIR}/textproc/aspell \
		dns_sd:${PORTSDIR}/net/mDNSResponder \
		idn:${PORTSDIR}/dns/libidn \
		jasper:${PORTSDIR}/graphics/jasper \
		pcre:${PORTSDIR}/devel/pcre \
		thai:${PORTSDIR}/devel/libthai \
		tiff.4:${PORTSDIR}/graphics/tiff \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	kdehier>0:${PORTSDIR}/misc/kdehier \
		${FONTSCALE}:${X_FONTS_TTF_PORT} \
		${FONTENCOD}:${X_FONTS_ENCODINGS_PORT} \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		iceauth:${PORTSDIR}/x11/iceauth

BROKEN=		does not build

CONFLICTS_BUILD=	openssl-1.*
CONFLICTS+=	kdeadmin-3.[0-3].* kdeadmin-3.4.[0-1]* kdeartwork-3.[2-3]* kdebase-3.[0-4]* kdepim-3.2*
.if defined(WITHOUT_CUPS) || defined(KDE_WITHOUT_CUPS)
CONFLICTS+=	kdelibs-[0-9]*
PKGNAMESUFFIX=	-nocups
CONFIGURE_ARGS+=--disable-cups
PLIST=		${.CURDIR}/../kdelibs3-nocups/pkg-plist
.else
CONFLICTS+=	kdelibs-nocups-[0-9]*
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
.endif

USE_BZIP2=	yes
USE_FAM=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_QT_VER=	3
PREFIX=		${KDE_PREFIX}

USE_LDCONFIG=	yes

USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=--disable-ltdl-install	\
		--disable-as-needed \
		--enable-mt \
		--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include \
		--with-libthai=yes \
		--with-lua=no \
		--with-ssl-dir=${OPENSSLBASE}
CONFIGURE_ENV+=	libltdl_cv_shlibext=".so"

FONTSCALE=	${LOCALBASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/lib/X11/fonts/encodings/encodings.dir

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

# bzip2 is required as a libdepend for the help: kioslave
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif # !exists(/usr/bin/bzip2)

pre-configure:
	${REINPLACE_CMD} "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/kdeprint/cups/kmcupsmanager.cpp
	${REINPLACE_CMD} -e "s,ac_cups_share_test=.*,ac_cups_share_test=,g" \
			 -e "s,pcreposix.h,pcre.h,g" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,applications.menu,kde-applications.menu,g" \
		${WRKSRC}/kded/Makefile.in ${WRKSRC}/kded/kbuildsycoca.cpp
	${REINPLACE_CMD} -e "s,hicolor,,g" ${WRKSRC}/pics/Makefile.in
	${REINPLACE_CMD} -e "s,/etc/exports,/nonexistent,g" \
			-e "s,/etc/samba/,${LOCALBASE}/etc/,g"  \
			-e "s,/etc/security/,${LOCALBASE}/etc/,g" \
			-e "s,'fileshare','network',g" \
		${WRKSRC}/kio/misc/fileshareset
	${REINPLACE_CMD} -e "s,LIB_QT),LIB_QT) $$\(LIBPTHREAD\) $$\(USE_THREADS\),g" \
		${WRKSRC}/dcop/dcopidl/Makefile.in ${WRKSRC}/dcop/dcopidl2cpp/Makefile.in
	${MV} ${WRKSRC}/kded/applications.menu ${WRKSRC}/kded/kde-applications.menu

post-configure:
	${TOUCH} ${WRKSRC}/dcop/dcop-path.h.in
	${TOUCH} ${WRKSRC}/kdecore/kdemacros.h.in
	${TOUCH} ${WRKSRC}/kio/kssl/ksslconfig.h.in
	${TOUCH} ${WRKSRC}/kjs/global.h.in

.include <bsd.port.post.mk>
