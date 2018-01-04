# $FreeBSD$

PORTNAME=	cwm
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2-9
DISTVERSIONSUFFIX=	-ga0774f4
CATEGORIES=	x11-wm

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Minimalistic window manager for X11 based on evilwm

LICENSE=	ISCL

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	chneukirchen
USE_XORG=	x11 xft xinerama xrandr

PLIST_FILES=	bin/cwm \
		bin/cwm-migrate-config.pl \
		man/man1/cwm.1.gz \
		man/man5/cwmrc.5.gz
SHEBANG_FILES=	migrate-config.pl

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's@/usr/X11R6@${LOCALBASE}@' ${WRKSRC}/cwmrc.5
	@${REINPLACE_CMD} -e 's@strlcpy.o strlcat.o@@' \
		-e 's@strtonum.o@@' ${WRKSRC}/Makefile
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100072
	@${REINPLACE_CMD} 's@reallocarray.o@@' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/migrate-config.pl \
		${STAGEDIR}${PREFIX}/bin/cwm-migrate-config.pl
	${INSTALL_MAN} ${WRKSRC}/cwm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cwmrc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
