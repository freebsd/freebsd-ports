# New ports collection makefile for:	WindowMaker with i18n extention
# Version required:	0.51.0
# Date created:		24 Nov 1998
# Whom:			mac@jp.freebsd.org
#
# $Id: Makefile,v 1.51 1999/02/12 17:00:00 flathill Exp $

DISTNAME=	WindowMaker-0.51.0
PKGNAME=	windowmaker-i18n-0.51.0
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER} \
		ftp://muse.brain.riken.go.jp/pub/ja.po/ \
		http://jgo.local.net/cool_downloads/wm/ \
		ftp://muse.brain.riken.go.jp/pub/rpm/contrib/
MASTER_SITE_SUBDIR=	beta/srcs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES} \
		WindowMaker-0.51.0ja1.tar.gz

MAINTAINER=	mac@jp.freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		PropList.1:${PORTSDIR}/devel/libPropList
BUILD_DEPENDS=	${LOCALBASE}/lib/libintl.a:${PORTSDIR}/devel/gettext \
		nkf:${PORTSDIR}/japanese/nkf

USE_PERL5=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}  LOCALBASE=${LOCALBASE} \
		CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib" \
		LINGUAS="de es fi fr hr it ja_JP.EUC ko nl no pl pt ru"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${PREFIX}/share/locale \
	--with-gfx-incs="-I${LOCALBASE}/include/giflib" \
	--disable-debug --enable-kanji --disable-shared

MAN1=	geticonset.1x getstyle.1x seticons.1x setstyle.1x \
	wdwrite.1x wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

DATAFILES=	WindowMaker-data.tar.gz

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${PERL} -pi -e "s|%%PERL%%|${PERL}|g" ${WRKSRC}/util/wm-oldmenu2new
	@${CP} ${WRKDIR}/WindowMaker-0.51.0ja1/WindowMaker.ja.po \
		${WRKSRC}/po/ja.po
	@${CP} ${WRKDIR}/WindowMaker-0.51.0ja1/WPrefs.ja.po \
		${WRKSRC}/WPrefs.app/po/ja.po

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Pixmaps/
	@${INSTALL_DATA} ${WRKDIR}/WindowMaker-data/pixmaps/* \
		${PREFIX}/share/WindowMaker/Pixmaps/
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds/

.include <bsd.port.post.mk>
