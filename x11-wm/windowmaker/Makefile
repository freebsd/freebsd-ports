# New ports collection makefile for:	WindowMaker
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	windowmaker
PORTVERSION=	0.64.0
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER} \
		http://jgo.local.net/cool_downloads/wm/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,sobomax,g}
MASTER_SITE_SUBDIR=	beta/srcs
DISTNAME=	WindowMaker-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		libwmfun-${PORTVERSION}${EXTRACT_SUFX} \
		${DATAFILES}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		PropList.2:${PORTSDIR}/devel/libPropList \
		intl.1:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE} \
		LIBS=-L${LOCALBASE}/lib \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LINGUAS="${LINGUAS}"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-appspath="${PREFIX}/GNUstep/Apps" \
		--disable-debug

MAN1=		geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wmaker.1x wmsetbg.1x wsetfont.1x wxcopy.1x wxpaste.1x

DATAFILES=	WindowMaker-extra-0.1.tar.bz2

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

.if defined(WITH_SINGLE_ICON)
CONFIGURE_ARGS+=	--enable-single-icon
.endif

post-patch:
	@perl -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/WPrefs.app/Paths.c \
		${WRKSRC}/WindowMaker/Defaults/*

post-configure:
	@cd ${WRKDIR}/WindowMaker-extra-0.1; \
		./configure --prefix=${PREFIX}

post-install:
	@cd ${WRKDIR}/WindowMaker-extra-0.1; \
		${MAKE} ${MAKE_ARGS} ${INSTALL_TARGET}
	${MKDIR} ${PREFIX}/share/WindowMaker/Sounds

update-LINGUAS: extract
	cd ${WRKSRC}/po && \
		${ECHO} *.po | ${SED} 's|\.po||g' > ${FILESDIR}/LINGUAS

.include <bsd.port.post.mk>
