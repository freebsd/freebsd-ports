# New ports collection makefile for:	WindowMaker
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	windowmaker
PORTVERSION=	0.92.0
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER}
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	GNUStep-compliant NeXTStep window manager clone

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	${X11BASE}/share/WindowMaker/Themes/LeetWM.themed/style:${PORTSDIR}/graphics/wmicons

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_XPM=	yes
USE_PERL5=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--disable-debug
INSTALLS_SHLIB=	yes

MANLANG=	"" sk
MAN1=		geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

.include <bsd.port.pre.mk>

OPTIONS=	XINERAMA "Enable xinerama support" off \
		XKB_STATUS "XKB keyboard language status support" off \
		WM_LINGUAS "Enable support for additional locales" off

.if ${ARCH} == amd64
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif

.if defined(WITH_XINERAMA) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

.if defined(WITH_XKB_STATUS) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-modelock
.endif

.if defined(WITH_WM_LINGUAS) || defined(PACKAGE_BUILDING)
LINGUAS!=	${CAT} ${FILESDIR}/LINGUAS
CONFIGURE_ENV+=	LINGUAS="${LINGUAS}"
PLIST_SUB=	WM_LINGUAS=""
.else
PLIST_SUB=	WM_LINGUAS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${REINPLACE_CMD} -e "s|%%PERL%%|${PERL}|g" ${WRKSRC}/util/wm-oldmenu2new
	@${REINPLACE_CMD} -e "s|Trebuchet MS,Luxi Sans|sans|g" ${WRKSRC}/WindowMaker/Defaults/WMGLOBAL
	@${REINPLACE_CMD} -e "s|/usr/local/GNUstep|${PREFIX}/GNUstep|g" \
		${WRKSRC}/WindowMaker/*menu*

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds

update-LINGUAS: extract
	cd ${WRKSRC}/po && \
		${ECHO_CMD} *.po | ${SED} 's|\.po||g' > ${FILESDIR}/LINGUAS

.include <bsd.port.post.mk>
