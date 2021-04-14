PORTNAME=	ntk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1001
MASTER_SITES=	https://git.kx.studio/non/ntk/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/ # was at GH_ACCOUNT=original-male
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of FLTK 1.3.0 which adds graphics rendering via Cairo, etc

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		gnome jpeg localbase:ldflags pkgconfig waf xorg
USE_GNOME=	cairo
USE_XORG=	x11 xft
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e " \
		s|conf\.env\['LIB_DL'\] = \['dl'\]|conf.env['LIB_DL'] = []|; \
		s|bld.add_post_fun( run_ldconfig )|#bld.add_post_fun( run_ldconfig )|" \
		${WRKSRC}/wscript

post-install:
	# Removing items that are there by mistake: https://github.com/original-male/ntk/issues/13
	@${REINPLACE_CMD} -e ' \
		/^Requires.*/d; \
		s| -lglu||; \
		s| -lgl||; \
		s| -D_LARGEFILE64_SOURCE||; \
		s| -D_FILE_OFFSET_BITS=64||' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/ntk*.pc
	@${RM} ${STAGEDIR}${PREFIX}/lib/libntk*.a* # https://github.com/original-male/ntk/issues/12
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ntk-chtheme \
		${STAGEDIR}${PREFIX}/bin/ntk-fluid \
		${STAGEDIR}${PREFIX}/lib/libntk.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libntk_images.so.${PORTVERSION}

.include <bsd.port.mk>
