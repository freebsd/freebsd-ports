# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk
PORTVERSION=	804.032
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Re-port of a perl5 interface to Tk8.4

LIB_DEPENDS=	libjpeg.so.11:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

OPTIONS_DEFINE=	XFT
OPTIONS_DEFAULT=	XFT
XFT_DESC=	Client-side fonts via libXft

CONFIGURE_ARGS=	X11INC=${LOCALBASE}/include X11LIB=${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure
USE_XORG=	x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
CONFIGURE_ARGS=	XFT=1
USE_XORG+=	xft
.else
CONFIGURE_ARGS=	XFT=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/JPEG/Makefile.PL \
		${WRKSRC}/PNG/Makefile.PL \
		${WRKSRC}/pTk/Makefile.PL

post-configure:
	@${REINPLACE_CMD} \
		-e '/^CC = / s|.*|CC = ${CC}|' \
		-e '/^CCFLAGS = / s|.*|CCFLAGS = ${CFLAGS}|' \
		-e '/^LD = / s|.*|LD = ${CC} ${CFLAGS} ${LDFLAGS}|' \
		-e '/^FULL_AR = / s|.*|FULL_AR = ${AR}|' \
		`${FIND} ${WRKSRC} -name Makefile`

post-stage:
	${FIND} ${STAGEDIR} -name '*.bs' -size 0c -exec ${RM} {} \;
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Tk/Tk.so
.for i in Canvas Compound Entry Event HList IO InputO JPEG Listbox Menubutton Mwm NBFrame PNG Pixmap Scale Scrollbar TList Text TixGrid WinPhoto X Xlib
		${STRIP_CMD} \
		    ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Tk/${i}/${i}.so
.endfor

.include <bsd.port.mk>
