# New ports collection makefile for:	WindowMaker
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	windowmaker
PORTVERSION=	0.80.2
PORTREVISION=	3
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER}
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUStep-compliant NeXTStep window manager clone

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
.if !defined(WITHOUT_HERMES)
LIB_DEPENDS+=	Hermes.1:${PORTSDIR}/graphics/Hermes
.endif

RUN_DEPENDS=	${X11BASE}/share/WindowMaker/Themes/Checker.themed/style:${PORTSDIR}/graphics/wmicons

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE} \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LINGUAS="${LINGUAS}"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-appspath="${PREFIX}/GNUstep/Apps" \
		--disable-debug

.if !defined(WITHOUT_HERMES)
CONFIGURE_ARGS+=	--enable-hermes
.else
CONFIGURE_ARGS+=	--disable-hermes
.endif

CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MANLANG=	"" sk
MAN1=		geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wcopy.1x wmaker.1x wmsetbg.1x wsetfont.1x wxcopy.1x wxpaste.1x

.include <bsd.port.pre.mk>

LINGUAS!=	/bin/cat ${FILESDIR}/LINGUAS

.if defined(WITH_XKB_STATUS)
CONFIGURE_ARGS+=	--enable-modelock       
.endif

.if defined(HAVE_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
.endif

.if defined(WITH_KDE)
CONFIGURE_ARGS+=	--enable-kde
.endif

pre-everything::
.if !defined(WITHOUT_HERMES)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable the Hermes library by defining WITHOUT_HERMES"
	@${ECHO_MSG}
.endif
.if !defined(WITH_KDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can add hooks for KDE by defining WITH_KDE"
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${REINPLACE_CMD} -e "s|%%PERL%%|${PERL}|g" ${WRKSRC}/util/wm-oldmenu2new
	@${REINPLACE_CMD} -e "s|/usr/local/GNUstep|${PREFIX}/GNUstep|g" \
		${WRKSRC}/WindowMaker/*menu*

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds
# 	XXX
	@${INSTALL_MAN} ${PREFIX}/man/man1/wcopy.1x ${PREFIX}/man/sk/man1

update-LINGUAS: extract
	cd ${WRKSRC}/po && \
		${ECHO_CMD} *.po | ${SED} 's|\.po||g' > ${FILESDIR}/LINGUAS

.include <bsd.port.post.mk>
