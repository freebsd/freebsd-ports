# New ports collection makefile for:	WindowMaker with i18n extention
# Date created:		24 Nov 1998
# Whom:			mac@jp.freebsd.org
#
# $FreeBSD$
#

PORTNAME=	windowmaker-i18n
PORTVERSION=	0.64.0
# PORTREVISION=
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER}
MASTER_SITE_SUBDIR=	beta/srcs
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	mac@jp.freebsd.org

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		PropList.2:${PORTSDIR}/devel/libPropList \
		intl.1:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	${X11BASE}/share/WindowMaker/Themes/Checker.themed/style:${PORTSDIR}/graphics/wmicons

USE_BZIP2=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}  LOCALBASE=${LOCALBASE} \
		CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib" \
		LINGUAS="cs de es fr gl it ja_JP.EUC ko nl no pt ru sv tr fi hr el pl ro da zh_TW.Big5 zh_CN sk bg hu"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
	--with-nlsdir=${PREFIX}/share/locale \
	--with-libs-from="-L${LOCALBASE}/lib" \
	--with-incs-from="-I${LOCALBASE}/include" \
	--with-appspath="${PREFIX}/GNUstep/Apps" \
	--disable-debug

MAN1=	geticonset.1x getstyle.1x seticons.1x setstyle.1x \
	wdwrite.1x wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x wsetfont.1x

JA_CATALOGFILE=	

.if defined(JA_CATALOGFILE) && !empty(JA_CATALOGFILE)
MASTER_SITES+=	ftp://muse.brain.riken.go.jp/pub/ja.po/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${JA_CATALOGFILE}${EXTRACT_SUFX}
.endif

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
.endif

.if defined(WITH_KDE)
CONFIGURE_ARGS+=	--enable-kde
.else
.SILENT:
pre-extract:
	@${ECHO} "You can add hooks for KDE by defining WITH_KDE"
.endif

# post-extract:
# 	@cd ${WRKSRC} && \
# 	${TAR} xfz libwmfun-0.0.3.tar.gz

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${PERL} -pi -e "s|%%PERL%%|${PERL}|g" ${WRKSRC}/util/wm-oldmenu2new
.if defined(JA_CATALOGFILE) && ${JA_CATALOGFILE} != ""
	@${CP} ${WRKDIR}/${JA_CATALOGFILE}/WindowMaker.ja.po \
		${WRKSRC}/po/ja.po
	@${CP} ${WRKDIR}/${JA_CATALOGFILE}/WPrefs.ja.po \
		${WRKSRC}/WPrefs.app/po/ja.po
.endif

pre-build:
	@cd ${WRKSRC}/WindowMaker/Defaults && ${MAKE} clean

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds/

.include <bsd.port.post.mk>
