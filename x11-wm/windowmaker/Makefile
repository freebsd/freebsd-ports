# New ports collection makefile for:	WindowMaker
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	windowmaker
PORTVERSION=	0.65.0
PORTREVISION=	2
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER}
MASTER_SITE_SUBDIR=	beta/srcs
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		PropList.2:${PORTSDIR}/devel/libPropList \
		intl.1:${PORTSDIR}/devel/gettext \
		Hermes.1:${PORTSDIR}/graphics/Hermes
RUN_DEPENDS=	${X11BASE}/share/WindowMaker/Themes/Checker.themed/style:${PORTSDIR}/graphics/wmicons

USE_BZIP2=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE} \
		LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LINGUAS="${LINGUAS}"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-appspath="${PREFIX}/GNUstep/Apps" \
		--enable-hermes \
		--disable-debug

MAN1=		geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wmaker.1x wmsetbg.1x wsetfont.1x wxcopy.1x wxpaste.1x

.include <bsd.port.pre.mk>

LINGUAS!=	/bin/cat ${FILESDIR}/LINGUAS

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

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c
	@${PERL} -pi -e "s|%%PERL%%|${PERL}|g" ${WRKSRC}/util/wm-oldmenu2new
	@${PERL} -pi -e "s|/usr/local/GNUstep|${PREFIX}/GNUstep|g" \
		${WRKSRC}/WindowMaker/*menu*

post-install:
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds

update-LINGUAS: extract
	cd ${WRKSRC}/po && \
		${ECHO} *.po | ${SED} 's|\.po||g' > ${FILESDIR}/LINGUAS

.include <bsd.port.post.mk>
