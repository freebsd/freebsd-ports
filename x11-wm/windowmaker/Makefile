# New ports collection makefile for:	WindowMaker
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	windowmaker
PORTVERSION=	0.90.0
PORTREVISION=	1
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER}
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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
		LDFLAGS="-L${LOCALBASE}/lib" \
		LINGUAS="${LINGUAS}"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-appspath="${PREFIX}/GNUstep/Apps" \
		--enable-vdesktop \
		--enable-xinerama \
		--disable-debug
INSTALLS_SHLIB=	yes

MANLANG=	"" sk
MAN1=		geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

OPTIONS=	XKB_STATUS "XKB STATUS" off

.include <bsd.port.pre.mk>

LINGUAS!=	${CAT} ${FILESDIR}/LINGUAS

.if defined(WITH_XKB_STATUS)
CONFIGURE_ARGS+=	--enable-modelock
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|TW\.Big5|TW|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${REINPLACE_CMD} -e "s|%%PERL%%|${PERL}|g" ${WRKSRC}/util/wm-oldmenu2new
	@${REINPLACE_CMD} -e "s|-version-info 3:|-version-info 5:|g" ${WRKSRC}/wrlib/Makefile.in
	@${REINPLACE_CMD} -e "s|Trebuchet MS,Luxi Sans|sans|g" ${WRKSRC}/WindowMaker/Defaults/WMGLOBAL
	@${REINPLACE_CMD} -e "s|/usr/local/GNUstep|${PREFIX}/GNUstep|g" \
		${WRKSRC}/WindowMaker/*menu*

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds

update-LINGUAS: extract
	cd ${WRKSRC}/po && \
		${ECHO_CMD} *.po | ${SED} 's|\.po||g' > ${FILESDIR}/LINGUAS

.include <bsd.port.post.mk>
