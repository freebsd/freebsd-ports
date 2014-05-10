# Created by: trevor
# $FreeBSD$

PORTNAME=	aewm
PORTVERSION=	1.2.7
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.red-bean.com/decklin/aewm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICCCM-compliant window manager based on 9wm

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" XROOT="${LOCALBASE}"
USE_XORG=	x11 xext xt xaw
WANT_GNOME=	yes

# XXX should use LICENSE instead of installing it as part of documentation,
# but our license framework does not support XFree86 license at this moment
PORTDOCS=	DESIGN LICENSE NEWS README TODO

GTKCLIENTS=	aemenu-gtk aepanel-gtk
XAWCLIENTS=	aemenu-xaw aepanel-xaw aesession set-gnome-pda

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20} != ""
USE_GNOME=	gtk20
PLIST_FILES=	bin/aemenu-gtk bin/aepanel-gtk
.endif

.if defined(WITH_XFT)
XORG+=		xft
MAKE_ENV+=	DEFINES="-DXFT" \
		EXTRA_INC="`pkg-config --cflags xft`" \
		EXTRA_LIBS="`pkg-config --libs xft`"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIR/s| clients||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/X11|${PREFIX}/etc|' \
		${WRKSRC}/clients/lib/aeclients.h ${WRKSRC}/src/aewm.h

post-build:
.if ${HAVE_GNOME:Mgtk20} != ""
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} \
		${GTKCLIENTS} ${XAWCLIENTS}
.else
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} \
		${XAWCLIENTS}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aewm ${STAGEDIR}${PREFIX}/bin
.for i in ${XAWCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${HAVE_GNOME:Mgtk20} != ""
.for i in ${GTKCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${LN} -sf aemenu-gtk ${STAGEDIR}${PREFIX}/bin/aemenu
	${LN} -sf aepanel-gtk ${STAGEDIR}${PREFIX}/bin/aepanel
.else
	${LN} -sf aemenu-xaw ${STAGEDIR}${PREFIX}/bin/aemenu
	${LN} -sf aepanel-xaw ${STAGEDIR}${PREFIX}/bin/aepanel
.endif
	${INSTALL_MAN} ${WRKSRC}/src/aewm.1x ${STAGEDIR}${MAN1PREFIX}/man/man1/aewm.1
	${INSTALL_MAN} ${WRKSRC}/clients/aeclients.1x \
		${STAGEDIR}${MAN1PREFIX}/man/man1/aeclients.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/aewm
	${INSTALL_DATA} ${WRKSRC}/src/aewmrc.sample ${STAGEDIR}${PREFIX}/etc/aewm
	${INSTALL_DATA} ${WRKSRC}/clients/clientsrc.sample ${STAGEDIR}${PREFIX}/etc/aewm
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
