# New ports collection makefile for:	WindowMaker with i18n extention
# Version required:	0.20.2
# Date created:		24 Nov 1998
# Whom:			mac@jp.freebsd.org
#
# $Id: Makefile,v 1.41 1998/11/25 10:44:00 flathill Exp $

DISTNAME=	WindowMaker-0.20.2
PKGNAME=	windowmaker-i18n-0.20.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/ \
		ftp://ftp.io.com/pub/mirror/windowmaker/beta/srcs/ \
		http://jgo.local.net/cool_downloads/wm/ \
		http://www.itlb.te.noda.sut.ac.jp/~manome/wmaker/archive/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES} setlinguas-0.4.gz

MAINTAINER=	mac@jp.freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34
BUILD_DEPENDS=	${LOCALBASE}/lib/libintl.a:${PORTSDIR}/devel/gettext \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE} \
		LINGUAS="de es fi fr hr it ja_JP.EUC ja_JP.SJIS ko nl no pl pt ru"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${PREFIX}/share/locale \
	--with-gfx-libs="-L${LOCALBASE}/lib" \
	--with-gfx-incs="-I${LOCALBASE}/include/tiff34 -I${LOCALBASE}/include" \
	--disable-debug --enable-kanji

MAN1=	geticonset.1x getstyle.1x seticons.1x setstyle.1x \
	wdwrite.1x wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

DATAFILES=	WindowMaker-data.tar.gz

.include <bsd.port.pre.mk>

post-extract:
	@${GUNZIP_CMD} -c < ${_DISTDIR}/setlinguas-0.4.gz > ${WRKDIR}/setlinguas

post-patch:
	@perl -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/setlinguas ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/WindowMaker/Pixmaps/
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds/
	@${INSTALL_DATA} ${WRKDIR}/WindowMaker-data/pixmaps/* \
		${PREFIX}/share/WindowMaker/Pixmaps/

.include <bsd.port.post.mk>
