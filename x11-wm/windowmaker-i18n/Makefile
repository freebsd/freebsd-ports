# New ports collection makefile for:	WindowMaker with i18n extention
# Version required:	0.50.2
# Date created:		24 Nov 1998
# Whom:			mac@jp.freebsd.org
#
# $Id: Makefile,v 1.46 1998/12/21 13:15:39 flathill Exp $

DISTNAME=	WindowMaker-0.50.2
PKGNAME=	windowmaker-i18n-0.50.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/misc/wmaker/ \
		ftp://muse.brain.riken.go.jp/pub/rpm/contrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	mac@jp.freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34
BUILD_DEPENDS=	${LOCALBASE}/lib/libintl.a:${PORTSDIR}/devel/gettext \
		nkf:${PORTSDIR}/japanese/nkf

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}  LOCALBASE=${LOCALBASE} \
		LINGUAS="de es fi fr hr it ja_JP.EUC ko nl no pl pt ru"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${PREFIX}/share/locale \
	--with-gfx-libs="-L${LOCALBASE}/lib" \
	--with-gfx-incs="-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
	--disable-debug --enable-kanji --disable-shared

MAN1=	geticonset.1x getstyle.1x seticons.1x setstyle.1x \
	wdwrite.1x wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

DATAFILES=	WindowMaker-data.tar.gz

.include <bsd.port.pre.mk>

post-patch:
	@perl -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${CP} ${FILESDIR}/WPrefs.hr.po ${WRKSRC}/WPrefs.app/po/hr.po

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Pixmaps/
	@${INSTALL_DATA} ${WRKDIR}/WindowMaker-data/pixmaps/* \
		${PREFIX}/share/WindowMaker/Pixmaps/
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds/

.include <bsd.port.post.mk>
