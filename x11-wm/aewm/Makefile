# Created by: trevor
# $FreeBSD$

PORTNAME=	aewm
PORTVERSION=	1.2.7
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	https://www.red-bean.com/decklin/aewm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICCCM-compliant window manager based on 9wm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS GTK2 XFT

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" XROOT="${LOCALBASE}"
USE_XORG=	x11 xext xt xaw

# XXX should use LICENSE instead of installing it as part of documentation,
# but our license framework does not support XFree86 license at this moment
PORTDOCS=	DESIGN LICENSE NEWS README TODO

GTKCLIENTS=	aemenu-gtk aepanel-gtk
XAWCLIENTS=	aemenu-xaw aepanel-xaw aesession set-gnome-pda

GTK2_USE=	GNOME=gtk20
GTK2_PLIST_FILES=	bin/aemenu-gtk bin/aepanel-gtk

XFT_USE=	XORG=xft
XFT_MAKE_ENV+=	DEFINES="-DXFT" \
		EXTRA_INC="`pkg-config --cflags xft`" \
		EXTRA_LIBS="`pkg-config --libs xft`"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIR/s| clients||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/X11|${PREFIX}/etc|' \
		${WRKSRC}/clients/lib/aeclients.h ${WRKSRC}/src/aewm.h

post-build:
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		${XAWCLIENTS}

post-build-GTK2-on:
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		${GTKCLIENTS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aewm ${STAGEDIR}${PREFIX}/bin
.for i in ${XAWCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/src/aewm.1x ${STAGEDIR}${MAN1PREFIX}/man/man1/aewm.1
	${INSTALL_MAN} ${WRKSRC}/clients/aeclients.1x \
		${STAGEDIR}${MAN1PREFIX}/man/man1/aeclients.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/aewm
	${INSTALL_DATA} ${WRKSRC}/src/aewmrc.sample ${STAGEDIR}${PREFIX}/etc/aewm
	${INSTALL_DATA} ${WRKSRC}/clients/clientsrc.sample ${STAGEDIR}${PREFIX}/etc/aewm

do-install-GTK2-on:
.for i in ${GTKCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${LN} -sf aemenu-gtk ${STAGEDIR}${PREFIX}/bin/aemenu
	${LN} -sf aepanel-gtk ${STAGEDIR}${PREFIX}/bin/aepanel

do-install-GTK2-off:
	${LN} -sf aemenu-xaw ${STAGEDIR}${PREFIX}/bin/aemenu
	${LN} -sf aepanel-xaw ${STAGEDIR}${PREFIX}/bin/aepanel

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
