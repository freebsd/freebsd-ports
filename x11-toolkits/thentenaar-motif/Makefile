PORTNAME=	thentenaar-motif
DISTVERSION=	2.4.0
CATEGORIES=	x11-toolkits
DISTNAME=	motif-${PORTVERSION}
DISTVERSIONPREFIX=	v

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif X11 Toolkit (industry standard GUI (IEEE 1295))
WWW=		https://github.com/thentenaar/motif

USE_GITHUB=	yes
GH_ACCOUNT=	thentenaar
GH_PROJECT=	motif

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	lesstif
CONFLICTS_INSTALL=	open-motif-devel thentenaar-motif-devel

USES=		autoreconf gmake iconv jpeg libtool:keepla pkgconfig xorg
USE_XORG=	x11 xaw xbitmaps xext xft xt xmu xrender sm ice
BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libXmu.so:x11-toolkits/libXmu
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-printing=no
CPPFLAGS+=	-DCSRG_BASED -DXUSE_MTSAFE_API -DXNO_MTSAFE_PWDAPI -I${PREFIX}/include
USE_CSTD=	gnu89
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

xxx-pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

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
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
