# $FreeBSD$

PORTNAME=	open-motif
PORTVERSION=	2.3.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits
# MASTER_SITES=	SF/${PORTNAME}/Motif%202.3.4%20Source%20Code/
MASTER_SITES=	SF/motif/Motif%202.3.6%20Source%20Code/
DISTNAME=	motif-${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif X11 Toolkit (industry standard GUI (IEEE 1295))

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	lesstif-[0-9]*

USES=		autoreconf gmake iconv jpeg libtool:keepla pkgconfig
USE_XORG=	x11 xaw xbitmaps xext xft xt xmu xrender sm ice
LIB_DEPENDS=	libXp.so:x11/libXp \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-DCSRG_BASED -DXUSE_MTSAFE_API -DXNO_MTSAFE_PWDAPI -I${PREFIX}/include
USE_CSTD=	gnu89
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
# fix sections
	@${FIND} ${WRKSRC}/doc/man/man1 -name '*.1' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|user cmd|1|'
	@${FIND} ${WRKSRC}/doc/man/man3 -name '*.3' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|library call|3|'
# mwmrc is not a kernel interface!!
	@cd ${WRKSRC}/doc/man && ${CP} -f man4/mwmrc.4 man5/mwmrc.5
	@${FIND} ${WRKSRC}/doc/man/man5 -name '*.5' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|special file|5| ; \
		 s|file formats|5|'
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUGREPORT README RELNOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
