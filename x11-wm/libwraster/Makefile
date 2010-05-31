# New ports collection makefile for:	libwraster
# Date created:				August 17, 2009
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libwraster
PORTVERSION=	0.92.0
PORTREVISION=	3
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	${MASTER_SITE_WINDOWMAKER} \
		http://dougbarton.us/Downloads/
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	libwraster from Window Maker

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

MAKE_JOBS_SAFE=	yes

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_XORG=	xpm
USE_PERL5=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--disable-debug
USE_LDCONFIG=	yes

PATCHDIR=	${.CURDIR}/../windowmaker/files
MD5_FILE=	${.CURDIR}/../windowmaker/distinfo

CONFLICTS=	windowmaker-0.*

PLIST_FILES=	bin/get-wraster-flags include/wraster.h lib/libwraster.a \
		lib/libwraster.la lib/libwraster.so lib/libwraster.so.4 \
		libdata/pkgconfig/wrlib.pc

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif

post-patch:
	@${CP} ${WRKSRC}/wrlib/Makefile.in ${WRKSRC}/wrlib/Makefile.in.presed
	@${SED} -e s#$$\(libdir\)/pkgconfig#${PREFIX}/libdata/pkgconfig#g \
	    ${WRKSRC}/wrlib/Makefile.in.presed > ${WRKSRC}/wrlib/Makefile.in

do-build:
	cd ${WRKSRC}/wrlib && ${MAKE}

do-install:
	cd ${WRKSRC}/wrlib && ${MAKE} install

.include <bsd.port.post.mk>
